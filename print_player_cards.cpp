/*This function is to print the player cards 
It takes the pointer P as the parameter which points to the 
user's Player data type*/

#include <iostream>
#include <iomanip>
#include "card.h"
#include <string>
#include "print_player_cards.h"
#define SPADE   "\xE2\x99\xA0"
#define CLUB    "\xE2\x99\xA3"
#define HEART   "\xE2\x99\xA5"
#define DIAMOND "\xE2\x99\xA6"
#include "player.h"


void print_player_cards(Player *P) 
{	int m = P->money;
	std::cout << "\n";
    std::cout << std::setw(30);
    if(P->is_dealer) //condition to print whether the player is a dealer or not 
    {
        std::cout << "Dealer \n";
    }
    std::cout << std::setw(28) << "Money : $" << m << "\n";
    std::cout << std::setw(27);
	std::cout << "YOU " <<"\n";
	std::vector<int> cards = P->hole;
	std::vector<Card> playerCards; //to convert the int vector of cards to printable strings with number on the card and card suit 

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
            playerCards.push_back(x); 
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
            playerCards.push_back(x);
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
            playerCards.push_back(x);
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
            playerCards.push_back(x); 
            //card is added to the vector to be returned 

        }
        k = 0;
        x.number = " ";
        x.suit = "";

    }
	//outer loop is to iterate the number of rows
	//inner loop is to print the row content for each row
	std::cout << std::setw(20);
    for (int i = 0; i < 16; i++)
	{	if(i == 7 || i == 15 )
			std::cout << " ";
		else 	
			std::cout << "▁";
	}
	std::cout << "\n";
	for (int i = 0; i < 5; i++)
	{	std::cout << std::setw(18);
		if(i == 0)
		{	
			for(int j = 0; j < 2 ; j++)
			{
				if(playerCards[j].number.length() == 1)
					std::cout << "|" << playerCards[j].number << std::setw(5) << "|" << std::setw(2) ;
				else 
					std::cout << "|" << playerCards[j].number << std::setw(4) << "|" << std::setw(2) ;
			}
		}
		
		else if (i == 4)
		{	
			for(int j = 0; j < 2 ; j++)
			{
				if(playerCards[j].number.length() == 1)
					std::cout << "|" << std::setw(5) << playerCards[j].number  << "|" << std::setw(2) ;
				else 
					std::cout << "|" << std::setw(5) << playerCards[j].number  << "|" << std::setw(2) ;
			}
		}
			
		else if ( i == 2 )
			for(int j = 0; j < 2 ; j++)
			{
				std::cout << "|"  << std::setw(5) << playerCards[j].suit << std::setw(3) <<"|" << std::setw(2) ;
			}
			
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
	std::cout << "\n" ;
	std::cout << "\n" ;
	std::cout << "\n" ;
	std::cout << "\n" ;
}
