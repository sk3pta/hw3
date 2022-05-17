#include "Group.h"
#include "headers.h"
#include "ID.h"
#include <fstream>
#include <map>

Group::Group() {

}

Group::Group(ID *id_manager, std::string name, unsigned int course,
             const std::vector<std::string> &subjects = {},size_t students_amount = 0) {
    this->group_id = id_manager->getGroupId();
    this->students_amount = students_amount;
    this->name = std::move(name);
    this->subjects = subjects;
    this->course = course;
    this->students = {};
}


Group::Group(ID *id_manager, std::string name, unsigned int course, size_t students_amount,
             const std::list<Student> &students,
             const std::vector<std::string> &subjects) {
    this->group_id = id_manager->getGroupId();
    this->students_amount = students_amount;
    this->name = std::move(name);
    this->course = course;
    this->subjects = subjects;
    for (auto student: students) {
        student.group_name = this->name;
        this->students.push_back(student);
    }
}

Group::Group(const Group &group) {
    this->group_id = group.group_id;
    this->students_amount = group.students_amount;
    this->name = group.name;
    this->course = group.course;
    this->subjects = group.subjects;
    for (auto student: group.students) {
        student.group_name = this->name;
        this->students.push_back(student);
    }
};

Group::Group(Group &&group) noexcept {
    std::swap(this->group_id, group.group_id);
    std::swap(this->students_amount, group.students_amount);
    std::swap(this->name, group.name);
    std::swap(this->course, group.course);
    std::swap(this->subjects, group.subjects);
    for (auto student: group.students) {
        student.group_name = this->name;
        this->students.push_back(student);
    }
}

Group &Group::operator=(const Group &group) {
    this->group_id = group.group_id;
    this->students_amount = group.students_amount;
    this->name = group.name;
    this->course = group.course;
    this->subjects = group.subjects;
    for (auto student: group.students) {
        student.group_name = this->name;
        this->students.push_back(student);
    }

    return *this;
}

Group &Group::operator=(Group &&group) noexcept {
    std::swap(this->group_id, group.group_id);
    std::swap(this->students_amount, group.students_amount);
    std::swap(this->name, group.name);
    std::swap(this->course, group.course);
    std::swap(this->subjects, group.subjects);
    for (auto student: group.students) {
        student.group_name = this->name;
        this->students.push_back(student);
    }

    return *this;
}


void Group::addStudent(const Student &student) {

    Student new_student = student;
    new_student.group_name = this->name;
    new_student.course = this->course;
    this->students_amount += 1;
    this->students.push_back(new_student);
}

void Group::Sorted_at_all() {
    students.sort([](Student &student1, Student &student2) {
        std::cout << "Check " << student1.averageAll() << " " << student2.averageAll() << std::endl;
        if (student1.averageAll() == student2.averageAll()) {
            std::cout << "wow" << std::endl;
            if (student1.last_name == student2.last_name) {
                if (student1.middle_name == student2.middle_name) {
                    if (student1.name == student2.name) {
                        if (student1.getStudentId() == student2.getStudentId()) {
                        }
                        return student1.getStudentId() > student2.getStudentId();
                    }
                    return student1.name > student2.name;
                }
                return student1.middle_name > student2.middle_name;
            }
            return student1.last_name > student2.last_name;
        }
        return student1.averageAll() > student2.averageAll();
    });
}

void Group::Sorted_by_name() {
    students.sort([](Student &student1, Student &student2) {
        if (student1.last_name == student2.last_name) {
            if (student1.middle_name == student2.middle_name) {
                if (student1.name == student2.name) {
                    if (student1.getStudentId() == student2.getStudentId()) {
                    }
                    return student1.getStudentId() < student2.getStudentId();
                }
                return student1.name > student2.name;
            }
            return student1.middle_name > student2.middle_name;
        }
        return student1.last_name > student2.last_name;
    });
}

const Student &Group::getStudentbyId(unsigned int student_id) {
    for (const auto &student: this->students) {
        if (student.getStudentId() == student_id) return student;
    }
}


std::ostream &Nice_Grades(std::ostream &out, const Group &group) {
    out << "Students wtih good marks in  " << group.name << std::endl;
    for (auto student: group.students) {
        std::map<std::string, unsigned int> grades = student.get_grades();
        int good_grades = 0;
        for (const auto &subject: group.subjects) {
            if (grades[subject] > 3) {
                good_grades += 1;
            }
        }
        if (good_grades == group.subjects.size() - 1) {
            out << student << std::endl;
        }
    }
    return out;
}

