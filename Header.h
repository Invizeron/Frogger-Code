//***************************************************************************
//George Turkette - Copywrite 2008  
// Any questions please email me at geoturk007@yahoo.com 
// Please do NOT claim rights or claim you wrote this program 
//  Enjoy  :D 
//****************************************************************************
//LIBRARIES


#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

using namespace std;

const int height = 18;

//frogger map
// frogger = 6, grass = 1, car = 2, water = 3, fence = 4, blank = 0, log = 7
int map[height][30] = { {4,4,4,4,0,4,4,4,4,4,0,4,4,4,4,0,4,4,4,4,4,0,4,4,4,4,0,4,4,4},
{3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3},
{3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3},
{3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3},
{3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3},
{3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3},
{3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3},
{4,4,4,4,4,4,4,4,4,4,4,4,4,0,0,0,0,4,4,4,4,4,4,4,4,4,4,4,4,4},
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0} };

//globals for map pieces
char one = 176;
char three = 219;
char four = 205;
char eight = 234;
char logg = 219;
char frogger = 1;
char carR = 35;
char carL = 35;
char menuchoice;
char restart;
int z = 666;
int sum = 0;
int sum1 = 0;
int hold = 0;
int life = 5;
int log_count = 0;
int choose = 1;
int restrict = 0;
int ChoiceNumbz = 0;
int score = 250;
int achieve1 = 0;
int achieve2 = 0;
int waste = 0;
int level = 1;
int framerate = 6250;
int levelchange = true;
bool moveb = false;

//frogger begin cordinates
int row = 17;
int column = 14;

//functions
void printmap(void);  //print map function
void color(unsigned short color); //colors
void clrscr(void); //clears screen
void carsearch(void); // moves car to the left
void gameover(void);  //game over
void printovermap(void); // game over map
void logsearch(void); //moves logs across screen
void playfrogger(void); // function to begin game
void froggermenu(int); // main menu for game
void howtoplay(void); //about game page
void closewindow(void); // closes game
void aboutfrogger(void); //about frogger page
void maximize(void); //maximize screen when game starts


//keydown
#define KEYDOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0 )
#define KEYUP(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 0 : 1 )

#define VK_LEFT0x25 // left arrow key
#define VK_UP0x26 // up arrow key
#define VK_RIGHT0x27 // right arrow key
#define VK_DOWN0x28 // down arrow key
#define VK_RETURN0x0D // enter key  // confirm
#define VK_SPACE0x20 // spacebar
#define VK_NUMPAD00x60 // Numeric keypad 0 key


int main (void) {

	//maxamize screen once game starts
	maximize();

	//keydown
	froggermenu(ChoiceNumbz); // print the title screen
	while (choose == 1) { // user wants to choose
		if (restrict == 0) { // keeps the cursor from going uber fast
			if (!KEYUP(VK_UP)) { // the up key is not up
				if (KEYDOWN(VK_UP)) { // the up key is being pressed
					ChoiceNumbz--; // decrement the choice by 1
					if (ChoiceNumbz < 0) { // if the choice becomes less than 0
						ChoiceNumbz = 3; // set the choice to 4
					}
					restrict = 1;  clrscr();  froggermenu(ChoiceNumbz); // set the restrict, clear the screen, print the new screen
				}
			}
			if (!KEYUP(VK_DOWN))
			{
				// the down key is not up
				if (KEYDOWN(VK_DOWN)) { // the down key is being pressed
					ChoiceNumbz++; // increment the choice by 1
					if (ChoiceNumbz > 3) { // if the choice becomes more than 4
						ChoiceNumbz = 0; // set the choice to 0;
					}
					restrict = 1;  clrscr();  froggermenu(ChoiceNumbz); // set the restrict, clear the screen, print the new screen
				}
			}
			else if (!KEYUP(VK_RETURN))
			{
				//code for when user picks menu item
				if (KEYDOWN(VK_RETURN))
				{
					if (ChoiceNumbz == 0) //start game when chosen
					{
						choose = 0;
						clrscr();
						playfrogger();
					}
					else if (ChoiceNumbz == 1) //goto how to play menu
					{
						choose = 1;
						clrscr();
						howtoplay();
					}
					else if (ChoiceNumbz == 2)
					{
						choose = 2;
						clrscr();
						aboutfrogger();
					}
					else if (ChoiceNumbz == 3) //quits the game function
					{
						choose = 3;
						closewindow();
					}

				}
			}

		}
		else if (restrict > 0) { // the restrict is activated
			restrict++; // increment the restriction time by 1
			if (restrict > 50000000) { // restriction time limit is reached
				restrict = 0; // let the user move the cursor again
			}
		}
		else { // an error is encountered
			cout << "ERROR!";
		}

	}

	froggermenu(ChoiceNumbz);





	return 0;
}

