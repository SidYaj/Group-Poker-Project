#include <vector>
#include <iostream>
#include <cstdlib>
#include "make_choice.h"
#include "is_pair.h"
#include "check_hand.h"
#include "combinations.h"

void fold(Player *current){
    current->status = 4;
}

void raise(Player *current, int raise_amt){
    current->status = 2;
    if(current->next->money < raise_amt)
        raise_amt = current->next->money;
    if(current->money < raise_amt)
        raise_amt = current->money;
    current->raise_amt = raise_amt;
}

void call(Player *current){
    current->status = 3;
    current->raise_amt = current->next->raise_amt;
}

void check(Player *current){
    current->status = 1;
}

void make_player_choice_A(Player *current, bool &flag){ // function for the player to make their choice against the 1st CPU in the pre-flop round
    if(current->next->status == 1 || (current->status == 0 && current->next->status == 3)){
        std::cout << "1. Check\n2. Raise\n3. Fold\nEnter your choice: ";
        int choice;
        std::cin >> choice;
        if(choice == 1){
            check(current);
            flag = false;
            std::cout << "You check" << std::endl;
        }
        else if(choice == 2){
            int raise_amt;
            while(true){
                std::cout << "Enter raise amount greater than or equal to $20: ";
                std::cin >> raise_amt;
                if(raise_amt >= 20)
                    break;
            }
            raise(current, raise_amt);
            std::cout << "You raise $" << current->raise_amt << std::endl;
        }
        else if(choice == 3){
            fold(current);
            flag = false;
            std::cout << "You fold" << std::endl;
        }
    }
    else if(current->next->status == 2 || (current->next->status == 0 && current->status == 0)){
        std::cout << "1. Raise\n2. Call\n3. Fold\nEnter your choice: ";
        int choice;
        std::cin >> choice;
        if(choice == 1){
            int raise_amt;
            while(true){
                std::cout << "Enter raise amount greater than CPU's raise amount: ";
                std::cin >> raise_amt;
                if(raise_amt > current->next->raise_amt)
                    break;
            }
            raise(current, raise_amt);
            std::cout << "You raise $" << current->raise_amt << std::endl;
        }
        else if(choice == 2){
            call(current);
            if(current->next->status == 2)
                flag = false;
            std::cout << "You call" << std::endl;
        }
        else if(choice == 3){
            fold(current);
            flag = false;
            std::cout << "You fold" << std::endl;
        }
    }    
}

void make_player_choice_B(Player *current, bool &flag){ // function for the player to make their choice against the 1st CPU in later rounds
    if(current->next->status == 0 || current->next->status == 1){
        std::cout << "1. Check\n2. Raise\n3. Fold\nEnter your choice: ";
        int choice;
        std::cin >> choice;
        if(choice == 1){
            check(current);
            if(current->next->status == 1)
                flag = false;
            std::cout << "You check" << std::endl;
        }
        else if(choice == 2){
            int raise_amt;
            while(true){
                std::cout << "Enter raise amount greater than or equal to $20: ";
                std::cin >> raise_amt;
                if(raise_amt >= 20)
                    break;
            }
            raise(current, raise_amt);
            std::cout << "You raise $" << current->raise_amt << std::endl;
        }
        else if(choice == 3){
            fold(current);
            flag = false;
        }
    }
    else if(current->next->status == 2){
        std::cout << "1. Raise\n2. Call\n3. Fold\nEnter your choice: ";
        int choice;
        std::cin >> choice;
        if(choice == 1){
            int raise_amt;
            while(true){
                std::cout << "Enter raise amount greater than CPU's raise amount: ";
                std::cin >> raise_amt;
                if(raise_amt > current->next->raise_amt)
                    break;
            }
            raise(current, raise_amt);
            std::cout << "You raise $" << current->raise_amt << std::endl;
        }
        else if(choice == 2){
            call(current);
            flag = false;
            std::cout << "You call" << std::endl;
        }
        else if(choice == 3){
            fold(current);
            flag = false;
            std::cout << "You fold" << std::endl;
        }
    }    
}

