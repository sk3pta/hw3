#include "ID.h"


ID::ID() {
    srand(time(nullptr));
    this->student_ids = {};
    this->group_ids = {};
}

ID::ID(const std::vector<unsigned int> &id_vector) {
    srand(time(nullptr));
    this->student_ids = {};
    this->group_ids = {};
}


unsigned int ID::getStudentId() {
    unsigned int new_id = 1 + rand() % 59999999;
    while (std::find(student_ids.begin(), student_ids.end(), new_id) != student_ids.end())
        new_id = rand();
    this->student_ids.push_back(new_id);

    return new_id;
}

unsigned int ID::getGroupId() {
    unsigned int new_id = 60000000 + rand() + RAND_MAX;
    while (std::find(student_ids.begin(), student_ids.end(), new_id) != student_ids.end())
        new_id = rand();
    this->student_ids.push_back(new_id);

    return new_id;
}