void
playfrogger()
{



	while (1 == 1)//continous loop
	{
		log_count++;

		//achieve2 = 1;
		map[row][column] = 6;
		moveb = false;

		if (life <= 0)
		{
			clrscr();
			break;
		}
		clrscr();
		printmap();

		//change level stuff
		levelchange = true;
		for (int i = 0; i < 30; i++)
		{
			if (map[0][i] != 4)
				levelchange = false;
		}
		if (levelchange == true)
		{
			life += 2;
			score += 150;
			map[0][4] = 0;
			map[0][10] = 0;
			map[0][15] = 0;
			map[0][21] = 0;
			map[0][26] = 0;
			level++;
			if (framerate > 1000)
				framerate -= 550;
		}

		for (int x = 1; x < framerate; x++) //framerate
			for (int y = 1; y < framerate; y++) //frame rate

				z = 666;



		//puts cars to move left at certain time intervals
		if (sum == 2)
		{
			map[13][29] = 2;
			map[13][28] = 2;
			map[13][27] = 2;
			map[10][29] = 2;
			map[10][28] = 2;
			map[10][29] = 2;
		}
		else if (sum == 10)
		{
			map[9][24] = 2;
			map[9][29] = 2;
			map[9][28] = 2;
			map[9][27] = 2;
			map[9][26] = 2;
			map[9][25] = 2;
			map[15][29] = 2;
			map[15][28] = 2;
			map[15][29] = 2;
			map[15][28] = 2;
			map[10][29] = 2;
			map[10][28] = 2;
			map[10][29] = 2;
			map[10][28] = 2;
		}
		else if (sum == 5)
		{
			map[12][29] = 2;
			map[12][28] = 2;
			map[12][27] = 2;
			map[12][26] = 2;
			map[12][25] = 2;
			map[9][29] = 2;
			map[9][28] = 2;
		}
		else if (sum == 15)
		{
			map[14][29] = 2;
			map[14][28] = 2;
			map[14][27] = 2;
			map[14][26] = 2;
			map[11][29] = 2;
			map[11][28] = 2;

		}
		else if (sum == 20)
		{
			map[15][29] = 2;
			map[15][28] = 2;
			map[15][27] = 2;
			map[15][26] = 2;
			sum = 0; //resets counter
		}

		//time intervals to put logs on the map and move them across the map
		if (sum == 5)
		{
			map[1][0] = 7;
			map[1][1] = 7;
			map[1][2] = 7;
			map[1][3] = 7;
			map[1][4] = 7;
		}
		else if (sum == 10)
		{
			map[6][29] = 7;
			map[6][28] = 7;
			map[6][27] = 7;
			map[2][29] = 7;
			map[2][28] = 7;
		}
		else if (sum == 18)
		{
			map[4][29] = 7;
			map[4][28] = 7;
			map[4][27] = 7;
			map[4][26] = 7;
			map[2][29] = 7;
		}
		else if (sum == 8)
		{
			map[3][0] = 7;
			map[3][1] = 7;
			map[3][2] = 7;
		}
		else if (sum == 13)
		{
			map[5][0] = 7;
			map[5][1] = 7;
			map[5][2] = 7;
			map[3][0] = 7;
		}

		//slows down logssss
		if (log_count >= 2)
		{
			log_count = 0;
			logsearch(); // move log
		}


		carsearch(); // move car function

		while ((!KEYDOWN(VK_RIGHT)) && (!KEYDOWN(VK_LEFT)) && (!KEYDOWN(VK_UP)) && (!KEYDOWN(VK_DOWN)) && (!KEYDOWN(VK_RETURN)))
		{
			waste++;

			if (waste >= 10)
				break;
		}

		//right
		if (!KEYUP(VK_RIGHT)) {
			if (column != 29 && moveb == false)
			{
				moveb = true;
				//collision detection for moving up into car
				if (map[row][column + 1] == 2)
				{
					map[row][column] = 0; // deletes old frogger
					row = 17; //resets row column to frogger starting spot
					column = 14;
					achieve1 = 0;
					life -= 1; //takes away a live
					hold = 0;

					map[row][column] = 6; // moves frogger to spot
				}
				//collision detection for water by moving to the right
				else if (map[row][column + 1] == 3)
				{
					map[row][column] = 0; // deletes old frogger
					row = 17; //resets row column to frogger starting spot
					column = 14;
					achieve1 = 0;
					life -= 1; //takes away a live
					hold = 0;

					map[row][column] = 6; // moves frogger to spot
				}
				else if (map[row][column + 1] == 7)
				{
					map[row][column] = 7;
					column += 1;
					map[row][column] = 6;
				}

				//move frogger right
				if (map[row][column + 1] == 1)
				{
					map[row][column] = 1;
					column += 1;
					map[row][column] = 6;
				}
				else if (map[row][column + 1] == 0)
				{
					map[row][column] = 0;
					column += 1;
					map[row][column] = 6;
				}
			}
		}
		//LEFT
		if (!KEYUP(VK_LEFT)) {
			if (column != 0 && moveb == false)
			{
				moveb = true;
				//collision detection for moving up into car
				if (map[row][column - 1] == 2)
				{
					map[row][column] = 0; // deletes old frogger
					row = 17; //resets row column to frogger starting spot
					column = 14;
					achieve1 = 0;
					life -= 1; //takes away a live
					hold = 0;
				}
				else if (map[row][column - 1] == 3)
				{
					map[row][column] = 0; // deletes old frogger
					row = 17; //resets row column to frogger starting spot
					column = 14;
					achieve1 = 0;
					life -= 1; //takes away a live
					hold = 0;

					map[row][column] = 6; // moves frogger to spot
				}

				if (map[row][column - 1] == 1)
				{
					map[row][column] = 1;
					column -= 1;
					map[row][column] = 6;
				}
				else if (map[row][column - 1] == 7)
				{
					map[row][column] = 7;
					column -= 1;
					map[row][column] = 6;
				}
				else if (map[row][column - 1] == 0)
				{
					map[row][column] = 0;
					column -= 1;
					map[row][column] = 6;
				}
			}
		}

		//DOWN
		if (!KEYUP(VK_DOWN)) {
			if (row != 17 && moveb == false)
			{
				moveb = true;
				//collision detection for moving up into car
				if (map[row + 1][column] == 2)
				{
					map[row][column] = 0; // deletes old frogger
					row = 16; //resets row column to frogger starting spot
					column = 14;
					achieve1 = 0;
					life -= 1; //takes away a live
					hold = 0;

					map[row][column] = 6; // moves frogger to spot
				}
				else
				{
					map[row][column] = hold;
					hold = map[row + 1][column];
					row++;
					map[row][column] = 6;
				}
			}
		}

		// frogger move up
		if (!KEYUP(VK_UP)) {
			if (row > 0 && moveb == false)
			{
				moveb = true;

				//collision detection for moving up into car
				if (map[row - 1][column] == 2)
				{
					map[row][column] = 0; // deletes old frogger
					row = 17; //resets row column to frogger starting spot
					column = 14;
					achieve1 = 0;
					score -= 50;
					life -= 1; //takes away a live
					hold = 0;

					map[row][column] = 6; // moves frogger to spot
				}
				//collision detection for water
				else if (map[row - 1][column] == 3)
				{
					map[row][column] = 0; // deletes old frogger
					row = 17; //resets row column to frogger starting spot
					column = 14;
					score -= 50; //takes away 50 points for losing a life
					life -= 1; //takes away a live
					hold = 0;

					map[row][column] = 6; // moves frogger to spot
				}
				else if (map[row - 1][column] == 7)
				{
					map[row][column] = hold;
					hold = map[row - 1][column];
					row--;
					map[row][column] = 6;
				}
				else if (map[row - 1][column] == 4)
				{
				}
				//move frogger UP
				else
				{
					map[row][column] = hold;
					hold = map[row - 1][column];
					row--;
					map[row][column] = 6;
				}
			}
		}

		//frogger scoring system
		if (row == 8 && achieve1 == 0)
		{
			score += 50; // if frogger makes it across traffic you get 50 points.
			achieve1 = 1;
		}

		else if (map[0][4] == 6) // if frogger makes it to a blank spot
		{
			map[row][column] = 4;
			row = 17; // resets row
			column = 14; // resets column
			life += 1; // adds one to froggers life
			score += 50; // adds points to score
			cout << "/a";
			map[row][column] = 6; // resets him to beginning
		}

		else if (map[0][10] == 6) // frogger makes it to another blank spot
		{
			map[row][column] = 4;
			row = 17; // resets row
			column = 14; // resets column
			life += 1; // adds one to froggers life
			score += 50; // adds points to score
			cout << "/a";
			map[row][column] = 6; // resets him to beginning
		}
		else if (map[0][15] == 6) // frogger makes it to another blank spot
		{
			map[row][column] = 4;
			row = 17; // resets row
			column = 14; // resets column5
			life += 1; // adds one to froggers life
			score += 50; // adds points to score
			cout << "/a";
			map[row][column] = 6; // resets him to beginning
		}
		else if (map[0][21] == 6) // frogger makes it to another blank spot
		{
			map[row][column] = 4;
			row = 17; // resets row
			column = 14; // resets column
			life += 1; // adds one to froggers life
			score += 50; // adds points to score
			cout << "/a";
			map[row][column] = 6; // resets him to beginning
		}
		else if (map[0][26] == 6) // frogger makes it to another blank spot
		{
			map[row][column] = 4;
			row = 17; // resets row
			column = 14; // resets column
			life += 1; // adds one to froggers life
			score += 50; // adds points to score
			cout << "/a";
			map[row][column] = 6; // resets him to beginning
		}


		sum += 1;
	}

	waste = 0;
}

