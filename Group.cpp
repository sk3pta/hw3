#include "Group.h"
#include "headers.h"
#include "ID.h"
#include <fstream>
#include <map>
#include <utility>

Group::Group(ID *id_manager, std::string name, unsigned int course, size_t students_amount = 0,
             const std::vector<std::string> subjects = {}) {
    this->group_id = id_manager->getGroupId();
    this->students_amount = students_amount;
    this->name = std::move(name);
    this->subjects = subjects;
    this->course = course;
    this->students = {};
}


Group::Group(ID *id_manager, std::string name, unsigned int course, size_t students_amount, const std::list<Student> &students,
             const std::vector<std::string> subjects) {
    this->group_id = id_manager->getGroupId();
    this->students_amount = students_amount;
    this->name = std::move(name);
    this-> course = course;
    this->subjects = subjects;
    for (auto student: students) {
        student.setGroup(this->name);
        this->students.push_back(student);
    }
}

void Group::addStudent(const Student &student) {

    Student new_student = student;
    new_student.setGroup(this->name);
    this->students_amount += 1;
    this->students.push_back(new_student);
}

void Group::Sorted_at_all()
{   
    students.sort([](Student& student1, Student& student2) {
        std::cout << "Check " << student1.averageAll() << " " << student2.averageAll() << std::endl;
        if (student1.averageAll() == student2.averageAll()) {
            std::cout << "wow" << std::endl;
            if (student1.last_name == student1.last_name) {
                if (student1.middle_name == student1.middle_name) {
                    if (student1.name == student1.name) {
                        if (student1.getStudentId() == student2.getStudentId()) {
                        }
                        return student1.getStudentId() < student2.getStudentId();
                    }
                    return student1.name > student1.name;
                }
                return student1.middle_name > student1.middle_name;
            }
            return student1.last_name > student1.last_name;
        }
        return student1.averageAll() > student2.averageAll();
        });
}

void Group::Sorted_by_name()
{
    students.sort([](Student& student1, Student& student2) {
        if (student1.last_name == student1.last_name) {
            if (student1.middle_name == student1.middle_name) {
                if (student1.name == student1.name) {
                    if (student1.getStudentId() == student2.getStudentId()) {
                    }
                    return student1.getStudentId() < student2.getStudentId();
                }
                return student1.name > student1.name;
            }
            return student1.middle_name > student1.middle_name;
        }
        return student1.last_name > student1.last_name;
        });
}

const Student &Group::getStudentbyId(unsigned int student_id) {
    for (const auto &student: this->students) {
        if (student.getStudentId() == student_id) return student;
    }
}

std::ostream &operator<<(std::ostream &out, const Group &group) {
    out << "Group: " << group.name << " with ID : " << group.group_id << std::endl;
    for (const auto &student: group.students) {
        std::cout << student;
    }

    return out;


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

std::ostream& Bad_Grades(std::ostream& out, const Group& group)
{
    out << "Students wtih bad marks in  " << group.name << std::endl;
    for (auto student : group.students) {
        std::map<std::string, unsigned int> grades = student.get_grades();
        int good_grades = 0;
        for (const auto& subject : group.subjects) {
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
    group.students.push_back(student);
    group.students_amount += 1;
    return group;
}

Group &operator-(Group &group, const Student &student) {
    std::list<Student>::iterator start = group.students.begin();
    unsigned int id = student.getStudentId();
    for (start = group.students.begin(); start != group.students.end(); start++) {
        if (start->getStudentId() == id) {
            std::list<Student>::iterator pos = group.students.erase(start);
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







