#include "Funktioner.h"
using namespace std;

void buildDeck(int deck[])
{
	int counter2 = 0, counter3 = 0, counter4 = 0, counter5 = 0, counter6 = 0, counter7 = 0, counter8 = 0,
		counter9 = 0, counter10 = 0, counter11 = 0, counter12 = 0, counter13 = 0, counter14 = 0, counter15 = 0;
	int i;
	for (i = 0; i < 56; i++)
	{
		deck[i] = rand() % 14 + 2;
		if (deck[i] == 2 && counter2 != 4)
		{
			counter2++;
		}
		else if (deck[i] == 3 && counter3 != 4)
		{
			counter3++;
		}
		else if (deck[i] == 4 && counter4 != 4)
		{
			counter4++;
		}
		else if (deck[i] == 5 && counter5 != 4)
		{
			counter5++;
		}
		else if (deck[i] == 6 && counter6 != 4)
		{
			counter6++;
		}
		else if (deck[i] == 7 && counter7 != 4)
		{
			counter7++;
		}
		else if (deck[i] == 8 && counter8 != 4)
		{
			counter8++;
		}
		else if (deck[i] == 9 && counter9 != 4)
		{
			counter9++;
		}
		else if (deck[i] == 10 && counter10 != 4)
		{
			counter10++;
		}
		else if (deck[i] == 11 && counter11 != 4)
		{
			counter11++;
		}
		else if (deck[i] == 12 && counter12 != 4)
		{
			counter12++;
		}
		else if (deck[i] == 13 && counter13 != 4)
		{
			counter13++;
		}
		else if (deck[i] == 14 && counter14 != 4)
		{
			counter14++;
		}
		else if (deck[i] == 15 && counter15 != 4)
		{
			counter15++;
		}
		else
		{
			i--;
		}
	}
	// cout << endl << counter2 << endl << counter3 << endl << counter4 << endl << counter5 << endl << counter6 << endl << counter7 << endl << counter8 << endl << counter9 << endl << counter10 << endl << counter11 << endl << counter12 << endl << counter13 << endl << counter14 << endl << counter15 << endl << i << endl << endl;
}

void printDeck(int deck[])
{
	cout << endl << "The deck:" << endl;
	for (int i = 0; i < 56; i++)
	{
		cout << deck[i] << endl;
	}
}

void dealHands(int deck[], int deck1[], int deck2[])
{
	int counter1 = 0, counter2 = 0;
	int i= 0, j = 0;
	for (i = 0; i < 28; i++)
	{
		deck1[i] = deck[i];
		counter1++;
	}
	for (i = 28; i < 56; i++)
	{
		deck2[j] = deck[i];
		j++;
		counter2++;
	}
}

void krig(int deck1[], int deck2[], int temp1[], int temp2[])
{
	int pointless = 0;
	int winP1 = 0, winP2 = 0, tie = 0, nothing = 0;
	int x = 0, y = 0, k = 0, l = 0;
	for (int i = 0; (k != 55) && (l != 55); i++)
	{
		if ((deck1[k] > deck2[l]) && (deck2[l] > 0))
		{
				cout << "Player 1 wins" << endl;
				temp1[x] = deck2[l];
				deck2[l] = 0;
				x++;
				k++;
				l++;
				winP1++;
		}
		else if ((deck1[k] < deck2[l]) && (deck1[k] > 0))
		{
				cout << "Player 2 wins" << endl;
				temp2[y] = deck1[k];
				deck1[k] = 0;
				y++;
				k++;
				l++;
				winP2++;
		}
		// Joker mod 2'er
		else if ((deck1[k] == 15) && (deck2[l] == 2))
		{
			cout << "Player 2 wins" << endl;
			temp2[y] = deck1[k];
			deck1[k] = 0;
			y++;
			k++;
			l++;
			winP2++;
		}
		// Joker mod 2'er
		else if ((deck2[l] == 15) && (deck1[k] == 2))
		{
			cout << "Player 1 wins" << endl;
			temp1[x] = deck2[l];
			deck2[l] = 0;
			x++;
			k++;
			l++;
			winP1++;
		}
		else if ((deck1[k] == 0) && (deck2[l] == 0))
		{
			nothing++;
			k++;
			l++;
			i--;
		}
		else if ((deck1[k] > 0) && (deck2[l] == 0))
		{
			l++;
			i--;
		}
		else if ((deck2[l] > 0) && (deck1[k] == 0))
		{
			k++;
			i--;
		}
		else if (deck1[k] == deck2[l])
		{
			cout << "It's a tie" << endl;
			tie++;
			k++;
			l++;
		}
	}
	cout << endl << "Out of cards" << endl;
	cout << "P1: " << winP1 << endl << "P2: " << winP2 << endl << "Ties: " << tie << endl << "Nothings: " << nothing << endl << endl;
}

bool checkWin(int deck1[], int deck2[])
{
	int counter1 = 0, counter2 = 0;
	for (int i = 0; i < 56; i++)
	{
		if (deck1[i] > 0)
		{
			counter1++;
		}
	}

	for (int i = 0; i < 56; i++)
	{
		if (deck2[i] > 0)
		{
			counter2++;
		}
	}

	if (counter1 > 50)
	{
		cout << "Player 1 wins!" << endl << endl;
		return true;
	}
	else if (counter2 > 50)
	{
		cout << "Player 2 wins!" << endl << endl;
		return true;
	}
	else
	{
		cout << "No winners this round" << endl << endl;
		return false;
	}
}

void nextRound(int deck1[], int deck2[], int temp1[], int temp2[])
{
	int x = 0, y = 0;
	// Player 1
	for (int i = 0; i < 56; i++)
	{
		if (temp1[x] > 0)
		{
			if (deck1[i] <= 0)
			{
				deck1[i] = temp1[x];
				x++;
			}
		}
	}
	// Player 2
	for (int i = 0; i < 56; i++)
	{
		if (temp2[y] > 0)
		{
			if (deck2[i] <= 0)
			{
				deck2[i] = temp2[y];
				y++;
			}
		}
	}
	// Reset temp decks
	for (int i = 0; i < 56; i++)
	{
		temp1[i] = 0;
	}
	for (int i = 0; i < 56; i++)
	{
		temp2[i] = 0;
	}
}

void shuffle(int deck[])
{
	for (int i = 0; i < 56; i++)
	{
		int r = i + (rand() % (56 - i));
		swap(deck[i], deck[r]);
	}
}

int counter(int deck[])
{
	int counter = 0;
	for (int i = 0; i < 56; i++)
	{
		if (deck[i] == 0)
		{
			counter++;
		}
	}
	return counter;
}