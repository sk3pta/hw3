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
    unsigned int course;
    std::vector<std::string> subjects;
    unsigned int group_id;

public:

    Group();

    Group(ID *id_manager, std::string name, unsigned int course,
          const std::vector<std::string> &subjects, size_t students_amount);

    Group(ID *id_manager, std::string name, unsigned int course, size_t students_amount,
           const std::list<Student> &students, const std::vector<std::string> &subjects);


    Group(const Group &group);


    Group(Group &&group) noexcept;

    ~Group() = default;
    //===================================================================//

    void addStudent( Student &student);

    void deleteStudent(Student &student);

    void editName(Student &student);

    void Sorted_at_all();

    std::string getName() {
        return this->name;
    }

    auto getCourse() {
        return this->course;
    }


    auto & getStudents() {
        return this->students;
    }

    void setName(std::string name) {
        this->name = name;
    };
    void setID(size_t id){
        this->group_id = id;
    }

    void setCourse(unsigned int course) {
        this->course = course;
    }

    void addSubjects(std::vector<std::string> subs) {
        this->subjects = subs;
    }

    void Sorted_by_name();

    std::vector<Student> findByLastName(const std::string &_lastname);

    std::vector<Student> findByName(const std::string &_name);

    std::vector<Student> findByCourse(size_t _course);

    std::vector<Student> findBy;

    std::vector<std::string> getSubjects();

    Student &getStudentbyId(unsigned int student_id);
    size_t getGroupbyId() const;
    //===================================================================//

    Group &operator=(const Group &group);

    Group &operator=(Group &&group) noexcept;


    friend std::ostream &operator<<(std::ostream &out, const Group &group);

    friend std::ostream &saveToJson(std::ostream &out, const Group &group);

    friend std::ostream &Nice_Grades(std::ostream &out, const Group &group);

    friend std::ostream &Bad_Grades(std::ostream &out, const Group &group);

    friend Group &operator+(Group &group, const Student &student);

    friend Group &operator-(Group &group, const Student &student);

    friend Group &operator++(Group &group); // course +1

    friend void loadFromJson(std::ifstream &inp, Group &group);

};
#endif //HW3__GROUP_H
