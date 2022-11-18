#include <vector>
#include "check_hand.h"
#include <algorithm>

/* Priority List
1. Straight Flush
2. Four of a Kind
3. Full House
4. Flush
5. Straight
6. Three of a Kind
7. Two Pairs
8. One Pair
9. High Card
*/

std::vector<int> flush(std::vector<int> cards){
    int ct1 = 0; // we create four count variables to see how many of each suite exist
    int ct2 = 0;
    int ct3 = 0;
    int ct4 = 0;
    std::vector<int> hand = {-1,-1};
    for(int j = 0;j < 5;j++){
        if(cards[j] < 13){ //these are the ranges for the suites
            ct1++;
        }
        else if(cards[j] < 26){
            ct2++;
        }
        else if(cards[j] < 39){
            ct3++;
        }
        else if(cards[j] < 52){
            ct4++;
        }
    }
    if(ct1 == 5||ct2 == 5||ct3 == 5||ct4 == 5){ // if any of them is 5 we have a flush
        hand[0] = 4;
        hand[1] = cards[4] % 13;
    }
    
    return hand;
}

std::vector<int> four_of_a_kind(std::vector<int> cards){
    int len = cards.size();
    int ct = 0;
    std::vector<int> hand = {-1, -1};
    for(int i = 0; i < 13; i++){
        for(int j = 0; j < 5; j++){
            if(cards[j] == i||cards[j] == i + 13||cards[j] == i + 26||cards[j] == i + 39)
                ct++;
            if(ct == 4){
                hand[0] = 2;
                hand[1] = i;
                return hand;
            }            
        }
        ct = 0;
    }
    return hand;
}

std::vector<int> full_house(std::vector<int> cards){
    int ct = 0; 
    std::vector<int> hand = {-1,-1,-1};
    for(int i = 0;i < 13;i++){
        for(int j = 0;j < 5;j++){
            if(cards[j] == i||cards[j] == i + 13||cards[j] == i + 26||cards[j] == i + 39){
                ct++;
            }
        }
        if(ct == 3){
            hand[1] = i; 
            break;
        }
        ct = 0;
    }
    if(hand[1] == -1){ 
        return hand;
    }
    for(int i = 0; i < 13;i++){ 
        ct = 0;
        if(i == hand[1])
            continue;
        for(int j = 0;j < 5;j++){
            if(cards[j] == i||cards[j] == i + 13||cards[j] == i + 26||cards[j] == i + 39){
                ct++;
            }
        }
        if(ct == 2){
            hand[0] = 3;
            hand[2] = i;
            return hand;
        }
    }
    return hand;
}

std::vector<int> high_card(std::vector<int> cards){
    std::vector<int> hand = {9, -1};
    for(int i = 0; i < cards.size(); i++){
        if(cards[i] % 13 > hand[1] && hand[1] != 0){
            hand[1] = cards[i] % 13;
        }
    }
    return hand;
}

std::vector<int> one_pair(std::vector<int> cards){
    int len = cards.size();
    int ct = 0;
    std::vector<int> hand = {-1,-1};
    for(int i = 0; i < 13; i++){
        for(int j = 0; j < 5; j++){
            if(cards[j] == i||cards[j] == i + 13||cards[j] == i + 26||cards[j] == i + 39)
                ct++;
            if(ct == 2){
                hand[0] = 8;
                hand[1] = i;
                return hand;
            }            
        }
        ct = 0;
    }
    return hand;
}

std::vector<int> straight_flush(std::vector<int> cards){
    std::vector<int> hand = {-1,-1};
    std::vector<int> temp1 = straight(cards);
    std::vector<int> temp2 = flush(cards);
    if(temp1[0] != -1 && temp2[0] != -1){
        hand[1] = temp1[1];
        hand[0] = 1;       
    }
    return hand;
}

std::vector<int> straight(std::vector<int> cards){ // still have to see how to deal with Aces
    std::vector<int> hand = {-1,-1};
    int ct = 0;
    std::vector<int> mod_cards;
    for(int i = 0; i < cards.size(); i++)
        mod_cards.push_back(cards[i] % 13);
    std::sort(mod_cards.begin(),mod_cards.end());
    for(int i = 0; i < cards.size() - 1; i++){
        if(mod_cards[i] != mod_cards[i + 1] - 1)
            break;
        ct++;        
    }
    if(ct == 4){
        hand[0] = 5;
        hand[1] = mod_cards[4];
    }    
    return hand;
} 

