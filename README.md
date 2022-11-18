# Poker International Limited 

## Team Members 
Siddharth Yajaman (_UID: 3035666865_)\
Ishanvi Mohan (_UID: 3035756311_)

## Game Flow

You enter this game as an agent (Agent 700 - Semaj Dnob) to hack into the facility of a fraud organisation Pokr Intnationl Lmited. They have been committing crimes resulting in the genuine Poker International Limited's good name being brought down. Their facility server has four firewalls. You will have to sequentially destroy each of the four firewalls. We, at Poker International Limited, are not sure what the firewalls are but we will be sure to guide you along the way. 

**Round 1: Trial Round**
Player must identify the 5-card poker hand shown to them. A series of five 5-card hands will be shown. This round is a trial round just to give a feel to the player about what to expect as an agent. 

**Round 2: First Firewall -  The Real Game Begins** 
Player again must identify the hand shown to them. This time a series of ten 6-card hands will be shown to them. Players must identify the best 5-card hand from the 6-card hand, along with the sub-type of the hand. Player will get 1 point for each correctly identified hand. To progress further into the game, the player must have at least 6 points ie correctly identify at least 6 hands out of the 10 shown. 

**Round 3: Poker Game**
Here, the player will have to play a Poker game with a Poker AI , each starting with $200. To proceed further, the player must win this poker game against the AI bot with making at least $50 in the game. Small hint: This guy doesnt like big bets! :P

**Round 4: Next Firewall - Another Hand Identification Round**
Player again must identify the hand shown to them. This time a series of ten 7-card hands will be shown to them. Players must identify the best 5-card hand from the 7-card hand, along with the sub-type of the hand. Player will get 1 point for each correctly identified hand and lose 1 point for each wrongly identified hand. To progress further into the game and reach the next round, the player must have at least 6 points ie correctly identify at least 6 hands out of the 10 shown. 

**Round 5: The Final Round - Poker Game**
Similar to round 3, a poker game with a Poker AI will begin here. However, this time, the Poker AI bot will be advanced and intelligent and it'' be challenging to win against it! Game will start with each of you having $400. To finish and **win the game**, you must make at least $100 this round! 

Note: in this game, the Ace card is being considered as a low card.


## Description of the Poker Game -  Texas Hold 'Em Poker
Texas Hold ‘Em Poker is the most popular poker variant that can be played between 2-10 players with a standard deck of 52 cards shuffled before each deal. 
The objective is to win money by capturing the pot which contains bets made by the various players over the course of the game. Bets could be in hopes that a player has the best hand or to (sometimes ) give an impression that he holds a strong hand leading the other opponents to abandon the game. 

#### Texas Hold 'Em Poker Rules
A regular deck of 52 cards is shuffled and dealt to 2-10 people. Each player gets 2 private “hole” cards and 5 “community” cards are dealt face down on the table in the progressing rounds. This is followed by four rounds of betting:

**Round 1:**
The person dealing the cards is known as the dealer, the person to their left is called the small blind and the person to the small blinds’ left is known as the big blind. A minimum bet is set, say $20. The small blind has to place half the minimum bet, in this case $10. The big blind has to place the full minimum bet, in this case $20. After this, in order to take part further, the rest of the players (in clockwise order), including the small blind have to match the bet of $20 (known as calling). The players also have the option to not take part further in this set of betting (known as folding). Once everyone has called or folded, three of the five community cards are revealed (known as the flop). 

**Round 2:**
This round is different from the previous round in that there are no small or big blinds. In this round players have a few options; A player can check, i.e., not raise or fold, they can raise, that is bet some money (they can also bet higher than the previous bet), they can call which is to match the previous bet or they can fold. Once everyone has either called or folded, a fourth community card is revealed (known as the turn)

**Round 3:**
This round is identical to the previous round. Once everyone has either called or folded, the fifth and final community card is revealed (known as the river).

**Round 4:**
This round is identical to the previous. At the end of the betting in round 4, the remaining players have a showdown. The winner is decided based on the hand a player has. A hand is a combination of 5 cards from a player’s 2 hole cards and the 5 community cards. This can be a combination of 2 hole cards and 3 community cards, 1 hole card and 4 community cards or even all 5 community cards. The winner gets all the money bet in that set (known as the pot).

At the end of the set the dealer changes to the player to the left of the current dealer. This is to ensure fairness when it comes to the small and big blinds. The game goes on until one person has all the money. 


## Features to implement 
1. Generation of random events:
  - Card distribution to players and card distribution on table will be random. 
  - Player being the dealer will be random
  - The probability of the CPU player performing a certain action such as checking, raising, calling or folding will be random but based on the cards the given CPU player has.
  - The probability of a player taking different actions will also depend on the money they have left. 
2. Data structures for storing game status -

 ➤ Player class to store the following:
  - Player hole cards
  - Player hand
  - Player money 
  - Payer choice status ie fold, check, raise, call
  - Whether a player is a dealer or not 
  - Aount that a player raises
  - Player probability of performing actions mentioned in 1b.
 
 ➤ Community class to store the following:
  - Community cards
  - Pot money
3. Dynamic memory management:
  - Player pointers used to direct the game flow and dynamically allocate memory through linked lists
  - Vectors have been used dynamically store data types 
  - If a given player runs out of money, we deallocate the memory for that player.
4. File input/output:
  - Storyline of the game input via story.txt file.
  - Random time seeds for the card distribution and deck shuffle.
  - output text file to store game summary 
5. Program codes in multiple files:
  - A set of files to print cards and the table
  - A set of files to make combinations of cards
  - A set of files to deal cards
  - A set of files to check hand type 
  - A set of files which incorporate the game flow
  - A file for choices being made(fold, check, raise, call)
  - A set of files to implement the first part of the game wherein hands have to be identified
  - A file to clear screen after rounds
  - A Makefile to declare all the dependencies
  - A file to introduce the rule set


## Compilation and execution instructions

  #### Start your game by the command: 
  **make main**\
  **./main**

  #### Clean up the unwanted files by:
  **make clean**

  
