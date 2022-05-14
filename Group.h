#ifndef HW3__GROUP_H
#define HW3__GROUP_H

#include "headers.h"
#include "Student.h"
#include "ID.h"

class Group {
private:


    std::string name;
    size_t students_amount;
    std::list<Student> students;

    std::vector<std::string> subjects;

public:
    unsigned int group_id;

    Group(ID *id_manager, std::string name,  size_t students_amount, std::vector<std::string> subjects);

    Group(ID *id_manager, std::string,  size_t students_amount,
          const std::list<Student> &students, std::vector<std::string> subjects);


    ~Group() = default;
    //===================================================================//

    void addStudent(const Student &student);

    std::vector<Student> findByLastName(const std::string &_lastname);

    std::vector<Student> findByName(const std::string &_name);

    std::vector<Student> findByCourse(size_t _course);

    std::vector<Student> findBy;


    const Student &getStudentbyId(unsigned int student_id);
    //===================================================================//


    friend std::ostream &operator<<(std::ostream &out, const Group &group);
    friend std::ostream &Nice_Grades(std::ostream& out, const Group& group);
    friend Group &operator+(Group &group, const Student &student);

    friend Group &operator-(Group &group, const Student &student);

};


#endif //HW3__GROUP_H
