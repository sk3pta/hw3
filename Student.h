
#ifndef HW3__STUDENT_H
#define HW3__STUDENT_H

#include "headers.h"
#include <map>

class Student {
private:

    std::string name;
    std::string middle_name;
    std::string last_name;


    std::string group_name;
    size_t course{};

    std::map<std::string, unsigned int> grades;

public:

    Student() = default;


    Student(std::string name, std::string middle_name, std::string last_name,
            std::string group_name, size_t course);

    Student(std::string name, std::string middle_name, std::string last_name,
            std::string group_name, size_t course, std::map<std::string, unsigned int> grades);

    Student(const Student &student);

    Student(Student &&student) noexcept;

    ~Student() = default;

    //--------------------------------------------------------------------------------------//

    void add_grades(const std::map<std::string,size_t>&);

    void remove_grades(const std::string& subject);

    double average_all();

    std::map<std::string, unsigned int> get_grades();

    //-------------------------------------------------------------------------------------//

    Student &operator=(const Student &student);

    Student &operator=(Student &&student);

    friend std::ostream &operator<<(std::ostream &out, const Student &student);

};


#endif //HW3__STUDENT_H
