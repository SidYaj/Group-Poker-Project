#include <iostream>
#include <cstdlib>
#include <string>
#include "check_hand.h"
#include "deal_cards.h"
#include "combinations.h"
#include "print_identify_cards.h"
#include "clear_screen.h"

int round_1(int rng){
    int ct = 0;
    std::string pause;
    std::srand(rng);
    for (int i = 0; i < 5; i++){
        int seed = rand();
        std::vector<int> deck;
        deck_gen(deck, seed);
        std::vector<int> cards;
        for(int j = 0; j < 5; j++){
            cards.push_back(deck[j]);
        }
        print_identify_cards(cards);
        std::cout << "List of hands" << std::endl;
        std::cout << "1. Straight Flush" << std::endl;
        std::cout << "2. Four of a Kind" << std::endl;
        std::cout << "3. Full House" << std::endl;
        std::cout << "4. Flush" << std::endl;
        std::cout << "5. Straight" << std::endl;
        std::cout << "6. Three of a Kind" << std::endl;
        std::cout << "7. Two Pairs" << std::endl;
        std::cout << "8. One Pair" << std::endl;
        std::cout << "9. High Card" << std::endl;
        std::cout << "Identify the type of hand: ";
        int ch;
        std::cin >> ch;
        std::vector<std::vector<int> > combs = combinations(cards);
        std::vector<int> hand = check_hand(combs);
        if(hand[0] == ch)
            std::cout << "Correct! You have " << ++ct << " points!" << std::endl;
        else
            std::cout << "Wrong! You have " << ct << " points!" << std::endl;
        std::cout << "\nPress any key followed by enter to continue: ";
        std::cin >> pause;
        clear_screen();
    }
    return ct;    
}

int round_2(int rng){
    int ct = 0;
    std::string pause;
    std::srand(rng);
    for (int i = 0; i < 10; i++){
        int seed = rand();
        std::vector<int> deck;
        deck_gen(deck, seed);
        std::vector<int> cards;
        for(int j = 0; j < 6; j++){
            cards.push_back(deck[j]);
        }
        print_identify_cards(cards);
        std::cout << "List of hands" << std::endl;
        std::cout << "1. Straight Flush" << std::endl;
        std::cout << "2. Four of a Kind" << std::endl;
        std::cout << "3. Full House" << std::endl;
        std::cout << "4. Flush" << std::endl;
        std::cout << "5. Straight" << std::endl;
        std::cout << "6. Three of a Kind" << std::endl;
        std::cout << "7. Two Pairs" << std::endl;
        std::cout << "8. One Pair" << std::endl;
        std::cout << "9. High Card" << std::endl;
        std::cout << "Identify the type of hand: ";
        int ch;
        std::cin >> ch;
        std::vector<std::vector<int> > combs = combinations(cards);
        std::vector<int> hand = check_hand(combs);
        if(hand[0] == ch)
            std::cout << "Correct! You have " << ++ct << " points!" << std::endl;
        else
            std::cout << "Wrong! You have " << ct << " points!" << std::endl;
        std::cout << "\nPress any key followed by enter to continue: ";
        std::cin >> pause;
        clear_screen();
    }
    return ct;
}

int round_3(int rng){
    int ct = 0;
    std::srand(rng);
    std::string pause;
    for (int i = 0; i < 10; i++){
        int seed = rand();
        std::vector<int> deck;
        deck_gen(deck, seed);
        std::vector<int> cards;
        for(int j = 0; j < 7; j++){
            cards.push_back(deck[j]);
        }
        print_identify_cards(cards);
        std::cout << "List of hands" << std::endl;
        std::cout << "1. Straight Flush" << std::endl;
        std::cout << "2. Four of a Kind" << std::endl;
        std::cout << "3. Full House" << std::endl;
        std::cout << "4. Flush" << std::endl;
        std::cout << "5. Straight" << std::endl;
        std::cout << "6. Three of a Kind" << std::endl;
        std::cout << "7. Two Pairs" << std::endl;
        std::cout << "8. One Pair" << std::endl;
        std::cout << "9. High Card" << std::endl;
        std::cout << "Identify the type of hand: ";
        int ch;
        std::cin >> ch;
        std::vector<std::vector<int> > combs = combinations(cards);
        std::vector<int> hand = check_hand(combs);
        if(hand[0] == ch)
            std::cout << "Correct! You have " << ++ct << " points!" << std::endl;
        else
            std::cout << "Wrong! You have " << --ct << " points!" << std::endl;
        std::cout << "\nPress any key followed by enter to continue: ";
        std::cin >> pause;
        clear_screen();
    }

    return ct;
}