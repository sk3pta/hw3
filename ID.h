
#ifndef HW3__ID_H
#define HW3__ID_H

#include "headers.h"
class ID {
private:
    std::vector<unsigned int> student_ids;
    std::vector<unsigned int> group_ids;
public:
    ID();

    explicit ID(const std::vector<unsigned int>& id_vector);



    void addStudentId(unsigned int id);

    unsigned int getStudentId();

    unsigned int getGroupId();

    ~ID() = default;

};


#endif //HW3__ID_H