void
aboutfrogger()
{

	clrscr();

	//title screen printing
	color(12);
	cout << "                      _________ _______  _______  _______  _______     n";
	cout << "             |     /|__   __/(  ____ )(  ____ (       )(  ____     n";
	cout << "             (    / )   ) (   | (    )|| (    /| () () || (    /    n";
	cout << "               (_) /    | |   | (____)|| (__    | || || || (__        n";
	cout << "               ) _ (     | |   |     __)|  __)   | |(_)| ||  __)       n";
	cout << "              / ( )     | |   | ( (   | (      | |   | || (          n";
	cout << "             ( /    )   | |   | )  __| (____/| )   ( || (____/    n";
	cout << "             |/     |   )_(   |/   __/(_______/|/     |(_______/    n" << flush;
	color(7);

	cout << flush;

	cout << endl;
	color(10);
	cout << "          _______  _______  _______  _______  _______  _______  _______   n";
	cout << "         (  ____ )(  ____ )(  ___  )(  ____ )(  ____) (  ____ )(  ____ )  n";
	cout << "         | (    /| (    )|| (   ) || (    /| (    /| (    /| (    )|  n";
	cout << "         | (__    | (____)|| |   | || |      | |      | (__    | (____)|  n";
	cout << "         |  __)   |     __)| |   | || | ____ | | ____ |  __)   |     __)  n";
	cout << "         | (      | ( (   | |   | || | _  )| | _  )| (      | ( (     n";
	cout << "         | )      | )  __| (___) || (___) || (___) || (____/| )  __  n";
	cout << "         |/       |/   __/(_______)(_______)(_______)(_______/|/   __/  n" << flush;
	color(7);

	cout << flush << endl;;

	cout << "                 VERSION 1.0 " << endl << endl;
	cout << "                                  ABOUT";
	for (int k = 0; k < 2; k++)
		cout << "" << endl;

	cout << " PROGRAMMER:     GEORGE TURKETTE" << endl << endl;
	cout << " PROGRAMMED FOR: PERIOD 7 PROGRAMMING CLASS" << endl << endl;
	cout << " HELP BY:        PHILIP O'BRIEN - COLLISION/MAP" << endl;
	cout << "                 ERIC KIM - MENU KEYDOWN" << endl;
	cout << "                 CJ 'JEW' STEELE - GRASS GLITCH / RIGHT LOG MOVEMENT / FENCE SUGGESTION" << endl;

	cout << " Copyright © 2008" << endl;


}

