#include "Funktioner.h"
using namespace std;

int main()
{
	srand(time(NULL));
	int mainDeck[56];
	int player1[56] = { 0 };
	int player2[56] = { 0 };
	int tempPlayer1[56] = { 0 };
	int tempPlayer2[56] = { 0 };

	buildDeck(mainDeck);
	dealHands(mainDeck, player1, player2);
	shuffle(player1);
	shuffle(player2);
	do
	{
		krig(player1, player2, tempPlayer1, tempPlayer2);
		nextRound(player1, player2, tempPlayer1, tempPlayer2);
		shuffle(player1);
		shuffle(player2);
	} while (checkWin(player1, player2) == false);
}