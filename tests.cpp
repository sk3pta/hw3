#include "headers.h"
#include "Student.h"
#include "Group.h"
#include "ID.h"
#include <fstream>

int main() {


    ID mainIdManager;


    Student alik("Alik", &mainIdManager, "Ab", "AArname", 1, {
            {"Physics",     3},
            {"Mathematics", 5},
            {"AL",          5}}
    );

    Student jack("Jack", &mainIdManager, "Ac", "AArname", 1);
    jack.addGrades({{"Math",    3},
                    {"Physics", 5},
                    {"AL",      5}});


    std::vector<std::string> subjects = {"Math", "Physics", "AL"};
    std::list<Student> students = {alik, jack};
    Group iu8_22(&mainIdManager, "IU8-22", 1, 2, students, subjects);

    std::ofstream output("/home/augustus/CLionProjects/hw3/student.json");
    saveToJson(output,jack);

    output.close();
    std::ofstream output_gr("/home/augustus/CLionProjects/hw3/group.json");
    saveToJson(output_gr,iu8_22);

    std::cout << "TESTING READING STUDENT FROM JSON FILE " << std::endl;
    std::ifstream input("/home/augustus/CLionProjects/hw3/student.json");
    Student me;
    loadFromJson(input,me);

    std::cout << "\n\n\n\n" << std::endl;

    std::ofstream output2("/home/augustus/CLionProjects/hw3/group.json");
    saveToJson(output2,iu8_22);
    output2.close();
    std::ifstream input2("/home/augustus/CLionProjects/hw3/group.json");

    Group iu8_33;
    loadFromJson(input2,iu8_33);
    output2.close();
    std::cout << "TESTING READING GROUP \n\n\n" << iu8_33;
}