#include "interface.h"
#include "headers.h"

LOBBY lobby() {
    std::cout << "WELCOME TO BMSTU STUDENTDB" << std::endl;

    size_t input;
    
    std::cin >> input;
    
    switch(input) {
        case 1:
            return LOBBY::ADD_GROUP;

        case 99:
            return LOBBY::PRINT_GROUPS;
    }
}
