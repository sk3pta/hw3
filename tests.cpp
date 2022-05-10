
#include "headers.h"
#include "Student.h"
#include "Group.h"
#include "ID.h"

int main() {


    ID mainIdManager(1);

    Student alik("Alik", "Murtazaevich", "Murtazaev", 1);

    Student malik("Alek", "Nonamovich", "Balls",
                  2, {{"Math",    5},
                      {"Physics", 4},
                      {"AL",      5}});

    Group iu10("ИУ10-22",&mainIdManager,0);
    std::cout << "GROUP ID TEST" << "\n" << iu10 << std::endl;
    iu10.addStudent(alik);

    std::cout << iu10 << std::endl;

/*
    //Testing add_grades  and get_grades method

    alik.addGrades({{"Math",5},{"Physics",3},{"AL",5}});
    std::cout << alik;

    alik.addGrades({{"Physics",5}});
    std::cout << alik;


    Group iu8_22("iu8-22");

    std::vector<Student> test_vector = {};
    test_vector.push_back(alik);
    test_vector.push_back(malik);
    std::cout << test_vector.size() << "size " << std::endl;
    Group iu8_33("iu8-33",test_vector.size(),test_vector);
    std::cout << "after adding to a group";
    std::cout << "\n";
    std::cout << iu8_33 << std::endl;

    */

}