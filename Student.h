
#ifndef HW3__STUDENT_H
#define HW3__STUDENT_H

#include "headers.h"
#include <map>
#include "ID.h"

class Student {


private:

    unsigned int student_id;
    std::map<std::string, unsigned int> grades;



public:
    std::string name;
    std::string middle_name;
    std::string last_name;
    std::string group_name;
    unsigned int course;
    Student() = default;


    Student(std::string name, ID *id_manager, std::string middle_name, std::string last_name, unsigned int course);

    Student(std::string name, ID *id_manager, std::string middle_name, std::string last_name,
            unsigned int course, std::map<std::string, unsigned int> grades);

    Student(const Student &student);

    Student(Student &&student) noexcept;

    ~Student() = default;

    //--------------------------------------------------------------------------------------//



    void addGrades(const std::map<std::string, size_t> &);

    std::map<std::string, unsigned int> getGrades();

    void removeGrades(const std::string &subject);

    void changeName(const std::string &_name);

    void changeLastName(const std::string &_lastname);

    void changeMiddlieName(const std::string &_middlename);

    void changeCourse(unsigned int _course);


    double averageAll();

    std::map<std::string, unsigned int> get_grades();

    std::string getGroup() const;

    unsigned int getStudentId() const;
    //-------------------------------------------------------------------------------------//

    Student &operator=(const Student &student);

    Student &operator=(Student &&student);

    friend std::ostream &operator<<(std::ostream &out, const Student &student);


};


#endif //HW3__STUDENT_H

