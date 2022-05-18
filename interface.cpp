#include <exception>
#include "interface.h"
#include "headers.h"

LOBBY lobby() {
    std::cout << "-------------HELLO THERE-------------" << std::endl;
    std::cout << "YOU HAVE MANY OPTIONS OF INTERACTION" << std::endl;
    std::cout << " 1 to add group" << std::endl;
    std::cout << " 2 to add student" << std::endl;
    std::cout << " 99 to print all groups" << std::endl;

    size_t input;
    
    std::cin >> input;
    std::cin.ignore();
    
    switch(input) {
        case 1:
            return LOBBY::ADD_GROUP;
        case 2:
            return LOBBY::ADD_STUDENT;
        case 99:
            return LOBBY::PRINT_GROUPS;
    }
}
std::string input_string()
{
    for (;;)
    {
        try
        {
            std::string str;
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