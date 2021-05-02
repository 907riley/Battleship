#include "PA8.h"

/*************************************************************  
* Function: void printArray(const char arr[NUM_ROWS][NUM_COLS], int rows, int cols)                  
* Date Created: 11/20/19                             
* Date Last Modified: 11/24/19                          
* Description: Print out a 2d array.         
* Input parameters: A 2d array and the number of rows and columns it has.   
* Returns: n/a          
* Pre: The 2d should have already been filled.         
* Post: n/a     
*************************************************************/ 
void printArray(const char arr[NUM_ROWS][NUM_COLS], int rows, int cols) {
int i, j;
cout << "  0 1 2 3 4 5 6 7 8 9" << endl;
for (i = 0; i < rows; i++) 
	{
		cout << static_cast<char>(i + 65) << " ";
		for (j = 0; j < cols; j++) 
		{
			if (arr[i][j] == '*')
			{
				cout << "\033[7;91m" << arr[i][j] << "\033[0m" << "\033[7;36m \033[0m";
			}
			else if (arr[i][j] == 'm')
			{
				cout << "\033[7;97m" << arr[i][j] << "\033[0m" << "\033[7;36m \033[0m";
			}
			else 
			{
				cout << "\033[7;36m" << arr[i][j] << "\033[0m" << "\033[7;36m \033[0m";
			}
		}
	cout << endl;
	}
}

/*************************************************************  
* Function: void fillArray(char arr[NUM_ROWS][NUM_COLS], int rows, int cols)                  
* Date Created: 11/20/19                             
* Date Last Modified: 11/24/19                          
* Description: Fills a 2d array with ~.         
* Input parameters: A 2d array and the number of rows and columns it has.   
* Returns: n/a          
* Pre: The 2d should have already been intialized.         
* Post: n/a     
*************************************************************/ 
void fillArray(char arr[NUM_ROWS][NUM_COLS], int rows, int cols) 
{
	int i, j;
	// outer loop iterates over each row
	for (i = 0; i < rows; i++) 
	{// inner loop iterates over int in arr[i] (row)
		for (j = 0; j < cols; j++) 
		{
			arr[i][j] = '~';
		}
	}
}

/*************************************************************  
* Function: void randomlyPlaceSingleShip(char grid[][NUM_COLS], string shipName, char shipSymbol, int shipSize)                  
* Date Created: 11/20/19                             
* Date Last Modified: 11/24/19                          
* Description: Randomly places a ship on the board.         
* Input parameters: A 2d array, the name of the ship being placed, the symbol of the ship, and its size.   
* Returns: n/a          
* Pre: The 2d should have already been intialized and filled with ~.         
* Post: n/a     
*************************************************************/ 
void randomlyPlaceSingleShip(char grid[][NUM_COLS], string shipName, char shipSymbol, int shipSize)
{
int flag = 0;
	
	while (flag == 0)
	{
		if (rand() % 2 == 1)
		{
			//horizontal
			int startCol = rand() % (NUM_COLS - shipSize + 1);
			int startRow = rand() % 10;
		
			bool openSpace = true;
		
			for (int j = 0; j < shipSize; ++j)
			{
				if (grid[startRow][j + startCol] != '~')
				{
					openSpace = false;
					break;
				}
			}
			
			if (openSpace)
			{
				for (int j = 0; j < shipSize; ++j)
				{
					grid[startRow][j + startCol] = shipSymbol;
					flag = 1;
				}
			}
		}
		else
		{
			//vertical
			int startRow = rand() % (NUM_ROWS - shipSize + 1);
			int startCol = rand() % 10;
			
			bool openSpace = true;
			
			for (int j = 0; j < shipSize ; ++j)
			{
				if(grid[startRow + j][startCol] != '~')
				{
					openSpace = false;
					break;
				}
			}
			
			if (openSpace)
			{
				for (int j = 0; j < shipSize ; ++j)
				{	
					grid[startRow + j][startCol] = shipSymbol;
					flag = 1;
				}
			}
		}
	}
}

