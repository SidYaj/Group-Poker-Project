#ifndef PLAYER_H
#define PLAYER_H
#include <vector>

struct Player{
    std::vector<int> hole; // to store player's hole cards
    int money;
    bool is_dealer;
    int status; // fold, check, raise, call
    int raise_amt;
    int player_number;
    std::vector<int> hand;
    Player *next;
    Player(int m, int n){
        raise_amt = 0;
        status = 0;
        money = m;
        player_number = n;
    }
};

#endif