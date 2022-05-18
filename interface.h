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
    SAVE = 3,
    DOWNLOAD = 4,
    ST_W_G_M = 5,
    ST_W_B_M = 6,
    SORT_ST = 7,
    EXIT = 8,
    EDIT_GROUPS = 9,
    EDIT_STUDENTS = 10,
    PRINT_GROUPS = 99
};
enum class STUDENT_PROFILE{
    ST_EDIT_ALL =0,
    ST_EDIT_MARKS = 1,
    ST_EDIT_NAME = 2,
    ST_EDIT_COURSE = 3,
    ST_DELETE = 4
};
enum class GROUP_PROFILE{
    GR_EDIT_COURSE = 0,
    GR_EDIT_NAME =1,
    GR_DELETE = 2
};
LOBBY lobby();
std::string input_string();
std::size_t input_size_t();



#endif //HW3__INTERFACE_H