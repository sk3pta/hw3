#include "Group.h"
#include <fstream>

Group::Group(std::string name, size_t students_amount)
{

    this->students = {};
    this-> name = name;
    this->students.resize(students_amount);
}

Group::Group(std::string name, size_t students_amount, std::vector<Student> students) 
{


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
    this->students.push_back(new_student);
}

const Student &Group::getStudent(unsigned int student_id)  {

    for (const auto &student : this->students) {
        if (student.getStudentId() == student_id)
            return student;
    }

}
std::ostream& operator <<(std::ostream& out, const Group group) {
    out << "Group: wow " << group.name << std::endl;
    for (int i = 0; i < group.students_amount; i++) {
        out << group.students[i] << std::endl;

    }
    return out;



}



