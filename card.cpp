/* This function accepts an integer vector of cards to data type 
Card to store the cards in the way they have to be printed instead of 
mere integers as this is in interest of the suitability of the print functions 
of the game. The function first retunrs a vector of the data type Card which has 
two string variables*/



#include <vector>
#include "card.h"
#include <string> 
#define NUMCARDS 5
#define SPADE   "\xE2\x99\xA0"
#define CLUB    "\xE2\x99\xA3"
#define HEART   "\xE2\x99\xA5"
#define DIAMOND "\xE2\x99\xA6"


std::vector<Card> card(std::vector<int> cards)
{  
    if(cards.size() == 0) 
     /*if the vector passed doesnt have any elements as is the case when the table has to be printed without 
     any cards revealed
     in this case number inside data type Card is initialised to a " " which suits the print function for community cards*/
    {
        std::vector<Card> c;
        Card x;
        x.number = " ";
        x.suit = " ";
        c.push_back(x);
        c.push_back(x);
        c.push_back(x);
        c.push_back(x);
        c.push_back(x);
        return c;
    }
    std::vector<Card> c;
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
            c.push_back(x); 
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
            c.push_back(x);
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
            c.push_back(x);
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
            c.push_back(x); 
            //card is added to the vector to be returned 

        }
        k = 0;
        x.number = " ";
        x.suit = "";

    }
    if(cards.size() == 2)
    {
        c.push_back(x);
        c.push_back(x);
        c.push_back(x);
        return c;
    }

    else if(cards.size() == 3) 
    //if number of cards to be revealed is 3, two more Cards are added to the function with number as " " which suits the print function
    {
        c.push_back(x);
        c.push_back(x);
        return c;
    }

    else if(cards.size() == 4)
    //if number of cards to be revealed is 4, one more Cards are added to the function with number as " " which suits the print function
    {
        c.push_back(x);
        return c;
    }

    else
        return c;
}