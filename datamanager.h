#include "Group.h"

#ifndef HW3__DATAMANAGER_H
#define HW3__DATAMANAGER_H

class DataManager {
public:
    //std::vector<Group> groups;

    std::map<unsigned int, Group> groups_ids;
    std::map<unsigned int, Student> students_ids;

    std::list<Group> groups;
    std::list<Student> students;

    DataManager() { groups = {}; };

    ~DataManager() = default;


    void addGroup(ID *id_manager, std::string name, unsigned int course,
                  const std::vector<std::string> &subjects = {}, size_t students_amount = 0) {


        try {
            Group group(id_manager, name, course, subjects, students_amount);


            //groups_ids.insert({group.group_id,group});
            groups.push_back(group);
            //groups_ids[group.group_id] = group;
            //groups.push_back(group);

        }
        catch (std::exception &ex) {
            std::cout << " Error occured. Perhaps your input was wrong" << std::endl;

        }
    }

    void addStudent(std::string name, ID *id_manager, std::string middle_name, std::string last_name,
                    unsigned int course,
                    std::map<std::string, unsigned int> grades, unsigned int group_id) {

        for (auto &grp: groups) {
            if (grp.getGroupbyId() == group_id) {
                Student student(name, id_manager, middle_name, last_name, course, grades);
                students.push_back(student);
                grp.addStudent(student);


                // grp.second = students_ids.rbegin->second;

            }
        }
    }


    /*
    void addStudent(std::string name, ID *id_manager, std::string middle_name, std::string last_name,
                    unsigned int course,
                    std::map<std::string, unsigned int> grades , unsigned int group_id){
        Student student(name, id_manager, middle_name, last_name, course, grades);
        students_ids[student.getStudentId()] = student;
        groups_ids[group_id]+student;
        //auto ngr = getGroupUsingID(group_id);
        //ngr = ngr + student;


    }
     */


/*
    Group &getGroupUsingID(unsigned int id) {
        for (auto &group: groups) {
            if (group.group_id == id) return group;
        }
    }
    */

    Group &getGroupUsingID(unsigned int id) {
        for (auto &group: groups) {
            if (group.getGroupbyId() == id) return group;

        }

    }


    bool ifExist(unsigned int id) {
        for (auto &group: groups) {
            if (group.getGroupbyId() == id) return true;
        }
        return false;

    }


    bool ifExStud(unsigned int id) {
        for (auto &st: students) {
            if (st.getID() == id) return true;
        }
        return false;
    }


    void saveEverything(std::ofstream &out) {


        if (!out.is_open()) {
            throw std::exception();
        }


        nlohmann::json jgroup;

        for (auto &group: this->groups) {
            jgroup[std::to_string(group.getGroupbyId())]["id"] = group.getGroupbyId();
            jgroup[std::to_string(group.getGroupbyId())]["name"] = group.getName();
            jgroup[std::to_string(group.getGroupbyId())]["course"] = group.getCourse();
            for (size_t x = 0; x < group.getSubjects().size(); ++x) {
                jgroup[std::to_string(group.getGroupbyId())]["subjects"][x] = group.getSubjects()[x];
            }

            size_t x = 0;
            for (auto student: group.getStudents()) {

                jgroup[std::to_string(group.getGroupbyId())]["students"][x]["ID"] = student.getID();
                jgroup[std::to_string(group.getGroupbyId())]["students"][x]["name"] = student.name;
                jgroup[std::to_string(group.getGroupbyId())]["students"][x]["middle_name"] = student.middle_name;
                jgroup[std::to_string(group.getGroupbyId())]["students"][x]["last_name"] = student.last_name;
                jgroup[std::to_string(group.getGroupbyId())]["students"][x]["course"] = student.course;
                jgroup[std::to_string(group.getGroupbyId())]["students"][x]["group_name"] = student.group_name;
                for (const auto &item: student.getGrades()) {
                    jgroup[std::to_string(group.getGroupbyId())]["students"][x]["grades"][item.first] = item.second;
                }
                ++x;
            }
            //saveToJson(out,group);
        }

        out << jgroup;
        std::cout << "SAVED " << std::endl;
    }

    void LoadEverything(std::ifstream &inp) {


        if (!inp.is_open()) {
            throw std::exception();
        }


        nlohmann::json jinp;


        inp >> jinp;

        for (auto &jgroup: jinp) {
            Group group;
            group.setID(jgroup["id"]);

            if (!ifExist(group.getGroupbyId())) {
                group.setName(jgroup["name"]);
                group.setCourse(jgroup["course"]);

                std::vector<std::string> subj;
                for (auto &x: jgroup["subjects"]) {
                    subj.push_back(x);
                    //group.subjects[x] = jgroup["subjects"][x];
                }
                //subj = jgroup["subjects"];
                group.addSubjects(subj);

                for (const auto &student: jgroup["students"]) {
                    Student _student;
                    _student.name = student["name"];
                    _student.middle_name = student["middle_name"];
                    _student.last_name = student["last_name"];
                    _student.group_name = student["group_name"];
                    _student.course = student["course"];
                    auto _grades = student["grades"];
                    _student.addGrades(_grades);
                    _student.setID(student["ID"]);
                    group.addStudent(_student);
                    this->students.push_back(_student);
                }
                this->groups.push_back(group);
                //groups_ids[group.group_id] = group;
                //groups.push_back(group);
                std::cout << group.getGroupbyId() << std::endl;
                // std::cout << groups[0] << std::endl;
            }
        }
    };


};


#endif //HW3__DATAMANAGER_H
