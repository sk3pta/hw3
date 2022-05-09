#include "Group.h"

Group::Group(std::string name, size_t students_amount) :
        name(name), students_amount(students_amount) {

    this->students = {};
    this->students.resize(students_amount);
}

Group::Group(std::string, size_t students_amount, std::vector<Student> students) :
        name(name), students_amount(students_amount), students(students) {


    this->students.resize(students_amount);
    this->students = students;

    for (auto &student: students) {
        student.setGroup(this->name);
    }
}



