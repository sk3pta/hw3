#include "Student.h"

Student::Student(std::string name, std::string middle_name, std::string last_name,
                 size_t course) : name(name), middle_name(middle_name),
                                  last_name(last_name), course(course), student_id(getRandomId()) {
    this->grades = {};
}

Student::Student(std::string name, std::string middle_name, std::string last_name,
                 size_t course,
                 std::map<std::string, unsigned int> grades) : name(name), middle_name(middle_name),
                                                               last_name(last_name),
                                                               course(course),
                                                               grades(grades), student_id(getRandomId()) {

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
}

Student::Student(Student &&student) noexcept {
    std::swap(this->name, student.name);
    std::swap(this->middle_name, student.middle_name);
    std::swap(this->last_name, student.last_name);
    std::swap(this->group_name, student.group_name);
    std::swap(this->course, student.course);
    std::swap(this->grades, student.grades);
}

Student &Student::operator=(const Student &student) {
    this->name = student.name;
    this->middle_name = student.middle_name;
    this->last_name = student.last_name;
    this->group_name = student.group_name;
    this->course = student.course;
    this->grades = student.grades;

    return *this;
}

Student &Student::operator=(Student &&student) {
    std::swap(this->name, student.name);
    std::swap(this->middle_name, student.middle_name);
    std::swap(this->last_name, student.last_name);
    std::swap(this->group_name, student.group_name);
    std::swap(this->course, student.course);
    std::swap(this->grades, student.grades);

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






