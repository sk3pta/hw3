#include "Group.h"
#include "headers.h"
#include "ID.h"
#include <fstream>
#include <map>
#include <utility>

Group::Group(ID *id_manager, std::string name,  size_t students_amount = 0) {
    this->group_id = id_manager->getGroupId();
    this->students_amount = students_amount;
    this->students = {};
    this->name = std::move(name);
}

Group::Group(ID *id_manager, std::string name,  size_t students_amount, const std::list<Student>& students) {
    this->group_id = id_manager->getGroupId();
    this->students_amount = students_amount;
    this->name = std::move(name);
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

const Student &Group::getStudent(unsigned int student_id) {
    for (const auto& student : this->students) {
        if (student.getStudentId() == student_id) return student;
    }
}

std::ostream &operator<<(std::ostream &out, const Group &group) {
    out << "Group: " << group.name << " with ID : " << group.group_id << std::endl;
    for (const auto &student : group.students) {
        std::cout << student;
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

std::ostream Nice_Grades(std::ostream& out, const Group& group)
{
    
}
