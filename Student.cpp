#include "Student.h"

Student::Student(std::string name, ID *id_manager, std::string middle_name,  std::string last_name,
                 size_t course){
    this->name = name;
    this->middle_name = middle_name;
    this->last_name = last_name;
    this->name = name;
    this->student_id = id_manager->getId();
    this->grades = {};
}

Student::Student(std::string name,ID *id_manager, std::string middle_name, std::string last_name,
                 size_t course,
                 std::map<std::string, unsigned int> grades) {
    this->name = name;
    this->middle_name = middle_name;
    this->last_name = last_name;
    this->name = name;
    this->student_id = id_manager->getId();
    this->grades = grades;

}

void Student::addGrades(const std::map<std::string, size_t> &new_grades) {

    for (const auto &grade: new_grades) {

        if (this->grades.find(grade.first) == grades.end())
            this->grades.insert(grade);

        else
            this->grades[grade.first] = grade.second;
    }
}

void Student::removeGrades(const std::string &subject) {
    this->grades.erase(subject);

}


std::ostream &operator<<(std::ostream &out, const Student &student) {
    out << "StudentID : " << student.student_id << std::endl;
    out << "Student : " << student.name << " " << student.middle_name << " " << student.last_name << std::endl;
    out << "Group : " << student.group_name << "\nCourse : " << student.course << std::endl;
    out << "Grades : \n";

    for (const auto &element: student.grades) {
        out << element.first << " " << element.second << std::endl;
    }
    out << std::endl;
    return out;
}

double Student::averageAll() {
    double average = 0.0;
    double subjects_amount = 0.0;
    for (const auto &element: this->grades) {
        average += element.second;
        subjects_amount += 1;
    }
    return average / subjects_amount;
}

Student::Student(const Student &student) {
    this->name = student.name;
    this->middle_name = student.middle_name;
    this->last_name = student.last_name;
    this->group_name = student.group_name;
    this->course = student.course;
    this->grades = student.grades;
    this->student_id = student.student_id;
}

Student::Student(Student &&student) noexcept {
    std::swap(this->name, student.name);
    std::swap(this->middle_name, student.middle_name);
    std::swap(this->last_name, student.last_name);
    std::swap(this->group_name, student.group_name);
    std::swap(this->course, student.course);
    std::swap(this->grades, student.grades);
    std::swap(this->student_id, student.student_id);
}

Student &Student::operator=(const Student &student) {
    this->name = student.name;
    this->middle_name = student.middle_name;
    this->last_name = student.last_name;
    this->group_name = student.group_name;
    this->course = student.course;
    this->grades = student.grades;
    this->student_id = student.student_id;

    return *this;
}

Student &Student::operator=(Student &&student) {
    std::swap(this->name, student.name);
    std::swap(this->middle_name, student.middle_name);
    std::swap(this->last_name, student.last_name);
    std::swap(this->group_name, student.group_name);
    std::swap(this->course, student.course);
    std::swap(this->grades, student.grades);
    std::swap(this->student_id, student.student_id);

    return *this;
}

std::map<std::string, unsigned int> Student::get_grades() {
    return this->grades;
}

void Student::setGroup(const std::string &groupname) {

    this->group_name = groupname;

}

std::string Student::getGroup() {
    return this->group_name;
}

unsigned int Student::getStudentId() const {
    return this->student_id;
}






