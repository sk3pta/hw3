#include "Student.h"

Student::Student(std::string name, std::string middle_name, std::string last_name,
                 std::string group_name, size_t course) : name(name), middle_name(middle_name),
                                                         last_name(last_name), group_name(group_name), course(course) {
}

Student::Student(std::string name, std::string middle_name, std::string last_name, std::string group_name, size_t course,
                 std::map<std::string, unsigned int> grades) : name(name), middle_name(middle_name),
                                                               last_name(last_name), group_name(group_name),
                                                               course(course),
                                                               grades(grades) {

}

void Student::add_grades(std::string subject, size_t grade) {
    if (this->grades.find(subject) == grades.end())
        this->grades.insert({subject,grade});
    else
        this->grades[subject] = grade;
}

void Student::remove_grades(std::string subject) {
    this->grades.erase(subject);

}



std::ostream &operator<<(std::ostream &out, const Student &student) {
    out << "Student : " <<student.name << " " << student.middle_name << " " << student.last_name << std::endl;
    out << "Group : " << student.group_name << "\nCourse : " << student.course << std::endl;
    out << "Grades : \n";

    for (const auto& element : student.grades) {
        out << element.first << " " << element.second << std::endl;
    }
    out << std::endl;
    return out;
}

double Student::average_all() {
    double average = 0.0;
    double subjects_amount = 0.0;
    for (const auto& element : this->grades) {
        average += element.second;
        subjects_amount +=1;
    }
    return average / subjects_amount;
}