void
howtoplay()
{

	clrscr();

	//title screen printing
	color(12);
	cout << "                      _________ _______  _______  _______  _______     n";
	cout << "             |     /|__   __/(  ____ )(  ____ (       )(  ____     n";
	cout << "             (    / )   ) (   | (    )|| (    /| () () || (    /    n";
	cout << "               (_) /    | |   | (____)|| (__    | || || || (__        n";
	cout << "               ) _ (     | |   |     __)|  __)   | |(_)| ||  __)       n";
	cout << "              / ( )     | |   | ( (   | (      | |   | || (          n";
	cout << "             ( /    )   | |   | )  __| (____/| )   ( || (____/    n";
	cout << "             |/     |   )_(   |/   __/(_______/|/     |(_______/    n" << flush;
	color(7);

	cout << flush;


	cout << endl;
	color(10);
	cout << "          _______  _______  _______  _______  _______  _______  _______   n";
	cout << "         (  ____ )(  ____ )(  ___  )(  ____ )(  ____) (  ____ )(  ____ )  n";
	cout << "         | (    /| (    )|| (   ) || (    /| (    /| (    /| (    )|  n";
	cout << "         | (__    | (____)|| |   | || |      | |      | (__    | (____)|  n";
	cout << "         |  __)   |     __)| |   | || | ____ | | ____ |  __)   |     __)  n";
	cout << "         | (      | ( (   | |   | || | _  )| | _  )| (      | ( (     n";
	cout << "         | )      | )  __| (___) || (___) || (___) || (____/| )  __  n";
	cout << "         |/       |/   __/(_______)(_______)(_______)(_______/|/   __/  n" << flush;
	color(7);

	cout << flush << endl;;

	cout << "                 VERSION 1.0 " << endl << endl;
	cout << "                           HOW TO PLAY";
	for (int k = 0; k < 2; k++)
		cout << "" << endl;

	cout << " GOAL: To get frogger across the cars and logs to all six of the slots." << endl << endl;
	cout << " CONTROLS: UP    Arrow Key     - Move Frogger UP" << endl;
	cout << "           DOWN  Arrow Key     - Move Frogger DOWN" << endl;
	cout << "           RIGHT Arrow Key     - Move Frogger RIGHT" << endl;
	cout << "           LEFT  Arrow Key     - Move Frogger LEFT" << endl;
	cout << endl;
	cout << " SCORING: Once you get frogger " << frogger << " into a blank space you recieve 50 points." << endl;
	cout << "          Each time you loose a life you lose ten points. You start out " << endl;
	cout << "          with five lives. You recieve a life one you get the frogger to" << endl;
	cout << "          a blank spot. You must avoid the cars " << carR << " and reach the" << endl;
	cout << "          logs " << logg << " on the other side." << endl << endl;
	cout << "              PRESS 'UP' OR 'DOWN' ARROW KEYS TO RETURN TO MAIN MENU" << endl;


}


