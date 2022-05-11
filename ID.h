
#ifndef HW3__ID_H
#define HW3__ID_H

#include "headers.h"
class ID {
private:
    std::vector<unsigned int> id_vector;
public:
    ID();

    explicit ID(const std::vector<unsigned int>& id_vector);



    void addId(unsigned int id);

    unsigned int getId();

    ~ID() = default;

};


#endif //HW3__ID_H
