
#include "headers.h"
#include "Student.h"
#include "Group.h"

int main() {

    srand(static_cast<int>(time(nullptr)));

    Student alik("Alik","Murtazaevich","Murtazaev",1);

    Student malik("Alek","Nonamovich","Balls",
                  2,{{"Math",5}, {"Physics",4},
                     {"AL",5}});


    //Testing add_grades  and get_grades method

    alik.addGrades({{"Math",5},{"Physics",3},{"AL",5}});
    std::cout << alik;

    alik.addGrades({{"Physics",5}});
    std::cout << alik;


    Group iu8_22("iu8-22");

    std::vector<Student> test_vector;
    test_vector.push_back(alik);
    test_vector.push_back(malik);

    Group iu8_33("iu8-33",test_vector.size(),test_vector);
    std::cout << "after adding to a group";
    std::cout << alik;
    std::cout << malik;
    std::cout << "";


    auto alik_id = alik.getStudentId();

}