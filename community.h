#ifndef COMMUNITY_H
#define COMMUNITY_H
#include <vector>

struct Community{ // to store community cards and pot
    std::vector<int> com_cards; 
    int money_pot;
    Community(){
        money_pot = 0;
    }
};

#endif