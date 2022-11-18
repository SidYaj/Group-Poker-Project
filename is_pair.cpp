#include <vector>

bool is_pair(std::vector<int> cards){
    if(cards[0] % 13 == cards[1] % 13)
        return true;
    else
        return false;
}