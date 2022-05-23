
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
    FIND_STUDENT = 11,
    FIND_GROUP = 12,
    PRINT_GROUPS = 99
};



enum class FIND_GROUP{
    BY_NAME = 1,
    BY_COURSE = 2,
    BY_ID = 3
};


enum class FIND_STUDENT{
    BY_NAME = 1,
    BY_MNAME = 2,
    BY_LNAME = 3,
    BY_COURSE = 4,
    BY_GROUPNAME = 5,
    BY_ID = 6
};



enum class STUDENT_PROFILE{
    ST_EDIT_ALL =0,
    ST_EDIT_NAME = 1,
    ST_DELETE = 2
};
enum class GROUP_PROFILE{
    GR_EDIT_COURSE = 0,
    GR_EDIT_NAME =1,
    GR_EDIT_ALL = 2,
    GR_DELETE = 3
};
enum class SORT{
    SORT_BY_ALL = 0,
    SORT_BY_NAME = 1
};
LOBBY lobby();
STUDENT_PROFILE editing_students();
GROUP_PROFILE editing_groups();
FIND_STUDENT find_student();
FIND_GROUP find_group();
SORT sorting();
std::string input_string();
unsigned int input_size_t();



#endif //HW3__INTERFACE_H