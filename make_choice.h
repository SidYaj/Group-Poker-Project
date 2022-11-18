#ifndef MAKE_CHOICE_H
#define MAKE_CHOICE_H
#include <vector>
#include "player.h"
#include "community.h"

void fold(Player *current);

void raise(Player *current);

void call(Player *current);

void check(Player *current);

void make_player_choice_A(Player *current, bool &flag);

void make_cpu_choice_A(Player *current, bool &flag, int rng);

void make_player_choice_B(Player *current, bool &flag);

void make_player_choice_C(Player *current, bool &flag);

void make_player_choice_D(Player *current, bool &flag);

void make_cpu_choice_B(Player *current, Community C, bool &flag, int rng);

void make_cpu_choice_C(Player *current, bool &flag, int rng);

void make_cpu_choice_D(Player *current, Community C, bool &flag, int rng);



#endif