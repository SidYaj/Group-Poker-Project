combinations.o: combinations.cpp player.h community.h combinations.h
	g++ -c $<

check_hand.o: check_hand.cpp check_hand.h
	g++ -c $<

clear_screen.o: clear_screen.cpp clear_screen.h
	g++ -c $<

deal_cards.o: deal_cards.cpp deal_cards.h
	g++ -c $<

display_hand.o: display_hand.cpp display_hand.h check_hand.h
	g++ -c $<

hand_identification.o: hand_identification.cpp hand_identification.h check_hand.h deal_cards.h combinations.h print_identify_cards.h
	g++ -c $<

print_ruleset.o: print_ruleset.cpp print_ruleset.h
	g++ -c $<

main.o: main.cpp combinations.h deal_cards.h check_hand.h hand_identification.h poker_game.h print_player_cards.h print_computer_cards.h print_com_cards.h card.h print_ruleset.h poker_game_2.h
	g++ -c $<

print_com_cards.o: print_com_cards.cpp print_com_cards.h community.h
	g++ -c $<

print_computer_cards.o: print_computer_cards.cpp print_computer_cards.h player.h
	g++ -c $<

print_player_cards.o: print_player_cards.cpp print_player_cards.h player.h
	g++ -c $<

print_computer_cards_lastRound.o: print_computer_cards_lastRound.cpp print_computer_cards_lastRound.h
	g++ -c $<

print_identify_cards.o: print_identify_cards.cpp print_identify_cards.h
	g++ -c $<

card.o: card.cpp card.h
	g++ -c $<
	
poker_game.o: poker_game.cpp check_hand.h deal_cards.h combinations.h make_choice.h display_hand.h print_player_cards.h print_computer_cards.h print_com_cards.h card.h print_computer_cards_lastRound.h print_identify_cards.h clear_screen.h
	g++ -c $<

poker_game_2.o: poker_game_2.cpp check_hand.h deal_cards.h combinations.h make_choice.h display_hand.h print_player_cards.h print_computer_cards.h print_com_cards.h card.h print_computer_cards_lastRound.h print_identify_cards.h 
	g++ -c $<

is_pair.o: is_pair.cpp is_pair.h
	g++ -c $<

make_choice.o: make_choice.cpp player.h make_choice.h is_pair.h
	g++ -c $<

main: main.o combinations.o check_hand.o deal_cards.o hand_identification.o make_choice.o poker_game.o display_hand.o poker_game_2.o is_pair.o print_player_cards.o print_computer_cards.o print_com_cards.o card.o clear_screen.o print_computer_cards_lastRound.o print_identify_cards.o print_ruleset.o
	g++ $^ -o $@

clean:
	rm -f main.o deck_gen.o combinations.o check_hand.o make_choice.o call.o raise.o fold.o deal_cards.o display_hand.o deal_cards.o poker_game.o print_cards.o is_pair.o poker_game_2.o hand_identification.o print_player_cards.o print_computer_cards.o print_com_cards.o card.o clear_screen.o print_computer_cards_lastRound.o print_identify_cards.o print_ruleset.o main summary.txt

.PHONY: clean