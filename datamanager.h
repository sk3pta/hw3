#include "Group.h"

#ifndef HW3__DATAMANAGER_H
#define HW3__DATAMANAGER_H

class DataManager {
public:
    std::vector<Group> groups;
    std::map<unsigned int, Group> groups_ids;
    std::map<unsigned int, Student> students_ids;

    DataManager() {groups = {};};

    ~DataManager() =default;


    void addGroup(ID *id_manager, std::string name, unsigned int course,
                  const std::vector<std::string> &subjects = {}, size_t students_amount = 0) {
        Group group(id_manager,name,course,subjects,students_amount);
        //groups_ids[group.getGroupbyId()] = group;
        groups.push_back(group);
    }

    void addStudent(std::string name, ID *id_manager, std::string middle_name, std::string last_name,
                    unsigned int course,
                    std::map<std::string, unsigned int> grades , unsigned int group_id) {

        for (auto & grp : groups ) {
            if (grp.group_id == group_id) {
                Student student(name, id_manager, middle_name, last_name, course, grades);
                grp.addStudent(student);
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



    Group& getGroupUsingID(unsigned int id) {
        for ( auto& group : groups) {
            if (group.group_id == id) return group;
        }
    }
};







#endif //HW3__DATAMANAGER_H