/*************************************************************  
* Function: void randomlyPlaceShips(char grid[][NUM_COLS])                 
* Date Created: 11/20/19                             
* Date Last Modified: 11/24/19                          
* Description: Uses the randomlyPlaceShingleShip to randomly place all 5 ships.         
* Input parameters: A 2d array.   
* Returns: n/a          
* Pre: The 2d should have already been intialized and filled with ~. It also needs the arrays with the ships names, symbols, and sizes.         
* Post: n/a     
*************************************************************/ 
void randomlyPlaceShips(char grid[][NUM_COLS]){

	for (int i = 0; i < 5; ++i)
	{
		randomlyPlaceSingleShip(grid, shipNames[i], shipSymbols[i], shipSizes[i]);
	}
}

/*************************************************************  
* Function: void welcomeScreen()             
* Date Created: 11/20/19                             
* Date Last Modified: 11/24/19                          
* Description: Outputs the welcom screern, rules, and ASCii art.        
* Input parameters: n/a   
* Returns: n/a          
* Pre: n/a         
* Post: n/a     
*************************************************************/ 
void welcomeScreen(){

	cout << "Welcome to \033[2;32mBATTLESHIP\033[0m!!!\n\n"; 
	cout << "                  _1_                                                                                                                " << endl;
	cout << "               __/\033[7;90m_o_\033[0m\\___                               _1_                                            _2_                         " << endl;
	cout << "      __    __/\033[7;90m_o__o__o__\033[0m\\___        __              __/\033[7;90m_o_\033[0m\\____    __                      __    ____/\033[7;37m_o_\033[0m\\__            _2_      " << endl;
	cout << "   _=|\033[7;90m--\033[0m|__/\033[7;90m__o__o__o__o__o__\033[0m\\______|\033[7;90m--\033[0m|=____   ____/\033[7;90m__o__o__o__\033[0m\\__|\033[7;90m--\033[0m|=___ \033[2;31m->\033[0m    \033[;31m<-\033[0m   ___=|\033[7;37m--\033[0m|__/\033[7;37m__o__o__o__\033[0m\\____    __/\033[7;37m_o_\033[0m\\__  " << endl;
	cout << "\033[1;34m~~~\033[0m\\\033[7;90m________________________________________\033[0m/\033[1;34m~~~\033[0m\\\033[7;90m_________________________\033[0m/\033[1;34m~~~~~~~~~~~~\033[0m\\\033[7;37m_________________________\033[0m/\033[1;34m~~~~\033[0m\\\033[7;37m_______\033[0m/\033[1;34m~~\033[0m" << endl;
	cout << "\033[7;94m                                                                                                                                 \033[0m" << endl;
	cout << "\033[7;94m                                                                                                                                 \033[0m" << endl;
	cout << "\033[7;94m                                                                                                                                 \033[0m" << endl;
	cout << "\033[7;94m      ______P_                                                                                                                   \033[0m" << endl;
	cout << "\033[7;94m   +-(\033[0m\033[7;90mo o o o \033[0m\033[7;94m)                                                                                      _?______                    \033[0m" << endl;
	cout << "\033[7;94m      ````````                                                                                      (\033[0m\033[7;37m o o o o\033[0m\033[7;94m)-+                 \033[0m" << endl;
	cout << "\033[7;94m                                                                                                     ````````                    \033[0m" << endl;
	cout << "\n\033[4;32mRULES\033[0m\n\n-The game of blattleship is played with two players.";
	cout << "  For this game you will be playing against the computer." << endl;
	cout << " You will be Player 1, while the computer will be Player 2." << endl;
	cout << "\n-Each player has a 10 x 10 board with 5 ships of varying sizes on them." << endl;
	cout << " You may choose to place these manually or randomly. You can only place ships vertically and horizontally." << endl;
	cout << "\n-The objective of the game is to sink all of your opponents ships before your opponent\n sinks all of yours.";
	cout << " Each turn you will get to enter two numbers, representing a coordinate on your opponents\n board.";
	cout << " If you guessed correctly and hit a ship, your version of their board will get an '*'\n in place of the '~'.";
	cout << " If you guessed incorrectly,\n your version of their board will get an 'm' representing miss.";
	cout << " You cannot guess the same position twice.\n\n-The first to sink all the opponents ships wins.";
	cout << "\n\n\033[2;32mGood Luck!\033[0m\n\n";
	
}

