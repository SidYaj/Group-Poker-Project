#include <vector>
#include <algorithm>
#include "player.h"
#include "community.h"
#include "combinations.h"

std::vector<std::vector<int>> combinations(std::vector<int> cards){
    //print_cards(cards);
    std::vector<std::vector<int>> combination;
    if(cards.size() == 7){
        for(int i = 0; i < 7; i++){
            for(int j = i+1; j < 7; j++){
                std::vector<int> vec = {};
                for(int k = 0; k < 7; k++){
                    if(k != i && k != j){
                        vec.push_back(cards[k]);
                    }
                }
                std::sort(vec.begin(), vec.end());
                combination.push_back(vec);
            }
        }
    }
    else if(cards.size() == 6){
        for(int i = 0; i < 6; i++){
            std::vector<int> vec = {};
            for(int k = 0; k < 6; k++){
                    if(k != i){
                        vec.push_back(cards[k]);
                    }
                }
                combination.push_back(vec);
        }
    }
    else if(cards.size() == 5){
        combination.push_back(cards);
    }
    return combination;
}