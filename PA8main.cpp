/*  Name: Riley Sikes  
	Class: CptS 121, Fall 2019  
    Date: November 24, 2019  
    Programming Assignment: PA8  
    Description: This program has the user playing the game battleship against the comptuer.
    Notes: I added battlship ASCII art for the welcome and end screens. The terminal has to have a large enough window otherwise it doesn't output correctly.
*/

#include "PA8.h"

int main() {
	
	int p1Hits = 0;
	int p2Hits = 0;
	int p1Misses = 0;
	int p2Misses = 0;
	char p1SolutionGrid[NUM_ROWS][NUM_COLS]; 
	char p2SolutionGrid[NUM_ROWS][NUM_COLS];
	char p2VisibleGrid[NUM_ROWS][NUM_COLS];
	char p1HiddenGrid[NUM_ROWS][NUM_COLS];
	int p1Moves[100] = {};
	int p2Moves[100] = {};
	int moveNum;
	char place;
	ofstream outfile;
	
	srand(time(0));
	
	//outputs rules and ascii art
	welcomeScreen();
	
	pressEnter();
	
	//fills all the arrays with ~
	fillMoveArrays(p1Moves);
	fillMoveArrays(p2Moves);
	fillArray(p1SolutionGrid, NUM_ROWS, NUM_COLS);
	fillArray(p2SolutionGrid, NUM_ROWS, NUM_COLS);
	fillArray(p2VisibleGrid, NUM_ROWS, NUM_COLS);
	fillArray(p1HiddenGrid, NUM_ROWS, NUM_COLS);
	
	outfile.open("battleship.log");
	
	cout << "Would you like to (m)annually place your ships or (r)andomly place your ships?" << endl;
	cin >> place;
	
	//allows the player to manually or randomly place their ships
	if (place == 'r')
	{
		randomlyPlaceShips(p1SolutionGrid);
	}else
	{
		manuallyPlaceShips(p1SolutionGrid);
	}
	
	//randomly place player 2's ships
	randomlyPlaceShips(p2SolutionGrid);
	
	//output the current standing of player 1's board and their view of player 2's board
	cout << "\n\n\n\n";
	cout << "__Player 1's Board:__\n" << endl;
	printArray(p1SolutionGrid, NUM_ROWS, NUM_COLS);
	cout << "\n\n__Player 2's Board:__\n" << endl;
	printArray(p2VisibleGrid, NUM_ROWS, NUM_COLS);
	cout << "\n\n";
	
	//randomly decides which player goes first
	if (selectWhoStartsFirst())
	{
		//player 1 goes first
		cin.ignore();
		pressEnter();
		moveNum = 0;
		cout << "\n\nPlayer 1's Turn" << endl;
		cout << "\n\n\n";
		cout << "___Player 1's Board___\n" << endl;
		printArray(p1SolutionGrid, NUM_ROWS, NUM_COLS);
		cout << "\n\n___Player 2's Board___\n" << endl;
		printArray(p2VisibleGrid, NUM_ROWS, NUM_COLS);
		pickShot(p2SolutionGrid, p2VisibleGrid, p1Moves, outfile, p2Hits, p2Misses);
					
		//outputs the results after player 1's turn
		cout << "___Player 1's Board___\n" << endl;
		printArray(p1SolutionGrid, NUM_ROWS, NUM_COLS);
	
		cout << "\n\n___Player 2's Board___\n" << endl;
		printArray(p2VisibleGrid, NUM_ROWS, NUM_COLS);
		cin.ignore();
		pressEnter();
	}else
	{
		//player 2 goes first
		cout << "The computer will be going first." << endl;
		cin.ignore();
		pressEnter();
		moveNum = 1;
		cout << "\n\nPlayer 2's Turn" << endl;
		randomShot(p1SolutionGrid, p2Moves, outfile, p2Hits, p2Misses);
		
		//outputs the results after player 2's turn
		cout << "__Player 1's Board:__\n" << endl;
		printArray(p1SolutionGrid, NUM_ROWS, NUM_COLS);
	
		cout << "\n\n__Player 2's Board:__\n" << endl;
		printArray(p2VisibleGrid, NUM_ROWS, NUM_COLS);
		pressEnter();
	}
	
	//the main loop that runs until their is a winner
	while (!(isp1Winner(p2VisibleGrid)) && !(isp2Winner(p1SolutionGrid)))
	{
		//alternates turns and the start is decided based on who went first
		if ((moveNum % 2) == 0)
		{
			//player 2's turn
			cout << "\n\nPlayer 2's Turn" << endl;
			randomShot(p1SolutionGrid, p2Moves, outfile, p2Hits, p2Misses);
			
			//outputs the results from player 2's turn
			cout << "___Player 1's Board___\n" << endl;
			printArray(p1SolutionGrid, NUM_ROWS, NUM_COLS);
			cout << "\n\n___Player 2's Board___\n" << endl;
			//checks to see if their is a sunken ship so the * can be changed to the corresponding letter on player 1's version of player 2's board
			sunkenShip(p2VisibleGrid, p2SolutionGrid, outfile);
			printArray(p2VisibleGrid, NUM_ROWS, NUM_COLS);
			pressEnter();
		}else
		{
			//player 1's turn
			cout << "\n\nPlayer 1's Turn" << endl;
			cout << "\n\n\n";
			//outputs player 1's board and player 2's board so player 1 can determine where they want to shoot
			cout << "___Player 1's Board___\n" << endl;
			printArray(p1SolutionGrid, NUM_ROWS, NUM_COLS);
			cout << "\n\n___Player 2's Board___\n" << endl;
			printArray(p2VisibleGrid, NUM_ROWS, NUM_COLS);
			//prompts for shot
			pickShot(p2SolutionGrid, p2VisibleGrid, p1Moves, outfile, p1Hits, p1Misses);
			
			//outputs the results from player 1's turn
			cout << "___Player 1's Board___\n" << endl;
			printArray(p1SolutionGrid, NUM_ROWS, NUM_COLS);
			cout << "\n\n___Player 2's Board___\n" << endl;
			//checks to see if their is a sunken ship so the * can be changed to the corresponding letter on player 1's version of player 2's board
			sunkenShip(p2VisibleGrid, p2SolutionGrid, outfile);
			printArray(p2VisibleGrid, NUM_ROWS, NUM_COLS);
			cin.ignore();
			pressEnter();
		}
		
		//checks to see if there is a winner
		if (isp1Winner(p2VisibleGrid))
		{
			outfile << "Player 1 won!" << endl;
			cout << "You beat Player 2! Nice job." << endl;
			cout << "                              _1_                                                                                                                " << endl;
 			cout << "                           __/\033[7;90m_o_\033[0m\\___                               _1_                                                                    " << endl;
 			cout << "                  __    __/\033[7;90m_o__o__o__\033[0m\\___        __              __/\033[7;90m_o_\033[0m\\____    __                      " << endl;
			cout << "               _=|\033[7;90m--\033[0m|__/\033[7;90m__o__o__o__o__o__\033[0m\\______|\033[7;90m--\033[0m|=____   ____/\033[7;90m__o__o__o__\033[0m\\__|\033[7;90m--\033[0m|=___     " << endl;
 			cout << "\033[1;34m~~~~~~~~~~~~~~~\033[0m\\\033[7;90m________________________________________\033[0m/\033[1;34m~~~\033[0m\\\033[7;90m_________________________\033[0m/\033[1;34m~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\033[0m" << endl;
 			cout << "\033[7;94m                                                                                                                                 \033[0m" << endl;
 			cout << "\033[7;94m                                                                                                                                 \033[0m" << endl;
 			cout << "\033[7;94m                                                                                                                                 \033[0m" << endl;
 			cout << "\033[7;94m      ______P_                                                                                                                   \033[0m" << endl;
 			cout << "\033[7;94m   +-(\033[0m\033[7;90mo o o o \033[0m\033[7;94m)                                                                                                                  \033[0m" << endl;
 			cout << "\033[7;94m      ````````                                                                                                                   \033[0m" << endl;
 			cout << "\033[7;94m                                                                                                                                 \033[0m" << endl;
		}
	
		if (isp2Winner(p1SolutionGrid))
		{
			outfile << "Player 2 won!" << endl;
			cout << "Player 2 beat you! Better luck next time." << endl;
			cout << "                                                                                                                                     " << endl;
			cout << "                                                                                                                         _2_                         " << endl;
			cout << "                                                                                                                                __    ____/\033[7;37m_o_\033[0m\\__            _2_      " << endl;
			cout << "                                                                                                                                                                                          \033[;31m<-\033[0m   ___=|\033[7;37m--\033[0m|__/\033[7;37m__o__o__o__\033[0m\\____    __/\033[7;37m_o_\033[0m\\__  " << endl;
			cout << "\033[1;34m~~~\033[0m\\\033[7;90m________________________________________\033[0m/\033[1;34m~~~\033[0m\\\033[7;90m_________________________\033[0m/\033[1;34m~~~~~~~~~~~~\033[0m\\\033[7;37m_________________________\033[0m/\033[1;34m~~~~\033[0m\\\033[7;37m_______\033[0m/\033[1;34m~~\033[0m" << endl;
			cout << "\033[7;94m                                                                                                                                 \033[0m" << endl;
			cout << "\033[7;94m                                                                                                                                 \033[0m" << endl;
			cout << "\033[7;94m                                                                                                                                 \033[0m" << endl;
			cout << "\033[7;94m      ______P_                                                                                                                   \033[0m" << endl;
			cout << "\033[7;94m   +-(\033[0m\033[7;90mo o o o \033[0m\033[7;94m)                                                                                      _?______                    \033[0m" << endl;
			cout << "\033[7;94m      ````````                                                                                      (\033[0m\033[7;37m o o o o\033[0m\033[7;94m)-+                 \033[0m" << endl;
			cout << "\033[7;94m                                                                                                     ````````                    \033[0m" << endl;		
		}
		++moveNum;
		

	}
	//prints stats final stats to the output file
	printStats(p1Hits, p1Misses, p2Hits, p2Misses, outfile);
	outfile.close();
return 0;
}

