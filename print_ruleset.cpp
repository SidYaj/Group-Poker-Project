/* this function prints the rule set of the game in the beginning
It doesnt take an input parameter, neither does it return*/
#include <iostream>
#include "print_ruleset.h"

void print_ruleset()
{
    std::cout << "\n";
	std::cout << "\n";
	for(int i = 0; i < 20; i++)
	{
		std::cout << "▲▼" ;
	}
	std::cout << "\n";
	std::cout << "\n";
	std::cout << "\n";
	std::cout << "  𝐏 𝐨 𝐤 𝐞 𝐫   𝐈 𝐧 𝐭 𝐞 𝐫 𝐧 𝐚 𝐭 𝐢 𝐨 𝐧 𝐚 𝐥 \n\n";
	std::cout << "             𝐋 𝐢 𝐦 𝐢 𝐭 𝐞 𝐝  \n";
	std::cout << "\n";
	std::cout << "\n";
	for(int i = 0; i < 20; i++)
	{
		std::cout << "▲▼" ;
	}
	std::cout << "\n";
	std::cout << "\n";
	std::cout << "                𝐑 𝐔 𝐋 𝐄 𝐒                ";
	std::cout << "\n";
	std::cout << "\n";
	for(int i = 0; i < 20; i++)
	{
		std::cout << "▲▼" ;
	}
	std::cout << "\n";
	std::cout << "\n";
	std::cout << "◉ Round 1: Trial Round\n\n"; 
	std::cout << "► A series of five 5-card hands is shown.\n\n";
	std::cout << "► Identify the hand type.\n\n";
	std::cout << "► Don't worry, this round is just to give\n";
	std::cout << "  you a feel of what's yet to unfold!.\n\n";
	
	std::cout << "◉ Round 2: The Real Game Begins!\n\n";
	std::cout << "► Similar to round 1 but, this time,\n";
	std::cout << "  a series of ten 6-card hands is shown. \n\n";
	std::cout << "► Identify the hand type along with a subtype\n";
	std::cout << "  of the hand. \n\n";
	std::cout << "► For each correct answer, you get 1 point.\n\n";
	std::cout << "► You need to get at least 6 point in this \n";
	std::cout << "  round in order to break the firewall \n";
	std::cout << "  and proceed further.\n\n";

	std::cout << "◉ Round 3: The Poker Game!\n\n";
	std::cout << "► A poker game with a Poker AI will begin\n";
	std::cout << "  here.\n\n";
	std::cout << "► Game will start with each of you having\n";
	std::cout << "  $200 in your money stashes\n\n";
	std::cout << "► You must make at least $50 to progress\n";
	std::cout << "  into the next round.\n\n";
	std::cout << "► Note that in this game, the Ace card is\n";
	std::cout << "  being considered as a low card.\n\n";

	std::cout << "◉ Round 4: Another firewall!\n\n";
	std::cout << "► Similar to round 2 but, this time,\n";
	std::cout << "  a series of ten 7-card hands is shown.\n\n";
	std::cout << "► Identify the hand type from six-card hand \n";
	std::cout << "  along with a subtype of the hand. \n\n";
	std::cout << "► For each correct answer, you get 1 point.\n\n";
	std::cout << "► Here, you get 1 point for one right answer\n";
	std::cout << "  and lose 1 point for every wrong answer.\n\n";
	std::cout << "► You need to get at least 6 point in this \n";
	std::cout << "  round in order to break the firewall \n";
	std::cout << "  and proceed further.\n\n";

	std::cout << "◉ Round 5: The FINAL Poker Game!\n\n";
	std::cout << "► Similar to round 3, A poker game with a \n";
	std::cout << "  Poker AI will begin here.\n\n";
	std::cout << "► However, this time, the Poker AI will be\n";
	std::cout << "  advanced and intelligent.\n\n";
	std::cout << "► Game will start with each of you having\n";
	std::cout << "  $400 in your money stashes\n\n";
	std::cout << "► To finish and win the game, you must make\n";
	std::cout << "  at least $100 this round!\n\n";
	std::cout << "► Note that in this game, the Ace card is\n";
	std::cout << "  being considered as a low card.\n\n";
	for(int i = 0; i < 20; i++)
	{
		std::cout << "▲▼" ;
	}
	std::cout << "\n";
	std::cout << "\n";
}