/*************************************************************  
* Function: bool selectWhoStartsFirst()             
* Date Created: 11/20/19                             
* Date Last Modified: 11/24/19                          
* Description: Decides who starts first by returning true or false.        
* Input parameters: n/a   
* Returns: true or false          
* Pre: n/a         
* Post: n/a     
*************************************************************/
bool selectWhoStartsFirst(){

		if (rand() % 2 == 1)
		{
			cout << "You will be going first!" << endl;
			return true;
		}
return false;
}

/*************************************************************  
* Function: void pressEnter()             
* Date Created: 11/20/19                             
* Date Last Modified: 11/24/19                          
* Description: Prompts the user to press enter to move onto the next part of the game. Also clears the terminal.        
* Input parameters: n/a   
* Returns: n/a          
* Pre: n/a         
* Post: n/a     
*************************************************************/
void pressEnter(){

	cout << "Press enter to continue" << endl;
	cin.ignore();
	
	system ("clear");
}

/*************************************************************  
* Function: void manuallyPlaceShips(char grid[][NUM_COLS])             
* Date Created: 11/20/19                             
* Date Last Modified: 11/24/19                          
* Description: Allows the user to manually place their ships where they would like.        
* Input parameters: A 2d array   
* Returns: n/a          
* Pre: The array should be filled with ~ already         
* Post: Changes the original array     
*************************************************************/
void manuallyPlaceShips(char grid[][NUM_COLS]){
	for (int i = 0; i < 5; ++i)
	{
		manuallyPlaceSingleShip(grid, shipNames[i], shipSymbols[i], shipSizes[i]);
	}	
}


/*************************************************************  
* Function: void manuallyPlaceSingleShip(char grid[][NUM_COLS], string shipName, char shipSymbol, int shipSize)            
* Date Created: 11/20/19                             
* Date Last Modified: 11/24/19                          
* Description: Allows the user to place each ship manually.        
* Input parameters: A 2d array, the name of the ship, the symbol, and the size.   
* Returns: n/a          
* Pre: Relies on manuallyPlaceShips to place all the ships. The array should be filled with ~ already.         
* Post: n/a     
*************************************************************/
void manuallyPlaceSingleShip(char grid[][NUM_COLS], string shipName, char shipSymbol, int shipSize){
	system ("clear");
	printArray(grid, NUM_ROWS, NUM_COLS);
	cout << "You're placing the " << shipName << " currently." << endl;
	
	char direction;
	cout << "Would you like to place this ship horizontally(h) or vertically(v)?" << endl;
	cin >> direction;
	
	if (direction == 'h')
	{
		int flag = 0;
		//horizontal
		while (flag == 0)
		{
			cout << "What will the first coordinate be? (Example input: A 8)" << endl;
			char startRowC;
			int startRow;
			int startCol;
			cin >> startRowC;
			cin >> startCol;
			startRow = toupper(startRowC);
			startRow = static_cast<int>(startRowC) - 65;
			
		 	if (startCol <= NUM_COLS - shipSize)
		 	{
				flag = 1;
				bool openSpace = true;
		
				for (int j = 0; j < shipSize; ++j)
				{
					if (grid[startRow][j + startCol] != '~')
					{
						cout << "There's already a ship there!" << endl;
						flag = 0;
						openSpace = false;
						break;
					}
				}	
		
				if (openSpace)
				{
					for (int j = 0; j < shipSize; ++j)
					{
						grid[startRow][j + startCol] = shipSymbol;
					}
				}
			}
			else
			{
				cout << "The ship won't fit there" << endl;
			}
		}
	}
	else
	{
		int flag = 0;
		//vertical
		while (flag == 0)
		{
			cout << "What will the first coordinate be? (Example input: A 8)" << endl;
			char startColC;
			int startRow;
			int startCol;
			cin >> startColC;
			cin >> startRow;
			startCol = static_cast<int>(startColC) - 65;
			
		 	if (startRow <= NUM_COLS - shipSize)
		 	{
				flag = 1;
				bool openSpace = true;
		
				for (int j = 0; j < shipSize ; ++j)
				{
					if(grid[startRow + j][startCol] != '~')
					{
						cout << "There's already a ship there." << endl;
						flag = 0;
						openSpace = false;
						break;
					}
				}
			
				if (openSpace)
				{
					for (int j = 0; j < shipSize ; ++j)
					{	
						grid[startRow + j][startCol] = shipSymbol;
					
					}
				}
			}
			else
			{
				cout << "The ship won't fit there." << endl;
			}
	
		}

	}
}


