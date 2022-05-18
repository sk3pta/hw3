#include <exception>
#include "interface.h"
#include "headers.h"

LOBBY lobby() {
    for(;;) {
        try {
            std::cout << "-------------HELLO THERE-------------" << std::endl;
            std::cout << "YOU HAVE MANY OPTIONS OF INTERACTION" << std::endl;
            std::cout << " 1 to add group" << std::endl;
            std::cout << " 2 to add student" << std::endl;
            std::cout << " 99 to print all groups" << std::endl;

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
            input = input_size_t();
            std::cout << std::endl;
            switch(input){
                case 0:
                    return ST_EDIT_ALL;
                case 1:
                    return ST_EDIT_MARKS;
                case 2:
                    return ST_EDIT_NAME;
                case 3:
                    return ST_EDIT_COURSE;
                case 4:
                    return ST_DELETE;
            }
        }
        catch(std::exception& ex){
            std::cout << "Repeat input" << std::endl;
        }
    }
}
STUDENT_PROFILE editing_groups(){
    for(;;){
        try{
            input = input_size_t();
            std::cout << std::endl;
            switch(input){
                case 0:
                    return GR_EDIT_COURSE;
                case 1:
                    return GR_EDIT_NAME;
                case 2:
                    return GR_DELETE;

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
size_t input_size_t()
{
    for (;;)
    {
        try
        {
            unsigned int num;
            if (std::cin >> num && num >= 0)
            {
                std::cin.ignore(std::numeric_limits<char>::max(), '\n');
                return (size_t)num;
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