void hand_rules()
{
	std::cout << "\n";
	std::cout << "\n";
	for(int i = 0; i < 20; i++)
	{
		std::cout << "▲▼" ;
	}
	
	std::cout << "\n";
	std::cout << "\n";
	std::cout << "\n";
	std::cout << "          𝐏 𝐨 𝐤 𝐞 𝐫   𝐇 𝐚 𝐧 𝐝 𝐬               ";
	std::cout << "\n";
	std::cout << "\n";
	std::cout << "\n";
	for(int i = 0; i < 20; i++)
	{
		std::cout << "▲▼" ;
	}
	std::cout << "\n";
	std::cout << "\n";
	std::cout << "1. Straight Flush:\n";
	std::cout << " hand contains five cards that are of the\n";
	std::cout << " same suit and the numbers are consecutive.\n";
	std::cout << " (e.g., 3♠︎ 4♠︎ 5♠︎ 6♠︎ 7♠︎)\n\n";
	std::cout << "2. Four of a kind:\n";
	std::cout << " hand contains four cards that are all of\n";
	std::cout << " the same number.\n";
	std::cout << " (e.g., 8♠︎ 8♣︎ 8♥︎ 8♦︎)\n\n";
	std::cout << "3. Full house:\n";
	std::cout << " hand contains three cards of one number and\n";
	std::cout << " two cards of another number.\n";
	std::cout << " (e.g., A♠︎ A♣︎ A♥︎ 9♣︎ 9♦︎)\n\n";
	std::cout << "4. Flush:\n";
	std::cout << " hand contains five cards that are of\n";
	std::cout << " the same suit.\n";
	std::cout << " (e.g., 2♣︎ 4♣︎ 5♣︎ 8♣︎ K♣︎)\n\n";
	std::cout << "5. Straight:\n";
	std::cout << " hand contains five cards with consecutive\n";
	std::cout << " numbers.\n";
	std::cout << " (e.g., 7♥︎ 8♠︎ 9♦︎ 10♦︎ J♣︎)\n\n";
	std::cout << "6. Three of a kind:\n";
	std::cout << " hand contains three cards that are all of\n";
	std::cout << " the same number.\n";
	std::cout << " (e.g., Q♣︎ Q♥︎ Q♦︎)\n\n";
	std::cout << "7. Two pairs:\n";
	std::cout << " hand contains two cards of one number and\n";
	std::cout << " two cards of another number.\n\n";
	std::cout << "8. One pair:\n";
	std::cout << " hand contains two cards of one number.\n";
	std::cout << " (e.g., 3♠︎ 3♦︎)\n\n";
	std::cout << "9. High Card:\n";
	std::cout << " hand contains none of the above\n";
	std::cout << " e.g., if your hand has A♠︎ 2♣︎ 4♥︎ 6♠︎ Q♦︎, \n";
	std::cout << " then the high card is Q\n\n";
	std::cout << "Note : In this game, the Ace card will be\n";
	std::cout << "       considered as a low card.\n\n";
	std::cout << "\n";
	for(int i = 0; i < 20; i++)
	{
		std::cout << "▲▼" ;
	}
	std::cout << "\n";
	std::cout << "\n";
	std::cout << "\n";

}

void print_poker_rules()
{
	std::cout << "▶ 𝐏 𝐎 𝐊 𝐄 𝐑   𝐑 𝐔 𝐋 𝐄 𝐒\n\n";
	std::cout << "A regular deck of 52 cards is shuffled and dealt to 2 people.\nEach player gets 2 private “hole” cards and 5 “community” cards are dealt face down on the table in the progressing rounds.\nThis is followed by four rounds of betting:\n\n";
	std::cout << "𝐑 𝐨 𝐮 𝐧 𝐝 1:\n\n➤The person dealing the cards is known as the dealer, they become the small blind and their opponent is known as the big blind.\n➤A minimum bet is set, say $20.\n➤The small blind has to place half the minimum bet, in this case $10.\n➤The big blind has to place the full minimum bet, in this case $20.\n➤After this, in order to take part further, the dealer has to match the bet of $20 (known as calling). If the dealer call, their opponent has the option to raise further (known as raising).\n➤The dealer also has the option to not take part further in this set of betting (known as folding).\n➤Once both have called or folded, three of the five community cards are revealed (known as the flop).\n\n";
	std::cout << "𝐑 𝐨 𝐮 𝐧 𝐝 2:\n\n➤This round is different from the previous round in that the dealer's opponent goes first.\n➤In this round players have a few options; A player can check, i.e., not raise or fold, they can raise, that is bet some money (they can also bet higher than the previous bet), they can call which is to match the previous bet or they can fold. \n➤Once everyone has either called or folded, a fourth community card is revealed (known as the turn)\n\n";
	std::cout << "𝐑 𝐨 𝐮 𝐧 𝐝 3:\n\n➤This round is identical to the previous round. \n➤Once everyone has either called or folded, the fifth and final community card is revealed (known as the river).\n\n";

	std::cout << "𝐑 𝐨 𝐮 𝐧 𝐝 4:\n\n➤This round is identical to the previous.\n➤At the end of the betting in round 4, the remaining players have a showdown.\n➤The winner is decided based on the hand a player has.\n➤A hand is a combination of 5 cards from a player’s 2 hole cards and the 5 community cards.\n➤This can be a combination of 2 hole cards and 3 community cards, 1 hole card and 4 community cards or even all 5 community cards.\n➤The winner gets all the money bet in that set (known as the pot).\n\n";
	std::cout << "At the end of the set the dealer changes to their opponent.\nThis is to ensure fairness when it comes to the small and big blinds. The game goes on until one person has all the money (or until decided otherwise).\n\n\n";

}