/*************************************************************  
* Function: bool checkShot(char grid[][NUM_COLS], int row, int col)             
* Date Created: 11/20/19                             
* Date Last Modified: 11/24/19                          
* Description: Checks to see if where the player is trying to shoot is a valid shot.     
* Input parameters: A 2d array, the row where the shot is, and the column where the shot is.   
* Returns: True or False          
* Pre: The array should already have been intialized and the shot location should already be determined.         
* Post: n/a     
*************************************************************/
bool checkShot(char grid[][NUM_COLS], int row, int col){
	
	if (grid[row][col] == 'd' || grid[row][col] == 's' || grid[row][col] == 'c' || grid[row][col] == 'b' || grid[row][col] == 'r')
	{
		return true;
	}	
return false;
}

/*************************************************************  
* Function: void randomShot(char solution[][NUM_COLS], int moves[])            
* Date Created: 11/20/19                             
* Date Last Modified: 11/24/19                          
* Description: Picks a random shot. Only really used to determine where player 2 is shooting.      
* Input parameters: A 2d array and a 1d array with the moves not used yet.   
* Returns: n/a          
* Pre: Both arrays whould have been filled already.         
* Post: n/a     
*************************************************************/
void randomShot(char solution[][NUM_COLS], int moves[], ofstream& outfile, int& p2Hits, int& p2Misses){

int flag = 0;
	while (flag == 0)
	{
		int randShot = rand() % 100;
		int row = randShot / 10;
		int col = randShot % 10;
		for (int i = 0; i < 100; ++i)
		{
			if (randShot == moves[i])
			{
				if (checkShot(solution, row, col))
				{
					solution[row][col] = '*';
					cout << "\n" << static_cast<char>(row + 65) << ", " << col << " is a hit!" << endl << endl;
					outfile << "Player 2: " << static_cast<char>(row + 65) << ", " << col << " is a hit!" << endl;
					++p2Hits;
				}else
				{
					solution[row][col] = 'm';
					cout << "\n" << static_cast<char>(row + 65) << ", " << col << " is a miss!" << endl << endl;
					outfile << "Player 2: " << static_cast<char>(row + 65) << ", " << col << " is a miss!" << endl;
					++p2Misses;				
				}
			moves[i] = -1;
			flag = 1;
			}
		} 
	}
}

/*************************************************************  
* Function: void fillMoveArrays(int moves[])             
* Date Created: 11/20/19                             
* Date Last Modified: 11/24/19                          
* Description: Fills an array with the numbers 0 - 99.        
* Input parameters: A 1d array.   
* Returns: n/a          
* Pre: The array needs to have been initialized already.         
* Post: n/a     
*************************************************************/
void fillMoveArrays(int moves[]) {

	for (int i = 0; i < 100; ++i)
	{
		moves[i] = i;
	}
}

