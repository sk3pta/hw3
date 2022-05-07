#include "headers.h"
#include "Student.h"
#include "Group.h"


int main() {

    Group test("IU8-21",20);
    Student test_student("Alik", "Murtazaev", "Murtazaevich", "IU8-22", 1, {{"maths", 5}
    });
    std::vector<Student> iu8_students;
    iu8_students.push_back(test_student);
    Group iu8("IU8-22",1);
    std::cout << test_student;

    test_student.add_grades("physics",5);
    std::cout << "\n new";
    test_student.remove_grades("maths");
    std::cout << "\n test";

    test_student.add_grades("physics",5);
    test_student.add_grades("meth",4);

    std::cout << "test" << std::endl;
    std::cout << test_student.average_all();

}