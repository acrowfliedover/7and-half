//Name: Rong Fan
//Project: Git/Baraja

#include <iostream>
#include <vector>
#include <fstream>
//#include <string>

using namespace std;

#ifndef HEADER_H
#define HEADER_H
class Card;//can output the card's suit and number
class Deck;//contains the full or changed deck...
class Hand;//found out much easier to have a class hand

class Card {
private:
	int count;
public:
	Card(int random);
	int get_suit();
	int get_number();
	void print();
	double get_value();
	friend class Deck;
};

class Deck {
private:
	std::vector<int> the_deck;
public:
	Deck();//default constructor
	Card draw_card();
	void reshuffle();
};
//construct a card using a number

class Hand {
private:
	vector<Card> the_hand;//can't be over 16 anyways
public:
	void push(Card c);
	double get_sum();
};
// the hand may contain many cards...

Card::Card(int random) {
	count = random;
}
//return the suit of the card
int Card::get_suit() {
	return count / 10; //this makes more sense
}
//return the number of the card
int Card::get_number() {
	return count % 10;
}
//output the card number and suit
void Card::print() {
	if (get_number() == 0) {
		std::cout << "Rey (12) of ";
	}
	else if (get_number() == 1) {
		std::cout << "As (A) of ";
	}
	else if (get_number() == 2) {
		std::cout << "Dos (2) of ";
	}
	else if (get_number() == 3) {
		std::cout << "Tres (3) of ";
	}
	else if (get_number() == 4) {
		std::cout << "Cuatro (4) of ";
	}
	else if (get_number() == 5) {
		std::cout << "Cinco (5) of ";
	}
	else if (get_number() == 6) {
		std::cout << "Seis (6) of ";
	}
	else if (get_number() == 7) {
		std::cout << "Siete (7) of ";
	}
	else if (get_number() == 8) {
		std::cout << "Sota (10) of ";
	}
	else if (get_number() == 9) {
		std::cout << "Caballo (11) of ";
	}
	if (get_suit() == 0) {
		std::cout << "Copas (Cups) ";
	}
	else if (get_suit() == 1) {
		std::cout << "Oros (Golds) ";
	}
	else if (get_suit() == 2) {
		std::cout << "Bastos (Clubs) ";
	}
	else if (get_suit() == 3) {
		std::cout << "Espadas (Swords)";
	}
	cout << endl;
}
//creates a full deck
double Card::get_value() {
	if (this->get_number() == 0 || this->get_number() >= 8) {
		return .5;
	}
	else {
		return this->get_number();
	}
}

Deck::Deck() {
	for (int i = 0; i < 40; ++i) {
		the_deck.push_back(i);
	}
}
Card Deck::draw_card() {
	int random = rand() % the_deck.size();
	Card draw(the_deck[random]);//this makes more sense
	the_deck.erase(the_deck.begin()+random);//note that now the deck has one less card so no repeat cards.
	//the erase funtion passes in a pointer
	return draw;//returns the card drawn...
}

void Deck::reshuffle() {
	the_deck.clear();
	for (int i = 0; i < 40; ++i) {
		the_deck.push_back(i);
	} //reused some code, probably not the best idea...
}

void Hand::push(Card c) {
	the_hand.push_back(c);
}
//adding a new card to the hand

double Hand::get_sum() {
	double sum = 0;
	for (int i = 0; i < the_hand.size(); ++i) {
		sum += the_hand[i].get_value();
	}
	return sum;
}
//return the sum of value in a hand

#endif

//to be honest...I don't really see the merging process...maybe I will try another time

//Visual Studio is so dumb that I have to copy and paste everything here...I guess I will start from here
