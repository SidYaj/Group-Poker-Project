/*This function of is used to print cards during the 2 rounds of the game
where the player has to indentify card hands
It takes the card hand integer vector as the input parameter
*/

#include <iostream>
#include <iomanip>
#include "card.h"
#include <string>
#include "print_identify_cards.h"
#define SPADE   "\xE2\x99\xA0"
#define CLUB    "\xE2\x99\xA3"
#define HEART   "\xE2\x99\xA5"
#define DIAMOND "\xE2\x99\xA6"
#include "player.h"


void print_identify_cards(std::vector<int> cards)
{
	std::vector<Card> identifyCards = card(cards); //to convert the int vector of cards to printable strings with number on the card and card suit 

	int len = cards.size();
	if(len == 5){ //conditions to print the first row
		for (int i = 0; i < 39; i++)
		{	if(i == 7 || i == 15 || i == 23 || i == 31)
				std::cout << " ";
			else
				std::cout << "▁";
		}
	}
	else if(len == 6){
		for (int i = 0; i < 47; i++)
		{	if(i == 7 || i == 15 || i == 23 || i == 31 || i==39	)
				std::cout << " ";
			else
				std::cout << "▁";
		}
	}
	else if(len == 7){
		for (int i = 0; i < 55; i++)
		{	if(i == 7 || i == 15 || i == 23 || i == 31 || i==39	|| i == 47)
				std::cout << " ";
			else
				std::cout << "▁";
		}
	}
	std::cout << "\n";
	//outer loop is to iterate the number of rows
	//inner loop is to print the row content for each row
	for (int i = 0; i < 5; i++)
	{	
		if(i == 0)
		{
			for(int j = 0; j < len; j++)
			{
				if(identifyCards[j].number.length() == 1)
					std::cout << "|" << identifyCards[j].number << std::setw(5) << "|" << std::setw(2) ;
				else 
					std::cout << "|" << identifyCards[j].number << std::setw(4) << "|" << std::setw(2) ;
			}
		}
		
		else if (i == 4)
			for(int j = 0; j < len; j++)
			{
				std::cout <<"|" << std::setw(5) << identifyCards[j].number << "|" << std::setw(2);
			}
			
		else if ( i == 2 )
		{
			for(int j = 0; j < len; j++) 
			{
				std::cout << "|"  << std::setw(5) << identifyCards[j].suit << std::setw(3) <<"|" << std::setw(2) ;
			}
		}
			
		else if(i == 1)
			for(int j = 0; j < len; j++)
			{
				std::cout << "|" << std::setw(6) << "|" << std::setw(2);
			}
			
		else if(i == 3)	
			for(int j = 0; j < len; j++)
			{
				std::cout << "|" << std::setw(6) << "|" << std::setw(2);
			}
			
		std::cout << "\n";
	}
	if(len == 5){
		for (int i = 0; i < 39; i++)
		{	if(i == 7 || i == 15 || i == 23 || i == 31)
				std::cout << " ";
			else
				std::cout << "▔";
		}
	}
	else if(len == 6){
		for (int i = 0; i < 47; i++)
		{	if(i == 7 || i == 15 || i == 23 || i == 31 || i==39	)
				std::cout << " ";
			else
				std::cout << "▔";
		}
	}
	else if(len == 7){
		for (int i = 0; i < 55; i++)
		{	if(i == 7 || i == 15 || i == 23 || i == 31 || i==39	|| i == 47)
				std::cout << " ";
			else
				std::cout << "▔";
		}
	}
    std::cout << "\n";
}