#include <iostream>
#include <vector>
#include <cstdlib>
#include "poker_game.h"
#include "display_hand.h"
#include "card.h"
#include "print_player_cards.h"
#include "print_com_cards.h"
#include "print_computer_cards.h"
#include "print_identify_cards.h"
#include "print_computer_cards_lastRound.h"
#include "clear_screen.h"


int poker_game(int rng){ // function for the match against the 1st CPU
    std::srand(rng);
    std::string pause;
    Player *p1 = new Player(200, 1);
    Player *p2 = new Player(200, 2);
    Community C;
    p1->next = p2;
    p2->next = p1;
    bool x = rand() % 2;
    bool y = 1 - x;
    std::vector<int> deck;
    for(int round = 1; round <= 4; round++){
        clear_screen();
        x = !x;
        y = !y;
        p1->hole = {};
        p2->hole = {};
        C.com_cards = {};
        p1->status = 0;
        p2->status = 0;
        deck_gen(deck, rand());
        p1->is_dealer = x;
        p2->is_dealer = y;
        Player *current;
        if(p1->is_dealer){
            current = p1;
        }
        else{
            current = p2;
        }
        for(int i = 0; i < 4; i++){
            current->hole.push_back(deal_cards(deck));
            current = current->next;
        }
        if(p1->is_dealer){
            p1->raise_amt = 10;
            p2->raise_amt = 20;
            current = p1;
        }
        else{
            p1->raise_amt = 20;
            p2->raise_amt = 10;
            current = p2;
        }

        std::cout << "Pre-Flop Round\n" << std::endl;
        print_computer_cards(p2);
        print_com_cards(C);
        print_player_cards(p1);
        std::cout << std::endl;
        if(p1->is_dealer){
            std::cout << "You are the small blind posting $10." << std::endl;
            std::cout << "CPU is the big blind posting $20." << std::endl;
        }
        else{
            std::cout << "You are the big blind posting $20." << std::endl;
            std::cout << "CPU is the small blind posting $10." << std::endl;
        }
        bool flag = true;
        while(flag == true){
            if((p1->raise_amt == p1->money && p2->raise_amt == p1->money) || (p1->raise_amt == p2->money && p2->raise_amt == p2->money))
                break;
            if(current == p1){
                std::cout << "\nYour turn: " << std::endl;
                make_player_choice_A(current, flag);
            }
            else {
                std::cout << "\nCPU's turn: ";
                make_cpu_choice_A(current, flag, rand());
            }
            current = current->next;
        }
        std::cout << std::endl;

        //std::cout << p1->raise_amt << " " << p2->raise_amt << std::endl;

        if(p1->raise_amt > p2->raise_amt){
            C.money_pot = 2*p2->raise_amt;
            p1->money -= p2->raise_amt;
            p2->money -= p2->raise_amt;
        }
        else{
            C.money_pot = 2*p1->raise_amt;
            p1->money -= p1->raise_amt;
            p2->money -= p1->raise_amt;
        }
        flag = true;

        //clear_screen();

        if(p1->status == 4){ 
            p2->money += C.money_pot;
            C.money_pot = 0;
            print_computer_cards(p2);
            print_com_cards(C);
            print_player_cards(p1);// print table here
            std::cout << "You folded. Press any key and press enter to continue: ";
            std::cin >> pause;
            continue;
        }
        if(p2->status == 4){ 
            p1->money += C.money_pot;
            C.money_pot = 0;
            print_computer_cards(p2);
            print_com_cards(C);
            print_player_cards(p1);// print table
            std::cout << "CPU Folded. Press any key and press enter to continue: ";
            std::cin >> pause;
            continue;
        }
        if(flag == true){
            if(p1->money == 0){
                std::cout << "You are all in" << std::endl;
                flag = false;
            }
            if(p2->money == 0){
                std::cout << "CPU is all in" << std::endl;
                flag = false;
            }
        }
        if(flag != false){
            print_computer_cards(p2);
            print_com_cards(C);
            print_player_cards(p1);// print table here
            std::cout << "Press any key and press enter to continue: ";
            std::cin >> pause;
            clear_screen();
        }

        if(p1->is_dealer){
            current = p2;
        }
        else{
            current = p1;
        }

        p1->status = p2->status = 0;
        p1->raise_amt = p2->raise_amt = 0;

        for(int i = 0; i < 3; i++){
            C.com_cards.push_back(deck[i]);
        }
        deck.erase(deck.begin(),deck.begin()+3);
        
        if(flag){
            std::cout << "Flop Round\n" << std::endl;
            print_computer_cards(p2);
            print_com_cards(C);
            print_player_cards(p1);
        }

        //print table here
        while(flag == true){
            if((p1->raise_amt == p1->money && p2->raise_amt == p1->money) || (p1->raise_amt == p2->money && p2->raise_amt == p2->money))
                break;
            if(current == p1){
                std::cout << "\nYour turn: " << std::endl;
                make_player_choice_B(current, flag);
            }
            else {
                std::cout << "\nCPU's turn: ";
                make_cpu_choice_B(current, C, flag, rand());
            }
            current = current->next;
        }
        std::cout << std::endl;

        if(p1->raise_amt > p2->raise_amt){
            C.money_pot += 2*p2->raise_amt;
            p1->money -= p2->raise_amt;
            p2->money -= p2->raise_amt;
        }
        else{
            C.money_pot += 2*p1->raise_amt;
            p1->money -= p1->raise_amt;
            p2->money -= p1->raise_amt;
        }
        
        if(p1->status == 4){ // print table here
            p2->money += C.money_pot;
            C.money_pot = 0;
            print_computer_cards(p2);
            print_com_cards(C);
            print_player_cards(p1);
            std::cout << "You folded. Press any key and press enter to continue: ";
            std::cin >> pause;
            continue;
        }
        if(p2->status == 4){ // print table here
            p1->money += C.money_pot;
            C.money_pot = 0;
            print_computer_cards(p2);
            print_com_cards(C);
            print_player_cards(p1);
            std::cout << "CPU folded. Press any key and press enter to continue: ";
            std::cin >> pause;
            continue;
        }
        flag = true;
        if(flag){
            if(p1->money == 0){
                std::cout << "You are all in" << std::endl;
                flag = false;
            }
            if(p2->money == 0){
                std::cout << "CPU is all in" << std::endl;
                flag = false;
            }
        }
        if(flag){
            print_computer_cards(p2);
            print_com_cards(C);
            print_player_cards(p1);
            std::cout << "Press any key and press enter to continue: ";
            std::cin >> pause;
            clear_screen();
        }
        //print table here
        
        if(p1->is_dealer){
            current = p2;
        }
        else{
            current = p1;
        }

        p1->status = p2->status = 0;
        p1->raise_amt = p2->raise_amt = 0;
        C.com_cards.push_back(deck[0]);
        deck.erase(deck.begin(),deck.begin()+1);
        if(flag){
            std::cout << "The Turn\n" << std::endl;
            print_computer_cards(p2);
            print_com_cards(C);
            print_player_cards(p1);
        }
        
        while(flag == true){
            if((p1->raise_amt == p1->money && p2->raise_amt == p1->money) || (p1->raise_amt == p2->money && p2->raise_amt == p2->money))
                break;
            if(current == p1){
                std::cout << "\nYour turn:" << std::endl;
                make_player_choice_B(current, flag);
            }
            else {
                std::cout << "\nCPU's turn: ";
                make_cpu_choice_B(current, C, flag, rand());
            }               
            current = current->next;
        }
        std::cout << std::endl;

        if(p1->raise_amt > p2->raise_amt){
            C.money_pot += 2*p2->raise_amt;
            p1->money -= p2->raise_amt;
            p2->money -= p2->raise_amt;
        }
        else{
            C.money_pot += 2*p1->raise_amt;
            p1->money -= p1->raise_amt;
            p2->money -= p1->raise_amt;
        }
        flag = true;
        if(p1->status == 4){
            p2->money += C.money_pot;
            C.money_pot = 0;
            print_computer_cards(p2);
            print_com_cards(C);
            print_player_cards(p1);
            std::cout << "You folded. Press any key and press enter to continue: ";
            std::cin >> pause;
            continue;
        }
        if(p2->status == 4){
            p1->money += C.money_pot;
            C.money_pot = 0;
            print_computer_cards(p2);
            print_com_cards(C);
            print_player_cards(p1);
            std::cout << "CPU folded. Press any key and press enter to continue: ";
            std::cin >> pause;
            continue;
        }
        if(flag){
            if(p1->money == 0){
                std::cout << "You are all in" << std::endl;
                flag = false;
            }
            if(p2->money == 0){
                std::cout << "CPU is all in" << std::endl;
                flag = false;
            }
        }   
        if(flag){
            print_computer_cards(p2);
            print_com_cards(C);
            print_player_cards(p1);
            std::cout << "Press any key and press enter to continue: ";
            std::cin >> pause;
            clear_screen();
        }
        if(p1->is_dealer){
            current = p2;
        }
        else{
            current = p1;
        }

        p1->status = p2->status = 0;
        p1->raise_amt = p2->raise_amt = 0;

        C.com_cards.push_back(deck[0]);
        deck.erase(deck.begin(),deck.begin()+1);
        if(flag){
            std::cout << "The River\n" << std::endl;
            print_computer_cards(p2);
            print_com_cards(C);
            print_player_cards(p1);
        }
        while(flag == true){
            if((p1->raise_amt == p1->money && p2->raise_amt == p1->money) || (p1->raise_amt == p2->money && p2->raise_amt == p2->money))
                break;
            if(current == p1){
                std::cout << "\nYour turn:" << std::endl;
                make_player_choice_B(current, flag);
            }
            else{
                std::cout << "\nCPU's turn: ";
                make_cpu_choice_B(current, C, flag, rand());
            }               
            current = current->next;
        }
        std::cout << std::endl;

        if(p1->raise_amt > p2->raise_amt){
            C.money_pot += 2*p2->raise_amt;
            p1->money -= p2->raise_amt;
            p2->money -= p2->raise_amt;
        }
        else{
            C.money_pot += 2*p1->raise_amt;
            p1->money -= p1->raise_amt;
            p2->money -= p1->raise_amt;
        }

        flag = true;
        
        if(p1->status == 4){
            p2->money += C.money_pot;
            C.money_pot = 0;
            print_computer_cards(p2);
            print_com_cards(C);
            print_player_cards(p1);
            std::cout << "You folded. Press any key and press enter to continue: ";
            std::cin >> pause;
            continue;
        }
        if(p2->status == 4){
            p1->money += C.money_pot;
            C.money_pot = 0;
            print_computer_cards(p2);
            print_com_cards(C);
            print_player_cards(p1);
            std::cout << "CPU Folded. Press any key and press enter to continue: ";
            std::cin >> pause;
            continue;
        }
        if(!flag){
            if(p1->money == 0){
                std::cout << "You are all in" << std::endl;
                flag = false;
            }
            if(p2->money == 0){
                std::cout << "CPU is all in" << std::endl;
                flag = false;
            }
        }
        if(flag){
            print_computer_cards(p2);
            print_com_cards(C);
            print_player_cards(p1);
            std::cout << "Press any key and press enter to continue: ";
            std::cin >> pause;
            clear_screen();
        }
        std::vector<int> cards1, cards2;

        for(int i = 0; i < 2; i++){
            cards1.push_back(p1->hole[i]);
            cards2.push_back(p2->hole[i]);
        }
        for(int i = 0; i < C.com_cards.size(); i++){
            cards1.push_back(C.com_cards[i]);
            cards2.push_back(C.com_cards[i]);
        }
        std::vector<std::vector<int>> comb1, comb2;
        comb1 = combinations(cards1);
        p1->hand = check_hand(comb1);
        comb2 = combinations(cards2);
        p2->hand = check_hand(comb2);

        std::cout << "Showdown!" << std::endl;
        print_comp_cards_lastRound(p2); 
        print_com_cards(C);
        print_player_cards(p1);
        std::cout << "Press any key and press enter to continue: ";
        std::cin >> pause;

        std::cout << "Your hand is: ";
        display_hand(p1->hand);
        std::cout << "CPU's hand is: ";
        display_hand(p2->hand);

        if(p1->hand[0] < p2->hand[0]){
            std::cout << "You win " << C.money_pot << std::endl;
            p1->money += C.money_pot;
        }
        else if(p1->hand[0] > p2->hand[0]){
            std::cout << "CPU wins " << C.money_pot << std::endl;
            p2->money += C.money_pot;
        }
        else
        {
            if(p1->hand.size() == 1){
                std::cout << "Tie, the money is split" << std::endl;
                p1->money += C.money_pot/2;
                p2->money += C.money_pot/2;
            }
            else{
                if(p1->hand[1] > p2->hand[1]){
                    std::cout << "You win " << C.money_pot << std::endl;
                    p1->money += C.money_pot;
                }
                    
                else if(p1->hand[1] < p2->hand[1]){
                    std::cout << "CPU wins " << C.money_pot << std::endl;
                    p2->money += C.money_pot;
                }
                else{
                    if(p1->hand.size() == 2){      
                        std::cout << "Tie, the money is split" << std::endl;
                        p1->money += C.money_pot/2;
                        p2->money += C.money_pot/2;
                    }
                    else{
                        if(p1->hand[2] > p2->hand[2]){
                            std::cout << "You win " << C.money_pot << std::endl;
                            p1->money += C.money_pot;
                        }
                            
                        else if(p1->hand[2] < p2->hand[2]){
                            std::cout << "CPU wins " << C.money_pot << std::endl;
                            p2->money += C.money_pot;
                        } 
                        else{
                            std::cout << "Tie, the money is split" << std::endl;
                            p1->money += C.money_pot/2;
                            p2->money += C.money_pot/2;
                        }
                    }
                }
            }
        }
        C.money_pot = 0;
        std::cout << "\nPress any key and then press enter to continue: ";
        std::cin >> pause;
    }
    int return_money = p1->money;
    delete p1;
    delete p2;
    return return_money;
}
