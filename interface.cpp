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
            std::cout << " 11 to find students" << std::endl;
            std::cout << " 12 to find groups" << std::endl;

            std::cout << " 99 to exit" << std::endl;

            std::cout << "CURRENT DATABASE : " << std::endl;




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
                case 11:
                    return LOBBY::FIND_STUDENT;
                case 12:
                    return LOBBY::FIND_GROUP;
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


FIND_GROUP find_group() {
    for (;;) {
        try {
            std::cout << "Find group by : " << std::endl;

            std::cout << "1 to find it by name " << std::endl;
            std::cout << "2 to find it by course " << std::endl;
            std::cout << "3 to find it by ID " << std::endl;

            auto input = input_size_t();
            switch (input) {
                case 1: {
                    return FIND_GROUP::BY_NAME;
                }
                case 2:
                    return FIND_GROUP::BY_COURSE;
                case 3:
                    return FIND_GROUP::BY_ID;

                default:
                    throw std::exception();
            }
        }


        catch(std::exception& ex){
            std::cout << "Repeat input" << std::endl;
        }


    }
}


FIND_STUDENT find_student() {
    for(;;) {
        try {
            std::cout << "Find student by : " << std::endl;
            std::cout << "1 to find it by  name " << std::endl;
            std::cout << "2 to find it by midde name " << std::endl;
            std::cout << "3 to find it by last name " << std::endl;
            std::cout << "4 to find it by course " << std::endl;
            std::cout << "5 to find it by group name " << std::endl;
            std::cout << "6 to find it by student id " << std::endl;
            auto input = input_size_t();
            switch(input){
                case 1:{
                    return FIND_STUDENT::BY_NAME;
                }
                case 2:
                    return FIND_STUDENT::BY_MNAME;
                case 3:
                    return FIND_STUDENT::BY_LNAME;
                case 4:
                    return FIND_STUDENT::BY_COURSE;
                case 5:
                    return FIND_STUDENT::BY_GROUPNAME;
                case 6:
                    return FIND_STUDENT::BY_ID;
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
            std::cout << " 1 to edit name" << std::endl;
            std::cout << " 2 to delete student" << std::endl;
            size_t input = input_size_t();
            std::cout << std::endl;
            switch(input){
                case 0:
                    return STUDENT_PROFILE::ST_EDIT_ALL;
                case 1:
                    return STUDENT_PROFILE::ST_EDIT_NAME;
                case 2:
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