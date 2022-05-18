//
// Created by augustus on 17.05.22.
//

#ifndef HW3__INTERFACE_H
#define HW3__INTERFACE_H
#include "headers.h"
/*
 * ADD_GROUP
 * ADD_STUDENT
 * MANAGE_GROUP_STUDENT
 * EDIT_STUDENT
 *
 */
enum class LOBBY {
    ADD_GROUP = 1,
    ADD_STUDENT = 2,
    PRINT_GROUPS = 99
};
LOBBY lobby();
std::string input_string();
std::size_t input_size_t();



#endif //HW3__INTERFACE_H