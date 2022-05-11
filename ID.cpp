#include "ID.h"


ID::ID() {
    srand(time(nullptr));
    this->id_vector = {};
}

ID::ID(const std::vector<unsigned int> &id_vector) {
    srand(time(nullptr));
    this->id_vector = id_vector;
}


unsigned int ID::getId() {
    unsigned int new_id = rand();
    while (std::find(id_vector.begin(), id_vector.end(), new_id) != id_vector.end())
        new_id = rand();
    this->id_vector.push_back(new_id);

    return new_id;
}

