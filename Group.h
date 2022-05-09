#ifndef HW3__GROUP_H
#define HW3__GROUP_H

#include "headers.h"
#include "Student.h"
class Group {
private:
    std::string name;
    size_t students_amount;
    std::vector<Student> students;


public:
    explicit Group(std::string name,size_t students_amount = 0);

    Group(std::string,size_t students_amount,
          std::vector<Student> students);


    //===================================================================//

    void addStudent(const Student &student);

    const Student &getStudent(unsigned int student_id);
};


#endif //HW3__GROUP_H
