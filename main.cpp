#include "headers.h"
#include "Student.h"


int main() {

    std::ofstream database("/home/augustus/CLionProjects/hw3/database.txt");



    Student test_student("Alik", "Murtazaev", "Murtazaevich", "IU8-22", 1, {{"maths", 5}
    });

    std::cout << "TESTATAD";

    test_student.add_grades("physics",2);
    std::cout << "testtdts";
    test_student.add_grades("physics",5);
    std::cout << test_student;
    std::cout << "\n new";
    test_student.remove_grades("maths");
    std::cout << "\n test";

}