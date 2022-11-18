#include <iostream>
#include <string>
#include "clear_screen.h"

void clear_screen(){
    for(int i = 0; i < 20; i++)
        std::cout << "\n\n\n\n\n";
}