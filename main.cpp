#include "headers.h"


#include "Student.h"
#include "Group.h"
#include "datamanager.h"
#include "interface.h"
int main() {
ID id_manager;
DataManager dataManager;


    for(;;) {
        switch (lobby()) {
            case LOBBY::ADD_GROUP:
            {
                std::cout << "\n>>Добавить группу : \n" << std::endl;
                std::string group_name; unsigned int course; std::vector<std::string> subjects;
                std::list<Student> students; std::string subject_name;

                std::cout << "Название группы : " << std::endl;
                std::getline(std::cin,group_name);
                std::cout << "Курс : \n" << std::endl;
                std::cin >> course; std::cin.ignore();
                std::cout << "Предметы : \n" << std::endl;
                do {
                    std::getline(std::cin, subject_name);
                    subjects.push_back(subject_name);
                }
                while (subject_name != "");

                dataManager.addGroup(&id_manager,group_name,course,subjects);
                std::cout << " Группа создана !" << std::endl;
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