void make_cpu_choice_A(Player *current, bool &flag, int rng){ // function for the 1st CPU to make their choice in the pre-flop round
    std::srand(rng);
    int random = rand() % 10 + 1;
    int n_raise = current->next->raise_amt;
    if(current->next->status == 1 || (current->status == 0 && current->next->status == 3)){
        if(random <= 7){
            check(current);
            std::cout << "CPU checks" << std::endl;
            flag = false;
        }
        else if(random <= 10){
            int raise_amt;
            if(random < 10)
                raise_amt = n_raise + 20;
            else
                raise_amt = n_raise + 30;
            raise(current, raise_amt);
            std::cout << "CPU raises $" << current->raise_amt << std::endl; 
        }
    }
    else if(current->next->status == 2 || (current->next->status == 0 && current->status == 0)){
        if(current->next->raise_amt <= 40){
            if(random <= 7){
                call(current);
                std::cout << "CPU calls" << std::endl;
                if(current->next->status == 2)
                    flag = false;
            }
            else if(random <= 9){
                int raise_amt = n_raise + (rand() % 2 + 1) * 10 + 10;
                raise(current, raise_amt);
                std::cout << "CPU raises $" << current->raise_amt << std::endl;
            }
            else{
                fold(current);
                std::cout << "CPU folds" << std::endl;
                flag = false;
            }
        }
        else{
            if(random <= 4){
                call(current);
                std::cout << "CPU calls" << std::endl;
                if(current->next->status == 0)
                    flag = false;
            }
            else if(random == 5){
                int raise_amt = n_raise + (rand() % 2 + 1) * 10 + 10;
                raise(current, raise_amt);
                std::cout << "CPU raises $" << current->raise_amt << std::endl;
            }
            else{
                fold(current);
                std::cout << "CPU folds" << std::endl;
                flag = false;
            }
        }
    }
}

void make_cpu_choice_B(Player *current, Community C, bool &flag, int rng){ // function for the 1st CPU to make their choice in later rounds
    std::srand(rng);
    std::vector<int> cards;
    int raise_amt;
    int n_raise = current->next->raise_amt;
    for(int i = 0; i < 2; i++){
        cards.push_back(current->hole[i]);
    }
    for(int i = 0; i < C.com_cards.size(); i++){
        cards.push_back(C.com_cards[i]);
    }
    std::vector<std::vector<int>> comb;
    comb = combinations(cards);
    current->hand = check_hand(comb);
    int hand = current->hand[0];
    if(current->next->status == 0 || current->next->status == 1){
        if(hand >= 4){
            check(current);
            std::cout << "CPU checks" << std::endl;
            if(current->next->status == 1)
                flag = false;
        }
        else if(hand >= 2){
            raise_amt = n_raise + 20;
            raise(current, raise_amt);
            std::cout << "CPU raises " << current->raise_amt << std::endl;
        }
        else{
            raise_amt = n_raise + 30;
            raise(current, raise_amt);
            std::cout << "CPU raises $" << current->raise_amt << std::endl; 
        }
    }
    else if(current->next->status == 2){
        if(hand <= 5){
            if(hand >= 4){
                call(current);
                std::cout << "CPU calls" << std::endl;
                flag = false;
            }
            else if(hand >= 3){
                int raise_amt = n_raise + (rand() % 2 + 1) * 10 + 10;
                raise(current, raise_amt);
                std::cout << "CPU raises $" << current->raise_amt << std::endl;
            }
        }
        else{
            if(hand >= 8){
                int random_seed = rand() % 3;
                if(random_seed == 0 || random_seed == 1){
                    fold(current);
                    std::cout << "CPU folds" << std::endl;
                    flag = false;
                }
                else{
                    call(current);
                    std::cout << "CPU calls" << std::endl;
                    flag = false;
                }
            }    
            else if(hand == 5){
                int raise_amt = current->next->raise_amt + (rand() % 2 + 1) * 10 + 10;
                raise(current, raise_amt);
                std::cout << "CPU raises $" << current->raise_amt << std::endl;
            }
            else{
                call(current);
                std::cout << "CPU calls" << std::endl;
                flag = false;
            }
        }
    }
}