std::vector<int> three_of_a_kind(std::vector<int> cards){
    int len = cards.size();
    int ct = 0;
    std::vector<int> hand = {-1, -1};
    for(int i = 0; i < 13; i++){
        for(int j = 0; j < 5; j++){
            if(cards[j] == i||cards[j] == i + 13||cards[j] == i + 26||cards[j] == i + 39)
                ct++;
            if(ct == 3){
                hand[0] = 6;
                hand[1] = i;
                return hand;
            }            
        }
        ct = 0;
    }
    return hand;
}

std::vector<int> two_pairs(std::vector<int> cards){
    int ct = 0; 
    std::vector<int> hand = {-1,-1,-1};
    for(int i = 0;i < 13;i++){
        for(int j = 0;j < 5;j++){
            if(cards[j] == i||cards[j] == i + 13||cards[j] == i + 26||cards[j] == i + 39){
                ct++;
            }
        }
        if(ct == 2){
            hand[1] = i;  
            break;
        }
        ct = 0;
    }
    if(hand[1] == -1){ // if there is no first pair, we can exit the function
        return hand;
    }
    for(int i = 0; i < 13;i++){ 
        ct = 0;
        if(i == hand[1])
            continue;
        for(int j = 0;j < 5;j++){
            if(cards[j] == i||cards[j] == i + 13||cards[j] == i + 26||cards[j] == i + 39){
                ct++;
            }
        }
        if(ct == 2){
            hand[0] = 7;
            hand[2] = i;
            if(hand[1] < hand[2]){
                int temp = hand[1];
                hand[1] = hand[2];
                hand[2] = temp;
            }
            return hand;
        }
    }
    return hand;
}

std::vector<int> check_hand(std::vector<std::vector<int>> combinations){
    std::vector<int> hand = {9, -1}; // the first element stores what type of hand and the second element stores the value
    int len = combinations.size();
    for(int i = 0; i < len; i++){
        std::vector<int> temp;
        temp = high_card(combinations[i]);
        if(temp[0] == hand[0] && temp[0] != -1){ // we keep comparing all the 21 combinations to see which is the best hand and we return that
            if(temp[1] > hand[1]){
                hand = temp;
            }
        }
        temp = one_pair(combinations[i]);
        if(temp[0] < hand[0] && temp[0] != -1){
            hand = temp;
        }
        else if(temp[0] == hand[0] && temp[0] != -1){
            if(temp[1] > hand[1]){
                hand = temp;
            }
        }
        temp = three_of_a_kind(combinations[i]);
        if(temp[0] < hand[0] && temp[0] != -1){
            hand = temp;
        }
        else if(temp[0] == hand[0] && temp[0] != -1){
            if(temp[1] > hand[1]){
                hand = temp;
            }
        }
        temp = four_of_a_kind(combinations[i]);
        if(temp[0] < hand[0] && temp[0] != -1){
            hand = temp;
        }
        else if(temp[0] == hand[0] && temp[0] != -1){
            if(temp[1] > hand[1]){
                hand = temp;
            }
        }
        temp = two_pairs(combinations[i]);
        if(temp[0] < hand[0] && temp[0] != -1){
            hand = temp;
        }
        else if(temp[0] == hand[0] && temp[0] != -1){
            if(temp[1] > hand[1]){
                hand = temp;
            }
            else if(temp[1] == hand[1] && temp[2] > hand[2]){
                hand = temp;
            }
        }
        temp = full_house(combinations[i]);
        if(temp[0] < hand[0] && temp[0] != -1){
            hand = temp;
        }
        else if(temp[0] == hand[0] && temp[0] != -1){
            if(temp[1] > hand[1]){
                hand = temp;
            }
            else if(temp[1] == hand[1] && temp[2] > hand[2]){
                hand = temp;
            }
        } 
        temp = straight(combinations[i]);
        if(temp[0] < hand[0] && temp[0] != -1){
            hand = temp;
        }
        else if(temp[0] == hand[0] && temp[0] != -1){
            if(temp[1] > hand[1]){
                hand = temp;
            }
        }
        temp = flush(combinations[i]);
        if(temp[0] < hand[0] && temp[0] != -1){
            hand = temp;
        }
        else if(temp[0] == hand[0] && temp[0] != -1){
            if(temp[1] > hand[1]){
                hand = temp;
            }
        }
        temp = straight_flush(combinations[i]);
        if(temp[0] < hand[0] && temp[0] != -1){
            hand = temp;
        }
        else if(temp[0] == hand[0] && temp[0] != -1){
            if(temp[1] > hand[1]){
                hand = temp;
            }
        }
    }
    return hand;
}