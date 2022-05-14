#include "headers.h"
#include "Student.h"
#include "Group.h"
#include "ID.h"

int main() {


    ID mainIdManager;

    Student alik("Alik", &mainIdManager, "Murtazaev", "Murtazaevich", 1, {
            {"Physics",     3},
            {"Mathematics", 5},
            {"AL",          5}}
    );

    Student jack("Jack", &mainIdManager,"Captain","The Sparrow",1);
    jack.addGrades({{"Math",5},{"Physics",5},{"AL",5} });
    std::vector < std::string > subjects = { "Math","Physics","AL" };
    std::list <Student> students = {alik,jack};
    Group iu8_22(&mainIdManager,"ИУ8-22",2,students, subjects);
    std::cout << iu8_22;
    std::cout << "test good marks " << std::endl;
    Nice_Grades(std::cout,iu8_22);

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