/*************************************************************  
* Function: void pickShot(char solution[][NUM_COLS], char visible[][NUM_COLS], int moves[])
* Date Created: 11/20/19
* Date Last Modified: 11/24/19
* Description: Allows the user to pick where they would like to shoot on player 2's board.
* Input parameters: The visible and hidden arrays with player 2's information and the array with the availiable moves.
* Returns: n/a
* Pre: All arrays need to have been filled before this.
* Post: n/a
*************************************************************/
void pickShot(char solution[][NUM_COLS], char visible[][NUM_COLS], int moves[], ofstream& outfile, int& p1Hits, int& p1Misses) {
	
	int flag = 0;
	while (flag == 0)
	{
		int shot;
		int col;
		int row;
		char rowC;
		
		cout << "Enter a target: ";
		
		cin >> rowC;
		cin >> col;
		rowC = toupper(rowC);
		row = static_cast<int>(rowC) - 65;
		shot = (row * 10) + col;
		
		system("clear");
		
		cout << "\n\nPlayer 1's Turn" << endl;
		
		for (int i = 0; i < 100; ++i)
		{
			if (shot == moves[i])
			{
				if (checkShot(solution, row, col))
				{
					visible[row][col] = '*';
					cout << "\n" << rowC << ", " << col << " is a hit!" << endl << endl;
					outfile << "Player 1: " << rowC << ", " << col << " is a hit!" << endl;
					++p1Hits;
				}else
				{
					visible[row][col] = 'm';
					cout << "\n" << rowC << ", " << col << " is a miss!" << endl << endl;
					outfile << "Player 1: " << rowC << ", " << col << " is a miss!" << endl;
					++p1Misses;
				}
			moves[i] = -1;
			flag = 1;
			}
		}
		if (flag == 0)
		{
			cout << "That's not a valid coordinate." << endl;
			cin.clear();
		} 
	}
}

/*************************************************************  
* Function: bool isp2Winner(char p1solution[][NUM_COLS])
* Date Created: 11/20/19
* Date Last Modified: 11/24/19
* Description: Checks to see if player 2 has won.
* Input parameters: Player 1's board.
* Returns: True or False
* Pre: Player 1's board must have been filled before this.
* Post: n/a
*************************************************************/
bool isp2Winner(char p1solution[][NUM_COLS]) {

	int hitCount = 0;
	for (int i = 0; i < NUM_ROWS; ++i)
	{
		for (int j = 0; j < NUM_COLS; ++j)
		{
			if (p1solution[i][j] == '*')
			{
				++hitCount;
				if (hitCount == 17)
				{	
					return true;
					break;
				}
			}
		}
	}
	return false;
}

/*************************************************************  
* Function: bool isp1Winner(char p2solution[][NUM_COLS])
* Date Created: 11/20/19
* Date Last Modified: 11/24/19
* Description: Checks to see if player 1 has won.
* Input parameters: Player 2's board.
* Returns: True or False
* Pre: Player 2's board must have been filled before this.
* Post: n/a
*************************************************************/
bool isp1Winner(char p2visible[][NUM_COLS]) {

	int hitCount = 0;
	for (int i = 0; i < NUM_ROWS; ++i)
	{
		for (int j = 0; j < NUM_COLS; ++j)
		{
			if (p2visible[i][j] == '~' || p2visible[i][j] == 'm')
			{
				++hitCount;
			}
		}
	}
	
	if (hitCount == 83)
	{	
		return true;		
	}
	return false;
}

