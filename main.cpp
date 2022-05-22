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
        for (const auto&group : dataManager.groups_ids) {
            std::cout<< "========================================" << std::endl;
            std::cout << group.second << std::endl;
            std::cout<< "========================================" << std::endl;
        }
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
                //std::cout << "Course : \n" << std::endl;
                //course = input_size_t();

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
                for (const auto &group: dataManager.groups_ids) {
                    std::cout << group.second;
                }
                break;
            }


            case LOBBY::EDIT_STUDENTS: {
                switch (editing_students()) {
                    case STUDENT_PROFILE::ST_EDIT_ALL: {
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
                        std::cout <<" Course " << std::endl;
                        size_t course;
                        course = input_size_t();

                        auto group = &(dataManager.getGroupUsingID(group_id));
                        auto student = &(group->getStudentbyId(student_id));
                        student->editname(new_name, new_middle_name, new_last_name);
                        student->editcourse(course);


                        std::cout << "Student with id " << student_id << " has successfule changed his name "
                                  << std::endl;

                        break;
                    }
                    case STUDENT_PROFILE::ST_EDIT_NAME: {
                        std::cout << ">>CHANGE ALL FOR STUDENT  :" << std::endl;
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

                        auto group = &(dataManager.getGroupUsingID(group_id));
                        auto student = &(group->getStudentbyId(student_id));
                        student->editname(new_name, new_middle_name, new_last_name);


                        std::cout << "Student with id " << student_id << " has successfule changed his name "
                                  << std::endl;

                        break;
                    }
                    /*
                    case STUDENT_PROFILE::ST_EDIT_COURSE:{
                        std::cout << ">>CHANGE STUDENT COURSE :" << std::endl;
                        unsigned int student_id;
                        unsigned int group_id;
                        std::cout << ">> ID of a group : " << std::endl;
                        group_id = input_size_t();
                        std::cout << ">> ID of a student : " << std::endl;
                        student_id = input_size_t();
                        std::cout <<" Course " << std::endl;
                        size_t course;
                        course = input_size_t();
                        auto group = &(dataManager.getGroupUsingID(group_id));
                        //auto student = &(group->getStudentbyId(student_id));

                        //student->editcourse(course);
                        group->getStudentbyId(student_id).course = course;
                        std::cout << "Student with id " << student_id << " has successfuly changed his name "
                                  << std::endl;
                        std::cout << student << std::endl;
                        break;
                    }
                     */
                    case STUDENT_PROFILE::ST_DELETE:{
                        std::cout << ">>CHANGE STUDENT NAME :" << std::endl;
                        size_t student_id;
                        size_t group_id;
                        std::cout << ">> ID of a group : " << std::endl;
                        group_id = input_size_t();
                        std::cout << ">> ID of a student : " << std::endl;
                        student_id = input_size_t();
                        auto group = &(dataManager.getGroupUsingID(group_id));
                        auto student = &(group->getStudentbyId(student_id));
                        for(auto i = group->getStudents().begin(); i != group->getStudents().end(); i++){
                            std::cout << *i << std::endl;
                            std::cout << i->getStudentId() << std::endl;
                            if (i->getStudentId() == student_id ){
                                //grSoup = group - *i;
                                std::cout << "wow" << std::endl;
                            }
                        }
                        break;
                    }
                }
                std::cout << "\n    \n" <<std::endl;
                break;
            }
            case LOBBY::EDIT_GROUPS: {
                switch(editing_groups()){
                    case GROUP_PROFILE::GR_EDIT_COURSE:{
                        std::cout << "CHANGE GROUP COURSE: " << std::endl;
                        unsigned int group_id;
                        std::cout << ">> ID of a group : " << std::endl;
                        group_id = input_size_t();
                        std::cout <<" Course " << std::endl;
                        size_t course;
                        course = input_size_t();
                        auto group = &(dataManager.getGroupUsingID(group_id));
                        //for(int i = 0; i < course; i++){
                        //group->setCourse(group->getCourse() +1 );
                        //}
                        group->setCourse(course);
                        for (auto & stud : group->getStudents() ){
                            stud.course = group->getCourse();
                        }
                        break;
                    }

                    case GROUP_PROFILE::GR_EDIT_NAME:{
                        std::cout << "CHANGE GROUP NAME : " << std::endl;
                        std::string _name;
                        std::cout << ">>ID of a group : " << std::endl;
                        unsigned int group_id = input_size_t();
                        std::cout << "NEW NAME : " << std::endl;
                        _name = input_string();
                        Group * group = &(dataManager.getGroupUsingID(group_id));
                        group->setName(_name);

                        for (auto & stud : group->getStudents() ){
                            stud.group_name = group->getName();
                        }
                        break;

                    }


                    case GROUP_PROFILE::GR_EDIT_ALL:{
                        std::cout << "CHANGE GROUP INFO: " << std::endl;


                        unsigned int group_id;
                        std::cout << ">> ID of a group : " << std::endl;
                        group_id = input_size_t();

                        std::cout <<" Course " << std::endl;
                        size_t course;
                        course = input_size_t();


                        std::string _name;
                        std::cout << "NEW NAME : " << std::endl;
                        _name = input_string();


                        Group * group = &(dataManager.getGroupUsingID(group_id));
                        group->setName(_name);
                        group->setCourse(course);

                        for (auto & stud : group->getStudents() ){
                            stud.group_name = group->getName();
                            stud.course = group->getCourse();
                        }
                        break;


                        group->setCourse(course);
                        for (auto & stud : group->getStudents() ){
                            stud.course = group->getCourse();
                        }
                    }



                }
                break;
            }
            case LOBBY::ST_W_G_M: {
                std::cout << "Enter id of the group" << std::endl;
                unsigned int id_group;
                id_group = input_size_t();
                auto group = dataManager.getGroupUsingID(id_group);
                Nice_Grades(std::cout, group);
                break;
            }
            case LOBBY::ST_W_B_M: {
                std::cout << "Enter id of the group" << std::endl;
                unsigned int id_group;
                id_group = input_size_t();
                auto group = dataManager.getGroupUsingID(id_group);
                Bad_Grades(std::cout, group);
                break;
            }

            case LOBBY::SAVE:
            {
                std::cout << "Name of the File " << std::endl;
                std::string str = "C:/Users/92065/Documents/plusses/labs_alg_1_n_2/2_sem/hw3/";
                std::string input = input_string();
                //std::ofstream out(str +input,std::ios::app);

                //thr = new std::thread(&DataManager::saveEverything,&out);
                //std::future<void> save = std::async(&dataManager.saveEverything,&out);

                std::ofstream out("saved.json");
                dataManager.saveEverything(out);
                out.close();
                std::cout << "Save was done!" << std::endl;
                break;
            }

            case LOBBY::DOWNLOAD:

            {
                std::string str = "C:/Users/92065/Documents/plusses/labs_alg_1_n_2/2_sem/hw3/";
                std::cout << "Name of the File " << std::endl;
                //std::string input = input_string();
                //std::ifstream inp(str +input);
                std::ifstream inp("saved.json");
                dataManager.LoadEverything(inp);\
                inp.close();
                std::cout << "Download was done!" << std::endl;
                break;
            }

        }

    }


}











