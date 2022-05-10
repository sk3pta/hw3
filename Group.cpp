#include "Group.h"
#include "headers.h"
#include "ID.h"
#include <fstream>
#include <map>

Group::Group(std::string name, ID *id_manager, size_t students_amount = 0) {
    this->group_id = id_manager->getId();
    this->students_amount = students_amount;
    this->students = {};
    this->name = name;
}

Group::Group(std::string name, size_t students_amount, std::map<unsigned int, Student > students,  ID *id_manager) {
    this->group_id = id_manager->getId();

    this->students_amount = students_amount;
    this->students = students;
    this->name = name;
    std::map<unsigned int, Student > :: iterator it;
    for (it = students.begin(); it != students.end(); ++it) {
        // здесь будет добавление, но так как пока с этим все сложно , ничего нет (((
        it->second.setGroup(this->name);

    }
}

void Group::addStudent(const Student &student) {

    Student new_student = student;
    new_student.setGroup(this->name);
    this->students_amount += 1;
    this->students.insert({ new_student.getStudentId(), new_student });
}

const Student &Group::getStudent(unsigned int student_id) {

    return students[student_id];
}

std::ostream &operator<<(std::ostream &out, const Group &group) {
    out << "Group: " << group.name  << "ID : " << group.group_id << std::endl;
    std::map <unsigned int, Student> :: iterator it;
    std::map<unsigned int, Student> remaked_map = group.students;
    for (it = remaked_map.begin(); it != group.students.end(); it++) {
        out << it->second << std::endl;

    }
    return out;


}

Group &operator+(Group &group, const Student &student) {
    group.students.insert({ student.getStudentId(), student });
    return group;
}

Group& operator-(Group& group, const Student& student)
{
    group.students.erase(group.students.find(student.getStudentId()));
    return group;
}