void
closewindow()
{
	HWND windowhandle;
	SetConsoleTitle("Program");
	windowhandle = FindWindow(NULL, "Program");
	SendMessage(windowhandle, WM_CLOSE, 0, 0);
}

void
logsearch()
{
	//even row logs to move to the left
	for (int i = 0; i < height; i++) //array
	{
		if (i == 6 || i == 4 || i == 2)
		{
			for (int j = 0; j < 30; j++)
			{
				if (map[i][j] == 7 || map[i][j] == 6) // searches for a log
				{
					if (map[i][j] == 7)
					{
						map[i][j] = 3;

						if (j != 0) //if column is not equal to 0 move log
						{
							map[i][j - 1] = 7; //moves log left
						}
					}
					else if (map[i][j] == 6) // looks for frogger
					{
						if (map[i][j + 1] != 3)
						{
							map[i][j] = 7; //future problem
						}
						else if (map[i][j + 1] == 3)
						{
							map[i][j] = 3;
						}
						if (j != 0)

						{
							column--;
						}
						else if (j > 28)
						{
							life -= 1;
							hold = 0;
						}

					}

				}
			}
		}

		//searches for odd row logs to move to the right
		if (i == 5 || i == 3 || i == 1)
		{
			for (int j = 29; j >= 0; j--)
			{
				if (map[i][j] == 7 || map[i][j] == 6) // searches for a log
				{
					if (map[i][j] == 7)
					{
						map[i][j] = 3;

						if (j != 29) //if column is not equal to 0 move log
						{
							map[i][j + 1] = 7; //moves log right
						}
					}
					else if (map[i][j] == 6) // looks for frogger to move him with the logs
					{
						map[i][j] = 7;

						if (j != 29)
						{
							column++;
						}
						else if (j < 0)
						{
							life -= 1;
							hold = 0;
						}
					}

				}
			}
		}
	}

}

