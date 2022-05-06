
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
    size_t course;

    std::map<std::string,unsigned int> grades;





public:


    Student(std::string name, std::string middle_name, std::string last_name,
            std::string group_name, size_t course);

    Student(std::string name, std::string middle_name, std::string last_name,
            std::string group_name, size_t course, std::map<std::string,unsigned int> grades);


    //--------------------------------------------------------------------------------------//

    void add_grades(std::string subject, size_t grade);
    void remove_grades(std::string subject);

    //-------------------------------------------------------------------------------------//

    friend std::ostream operator << (std::ostream &out,const Student &student);
};


#endif //HW3__STUDENT_H