/*************************************************************  
* Function: void sunkenShip(char visible[][NUM_COLS], char solution[][NUM_COLS)
* Date Created: 11/20/19
* Date Last Modified: 11/24/19
* Description: Checks to see if a ship has been sunken and if so replaces the * with the corresponding letter of the ship
* Input parameters: The visible and hidden player 2's boards.
* Returns: n/a
* Pre: Player 2's board must have been filled before this.
* Post: n/a
*************************************************************/
void sunkenShip(char visible[][NUM_COLS], char solution[][NUM_COLS], ofstream& outfile){

	int cCount = 5;
	int rCount = 3;
	int bCount = 4;
	int sCount = 3;
	int dCount = 2;
	for (int i = 0; i < NUM_ROWS; ++i)
	{
		for (int j = 0; j < NUM_COLS; ++j)
		{
			char temp = solution[i][j];
			if (visible[i][j] == '*')
			{
				switch(temp){
					case 'r':
						--rCount;
						break;
					case 'c':
						--cCount;
						break;
					case 'b':
						--bCount;
						break;
					case 's':
						--sCount;
						break;
					case 'd':
						--dCount;
						break;
					default:
						cout << temp << endl;
						break;
				}
			}
		}
	}
	if (cCount == 0)
	{
		outfile << "Carrier sunk!" << endl;
		for (int i = 0; i < NUM_ROWS; ++i)
		{
			for (int j = 0; j < NUM_COLS; ++j)
			{
				if (solution[i][j] == 'c')
				{
					visible[i][j] = 'c';
				}
			}
		}
	}
	if (bCount == 0)
	{
		outfile << "Battleship sunk!" << endl;
		for (int i = 0; i < NUM_ROWS; ++i)
		{
			for (int j = 0; j < NUM_COLS; ++j)
			{
				if (solution[i][j] == 'b')
				{
					visible[i][j] = 'b';
				}
			}
		}
	}
	if (sCount == 0)
	{
		outfile << "Submarine sunk!" << endl;
		for (int i = 0; i < NUM_ROWS; ++i)
		{
			for (int j = 0; j < NUM_COLS; ++j)
			{
				if (solution[i][j] == 's')
				{
					visible[i][j] = 's';
				}
			}
		}
	}
	if (dCount == 0)
	{
		outfile << "Destroyer sunk!" << endl;
		for (int i = 0; i < NUM_ROWS; ++i)
		{
			for (int j = 0; j < NUM_COLS; ++j)
			{
				if (solution[i][j] == 'd')
				{
					visible[i][j] = 'd';
				}
			}
		}
	}
	if (rCount == 0)
	{
		outfile << "Cruiser sunk!" << endl;
		for (int i = 0; i < NUM_ROWS; ++i)
		{
			for (int j = 0; j < NUM_COLS; ++j)
			{
				if (solution[i][j] == 'r')
				{
					visible[i][j] = 'r';
				}
			}
		}
	}
}

/*************************************************************  
* Function: bool isp2Winner(char p1solution[][NUM_COLS])
* Date Created: 11/23/19
* Date Last Modified: 11/24/19
* Description: Prints the stats of the game to the output file after the full game had been played.
* Input parameters: n/a
* Returns: n/a
* Pre: The output file needs to have been opened.
* Post: The final statistics are put in the output file and the file closes.
*************************************************************/
void printStats(int p1Hits, int p1Misses, int p2Hits, int p2Misses, ofstream& outfile){
	outfile << "\nPlayer 1 Stats" << endl;
	outfile << "******************************" << endl;
	outfile << "Total Number of Hits: " << p1Hits << endl;
	outfile << "Total Number of Misses: " << p1Misses << endl;
	outfile << "Total Number of Shots: " << p1Hits + p1Misses << endl;
	outfile << "Hit to Miss Ratio: " << static_cast<double>(p1Hits)/(p1Hits + p1Misses) * 100 << "%" << endl;
	
	outfile << "\nPlayer 2 Stats" << endl;
	outfile << "******************************" << endl;
	outfile << "Total Number of Hits: " << p2Hits << endl;
	outfile << "Total Number of Misses: " << p2Misses << endl;
	outfile << "Total Number of Shots: " << p2Hits + p2Misses << endl;
	outfile << "Hit to Miss Ratio: " << static_cast<double>(p2Hits)/(p2Hits + p2Misses) * 100 << "%" << endl;
}
