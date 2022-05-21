#include "Student.h"

Student::Student(std::string name, ID *id_manager, std::string middle_name, std::string last_name,
                 unsigned int course) {
    this->course = course;
    this->name = name;
    this->middle_name = middle_name;
    this->last_name = last_name;
    this->student_id = id_manager->getStudentId();
    this->grades = {};
}

Student::Student(std::string name, ID *id_manager, std::string middle_name, std::string last_name,
                 unsigned int course,
                 std::map<std::string, unsigned int> grades) {
    this->course = course;
    this->name = name;
    this->middle_name = middle_name;
    this->last_name = last_name;
    this->student_id = id_manager->getStudentId();
    this->grades = grades;

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


//============================================================


void Student::addGrades(const std::map<std::string, size_t> &new_grades) {

    for (const auto &grade: new_grades) {

        if (this->grades.find(grade.first) == grades.end())
            this->grades.insert(grade);

        else
            this->grades[grade.first] = grade.second;
    }
}

void Student::editname( std::string name1, std::string middle_name1 , std::string last_name1){
    this->name = name1;
    this->middle_name = middle_name1;
    this->last_name = last_name1;

}

void Student::removeGrades(const std::string &subject) {
    this->grades.erase(subject);
}

void Student::changeName(const std::string &_name) {
    this->name = _name;
}

void Student::changeLastName(const std::string &_lastname) {
    this->last_name = _lastname;

}

void Student::changeMiddlieName(const std::string &_middlename) {
    this->middle_name = _middlename;

}

void Student::changeCourse(unsigned int _course) {

    this->course = _course;

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

std::map<std::string, unsigned int> Student::get_grades() {
    return this->grades;
}

std::string Student::getGroup() const {
    return this->group_name;
}

unsigned int Student::getStudentId() const {
    return this->student_id;
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


//======================================
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

std::ostream& saveToJson(std::ostream& out, const Student& student)
{
    using namespace nlohmann;
    json jstud;

    jstud["ID"] = student.student_id;
    jstud["name"] = student.name;
    jstud["middle_name"] = student.middle_name;
    jstud["last_name"] = student.last_name;
    jstud["course"] = student.course;
    jstud["group_name"] = student.group_name;
    for (const auto& item : student.grades) {
        jstud["grades"][item.first] = item.second;
    }
    //jstud.push_back(student.grades);

    out << jstud;
    return out;
}

std::map<std::string, unsigned int> Student::getGrades() {
    return this->grades;
}

unsigned int Student::getID() const {
    return this->student_id;
}

void loadFromJson(std::istream &inp, Student &student) {
    using namespace nlohmann;
    json jstud;
    inp >> jstud;

    student.student_id = jstud["ID"];
    student.course = jstud["course"];
    student.group_name = jstud["group_name"];
    student.name = jstud["name"];
    student.middle_name = jstud["middle_name"];
    student.last_name = jstud["last_name"];

    student.grades = jstud["grades"];

    std::cout << student;

}

void Student::setID(unsigned int _id) {
    student_id = _id;
}











