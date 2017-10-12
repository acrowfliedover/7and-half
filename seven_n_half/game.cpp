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
		int bet;
		do  {
			cout << "How much do you want to bet?" << endl;
			cin >> bet;
		} while (bet <= 0 || bet > deposit);
		Deck cards;
		Card host_1 = cards.draw_card();
	}
}