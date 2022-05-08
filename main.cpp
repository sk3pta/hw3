#include "headers.h"
#include "Student.h"
#include "Group.h"


int main() {

    Student test_student("Alik", "Murtazaev", "Murtazaevich", "IU8-22", 1, {{"maths", 5}
    });
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