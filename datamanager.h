#include "Group.h"

#ifndef HW3__DATAMANAGER_H
#define HW3__DATAMANAGER_H

class DataManager {
public:
    std::vector<Group> groups;

    DataManager() {groups = {};};

    ~DataManager() =default;


    void addGroup(ID *id_manager, std::string name, unsigned int course,
                  const std::vector<std::string> &subjects = {}, size_t students_amount = 0) {
        Group group(id_manager,name,course,subjects,students_amount);
        groups.push_back(group);
    }

};







#endif //HW3__DATAMANAGER_H
