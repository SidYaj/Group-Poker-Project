#ifndef CARD_H
#define CARD_H
#include <vector>
#include <string> 
#define NUMCARDS 5
#define SPADE   "\xE2\x99\xA0"
#define CLUB    "\xE2\x99\xA3"
#define HEART   "\xE2\x99\xA5"
#define DIAMOND "\xE2\x99\xA6"

struct Card{
    std::string number;
    std::string suit;
};

std::vector<Card> card(std::vector<int> cards);

#endif