//function to move cars left
void
carsearch()
{

	//2 is carR , 5 is carL

	for (int i = 0; i < height; i++) //array
	{
		for (int j = 0; j < 30; j++)
		{
			if (map[i][j] == 2) // searches for a RIGHT car
			{
				map[i][j] = 0;
				if (j != 0) //if column is not equal to 0 move car
				{

					//collision detection for moving up into car
					if (map[i][j - 1] == 6)
					{
						row = 17; //resets row column to frogger starting spot
						column = 14;
						achieve1 = 0;
						score -= 50; // takes away 50 points for hitting a car
						life -= 1; //takes away a live
						hold = 0;
						map[row][column] = 6; // moves frogger to spot
					}

					map[i][j - 1] = 2; //moves car left
				}
			}


		}
	}
}


void
printmap()
{
	//print map

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < 30; j++)
		{
			//converts number to ascii character
			if (map[i][j] == 1)
			{
				color(10);
				cout << one << flush;
				color(7);
			}
			else if (map[i][j] == 0) // blank spot
			{
				cout << " ";
			}
			else if (map[i][j] == 3) // water
			{
				color(9);
				cout << three << flush;
				color(7);
			}
			else if (map[i][j] == 4) // fence
			{
				color(6);
				cout << four << flush;
				color(7);
			}
			else if (map[i][j] == 6) // frogger
			{
				cout << frogger << flush;
			}
			else if (map[i][j] == 2) // car
			{
				color(11);
				cout << carR << flush;
				color(7);
			}
			else if (map[i][j] == 7) // log
			{
				color(22);
				cout << logg << flush;
				color(7);
			}

		}

		cout << endl;
	}

	cout << endl << endl << "Lives: " << life << "  Level: " << level << "  Score: " << score << endl;

}