std::ostream &Bad_Grades(std::ostream &out, const Group &group) {
    out << "Students wtih bad marks in  " << group.name << std::endl;
    for (auto student: group.students) {
        std::map<std::string, unsigned int> grades = student.get_grades();
        int good_grades = 0;
        for (const auto &subject: group.subjects) {
            if (grades[subject] <= 3) {
                good_grades += 1;
            }
        }
        if (good_grades != 0) {
            out << student << std::endl;
        }
    }
    return out;
}

Group &operator+(Group &group, const Student &student) {
    Student new_student = student;
    new_student.course = group.course;
    new_student.group_name = group.name;
    group.students.push_back(new_student);
    group.students_amount += 1;
    return group;
}

Group &operator-(Group &group, const Student &student) {
    //std::list<Student>::iterator
    auto start = group.students.begin();
    unsigned int id = student.getStudentId();
    for (start = group.students.begin(); start != group.students.end(); start++) {
        if (start->getStudentId() == id) {
            //std::list<Student>::iterator
            auto pos = group.students.erase(start);
            start = pos;
            if (start == group.students.end()) {
                break;
            }
        }
    }
    return group;
}


std::vector<Student> Group::findByLastName(const std::string &_lastname) {
    std::vector<Student> _students = {};

    for (const auto &student: this->students) {
        if (student.last_name == _lastname) _students.push_back(student);
    }

    return _students;


}

std::vector<Student> Group::findByName(const std::string &_name) {
    std::vector<Student> _students = {};

    for (const auto &student: this->students) {
        if (student.name == _name) _students.push_back(student);
    }

    return _students;
}

std::vector<Student> Group::findByCourse(size_t _course) {
    std::vector<Student> _students = {};

    for (const auto &student: this->students) {
        if (student.course == _course) _students.push_back(student);
    }

    return _students;
}

Group &operator++(Group &group) {
    group.course += 1;
    for (auto &student: group.students) {
        student.course += 1;
    }
    return group;
}


//==========================================================

std::ostream &operator<<(std::ostream &out, const Group &group) {
    out << "Group: " << group.name << " with ID : " << group.group_id << std::endl;
    for (const auto &student: group.students) {
        std::cout << student;
    }
    return out;
}

std::ostream &saveToJson(std::ostream &out, const Group &group) {
    using namespace nlohmann;

    json jgroup;

    jgroup["id"] = group.group_id;
    jgroup["name"] = group.name;
    jgroup["course"] = group.course;
    for (size_t x = 0; x < group.subjects.size(); ++x) {
        jgroup["subjects"][x] = group.subjects[x];
    }

    size_t x = 0;
    for (auto student: group.students) {

        jgroup["students"][x]["ID"] = student.getID();
        jgroup["students"][x]["name"] = student.name;
        jgroup["students"][x]["middle_name"] = student.middle_name;
        jgroup["students"][x]["last_name"] = student.last_name;
        jgroup["students"][x]["course"] = student.course;
        jgroup["students"][x]["group_name"] = student.group_name;
        for (const auto &item: student.getGrades()) {
            jgroup["students"][x]["grades"][item.first] = item.second;
        }
        ++x;
    }


    out << jgroup;
    return out;
}

void loadFromJson(std::ifstream &inp, Group &group) {
    using namespace nlohmann;
    json jgroup;
    inp >> jgroup;

    group.group_id = jgroup["id"];
    group.name = jgroup["name"];
    group.course = jgroup["course"];

    for (size_t x = 0; x < group.subjects.size(); ++x) {
        group.subjects[x] = jgroup["subjects"][x];
    }

    for (const auto &student: jgroup["students"]) {
        Student _student;
        _student.name = student["name"];
        _student.middle_name = student["middle_name"];
        _student.last_name = student["last_name"];
        _student.group_name = student["group_name"];
        _student.course = student["course"];
        auto _grades = student["grades"];
        _student.addGrades(_grades);
        _student.setID(student["ID"]);
        group.students.push_back(_student);
    }

    //group.students = jgroup["students"];

}











