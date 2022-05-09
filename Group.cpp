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

void Group::addStudent(const Student &student) {

    Student new_student = student;
    new_student.setGroup(this->name);
    this->students.push_back(new_student);
}

const Student &Group::getStudent(unsigned int student_id)  {

    for (const auto &student : this->students) {
        if (student.getStudentId() == student_id)
            return student;
    }

}



