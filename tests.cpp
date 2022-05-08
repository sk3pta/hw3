
#include "headers.h"
#include "Student.h"
#include "Group.h"

int main() {

    Student alik("Alik","Murtazaevich","Murtazaev","IU8-22",1);

    Student malik("Alek","Nonamovich","Balls","AY8-32",
                  2,{{"Math",5}, {"Physics",4},
                     {"AL",5}});


    //Testing add_grades  and get_grades method

    alik.add_grades({{"Math",5},{"Physics",3},{"AL",5}});
    std::cout << alik;

    alik.add_grades({{"Physics",5}});
    std::cout << alik;


    Group iu8_22("iu8-22");
}