//game over map
void
printovermap()
{


	//print map
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < 30; j++)
		{
			//converts number to ascii character
			if (map[i][j] == 1)
			{
				color(10);
				cout << one << flush;
				color(7);
			}
			else if (map[i][j] == 0)
				cout << " ";
			else if (map[i][j] == 3)
			{
				color(19);
				cout << three << flush;
				color(7);
			}
			else if (map[i][j] == 4)
				cout << four;
			else if (map[i][j] == 6)
			{
				frogger = 88;
				cout << frogger << flush;
			}
			else if (map[i][j] == 2)
				cout << carR << flush;
			else if (map[i][j] == 5)
				cout << carL << flush;


		}

		cout << endl;
	}

	cout << endl << endl << "Lives: " << life << endl << "GAME OVER NUB" << endl;
	cout << " PRESS 'ENTER' RETURNING TO MENU..." << endl;

	if (!KEYUP(VK_RETURN))
	{
		if (KEYDOWN(VK_RETURN))
		{
			clrscr();
			froggermenu(ChoiceNumbz);
		}
	}



}

//Body of the maximize function
void maximize(void) {
	HWND windowhandle;
	SetConsoleTitle("Program");
	windowhandle = FindWindow(NULL, "Program");
	SendMessage(windowhandle, WM_SYSKEYDOWN, VK_RETURN, 536870912);
}

//MENU
void
froggermenu(int ChoiceNumbz)
{
	clrscr();

	char gman = 3;
	char choice[4] = { ' ' };
	if (ChoiceNumbz == 0) {
		choice[0] = gman;
	}
	else if (ChoiceNumbz == 1) {
		choice[1] = gman;
	}
	else if (ChoiceNumbz == 2) {
		choice[2] = gman;
	}
	else if (ChoiceNumbz == 3) {
		choice[3] = gman;
	}
	else {//errors
		cout << "ERROR! THE FAULT OF NON POSITION HOLDING IN KEY CLUB STEVE!";
	}




	//title screen printing
	color(12);
	cout << "                      _________ _______  _______  _______  _______     n";
	cout << "             |     /|__   __/(  ____ )(  ____ (       )(  ____     n";
	cout << "             (    / )   ) (   | (    )|| (    /| () () || (    /    n";
	cout << "               (_) /    | |   | (____)|| (__    | || || || (__        n";
	cout << "               ) _ (     | |   |     __)|  __)   | |(_)| ||  __)       n";
	cout << "              / ( )     | |   | ( (   | (      | |   | || (          n";
	cout << "             ( /    )   | |   | )  __| (____/| )   ( || (____/    n";
	cout << "             |/     |   )_(   |/   __/(_______/|/     |(_______/    n" << flush;
	color(7);

	cout << flush;


	cout << endl;
	color(10);
	cout << "          _______  _______  _______  _______  _______  _______  _______   n";
	cout << "         (  ____ )(  ____ )(  ___  )(  ____ )(  ____) (  ____ )(  ____ )  n";
	cout << "         | (    /| (    )|| (   ) || (    /| (    /| (    /| (    )|  n";
	cout << "         | (__    | (____)|| |   | || |      | |      | (__    | (____)|  n";
	cout << "         |  __)   |     __)| |   | || | ____ | | ____ |  __)   |     __)  n";
	cout << "         | (      | ( (   | |   | || | _  )| | _  )| (      | ( (     n";
	cout << "         | )      | )  __| (___) || (___) || (___) || (____/| )  __  n";
	cout << "         |/       |/   __/(_______)(_______)(_______)(_______/|/   __/  n" << flush;
	color(7);

	cout << flush << endl;;

	cout << "                 VERSION 1.0 ";
	for (int k = 0; k < 2; k++)
		cout << "" << endl;


	cout << "                             " << choice[0] << " PLAY FROGGERn";
	cout << "                             " << choice[1] << " How To Playn";
	cout << "                             " << choice[2] << " Aboutn";
	cout << "                             " << choice[3] << " Exitn";

}

//game over
void
gameover()
{


	cout << "GAME OVER" << endl;


}
//color
void color(unsigned short color)
{
	HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hcon, color);
}

//clear screen
void clrscr(void)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord = { 0, 0 };
	DWORD count;

	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hStdOut, &csbi);

	FillConsoleOutputCharacter(hStdOut, ' ', csbi.dwSize.X * csbi.dwSize.Y, coord, &count);

	SetConsoleCursorPosition(hStdOut, coord);
}


//*/