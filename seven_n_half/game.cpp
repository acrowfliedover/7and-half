#include <iostream>
#include "card_n_deck.h"
#include <ctime>
#include <cstdlib>

using namespace std;
void play_game();//one complete game




void play_game() {
	int deposit = 1000;//starting cash
	cout << "Start Game? (Y/N)";
	while ((cin >>"Y"|| cin >> "y")&& deposit>0) {
		cout << "You have " << deposit << " Pisos. \n";
		int bet;
		do  {
			cout << "How much do you want to bet?" << endl;
			cin >> bet;
		} while (bet <= 0 || bet > deposit);
		Deck cards;
		Hand host;
		Hand player;
		Card host_1 = cards.draw_card();
		host.push(host_1);
		cout << "The dealer drew a card";
		Card player_1 = cards.draw_card();
		player.push(player_1);
		cout << "You drew ";
		player_1.print();
		while (player.get_sum() <= 7.5) {
			cout << "Your hand value is: " << player.get_sum() << endl;
			cout << "Do you want another card? (Y/N)";
			if (cin >> "Y" || cin >> "y") {
				Card player_2 = cards.draw_card();
				player.push(player_2);
				cout << "You drew ";
				player_2.print();
			}
		}
		if (player.get_sum() > 7.5) {
			cout << "You bust!!\n";
			deposit -= bet;
			cout << "You lost " << bet << " Pisos \n";
		}
		else {

		}
	}
	cout << "Game Over";
}