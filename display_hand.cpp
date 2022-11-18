#include <vector>
#include <iostream>


void display_hand(std::vector<int> hand){ // to display what hand a player has
    std::string values[13] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"}; // array of values
    int len = hand.size();
    if(len == 2){
        if (hand[0] == 9)
            std::cout << "High Card " << values[hand[1]] << std::endl;
        if(hand[0] == 1)
            std::cout << values[hand[1]] << " High Straight Flush" << std::endl;
        else if(hand[0] == 2){
            std::cout << "Four of a Kind " << values[hand[1]] << "s" << std::endl;
        }
        else if(hand[0] == 4){
            std::cout << values[hand[1]] << " High Flush" << std::endl;
        }
        else if(hand[0] == 5){
            std::cout << values[hand[1]] << " High Straight" << std::endl;
        }
        else if(hand[0] == 6){
            std::cout << "Three of a Kind " << values[hand[1]] << "s" << std::endl;
        }
        else if(hand[0] == 8){
            std::cout << "One Pair " << values[hand[1]] << "s" << std::endl;
        }
    }
    else if(len == 3){
        if(hand[0] == 3){
            std::cout << "Full house of " << values[hand[2]] << "s in " << values[hand[1]] << "s" << std::endl;
        }
        if(hand[0] == 7){
            std::cout << "Two pairs " << values[hand[1]] << "s and " << values[hand[2]] << "s" << std::endl;
        }
    }
}