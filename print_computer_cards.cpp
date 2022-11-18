/* this function prints out the CPU cards 
in all the rounds of the game except the last round
It takes the pointer P as the parameter which points to the 
CPU's Player data type*/



#include <iostream>
#include <iomanip>
#define SPADE   "\xE2\x99\xA0"
#define CLUB    "\xE2\x99\xA3"
#define HEART   "\xE2\x99\xA5"
#define DIAMOND "\xE2\x99\xA6"
#define NUMCARDS  5
#include "print_computer_cards.h"
#include "player.h"

void print_computer_cards(Player *P)
{
	int m = P -> money; //amount of money the cpu has
	std::cout << std::setw(20);
    for (int i = 0; i < 16; i++)
	{	if(i == 7 || i == 15 )
			std::cout << " ";
		else 	
			std::cout << "▁";
	}
	std::cout << "\n";
	//outer loop is to iterate the number of rows
	//inner loop is to print the row content for each row
	for (int i = 0; i < 5; i++) 
	{	std::cout << std::setw(18);
		if(i == 2)
			std::cout << "|"  << "𝓹𝓸𝓴𝓮𝓻" << "|" << std::setw(2)  << "|"  << "𝓹𝓸𝓴𝓮𝓻" << "|" ; //since the cards need not be revealed
		else
			std::cout << "|" << std::setw(6) << "|" << std::setw(2) <<  "|" << std::setw(6) << "|" << std::setw(2);
		std::cout << "\n";
	}
	std::cout << std::setw(20);
	for (int i = 0; i < 16; i++)
	{	if(i == 7 || i == 15 )
			std::cout << " ";
		else 	
			std::cout << "▔";
	}
	std::cout << "\n";
    std::cout << std::setw(30);
    if(P->is_dealer) 
	//prints status of the CPU regarding whether it is a dealer or not
    {
        std::cout << "Dealer \n";
    }
    std::cout << std::setw(28) << "Money : $" << m << "\n";
    std::cout << std::setw(27);
    std::cout << "CPU " <<"\n";
}
