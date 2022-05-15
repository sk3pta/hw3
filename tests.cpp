#include "headers.h"
#include "Student.h"
#include "Group.h"
#include "ID.h"

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



    std::cout << "Init group \n";
    std::cout << iu8_22;
    std::cout << "/==============================/ \n";


    std::cout << "Group ++" << std::endl;
    std::cout << ++iu8_22 << std::endl;
    std::cout << "/=============================/" << std::endl;


    /*

    auto bylastname = iu8_22.findByLastName("Фдшум");
    auto byname = iu8_22.findByName("Jack");
    auto bycourse = iu8_22.findByCourse(1);

    for (auto element: bycourse) {
        std::cout << element;
    }

    Student max("Maximus", &mainIdManager, "Aa", "AArname", 1, {
            {"Physics",     3},
            {"Mathematics", 5},
            {"AL",          5}}
    );

    iu8_22 = iu8_22 +  max;
    std::cout << "tests after +" << std::endl;
    std::cout << iu8_22;
    iu8_22 = iu8_22 - max;
    std::cout << "tests after -" << std::endl;
    std::cout << iu8_22;
    std::cout << "test of sort" << std::endl;
    iu8_22.Sorted_at_all();
    std::cout << iu8_22;


    //std::cout << "test good marks " << std::endl;
    //Nice_Grades(std::cout,iu8_22);


     */
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