#include "deal_cards.h"
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <iostream>

#define SPADE   "\xE2\x99\xA0"
#define CLUB    "\xE2\x99\xA3"
#define HEART   "\xE2\x99\xA5"
#define DIAMOND "\xE2\x99\xA6"
#define NUMCARDS  5

void print_cards(std::vector<int> cards){
    int len = cards.size();
    std::string suites[4] = {SPADE, HEART, CLUB, DIAMOND}; // array of suites
    std::string values[13] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"}; // array of values
    std::string deck[52] = {};
    for(int i = 0; i < 4; i++){ // we use nested loops to generate a deck of 52 cards
        for(int j = 0; j < 13; j++){
        deck[13*i + j] = values[j]+suites[i];
        }
    }
    for(int i = 0; i < len; i++){ // loop prints the corresponding values of deck from hand
        std::cout << deck[cards[i]] << " ";
    }
    std::cout << std::endl;
}

void deck_gen(std::vector<int> &deck, int rng){ // to create a deck and then shuffle it randomly
    std::srand(rng);
    for(int i = 0; i <= 51; i++){
        deck.push_back(i);
    }
    std::random_shuffle(deck.begin(), deck.end());
}

int deal_cards(std::vector<int> &deck) // changed this so that cards are dealt to the players one at a time
{ 
  int hole;
  hole = deck[0];
  deck.erase(deck.begin());
  return hole;
}
