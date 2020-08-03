#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "DoubleShuffle.h"
using namespace std;

int main() {
	srand(time(NULL));
	size_t counter = 0;
	size_t h = 0, l = 0, k = 0;
	int value = 0;
	int counter1 = 0, counter2 = 0, counter3 = 0, counterTotal = 0;

	string deck[CARDS] = {"Two", "Two", "Two", "Two", "Three", "Three", "Three", "Three", "Four", "Four", "Four", "Four", "Five", "Five", "Five", "Five", "Six", "Six", "Six", "Six", "Seven", "Seven", "Seven", "Seven", "Eight", "Eight", "Eight", "Eight", "Nine", "Nine", "Nine", "Nine",
	"Ten", "Ten", "Ten", "Ten", "Jack", "Jack", "Jack", "Jack", "Queen", "Queen", "Queen", "Queen", "King", "King", "King", "King", "Ace", "Ace", "Ace", "Ace", "Joker", "Joker", "Joker", "Joker"};
	string deck1[CARDS];
	string deck2[CARDS];
	string deck1Temp[CARDS];
	string deck2Temp[CARDS];

	// Alle de forskellige slags kort der er
	cout << "Alle slags kort:" << endl;
	for (size_t i = 0; i < CARDS; i += 4) {
		cout << deck[i] << " ";
	}

	cout << endl << endl;

	// The Double Shuffle
	DoubleShuffle(deck);

	// Lav deck1 og deck2
	for (size_t i = 0; i < 28; i++) {
		deck1[i] = deck[i];
	}

	for (size_t j = 28; j < CARDS; j++) {
		deck2[h] = deck[j];
		h++;
	}

	while (deck1[55] == "" || deck2[55] == "") {
		// Gå i krig
		for (size_t i = 0; deck1[i] != "" || deck2[i] != ""; i++) {
			value = War(deck1[i], deck2[i]);
			if (value == 1 && deck2[i] != "") {
				deck1Temp[k] = deck1[i];
				k++;
				deck1Temp[k] = deck2[i];
				k++;
				counter1++;
			}
			else if (value == 2 && deck1[i] != "") {
				deck2Temp[l] = deck2[i];
				l++;
				deck2Temp[l] = deck1[i];
				l++;
				counter2++;
			}
			else if (value == 3 && deck1[i] != "" && deck2[i] != "") {
				deck1Temp[k] = deck1[i];
				deck2Temp[l] = deck2[i];
				counter3++;
				k++;
				l++;
			}
			else if (value == 4) {
				value = 0;
				counterTotal++;
				break;
			}
			value = 0;
			counterTotal++;
		}
		cout << "Der blev lavet " << counterTotal << " moves i alt. Player 1 vandt " << counter1 << ", Player 2 vandt " << counter2 << ". " << counter3 << " stod lige." << endl << endl;

		// Saml decks efter krig
		for (size_t i = 0; i < CARDS && i < ((counter1 * 2) + counter3); i++) {
			deck1[i] = deck1Temp[i];
		}
		for (size_t i = 0; i < CARDS && i < ((counter2 * 2) + counter3); i++) {
			deck2[i] = deck2Temp[i];
		}
		for (size_t i = 0; i < CARDS; i++) {
			deck1Temp[i].clear();
		}
		for (size_t i = 0; i < CARDS; i++) {
			deck2Temp[i].clear();
		}

		// Check
		if (deck1[55] != "") {
			cout << "Player 1 vandt!!" << endl << endl;
			return 0;
		}
		else if (deck2[55] != "") {
			cout << "Player 2 vandt!!" << endl << endl;
			return 0;
		}
		else if (deck1[0] == "" || deck2[0] == "") {
			cout << "You've run out of cards" << endl << endl;
			return 0;
		}
		else {
			cout << "No winner this round" << endl << endl;
		}
		ReShuffle(deck1, counter1, counter3);
		ReShuffle(deck2, counter2, counter3);

		// Reset
		k = 0;
		l = 0;
		counter1 = 0;
		counter2 = 0;
		counter3 = 0;
		counterTotal = 0;
	}
}