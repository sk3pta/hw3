
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
    size_t grade;

    std::map<std::string,unsigned int> grades;
public:
    Student(std::string name, std::string middle_name, std::string last_name,
            std::string group_name, size_t grade);



};


#endif //HW3__STUDENT_H
