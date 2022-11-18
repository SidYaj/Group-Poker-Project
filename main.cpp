#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include "deal_cards.h"
#include "combinations.h"
#include "check_hand.h"
#include "hand_identification.h"
#include "poker_game.h"
#include "poker_game_2.h"
#include "card.h"
#include "print_player_cards.h"
#include "print_com_cards.h"
#include "print_computer_cards.h"
#include "clear_screen.h"
#include "print_ruleset.h"

int main(){
    int current_time = std::time(NULL);
    std::srand(current_time);
    std::ifstream fin;
    std::ofstream fout;
    fin.open("story.txt");
    fout.open("summary.txt");
    std::string str;
    std::string pause;
    getline(fin, str); // 1
    std::cout << str << std::endl;
    std::cout << "\nBegin hacking...\tConnection made...\tConnection secured...\tReached server of Pokr Intnational...\n" << std::endl;
    getline(fin, str); // 2
    std::cout << str << std::endl;
    char ch;
    std::cout << "\nDo you want to see a list of Poker hands? (y/n): ";
    do{
        std::cin >> ch;
        if(ch == 'Y' || ch == 'y'){
            hand_rules();
            std::cout << "\nPress any key followed by enter to continue: ";
            std::cin >> pause;
            clear_screen();
            break;
        }
        else if(ch == 'N' || ch == 'n'){
            clear_screen();
            break;
        }
        else{
            std::cout << "Invalid input. Please enter your choice again (y/n): ";
        }
    } while(true);
    std::cout << "\nLet us begin!\n" << std::endl;
    int points = round_1(rand());
    if(points >= 4)
        std::cout << "You scored " << points << " points in the trial round. Good try!\n" << std::endl;
    else
        std::cout << "You scored " << points << " points in the trial round. Buck up, agent.\n" << std::endl;
    std::cout << "Press any key followed by enter to continue: ";
    std::cin >> pause;
    clear_screen();
    fout << "Trial Round Summary: " << points << " out of 5 hands identified correctly.\n"; 
    
    getline(fin, str); // 3
    std::cout << str << "\n" << std::endl;
    std::cout << "\nDo you want to see a list of Poker hands? (y/n): ";
    do{
        std::cin >> ch;
        if(ch == 'Y' || ch == 'y'){
            hand_rules();
            std::cout << "\nPress any key followed by enter to continue: ";
            std::cin >> pause;
            break;
        }
        else if(ch == 'N' || ch == 'n'){
            clear_screen();
            break;
        }
        else{
            std::cout << "Invalid input. Please enter your choice again (y/n): ";
        }
    } while(true);

    
    std::cout << "\nThe real game begins now.\n" << std::endl;
    points = 0;
    bool flag = true;
    while(flag){
        points = round_2(rand());
        std::cout << "You got " << points << " points\n" << std::endl;
        if(points >= 6){
            flag = false;
            std::cout << "\nYou have successfully broken the first firewall!\n" << std::endl;
        }            
        else{
            std::cout << "You failed to break the first firewall. Try again? (y/n): ";
            while(true){           
                std::cin >> ch;
                if(ch == 'Y' || ch == 'y'){
                    std::cout << "\nAlright, you get a second chance.\n" << std::endl;
                    break;
                }
                else if(ch == 'N' || ch == 'n'){
                    std::cout << "\nWell then, let us pretend you did an exemplary job.\n" << std::endl;
                    flag = false;
                    break;
                }
                else
                    std::cout << "\nInvalid input. Please enter your choice again (y/n): " << std::endl;
            }
        }
    }
    std::cout << "Press any key followed by enter to continue: ";
    std::cin >> pause;
    clear_screen();
    fout << "Round 1 Summary: " << points << " out of 10 hands identified correctly.\n";

    getline(fin, str); // 4
    std::cout << str << "\n" << std::endl;
    int money;
    flag = true;
    std::cout << "\nDo you want to see the Poker rules? (y/n): ";
    do{
        std::cin >> ch;
        if(ch == 'Y' || ch == 'y'){
            print_poker_rules();
            std::cout << "\nPress any key followed by enter to continue: ";
            std::cin >> pause;
            clear_screen();
            break;
        }
        else if(ch == 'N' || ch == 'n'){
            clear_screen();
            break;
        }
        else{
            std::cout << "Invalid input. Please enter your choice again (y/n): ";
        }
    } while(true);
    while(flag){
        money = poker_game(rand());
        std::cout << "\nYou have $" << money << "\n" << std::endl;
        if(money >= 250){
            flag = false;
            std::cout << "\nYou have successfully broken the second firewall!\n" << std::endl;
        }            
        else{
            std::cout << "You failed to break the second firewall. Try again? (y/n): ";
            while(true){           
                std::cin >> ch;
                if(ch == 'Y' || ch == 'y'){
                    std::cout << "\nAlright, you get a second chance.\n" << std::endl;
                    break;
                }
                else if(ch == 'N' || ch == 'n'){
                    std::cout << "\nTaking the easy way out, is it?\n" << std::endl;
                    flag = false;
                    break;
                }
                else
                    std::cout << "\nInvalid input. Please enter your choice again (y/n): " << std::endl;
            }
        }
    }
    std::cout << "Press any key followed by enter to continue: ";
    std::cin >> pause;
    clear_screen();
    fout << "Round 2 Summary: Money at the end of the first poker game is $" << money << ".\n";
    
    getline(fin, str); // 5
    std::cout << str << "\n" << std::endl;
    std::cout << "\nThe hand identification can only get tougher.\n" << std::endl;
    points = 0;
    flag = true;
    std::cout << "\nDo you want to see a list of Poker hands? (y/n): ";
    do{
        std::cin >> ch;
        if(ch == 'Y' || ch == 'y'){
            hand_rules();
            std::cout << "\nPress any key followed by enter to continue: ";
            std::cin >> pause;
            clear_screen();
            break;
        }
        else if(ch == 'N' || ch == 'n'){
            clear_screen();
            break;
        }
        else{
            std::cout << "Invalid input. Please enter your choice again (y/n): ";
        }
    } while(true);


    while(flag){
        points = round_3(rand());
        std::cout << "You got " << points << " points\n" << std::endl;
        if(points >= 6){
            flag = false;
            std::cout << "\nYou have successfully broken the third firewall!\n" << std::endl;
        }            
        else{
            std::cout << "You failed to break the third firewall. Try again? (y/n): ";
            while(true){           
                std::cin >> ch;
                if(ch == 'Y' || ch == 'y'){
                    std::cout << "\nHere we go again!.\n" << std::endl;
                    break;
                }
                else if(ch == 'N' || ch == 'n'){
                    std::cout << "\nWell then, be like that.\n" << std::endl;
                    flag = false;
                    break;
                }
                else
                    std::cout << "\nInvalid input. Please enter your choice again (y/n): " << std::endl;
            }
        }
    }
    std::cout << "Press any key followed by enter to continue: ";
    std::cin >> pause;
    clear_screen();
    int number_correct = points + (10 - points)/2;
    fout << "Round 3 Summary: " << number_correct << " out of 10 hands identified correctly.\n";

    getline(fin, str); // 6
    std::cout << str << "\n" << std::endl;
    std::cout << "\nDo you want to see the Poker rules? (y/n): ";
    do{
        std::cin >> ch;
        if(ch == 'Y' || ch == 'y'){
            print_poker_rules();
            std::cout << "\nPress any key followed by enter to continue: ";
            std::cin >> pause;
            clear_screen();
            break;
        }
        else if(ch == 'N' || ch == 'n'){
            clear_screen();
            break;
        }
        else{
            std::cout << "Invalid input. Please enter your choice again (y/n): ";
        }
    } while(true);
       
    
    std::cout << "\nTime for the final boss.\n" << std::endl;
    money = 0;
    money = poker_game_2(rand());
    std::cout << "\nYou have $" << money << "\n" << std::endl;
    if(money >= 500){
        std::cout << "\nYou have successfully broken the final firewall!\n" << std::endl;
        getline(fin, str); // 7
        std::cout << str << "\n" << std::endl;
        getline(fin, str); // 8
        std::cout << str << "\n" << std::endl;
        getline(fin, str); // 9
        std::cout << str << "\n" << std::endl;
        getline(fin, str); // 10
        std::cout << str << "\n" << std::endl;

    }            
    else{
        std::cout << "\nSorry, this time there are no second chances. You lose.\n\nDisconnecting...\n\nAnd so, Agent Dnob left for a \"holiday\" to Antarctica, never to be seen again." << std::endl;
    }
    fout << "Round 4 Summary: Money at the end of the second poker game is $" << money << "\n";
    fin.close();
    fout.close();
}
