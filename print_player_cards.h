#ifndef PRINT_PLAYER_CARDS_H
#define PRINT_PLAYER_CARDS_H
#include <iostream>
// #include <cmath>
#include <iomanip>
#include "player.h"
#include "card.h"
#define SPADE   "\xE2\x99\xA0"
#define CLUB    "\xE2\x99\xA3"
#define HEART   "\xE2\x99\xA5"
#define DIAMOND "\xE2\x99\xA6"

void print_player_cards(Player *P);

#endif