void make_player_choice_C(Player *current, bool &flag){ // function for player to make their choice against the 2nd CPU in the pre-flop round
    if(current->next->status == 1 || (current->status == 0 && current->next->status == 3)){
        std::cout << "1. Check\n2. Raise\n3. Fold\nEnter your choice: ";
        int choice;
        std::cin >> choice;
        if(choice == 1){
            check(current);
            flag = false;
            std::cout << "You check" << std::endl;
        }
        else if(choice == 2){
            int raise_amt;
            while(true){
                std::cout << "Enter raise amount greater than or equal to $40: ";
                std::cin >> raise_amt;
                if(raise_amt >= 40)
                    break;
            }
            raise(current, raise_amt);
            std::cout << "You raise $" << current->raise_amt << std::endl;
        }
        else if(choice == 3){
            fold(current);
            flag = false;
            std::cout << "You fold" << std::endl;
        }
    }
    else if(current->next->status == 2 || (current->next->status == 0 && current->status == 0)){
        std::cout << "1. Raise\n2. Call\n3. Fold\nEnter your choice: ";
        int choice;
        std::cin >> choice;
        if(choice == 1){
            int raise_amt;
            while(true){
                std::cout << "Enter raise amount greater than CPU's raise amount: ";
                std::cin >> raise_amt;
                if(raise_amt > current->next->raise_amt)
                    break;
            }
            raise(current, raise_amt);
            std::cout << "You raise $" << current->raise_amt << std::endl;
        }
        else if(choice == 2){
            call(current);
            if(current->next->status == 2)
                flag = false;
            std::cout << "You call" << std::endl;
        }
        else if(choice == 3){
            fold(current);
            flag = false;
            std::cout << "You fold" << std::endl;
        }
    }    
}

void make_player_choice_D(Player *current, bool &flag){ // function for the player to make their choice against the 2nd CPU in later rounds
    if(current->next->status == 0 || current->next->status == 1){
        std::cout << "1. Check\n2. Raise\n3. Fold\nEnter your choice: ";
        int choice;
        std::cin >> choice;
        if(choice == 1){
            check(current);
            if(current->next->status == 1)
                flag = false;
            std::cout << "You check" << std::endl;
        }
        else if(choice == 2){
            int raise_amt;
            while(true){
                std::cout << "Enter raise amount greater than or equal to $40: ";
                std::cin >> raise_amt;
                if(raise_amt >= 20)
                    break;
            }
            raise(current, raise_amt);
            std::cout << "You raise $" << current->raise_amt << std::endl;
        }
        else if(choice == 3){
            fold(current);
            flag = false;
            std::cout << "You fold" << std::endl;
        }
    }
    else if(current->next->status == 2){
        std::cout << "1. Raise\n2. Call\n3. Fold\nEnter your choice: ";
        int choice;
        std::cin >> choice;
        if(choice == 1){
            int raise_amt;
            while(true){
                std::cout << "Enter raise amount greater than CPU's raise amount: ";
                std::cin >> raise_amt;
                if(raise_amt > current->next->raise_amt)
                    break;
            }
            raise(current, raise_amt);
            std::cout << "You raise $" << current->raise_amt << std::endl;
        }
        else if(choice == 2){
            call(current);
            flag = false;
            std::cout << "You call" << std::endl;
        }
        else if(choice == 3){
            fold(current);
            flag = false;
            std::cout << "You fold" << std::endl;
        }
    }    
}

