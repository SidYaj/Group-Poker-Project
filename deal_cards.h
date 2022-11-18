#ifndef DEAL_CARDS_H
#define DEAL_CARDS_H

#include <vector>
#include <algorithm>
#include <cstdlib>
#include "player.h"


void deck_gen(std::vector<int> &deck, int rng);

void print_cards(std::vector<int> cards);

int deal_cards(std::vector<int> &deck);

#endif
