#include "headers.h"


#include "Student.h"
#include "Group.h"
#include "datamanager.h"
#include "interface.h"
int main() {
ID id_manager;
DataManager dataManager;
std::map<Group, unsigned int> groups_ids;
std::map<Student, unsigned int> student_ids;


    for(;;) {
        switch (lobby()) {
            case LOBBY::ADD_GROUP:
            {
                std::cout << "\n>>Add Group : \n" << std::endl;
                std::string group_name; unsigned int course; std::vector<std::string> subjects;
                std::list<Student> students; std::string subject_name;

                std::cout << "Name of the group : " << std::endl;
                group_name = input_string();
                std::cout << "Course : \n" << std::endl;
                course = input_size_t();
                std::cout << "Subjects : \n" << std::endl;
                do {
                    subject_name = input_string();
                    if(subject_name != "0") {
                        subjects.push_back(subject_name);
                    }
                }
                while (subject_name != "0");
                dataManager.addGroup(&id_manager,group_name,course,subjects);
                std::cout << " WOw Group is created !" << std::endl;
            }
            case LOBBY::ADD_STUDENT:{
                std::cout<< "\n >> Add Student : \n" << std::endl;
                std::cout << "\n >> Enter id of the group: \n" << std::endl;
                unsigned int id_group;
                id_group = input_size_t();
                std::string name;
                std::string middle_name;
                std::string last_name;
                unsigned int course;
                std::cout<< "\n >>  : \n" << std::endl;
                std::map<std::string, unsigned int> grades;
                std::cout << "First name: " << std::endl;
                name = input_string();
                std::cout << "Middle name: " << std::endl;
                middle_name = input_string();
                std::cout << "Last name: " << std::endl;
                last_name = input_string();
                std::cout << "Course : \n" << std::endl;
                course = input_size_t();
                std::cout << "Subjects : \n" << std::endl;
                std::string subject_name;
                do {
                    subject_name = input_string();
                    if(subject_name != "0") {
                        std::size_t mark;
                        mark = input_size_t();
                        grades[subject_name] = mark;
                    }
                }
                while (subject_name != "0");
                if (dataManager.groups_ids.find(id_group) != dataManager.groups_ids.end()) {
                    dataManager.addStudent(name,&id_manager,middle_name,last_name,course,grades,id_group);
                }
                std::cout << " WOw Group is created !" << std::endl;
            }
            case LOBBY::PRINT_GROUPS:
            {
                for (auto group : dataManager.groups) {
                    std::cout << group;
                }
            }
        }
    }





}