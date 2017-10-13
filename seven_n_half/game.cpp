#include <iostream>
#include "card_n_deck.h"
#include <ctime>
#include <cstdlib>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;
void play_game() {
	ofstream fout;
	int game_count = 0;
	int deposit = 100;//starting cash
	string restart;
	Deck cards;
	cout << "You have " << deposit << " Pisos. \n";
	do  {
		int bet;
		game_count++;
		do  {
			cout << "How much do you want to bet?" << endl;
			cin >> bet;
		} while (bet <= 0 || bet > deposit);
		fout << "******************************************\n\n\n" << "game: "<<game_count<<endl<<"Current Deposit: " << deposit << "           bet: " << bet<<endl<<endl;
		cards.reshuffle();
		Hand host;
		Hand player;
		Card host_1 = cards.draw_card();
		host.push(host_1);
		cout << "The dealer drew a card\n";
		Card player_1 = cards.draw_card();
		player.push(player_1);
		cout << "You drew ";
		player_1.print();
		cout << "Your hand value is: " << player.get_sum() << endl;
		string input="Y";
		while (player.get_sum() <= 7.5&&(input=="Y"||input=="y")) {
			cout << "Do you want another card? (Y/N)";
			cin >> input;
			if (input== "Y" || input== "y") {
				Card player_2 = cards.draw_card();
				player.push(player_2);
				cout << "You drew ";
				player_2.print();
				cout << "Your hand value is: " << player.get_sum() << endl;
			}
		}
		if (player.get_sum() > 7.5) {
			cout << "You bust!!\n";
			deposit -= bet;
			cout << "You lost " << bet << " Pisos \n";
		}
		else {
			cout << "The dealer's first card is ";
			host_1.print();
			cout << "The dealer's hand is now " << host.get_sum() << " points \n";
			while (host.get_sum() <= 5) {
				Card host_2 = cards.draw_card();
				host.push(host_2);
				cout << "The dealer drew ";
				host_2.print();
				cout << "The dealer's hand is now " << host.get_sum() << " points \n";
			}
			if (host.get_sum() > 7.5) {
				cout << "The dealer bust!!\n";
				deposit += bet;
				cout << "You won " << bet << " Pisos \n";
			}
			else if (host.get_sum() == player.get_sum()) {
				cout << "You tied!\n" << "Your money is returned\n";
			}
			else if (host.get_sum() < player.get_sum()) {
				cout << "You beat the dealer!";
				deposit += bet;
				cout << "You earned " << bet << " Pisos \n";
			}
			else {
				cout << "The dealer beats you!";
				deposit -= bet;
				cout << "You lost " << bet << " Pisos\n";
			}
			
		}
		cout << "You have " << deposit << " Pisos. \n";
		if (deposit <= 0) {
			cout << "You have no money!\n";
		}
		else if (deposit >= 1000) {
			cout << "You are the grand winner!!!\n";
		}
		else {
			cout << "Do you want to continue?(Y/N)\n";
			cin >> restart;
		}
		fout << "Your cards: \n";
		for (int i = 0; i < player.size(); ++i) {
			fout << "\t\t";
			player.the_hand[i].print();
		}
		fout << "Your total is: \n" << player.get_sum() << endl << endl;
		fout << "The dealer's cards: \n";
		for (int i = 0; i < host.size(); ++i) {
			fout << "\t\t";
			host.the_hand[i].print();
		}
		fout << "The dealer's total is: \n" << host.get_sum() << endl << endl << endl;
	} while ((restart == "Y" || restart == "y") && deposit > 0 && deposit < 1000);
	cout << "Game Over\n";
}

int main() {
	srand((int)time(0));
	ofstream fout;
	fout.open("gamelog.txt");
	string restart = "Y";
	while (restart == "Y" || restart == "y") {
		play_game();
		cout << "Do you want to restart the game? (Y/N)\n";
		cin >> restart;
	}
	fout << "******************************************";
	fout.close();
	return 0;
}