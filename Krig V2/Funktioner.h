#pragma once
#include <iostream>
#include <string>
#include <ctime>

void buildDeck(int deck[]);
void printDeck(int deck[]);
void dealHands(int deck[], int deck1[], int deck2[]);
void krig(int deck1[], int deck2[], int temp1[], int temp2[]);
bool checkWin(int deck1[], int deck2[]);
void nextRound(int deck1[], int deck2[], int temp1[], int temp2[]);
void shuffle(int deck[]);
int counter(int deck[]);