void make_cpu_choice_C(Player *current, bool &flag, int rng){ // function for 2nd CPU to make their choice in the pre-flop round
    std::srand(rng);
    int random = rand() % 10 + 1;
    int n_raise = current->next->raise_amt;
    if(current->next->status == 1 || (current->status == 0 && current->next->status == 3)){
        if(random <= 6){
            check(current);
            std::cout << "CPU checks" << std::endl;
            flag = false;
        }
        else if(random <= 10){
            int raise_amt;
            if(random < 9)
                raise_amt = n_raise + 40;
            else
                raise_amt = n_raise + 80;
            raise(current, raise_amt);
            std::cout << "CPU raises $" << current->raise_amt << std::endl; 
        }
    }
    else if(current->next->status == 2 || (current->next->status == 0 && current->status == 0)){
        if(current->next->raise_amt <= 60 || is_pair(current->hole)){
            if(random <= 7){
                call(current);
                std::cout << "CPU calls" << std::endl;
                if(current->next->status == 2)
                    flag = false;
            }
            else if(random <= 9){
                int raise_amt = n_raise + (rand() % 2 + 1) * 20;
                raise(current, raise_amt);
                std::cout << "CPU raises $" << current->raise_amt << std::endl;
            }
            else{
                fold(current);
                std::cout << "CPU folds" << std::endl;
                flag = false;
            }
        }
        else{
            if(random <= 6){
                call(current);
                std::cout << "CPU calls" << std::endl;
                if(current->next->status == 0)
                    flag = false;
            }
            else if(random <= 7){
                int raise_amt = n_raise + (rand() % 2 + 1) * 20;
                raise(current, raise_amt);
                std::cout << "CPU raises $" << current->raise_amt << std::endl;
            }
            else{
                fold(current);
                std::cout << "CPU folds" << std::endl;
                flag = false;
            }
        }
    }
}

void make_cpu_choice_D(Player *current, Community C, bool &flag, int rng){ // function for the 2nd CPU to make their choice in later rounds
    std::srand(rng);
    std::vector<int> cards;
    int raise_amt;
    int n_raise = current->next->raise_amt;
    for(int i = 0; i < 2; i++){
        cards.push_back(current->hole[i]);
    }
    for(int i = 0; i < C.com_cards.size(); i++){
        cards.push_back(C.com_cards[i]);
    }
    std::vector<std::vector<int>> comb;
    comb = combinations(cards);
    current->hand = check_hand(comb);
    int hand = current->hand[0];
    if(current->next->status == 0 || current->next->status == 1){
        if(hand >= 6){
            check(current);
            std::cout << "CPU checks" << std::endl;
            if(current->next->status == 1)
                flag = false;
        }
        else if(hand >= 3){
            raise_amt = n_raise + 40;
            raise(current, raise_amt);
            std::cout << "CPU raises $" << current->raise_amt << std::endl;
        }
        else{
            raise_amt = n_raise + 60;
            raise(current, raise_amt);
            std::cout << "CPU raises $" << current->raise_amt << std::endl; 
        }
    }
    else if(current->next->status == 2){
        if(hand <= 7){
            if(hand >= 5){
                call(current);
                std::cout << "CPU calls" << std::endl;
                flag = false;
            }
            else if(hand >= 3){
                int raise_amt = n_raise + 40;
                raise(current, raise_amt);
                std::cout << "CPU raises $" << current->raise_amt << std::endl;
            }
            else{
                int raise_amt = n_raise + 60;
                raise(current, raise_amt);
                std::cout << "CPU raises $" << current->raise_amt << std::endl;
            }
        }
        else{
            if(hand == 9){
                int rand_seed = rand() % 2;
                if(rand_seed == 0){
                    fold(current);
                    std::cout << "CPU folds" << std::endl;
                    flag = false;
                }
                else{
                    call(current);
                    std::cout << "CPU calls" << std::endl;
                    flag = false;
                }
            }    
            else{
                call(current);
                std::cout << "CPU calls" << std::endl;
                flag = false;
            }
        }
    }
}