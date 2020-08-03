#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
const size_t CARDS = 56;

void DoubleShuffle(string deck[]) {
	for (size_t i = 0; i < CARDS && deck[i] != ""; i++) {
		size_t j = i + rand() / (RAND_MAX / (CARDS - i));
		string t = deck[j];
		deck[j] = deck[i];
		deck[i] = t;
	}

	for (size_t i = 0; i < CARDS && deck[i] != ""; i++) {
		size_t j = i + rand() / (RAND_MAX / (CARDS - i));
		string t = deck[j];
		deck[j] = deck[i];
		deck[i] = t;
	}
}

void ReShuffle(string deck[], int counter1, int counter2) {
	for (size_t i = 0; i < CARDS && deck[i] != ""; i++) {
		size_t j = i + rand() / (RAND_MAX / (((counter1 * 2) + counter2)-1));
		string t = deck[j];
		deck[j] = deck[i];
		deck[i] = t;
	}
}

int War(string string1, string string2) {
	cout << "Der blev spillet en " << string1 << " mod en " << string2;
	
	int value1 = 0, value2 = 0;

	if (string1 == "Joker") {
		value1 = 15;
	}
	else if (string1 == "Ace") {
		value1 = 14;
	}
	else if (string1 == "King") {
		value1 = 13;
	}
	else if (string1 == "Queen") {
		value1 = 12;
	}
	else if (string1 == "Jack") {
		value1 = 11;
	}
	else if (string1 == "Ten") {
		value1 = 10;
	}
	else if (string1 == "Nine") {
		value1 = 9;
	}
	else if (string1 == "Eight") {
		value1 = 8;
	}
	else if (string1 == "Seven") {
		value1 = 7;
	}
	else if (string1 == "Six") {
		value1 = 6;
	}
	else if (string1 == "Five") {
		value1 = 5;
	}
	else if (string1 == "Four") {
		value1 = 4;
	}
	else if (string1 == "Three") {
		value1 = 3;
	}
	else if (string1 == "Two") {
		value1 = 2;
	}
	else if (string1 == "" || string1 == " ") {
		value1 = 16;
	}
	else {
		value1 = 16;
	}

	if (string2 == "Joker") {
		value2 = 15;
	}
	else if (string2 == "Ace") {
		value2 = 14;
	}
	else if (string2 == "King") {
		value2 = 13;
	}
	else if (string2 == "Queen") {
		value2 = 12;
	}
	else if (string2 == "Jack") {
		value2 = 11;
	}
	else if (string2 == "Ten") {
		value2 = 10;
	}
	else if (string2 == "Nine") {
		value2 = 9;
	}
	else if (string2 == "Eight") {
		value2 = 8;
	}
	else if (string2 == "Seven") {
		value2 = 7;
	}
	else if (string2 == "Six") {
		value2 = 6;
	}
	else if (string2 == "Five") {
		value2 = 5;
	}
	else if (string2 == "Four") {
		value2 = 4;
	}
	else if (string2 == "Three") {
		value2 = 3;
	}
	else if (string2 == "Two") {
		value2 = 2;
	}
	else if (string2 == "" || string2 == " ") {
		value2 = 16;
	}
	else {
		value2 = 16;
	}
	
	if (value1 > value2) {
		if (value1 == 16) {
			return 4;
		}
		else if (value2 == 16) {
			return 4;
		}
		else {
			cout << " - " << string1 << " vandt!" << endl;
			return 1;
		}
	}
	else if (value2 > value1) {
		if (value1 == 16) {
			return 4;
		}
		else if (value2 == 16) {
			return 4;
		}
		else {
			cout << " - " << string2 << " vandt!" << endl;
			return 2;
		}
	}
	else if (value1 == value2) {
		if (value1 == 16) {
			return 4;
		}
		else if (value2 == 16) {
			return 4;
		}
		else {
			cout << " - " << "Der var ingen der vandt!" << endl;
			return 3;
		}
	}
	else if (value1 == 16 || value2 == 16) {
		cout << " - " << "Der er ikke noget kort her!" << endl;
		return 4;
	}
	else {
		return 0;
	}
}