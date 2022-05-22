#include <exception>
#include "interface.h"
#include "headers.h"

LOBBY lobby() {
    for(;;) {
        try {
            std::cout << "YOU HAVE MANY OPTIONS OF INTERACTION" << std::endl;
            std::cout << " 1 to add group" << std::endl;
            std::cout << " 2 to add student" << std::endl;
            std::cout << " 3 to save" << std::endl;
            std::cout << " 4 to download" << std::endl;
            std::cout << " 5 to print_groups" << std::endl;
            std::cout << " 6 to print students with good marks" << std::endl;
            std::cout << " 7 to  print students with bad marks" << std::endl;
            std::cout << " 8 to sort students" << std::endl;
            std::cout << " 9 to edit groups" << std::endl;
            std::cout << " 10 to edit students" << std::endl;
            std::cout << " 99 to exit" << std::endl;

            std::cout << "CURRENT DATABASE : " << std::endl;
            LOBBY::CONDITION;



            size_t input;

            input = input_size_t();
            std::cout << std::endl;

            switch (input) {
                case 1:
                    return LOBBY::ADD_GROUP;
                case 2:
                    return LOBBY::ADD_STUDENT;
                case 3:
                    return LOBBY::SAVE;
                case 4:
                    return LOBBY::DOWNLOAD;
                case 5:
                    return LOBBY::PRINT_GROUPS;
                case 6:
                    return LOBBY::ST_W_G_M;
                case 7:
                    return LOBBY::ST_W_B_M;
                case 8:
                    return LOBBY::SORT_ST;
                case 9:
                    return LOBBY::EDIT_GROUPS;
                case 10:
                    return LOBBY::EDIT_STUDENTS;
                case 99:
                    return LOBBY::EXIT;
                default:
                    throw std::exception();
            }
        }
        catch(std::exception& ex){
            std::cout << "Repeat input" << std::endl;
        }
    }
}
STUDENT_PROFILE editing_students(){
    for(;;){
        try{
            std::cout << "INTERACTION WITH STUDENT PROFILE" << std::endl;
            std::cout << " 0 to edit all parametrs" << std::endl;
            std::cout << " 2 to edit name" << std::endl;
            std::cout << " 4 to delete student" << std::endl;
            size_t input = input_size_t();
            std::cout << std::endl;
            switch(input){
                case 0:
                    return STUDENT_PROFILE::ST_EDIT_ALL;
                case 2:
                    return STUDENT_PROFILE::ST_EDIT_NAME;
                case 4:
                    return STUDENT_PROFILE::ST_DELETE;
                default:
                    throw std::exception();
            }
        }
        catch(std::exception& ex){
            std::cout << "Repeat input" << std::endl;
        }
    }
}
GROUP_PROFILE editing_groups(){
    for(;;){
        try{
            std::cout << "INTERACTION WITH GROUP PROFILE" << std::endl;
            std::cout << " 0 to edit  course" << std::endl;
            std::cout << " 1 to edit only name" << std::endl;
            std::cout << " 2 to edit all" << std::endl;
            std::cout << " 3 to delete group" << std::endl;
            size_t input = input_size_t();
            std::cout << std::endl;
            switch(input){
                case 0:
                    return GROUP_PROFILE::GR_EDIT_COURSE;
                case 1:
                    return GROUP_PROFILE::GR_EDIT_NAME;
                case 2:
                    return GROUP_PROFILE::GR_EDIT_ALL;
                case 3:
                    return GROUP_PROFILE::GR_DELETE;
                default:
                    throw std::exception();
            }
        }
        catch(std::exception& ex){
            std::cout << "Repeat input" << std::endl;
        }
    }
}
SORT sorting(){
    for(;;){
        try{
            std::cout << "INTERACTION WITH SORTING" << std::endl;
            std::cout << " 0 to sort by all" << std::endl;
            std::cout << " 1 to sort by name" << std::endl;
            size_t input = input_size_t();
            std::cout << std::endl;
            switch(input){
                case 0:
                    return SORT::SORT_BY_ALL;
                case 1:
                    return SORT::SORT_BY_NAME;
                default:
                    throw std::exception();
            }
        }
        catch(std::exception& ex){
            std::cout << "Repeat input" << std::endl;
        }
    }
}
std::string input_string()
{
    for (;;)
    {
        try
        {
            std::string str = "";
            std::getline(std::cin, str);

            if (str == "")
                throw std::exception();
            return str;
        }
        catch (std::exception& ex)
        {
            std::cout  << "oops it is empty"<<std::endl;
        }
    }
}
unsigned int input_size_t()
{
    for (;;)
    {
        try
        {
            unsigned int num;
            if (std::cin >> num && num >= 0)
            {
                std::cin.ignore(std::numeric_limits<char>::max(), '\n');
                return num;
            }
            else
                throw std::exception();
        }
        catch (std::exception& ex)
        {
            std::cout << ex.what() << "oops, ur input is less than 0";
        }
    }

}