#include "headers.h"
#include <thread>
#include <future>
#include "Student.h"
#include "Group.h"
#include "datamanager.h"
#include "interface.h"

int main() {


    std::thread *thr = nullptr;
    ID id_manager;
    DataManager dataManager;


    for (;;) {
        switch (lobby()) {
            case LOBBY::ADD_GROUP: {
                std::cout << "\n>>Add Group : \n" << std::endl;
                std::string group_name;
                unsigned int course;
                std::vector<std::string> subjects;
                std::list<Student> students;
                std::string subject_name;

                std::cout << "Name of the group : " << std::endl;
                group_name = input_string();
                std::cout << "Course : \n" << std::endl;
                course = input_size_t();
                std::cout << "Subjects : \n" << std::endl;
                do {
                    std::cout << "\n Name of the subject \n" << std::endl;
                    subject_name = input_string();
                    if (subject_name != "0") {
                        subjects.push_back(subject_name);
                    }
                } while (subject_name != "0");
                dataManager.addGroup(&id_manager, group_name, course, subjects);
                std::cout << " WOw Group is created with id!"
                          << dataManager.groups[dataManager.groups.size() - 1].getGroupbyId() << std::endl;
                break;
            }
            case LOBBY::ADD_STUDENT: {
                std::cout << "\n >> Add Student : \n" << std::endl;
                std::cout << "\n >> Enter id of the group: \n" << std::endl;
                unsigned int id_group;
                id_group = input_size_t();
                std::string name;
                std::string middle_name;
                std::string last_name;
                unsigned int course;
                std::map<std::string, unsigned int> grades;
                std::cout << "First name: " << std::endl;
                name = input_string();
                std::cout << "Middle name: " << std::endl;
                middle_name = input_string();
                std::cout << "Last name: " << std::endl;
                last_name = input_string();
                std::cout << "Course : \n" << std::endl;
                course = input_size_t();

                auto group = dataManager.getGroupUsingID(id_group);
                for (const auto &subj: group.getSubjects()) {
                    grades.insert({subj, 0});

                }
                for (auto &subj: grades) {
                    std::cout << "Your mark for the subject : " << subj.first << std::endl;
                    std::size_t mark = input_size_t();
                    subj.second = mark;
                }
                /*
                do {
                    std::cout << "name of the subject: \n" << std::endl;
                    subject_name = input_string();
                    if(subject_name != "0") {
                        std::size_t mark;
                        std::cout << "your mark: \n" << std::endl;
                        mark = input_size_t();
                        grades[subject_name] = mark;
                    }
                }
                while (subject_name != "0");
                 */




                if (dataManager.groups_ids.find(id_group) == dataManager.groups_ids.end()) {
                    dataManager.addStudent(name, &id_manager, middle_name, last_name, course, grades, id_group);

                }
                std::cout << " Created a student with id " << dataManager.students_ids.rbegin()->second.getID()
                          << std::endl;
                break;
            }


            case LOBBY::PRINT_GROUPS: {
                for (const auto &group: dataManager.groups) {
                    std::cout << group;
                }
                break;
            }


            case LOBBY::EDIT_STUDENTS: {
                switch (editing_students()) {
                    case STUDENT_PROFILE::ST_EDIT_NAME: {
                        std::cout << ">>CHANGE STUDENT NAME :" << std::endl;
                        size_t student_id;
                        size_t group_id;
                        std::cout << ">> ID of a group : " << std::endl;
                        group_id = input_size_t();
                        std::cout << ">> ID of a student : " << std::endl;
                        student_id = input_size_t();

                        std::cout << "NAME : " << std::endl;
                        std::string new_name = input_string();
                        std::cout << "LAST NAME : " << std::endl;
                        std::string new_last_name = input_string();
                        std::cout << "MIDDLE NAME : " << std::endl;
                        std::string new_middle_name = input_string();

                        auto group = dataManager.getGroupUsingID(group_id);

                        auto student = group.getStudentbyId(student_id);
                        student.name = new_name;
                        student.last_name = new_last_name;
                        student.middle_name = new_middle_name;


                        std::cout << "Student with id " << student_id << " has successfule changed his name "
                                  << std::endl;
                    }
                }
            }

            case LOBBY::ST_W_G_M: {
                std::cout << "Enter id of the group" << std::endl;
                unsigned int id_group;
                auto group = dataManager.getGroupUsingID(id_group);
                Nice_Grades(std::cout, group);
                break;
            }
            case LOBBY::ST_W_B_M: {
                std::cout << "Enter id of the group" << std::endl;
                unsigned int id_group;
                auto group = dataManager.getGroupUsingID(id_group);
                Bad_Grades(std::cout, group);
                break;
            }

            case LOBBY::SAVE:
            {
                std::ofstream out("saved.json",std::ios::app);

                //thr = new std::thread(&DataManager::saveEverything,&out);
                //std::future<void> save = std::async(&dataManager.saveEverything,&out);


                dataManager.saveEverything(out);
                break;
            }

            case LOBBY::DOWNLOAD:

            {

                std::ifstream inp("saved.json");

                dataManager.LoadEverything(inp);
            }

        }

    }


}











