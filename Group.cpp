#include "Group.h"
#include "headers.h"
#include "ID.h"
#include <fstream>
#include <map>
#include <utility>

Group::Group(ID *id_manager, std::string name, size_t students_amount = 0,
             const std::vector<std::string> subjects = {}) {
    this->group_id = id_manager->getGroupId();
    this->students_amount = students_amount;
    this->name = std::move(name);
    this->subjects = subjects;
    this->students = {};
}


Group::Group(ID *id_manager, std::string name, size_t students_amount, const std::list<Student> &students,
             const std::vector<std::string> subjects) {
    this->group_id = id_manager->getGroupId();
    this->students_amount = students_amount;
    this->name = std::move(name);
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

Group &operator+(Group &group, const Student &student) {
    group.students.push_back(student);
    group.students_amount += 1;
    return group;
}

Group &operator-(Group &group, const Student &student) {
    //
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







