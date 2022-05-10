#include "Group.h"
#include "headers.h"
#include "ID.h"
#include <fstream>

Group::Group(std::string name, ID *id_manager, size_t students_amount = 0) {
    this->group_id = id_manager->getId();
    this->students_amount = students_amount;
    this->students = {};
    this->name = name;
    this->students.resize(students_amount);
}

Group::Group(std::string name, size_t students_amount, std::vector<Student> students,  ID *id_manager) {
    this->group_id = id_manager->getId();

    this->students_amount = students_amount;
    this->students.resize(students_amount);
    this->students = students;
    this->name = name;
    for (auto &student: students) {
        student.setGroup(this->name);
    }
}

void Group::addStudent(const Student &student) {

    Student new_student = student;
    new_student.setGroup(this->name);
    this->students_amount += 1;
    this->students.push_back(new_student);
}

const Student &Group::getStudent(unsigned int student_id) {

    for (const auto &student: this->students) {
        if (student.getStudentId() == student_id)
            return student;
    }

}

std::ostream &operator<<(std::ostream &out, const Group &group) {
    out << "Group: " << group.name  << "ID : " << group.group_id << std::endl;
    for (int i = 0; i < group.students_amount; i++) {
        out << group.students[i] << std::endl;

    }
    return out;


}

Group &operator+(Group &group, const Student &student) {
    group.students_amount += 1;
    group.students.push_back(student);
    return group;
}





