/*this function prints the community cards on the table
the Community type is passed as the parameter which stores an int vector
of the community cards and also stores the interger of the 
money in the pot.*/


#include <iostream>
#include <iomanip>
#include "card.h"
#include <string>
#include "print_com_cards.h"
#define SPADE   "\xE2\x99\xA0"
#define CLUB    "\xE2\x99\xA3"
#define HEART   "\xE2\x99\xA5"
#define DIAMOND "\xE2\x99\xA6"
#define NUMCARDS  5
#include "player.h"
#include "community.h"


void print_com_cards(Community C) 
{
	std::vector<int> cards = C.com_cards;
	std::vector<Card> comCards; //to convert the int vector of cards to printable strings with number on the card and card suit 
	
	if(cards.size() == 0) 
     /*if the vector passed doesnt have any elements as is the case when the table has to be printed without 
     any cards revealed
     in this case number inside data type Card is initialised to a " " which suits the print function for community cards*/
    {
        Card x;
        x.number = " ";
        x.suit = " ";
        comCards.push_back(x);
        comCards.push_back(x);
        comCards.push_back(x);
        comCards.push_back(x);
        comCards.push_back(x);
    }
	else{
		Card x;
		for (int i = 0; i < cards.size(); i++)
		{   int k = cards[i];

			if(k / 13 == 0) 
			//card suit condition
			{   
				if(k % 13 == 0) 
				//card number condition
					x.number = "A";
				else if(k % 13 <= 9)
				//card number condition
					x.number = std::to_string((k % 13 + 1));
				else if(k % 13 > 9)
				//card number condition
				{
					if(k % 13 == 10)
					//card number condition
						x.number = "J";
					else if(k % 13 == 11)
					//card number condition
						x.number = "Q";
					else if(k%13 == 12)
					//card number condition
						x.number = "K";
				}
				x.suit = SPADE;
				comCards.push_back(x); 
				//card is added to the vector to be returned 
			}

			else if(k / 13== 1)//card suit condition
			{
				if(k % 13 == 0)
				//card number condition
					x.number = "A";
				else if(k % 13 <= 9)
				//card number condition
					x.number = std::to_string((k % 13 + 1));
				else if(k % 13 > 9)
				//card number condition
				{
					if(k % 13 == 10)
					//card number condition
						x.number = "J";
					else if(k % 13 == 11)
					//card number condition
						x.number = "Q";
					else if(k % 13 == 12)
					//card number condition
						x.number = "K";
				}
				x.suit = HEART;
				comCards.push_back(x);
				//card is added to the vector to be returned 
			}

			else if(k / 13 == 2)//card suit condition
			{
				if(k % 13 == 0)//card number condition
					x.number = "A";
				else if(k % 13 <= 9)//card number condition
					x.number = std::to_string((k % 13 + 1));
				else if(k % 13 > 9)//card number condition
				{
					if(k % 13 == 10)//card number condition
						x.number = "J";
					else if(k % 13 == 11)//card number condition
						x.number = "Q";
					else if(k % 13 == 12)//card number condition
						x.number = "K";
				}
				x.suit = CLUB;
				comCards.push_back(x);
				//card is added to the vector to be returned 

			}

			else if(k / 13 == 3)//card suit condition
			{
				if(k % 13 == 0)//card number condition
					x.number = "A";
				else if(k % 13 <= 9)//card number condition
					x.number = std::to_string((k%13 + 1));
				else if(k % 13 > 9)//card number condition
				{
					if(k % 13 == 10)//card number condition
						x.number = "J";
					else if(k % 13 == 11)
					//card number condition
						x.number = "Q";
					else if(k % 13 == 12)
					//card number condition
						x.number = "K";
				}
				x.suit = DIAMOND;
				comCards.push_back(x); 
				//card is added to the vector to be returned 

			}
			k = 0;
			x.number = " ";
			x.suit = "";

		}
		if(cards.size() == 2)
		{
			comCards.push_back(x);
			comCards.push_back(x);
			comCards.push_back(x);
		}

		else if(cards.size() == 3) 
		//if number of cards to be revealed is 3, two more Cards are added to the function with number as " " which suits the print function
		{
			comCards.push_back(x);
			comCards.push_back(x);
		}

		else if(cards.size() == 4)
		//if number of cards to be revealed is 4, one more Cards are added to the function with number as " " which suits the print function
		{
			comCards.push_back(x);
		}
	}
    
	
	
	std::string pot_money = std::to_string(C.money_pot);
	std::cout << std::setw(7) << "  ░" ;
	for(int i = 0; i < 40 ; i++)
		std::cout << "░" ;
	std::cout << "\n";
	std::cout << std::setw(6) << "  ░" << std::setw(45) << "░\n";
	std::cout << std::setw(5) << "  ░" << std::setw(47) << "░\n";
	std::cout << std::setw(5) << " ░   ";
	for (int i = 0; i < 39; i++)
	{	if(i == 7 || i == 15 || i == 23 || i == 31)
			std::cout << " ";
		else
			std::cout << "✶";
	}
	std::cout << std::setw(5) << "   ░";
	std::cout << "\n"; 
	
	//outer loop is to iterate the number of rows
	//inner loop is to print the row content for each row

	for (int i = 0; i < 5; i++)
	{	
		if(i == 0) 
		{	std::cout << "░    ";
			for(int j = 0; j < 5 ; j++)
			{
				if(comCards[j].number.length() == 1)
					std::cout << "|" << comCards[j].number << std::setw(5) << "|" << std::setw(2) ;
				else 
					std::cout << "|" << comCards[j].number << std::setw(4) << "|" << std::setw(2) ;
			}
		}
		// 	std::cout << "|" << number[0] << std::setw(9) << "|" << std::setw(2) << "|" << number[1] << std::setw(9) << "|" << std::setw(2) << "|" << number[2] << std::setw(9)  << "|" << std::setw(2) << "|" << number[3] << std::setw(9) << "|" << std::setw(2) << "|" << number[4] << std::setw(9) << "|";
		else if (i == 4)
			std::cout << "░    "<<"|" << std::setw(5) << comCards[0].number << "|" << std::setw(2) << "|"  << std::setw(5) << comCards[1].number<< "|" << std::setw(2) << "|" << std::setw(5) << comCards[2].number <<"|" << std::setw(2) << "|" << std::setw(5) << comCards[3].number <<"|" << std::setw(2) << "|" << std::setw(5) << comCards[4].number <<"|";
		else if ( i == 2 )
		{
			std::cout << "░" << std::setw(5) ;
			for(int j = 0; j < 5 ; j++)
			{
				if(comCards[j].number == " ")
					std::cout << "|"  << "𝓹𝓸𝓴𝓮𝓻" << "|" << std::setw(2) ;
				else 
					std::cout << "|"  << std::setw(5) << comCards[j].suit << std::setw(3) <<"|" << std::setw(2) ;
			}
		}
			//std::cout << "|" << std::setw(7) << SPADE <<  std::setw(5) << "|" << std::setw(2)  << "|" << std::setw(7) << HEART<<  std::setw(5) << "|" << std::setw(2)  << "|" << std::setw(7) << HEART<<  std::setw(5) << "|" << std::setw(2)  << "|" << std::setw(7) << HEART<<  std::setw(5) << "|" << std::setw(2)  << "|" << std::setw(7) << DIAMOND <<  std::setw(5) << "|";
		else if(i == 1)
			std::cout << "░" << std::setw(5) << "|" << std::setw(6) << "|" << std::setw(2) << "|" << std::setw(6) << "|" << std::setw(2) << "|" <<  std::setw(6)  << "|" << std::setw(2) << "|" <<  std::setw(6) << "|" << std::setw(2) << "|" << std::setw(6) << "|";
		else if(i == 3)	
			std::cout << "░" << std::setw(5) << "|" << std::setw(6) << "|" << std::setw(2) << "|" << std::setw(6) << "|" << std::setw(2) << "|" <<  std::setw(6)  << "|" << std::setw(2) << "|" <<  std::setw(6) << "|" << std::setw(2) << "|" << std::setw(6) << "|";
		std::cout << "    ░";
		std::cout << "\n";
	}
	std::cout << " ░   ";
	for (int i = 0; i < 39; i++)
	{	if(i == 7 || i == 15 || i == 23 || i == 31)
			std::cout << " ";
		else 	
			std::cout << "✶";
	}
	std::cout << "   ░";
	std::cout << "\n";
	std::cout << std::setw(5) << "  ░" << std::setw(32) << "𝓟 𝓸 𝓽 $" << pot_money << std::setw(24-pot_money.length()) << "░\n"; //so that pot fits right at the centre of the table being printed
// 	if(pot_money < 100)
// 		std::cout << std::setw(5) << "  ░" << std::setw(32) << "𝓟 𝓸 𝓽 $" << pot_money << std::setw(22) << "░\n";
// 	else if(pot_money >=100 && pot_money < 1000)
// 		std::cout << std::setw(5) << "  ░" << std::setw(32) << "𝓟 𝓸 𝓽 $" << pot_money << std::setw(21) << "░\n";
// 	else if(pot_money >= 1000)
// 		std::cout << std::setw(5) << "  ░" << std::setw(32) << "𝓟 𝓸 𝓽 $" << pot_money << std::setw(20) << "░\n";
	//std::cout << std::setw(5) << "  ░" << std::setw(32) << "𝓟 𝓸 𝓽 $" << pot_money << std::setw(21) << "░\n";
	std::cout << std::setw(6) << "  ░" << std::setw(45) << "░\n";
	std::cout << std::setw(7) << "░";
	for(int i = 0; i < 40 ; i++)
		std::cout << "░" ;
	std::cout << "\n";

}
