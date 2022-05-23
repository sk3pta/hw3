#include "headers.h"
#include <thread>
#include <future>
#include "Student.h"
#include "Group.h"
#include "datamanager.h"
#include "interface.h"
#include <mutex>


int main() {

    std::mutex main;
    std::thread *thr = nullptr;
    ID id_manager;
    DataManager dataManager;


    for (;;) {
        for (const auto &group: dataManager.groups) {
            std::cout << "========================================" << std::endl;
            std::cout << group << std::endl;
            std::cout << "========================================" << std::endl;
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
                    if (course <= 0) break;
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
                              << dataManager.groups.back().getGroupbyId() << std::endl;
                    break;

            }
            case LOBBY::ADD_STUDENT: {
                std::cout << "\n >> Add Student : \n" << std::endl;
                std::cout << "\n >> Enter id of the group: \n" << std::endl;
                unsigned int id_group;
                id_group = input_size_t();
                if (!dataManager.ifExist(id_group)) {std::cout << "No such group"; break;}

                std::string name;
                std::string middle_name;
                std::string last_name;
                //unsigned int course;
                std::map<std::string, unsigned int> grades;
                std::cout << "First name: " << std::endl;
                name = input_string();
                std::cout << "Middle name: " << std::endl;
                middle_name = input_string();
                std::cout << "Last name: " << std::endl;
                last_name = input_string();
                std::cout << "Course : \n" << std::endl;
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




                //if (dataManager.groups_ids.find(id_group) == dataManager.groups_ids.end()) {
                if (dataManager.ifExist(id_group))
                    dataManager.addStudent(name, &id_manager, middle_name, last_name, 0, grades, id_group);

                //std::cout << " Created a student with id " << dataManager.students_ids.rbegin()->second.getID()
                //         << std::endl;
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
                    case STUDENT_PROFILE::ST_EDIT_ALL: {
                        std::cout << ">>CHANGE STUDENT NAME :" << std::endl;
                        size_t student_id;
                        size_t group_id;
                        std::cout << ">> ID of a group : " << std::endl;
                        group_id = input_size_t();
                        if (!dataManager.ifExist(group_id)) {std::cout << "No such group"; break;}

                        std::cout << ">> ID of a student : " << std::endl;
                        student_id = input_size_t();
                        if (!dataManager.ifExStud(student_id)) {std::cout << "No such group"; break;}

                        std::cout << "NAME : " << std::endl;
                        std::string new_name = input_string();
                        std::cout << "LAST NAME : " << std::endl;
                        std::string new_last_name = input_string();
                        std::cout << "MIDDLE NAME : " << std::endl;
                        std::string new_middle_name = input_string();
                        //size_t course;
                        //course = input_size_t();

                        auto group = &(dataManager.getGroupUsingID(group_id));
                        auto student = &(group->getStudentbyId(student_id));
                        student->editname(new_name, new_middle_name, new_last_name);
                        //student->editcourse(course);


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
                        if (!dataManager.ifExist(group_id)) {std::cout << "No such group"; break;}
                        std::cout << ">> ID of a student : " << std::endl;
                        student_id = input_size_t();
                        if (!dataManager.ifExStud(student_id)) {std::cout << "No such group"; break;}
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
                    case STUDENT_PROFILE::ST_DELETE: {
                        std::cout << "Delete Student :" << std::endl;
                        size_t student_id;
                        size_t group_id;
                        std::cout << ">> ID of a group : " << std::endl;
                        group_id = input_size_t();
                        if (!dataManager.ifExist(group_id)) {std::cout << "No such group"; break;}
                        std::cout << ">> ID of a student : " << std::endl;
                        student_id = input_size_t();
                        if (!dataManager.ifExStud(student_id)) {std::cout << "No such group"; break;}
                        auto group = &(dataManager.getGroupUsingID(group_id));
                        auto student = &(group->getStudentbyId(student_id));
                        auto students = &(group->getStudents());
                        for (auto i = group->getStudents().begin(); i != group->getStudents().end(); i++) {
                            if(i->getStudentId()==student_id) {
                                auto pos = students->erase(i);
                                i = pos;
                                if (i == students->end()){
                                    break;
                                }
                            }
                        }
                        break;
                    }
                }
                std::cout << "\n    \n" << std::endl;
                break;
            }
            case LOBBY::EDIT_GROUPS: {
                switch (editing_groups()) {
                    case GROUP_PROFILE::GR_EDIT_COURSE: {
                        std::cout << "CHANGE GROUP COURSE: " << std::endl;
                        unsigned int group_id;
                        std::cout << ">> ID of a group : " << std::endl;
                        group_id = input_size_t();
                        if (!dataManager.ifExist(group_id)) {std::cout << "No such group"; break;}
                        std::cout << " Course " << std::endl;
                        size_t course;
                        course = input_size_t();

                        auto group = &(dataManager.getGroupUsingID(group_id));
                        //for(int i = 0; i < course; i++){
                        //group->setCourse(group->getCourse() +1 );
                        //}
                        group->setCourse(course);
                        for (auto &stud: group->getStudents()) {
                            stud.course = group->getCourse();
                        }
                        break;
                    }

                    case GROUP_PROFILE::GR_EDIT_NAME: {
                        std::cout << "CHANGE GROUP NAME : " << std::endl;
                        std::string _name;
                        std::cout << ">>ID of a group : " << std::endl;
                        unsigned int group_id = input_size_t();
                        if (!dataManager.ifExist(group_id)) {std::cout << "No such group"; break;}
                        std::cout << "NEW NAME : " << std::endl;
                        _name = input_string();
                        Group *group = &(dataManager.getGroupUsingID(group_id));
                        group->setName(_name);

                        for (auto &stud: group->getStudents()) {
                            stud.group_name = group->getName();
                        }
                        break;

                    }


                    case GROUP_PROFILE::GR_EDIT_ALL: {
                        std::cout << "CHANGE GROUP INFO: " << std::endl;


                        unsigned int group_id;
                        std::cout << ">> ID of a group : " << std::endl;
                        group_id = input_size_t();
                        if (!dataManager.ifExist(group_id)) {std::cout << "No such group"; break;}
                        std::cout << " Course " << std::endl;
                        size_t course;
                        course = input_size_t();


                        std::string _name;
                        std::cout << "NEW NAME : " << std::endl;
                        _name = input_string();


                        Group *group = &(dataManager.getGroupUsingID(group_id));
                        group->setName(_name);
                        group->setCourse(course);

                        for (auto &stud: group->getStudents()) {
                            stud.group_name = group->getName();
                            stud.course = group->getCourse();
                        }
                        break;

                    }
                    case GROUP_PROFILE::GR_DELETE:{
                        std::cout << "Delete Group :" << std::endl;
                        size_t group_id;
                        for(auto i = dataManager.groups.begin(); i!= dataManager.groups.begin(); i++){
                            if (i->getGroupbyId() == group_id){
                                auto pos = dataManager.groups.erase(i);
                                i = pos;
                                if(i == dataManager.groups.end()){
                                    break;
                                }
                            }
                        }
                    }


                }
                break;
            }
            case LOBBY::SORT_ST:{
                switch (sorting()) {
                    case SORT::SORT_BY_ALL:{
                        std::cout << "Enter id of the group" << std::endl;
                        unsigned int group_id;
                        group_id = input_size_t();
                        if (!dataManager.ifExist(group_id)) {std::cout << "No such group"; break;}
                        std::cout << "How u want to see sorted students? :" << std::endl;
                        std::cout << "0 in console" << std::endl;
                        std::cout << "1 in file " << std::endl;
                        size_t inputt;
                        inputt = input_size_t();
                        auto group = &(dataManager.getGroupUsingID(group_id));
                        group->Sorted_at_all();
                        if(inputt == 0){
                            std::cout << *group << std::endl;
                        }
                        else if(inputt == 1){
                            std::string str = "C:/Users/92065/Documents/plusses/labs_alg_1_n_2/2_sem/hw3/";
                            std::string input = input_string();
                            std::ofstream out(str +input,std::ios::app);
                            out<<*group;
                            auto students = group->getStudents();
                            for(auto i = students.begin(); i!= students.end(); i++){
                                out<<*i;
                            }
                            out.close();
                            std::cout << "Save was done!" << std::endl;
                        }
                        break;
                    }
                    case SORT::SORT_BY_NAME:{
                        std::cout << "Enter id of the group" << std::endl;
                        unsigned int group_id;
                        group_id = input_size_t();
                        if (!dataManager.ifExist(group_id)) {std::cout << "No such group"; break;}
                        std::cout << "How u want to see sorted students? :" << std::endl;
                        std::cout << "0 in console" << std::endl;
                        std::cout << "1 in file " << std::endl;
                        size_t inputt;
                        inputt = input_size_t();
                        auto group = &(dataManager.getGroupUsingID(group_id));
                        group->Sorted_by_name();
                        if(inputt == 0){
                            std::cout << *group << std::endl;
                        }
                        else if(inputt == 1){
                            std::string str = "C:/Users/92065/Documents/plusses/labs_alg_1_n_2/2_sem/hw3/";
                            std::string input = input_string();
                            std::ofstream out(str +input,std::ios::app);
                            out<<*group;
                            auto students = group->getStudents();
                            for(auto i = students.begin(); i!= students.end(); i++){
                                out<<*i;
                            }
                            out.close();
                            std::cout << "Save was done!" << std::endl;
                        }
                    }
                }
                break;
            }
            case LOBBY::ST_W_G_M: {
                std::cout << "Enter id of the group" << std::endl;
                unsigned int id_group;
                id_group = input_size_t();
                if (!dataManager.ifExist(id_group)) {std::cout << "No such group"; break;}
                auto group = dataManager.getGroupUsingID(id_group);
                main.lock();
                thr = new std::thread(&Group::Nice_Grades,group,std::ref(std::cout));
                thr->join();
                main.unlock();

                delete thr;
                //Nice_Grades(std::cout, group);
                break;
            }
            case LOBBY::ST_W_B_M: {
                std::cout << "Enter id of the group" << std::endl;
                unsigned int id_group;
                id_group = input_size_t();
                if (!dataManager.ifExist(id_group)) {std::cout << "No such group"; break;}
                auto group = dataManager.getGroupUsingID(id_group);
                main.lock();


                thr = new std::thread(&Group::Bad_Grades,group,std::ref(std::cout));
                thr->join();
                main.unlock();
                delete thr;
                //Bad_Grades(std::cout, group);
                break;
            }

            case LOBBY::SAVE: {
                std::cout << "Name of the File " << std::endl;
                std::string str = "C:/Users/92065/Documents/plusses/labs_alg_1_n_2/2_sem/hw3/";
                std::string input = input_string();
                //std::ofstream out(str +input,std::ios::app);

                //thr = new std::thread(&DataManager::saveEverything,&out);
                //std::future<void> save = std::async(&dataManager.saveEverything,&out);

                std::ofstream out("saved.json");


                main.lock();

                thr = new std::thread(&DataManager::saveEverything,dataManager,std::ref(out));
                //dataManager.saveEverything(out);
                thr->join();
                main.unlock();
                delete thr;


                out.close();
                std::cout << "Save was done!" << std::endl;
                break;
            }

            case LOBBY::DOWNLOAD: {
                std::string str = "C:/Users/92065/Documents/plusses/labs_alg_1_n_2/2_sem/hw3/";
                std::cout << "Name of the File " << std::endl;
                std::string input = input_string();
                //std::ifstream inp(str +input);
                std::ifstream inp("saved.json");
                dataManager.LoadEverything(inp);\
                inp.close();
                std::cout << "Download was done!" << std::endl;
                break;
            }


            case LOBBY::FIND_STUDENT: {
                switch (find_student()) {
                    case FIND_STUDENT::BY_NAME: {
                        std::cout << "Name ? " << std::endl;
                        auto _name = input_string();
                        size_t count = 0;
                        for (const auto &stud: dataManager.students) {
                            if (stud.name == _name) {
                                std::cout << stud << std::endl;
                                count += 1;
                            }
                        }


                        std::cout << count << " students were found " << std::endl;
                        break;
                    }

                    case FIND_STUDENT::BY_MNAME: {
                        std::cout << "Middle name ? " << std::endl;
                        auto _name = input_string();
                        size_t count = 0;
                        for (const auto &stud: dataManager.students) {
                            if (stud.middle_name == _name) {
                                std::cout << stud << std::endl;
                                count += 1;
                            }
                        }

                        std::cout << count << " students were found " << std::endl;
                        break;
                    }


                    case FIND_STUDENT::BY_LNAME: {
                        std::cout << "Last name ? " << std::endl;
                        auto _name = input_string();
                        size_t count = 0;
                        for (const auto &stud: dataManager.students) {
                            if (stud.last_name == _name) {
                                std::cout << stud << std::endl;
                                count += 1;
                            }
                        }

                        std::cout << count << " students were found " << std::endl;
                        break;
                    }

                    case FIND_STUDENT::BY_COURSE: {
                        std::cout << "Course ? " << std::endl;
                        auto _course = input_size_t();
                        size_t count = 0;
                        for (const auto &stud: dataManager.students) {
                            if (stud.course == _course) {
                                std::cout << stud << std::endl;
                                count += 1;
                            }
                        }

                        std::cout << count << " students were found " << std::endl;
                        break;
                    }


                    case FIND_STUDENT::BY_GROUPNAME: {
                        std::cout << "Group name ? " << std::endl;
                        auto _name = input_string();
                        size_t count = 0;
                        for (const auto &stud: dataManager.students) {
                            if (stud.group_name == _name) {
                                std::cout << stud << std::endl;
                                count += 1;
                            }
                        }

                        std::cout << count << " students were found " << std::endl;
                        break;
                    }

                    case FIND_STUDENT::BY_ID: {
                        std::cout << "ID ? " << std::endl;
                        auto _id = input_size_t();
                        if (!dataManager.ifExStud(_id)) {std::cout << "No such group"; break;}
                        size_t count = 0;
                        for (const auto &stud: dataManager.students) {
                            if (stud.getID() == _id) {
                                std::cout << stud << std::endl;
                                count += 1;
                            }
                        }

                        std::cout << count << " students were found " << std::endl;
                        break;
                    }

                }
                break;
            }


            case LOBBY::FIND_GROUP: {
                switch (find_group()) {
                    case FIND_GROUP::BY_NAME: {
                        std::cout << "Name ? " << std::endl;
                        auto _name = input_string();

                        size_t count = 0;
                        for (auto &group: dataManager.groups) {
                            if (group.getName() == _name) {
                                std::cout << group << std::endl;
                                count += 1;
                            }
                        }
                        break;
                    }

                    case FIND_GROUP::BY_COURSE: {
                        std::cout << "Course ? " << std::endl;
                        auto _course = input_size_t();

                        size_t count = 0;
                        for (auto &group: dataManager.groups) {
                            if (group.getCourse() == _course) {
                                std::cout << group << std::endl;
                                count += 1;
                            }
                        }
                        break;
                    }

                    case FIND_GROUP::BY_ID: {
                        std::cout << "ID ? " << std::endl;
                        auto _id = input_size_t();
                        if (!dataManager.ifExist(_id)) {std::cout << "No such group"; break;}
                        size_t count = 0;
                        for (auto &group: dataManager.groups) {
                            if (group.getGroupbyId() == _id) {
                                std::cout << group << std::endl;
                                count += 1;
                            }
                        }
                        break;
                    }

                }

                break;
            }

            case LOBBY::EXIT:
                return 0;

        }


    }


}











