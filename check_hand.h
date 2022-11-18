#ifndef CHECK_HAND_H
#define CHECK_HAND_H
#include <vector>

std::vector<int> flush(std::vector<int> cards);

std::vector<int> four_of_a_kind(std::vector<int> cards);

std::vector<int> full_house(std::vector<int> cards);

std::vector<int> high_card(std::vector<int> cards);

std::vector<int> one_pair(std::vector<int> cards);

std::vector<int> straight_flush(std::vector<int> cards);

std::vector<int> straight(std::vector<int> cards);

std::vector<int> two_pairs(std::vector<int> cards);

std::vector<int> three_of_a_kind(std::vector<int> cards);

std::vector<int> check_hand(std::vector<std::vector<int>> combinations);

#endif