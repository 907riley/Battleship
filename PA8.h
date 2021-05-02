#ifndef PA8_H
#define PA8_H

#include <iostream>
#include <ctime>
#include <fstream>

using namespace std;

const int NUM_ROWS = 10;
const int NUM_COLS = 10;

const string shipNames[] = {"carrier", "battleship", "cruiser", "submarine", "destroyer"};
const char shipSymbols[] = {'c', 'b', 'r', 's', 'd'};
const int shipSizes[] = {5, 4, 3, 3, 2};


void fillArray(char[NUM_ROWS][NUM_COLS], int, int);
void printArray(const char[NUM_ROWS][NUM_COLS], int, int);
void randomlyPlaceSingleShip(char grid[][NUM_COLS], string shipName, char shipSymbol, int shipSize);
void randomlyPlaceShips(char grid[][NUM_COLS]);
void welcomeScreen();
bool selectWhoStartsFirst();
void pressEnter();
void manuallyPlaceShips(char grid[][NUM_COLS]);
void manuallyPlaceSingleShip(char grid[][NUM_COLS], string shipName, char shipSymbol, int shipSize);
bool checkShot(char grid[][NUM_COLS], int row, int col);
void fillMoveArrays(int moves[]);
void randomShot(char solution[][NUM_COLS], int moves[], ofstream& outfile, int& p2Hits, int& p2Misses);
void pickShot(char solution[][NUM_COLS], char visible[][NUM_COLS], int moves[], ofstream& outfile, int& p1Hits, int& p1Misses);
bool isp2Winner(char p1solution[][NUM_COLS]);
bool isp1Winner(char p2visible[][NUM_COLS]);
void sunkenShip(char visible[][NUM_COLS], char solution[][NUM_COLS], ofstream& outfile);
void printStats(int p1Hits, int p1Misses, int p2Hits, int p2Misses, ofstream& outfile);

#endif
