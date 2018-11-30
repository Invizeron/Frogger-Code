#include "Master.h"
#include <vector>
#include <conio.h>
using namespace std;

//Simple messages/outputs the program gives title.
const HANDLE hIn = GetStdHandle(STD_INPUT_HANDLE);
const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
COORD title;
COORD cursorPos;

//Main Menu and required bools
static bool Story = false, infinite = false, endGame = false, DLC = false;

// User input
string userInput;

#define KEY_UP 72 
#define KEY_DOWN 80 
#define KEY_LEFT 75 
#define KEY_RIGHT 77 

void checkLives();

// Player direction
int direction = 1;
bool alive = true;
int counter = 0;
int delay = 0;
// Player coorcinate variable
int playerY = 0, playerX = 0;
int lives = 0;

bool onLog = false;

char footX = 0;
char footY = 0;

// Grid size
const char x = 11;
const char y = 12;

/*
0 = slug
6 = right feet
9 = left feet
w = water
1 = log left
2 = slug on log
3 = long right
*/
const char mapGrid[y][x] = {
	{ ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ', ' ',},
	{ ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ', ' ',},
	{ 'w','w','w','w','1','w','w','w','w','1', '1',},
	{ ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ', ' ',},
	{ ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ', ' ',},
	{ ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ', ' ',},
	{ ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ', ' ',},
	{ ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ', ' ',},
	{ ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ', ' ',},
	{ ' ',' ',' ',' ',' ','9',' ',' ',' ','9', ' ',},
	{ ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ', ' ',},
	{ ' ',' ',' ',' ',' ','0',' ',' ',' ',' ', ' ',},
};
/*
	vector<pair<float, wstring>> Grid =
	{
		{0.0f,  L"xx..xxx..xxx..xx"}, //16 elements per lane
		{-3.0f, L"...xxxx..xxxx..x"},
		{3.0f,  L"....xxxx.....xxx"},
		{2.0f,  L"..xxx.....xxx..."},
		{0.0f,  L"................"},
		{-3.0f, L"xxx....xxx...x.."},
		{ 3.0f, L".....xx..x...x.."},
		{-4.0f, L".x......x....x.."},
		{2.0f,  L"x..x.....x...x.."},
		{0.0f,  L"................"}
	};*/

char map[y][x] = {};

void setMap() {
	system("cls");
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			map[i][j] = mapGrid[i][j];
		}
	}
}

void update(int playerY, int playerX)
{

	system("cls");

	//Loops through grid to draw
	for (int i = 0; i < y; i++)
	{
		std::cout << "---------------------------------------------------------\n";
		//Drawing the ASCII
		for (int k = 0; k < 3; k++)
		{
			std::cout << "|";
			for (int j = 0; j < x; j++)
			{
				//Set coordinate if slug in either on road or on log
				if (map[i][j] == '0')
				{
					playerX = j;
					playerY = i;
				}
				else if (map[i][j] == '2')
				{
					playerX = j;
					playerY = i;
					onLog = true;
				}

				//Slug drawing in direction
				if (direction == 1)
				{
					if (map[i][j] == '0' && k == 0)
						std::cout << " \\_/ ";
					if (map[i][j] == '0' && k == 1)
						std::cout << " ||  ";
					if (map[i][j] == '0' && k == 2)
						std::cout << " \\/  ";
				}
				else if (direction == 2)
				{
					if (map[i][j] == '0' && k == 0)
						std::cout << "     ";
					if (map[i][j] == '0' && k == 1)
						std::cout << " <=< ";
					if (map[i][j] == '0' && k == 2)
						std::cout << "     ";
				}
				else if (direction == 3)
				{
					if (map[i][j] == '0' && k == 0)
						std::cout << "     ";
					if (map[i][j] == '0' && k == 1)
						std::cout << " >=> ";
					if (map[i][j] == '0' && k == 2)
						std::cout << "     ";
				}
				else if (direction == 4)
				{
					if (map[i][j] == '0' && k == 0)
						std::cout << " /\\  ";
					if (map[i][j] == '0' && k == 1)
						std::cout << " ||  ";
					if (map[i][j] == '0' && k == 2)
						std::cout << " /-\\ ";
				}

				// Draws space
				if (map[i][j] == ' ')
				{
					std::cout << "     ";
				}

				// Draws water
				if (map[i][j] == 'w')
				{
					if (k == 0)
						std::cout << "w w  ";
					if (k == 1)
						std::cout << "  w w";
					if (k == 2)
						std::cout << "w w  ";
				}

				// Draw the log
				if (map[i][j] == '1')
				{
					if (k == 0)
						std::cout << "|-|-|";
					if (k == 1)
						std::cout << "|-|-|";
					if (k == 2)
						std::cout << "|-|-|";
					if (j > 0 && k == 2)
					{
						if (delay == 5)
						{
							map[i][j] = 'w';
							map[i][j - 1] = '1';
						}
					}
					else if (j == 0 && k == 2)
					{
						if (delay == 5)
						{
							map[i][j] = 'w';
							map[i][10] = '1';
						}
					}
				}

				// Draws the log with the slug on
				if (map[i][j] == '2')
				{
					if (direction == 1)
					{
						if (k == 0)
							std::cout << "|\\_/|";
						if (k == 1)
							std::cout << "||| |";
						if (k == 2)
							std::cout << "|\\/ |";
					}
					if (direction == 2)
					{
						if (k == 0)
							std::cout << "|\\_/|";
						if (k == 1)
							std::cout << "||| |";
						if (k == 2)
							std::cout << "|\\/ |";
					}
					if (direction == 3)
					{
						if (k == 0)
							std::cout << "|\\_/|";
						if (k == 1)
							std::cout << "||| |";
						if (k == 2)
							std::cout << "|\\/ |";
					}
					if (direction == 4)
					{
						if (k == 0)
							std::cout << "|/\\ |";
						if (k == 1)
							std::cout << "||| |";
						if (k == 2)
							std::cout << "|/-\\|";
					}
					if (j > 0 && k == 2)
					{
						if (delay == 5)
						{
							map[i][j] = 'w';
							map[i][j - 1] = '2';
						}
					}
			
					else if (j == 0 && k == 2)
					{
						if (delay == 5)
						{
							map[i][j] = 'w';
							map[i][10] = '2';
						}
					}
				}

				if (map[i][j] == '6')
				{
					if (k == 0)
					{
						std::cout << "_____";
					}
					if (k == 1)
					{
						std::cout << "|   |";
					}
					if (k == 2)
					{
						std::cout << "|___/";
					}
					if (map[i][j + 1] == '0' && k == 2)
					{
						map[i][j] = ' ';
						map[i][j + 1] = '6';
						alive = false;
						lives = lives - 1;
					}
					/*else if (j < 10 && k == 2)
					{
						map[i][j] = ' ';
						map[i][j + 1] = '6';
					}
					else if (footX == 10 && k == 2)
					
						map[i][j] = ' ';
						map[i][0] = '6';
					}*/
				}

				if (map[i][j] == '9')
				{
					if (k == 0)
					{
						std::cout << "_____";
					}
					if (k == 1)
					{
						std::cout << "|   |";
					}
					if (k == 2)
					{
						std::cout << "\\___|";
					}
					if (map[i][j - 1] == '0' && k == 2)
					{
						if (delay == 5)
						{
							map[i][j] = ' ';
							map[i][j - 1] = '9';
							alive = false;
							lives = lives - 1;
						}
					}
					else if (j > 0 && k == 2)
					{
						if (delay == 5)
						{
							map[i][j] = ' ';
							map[i][j - 1] = '9';
						}
					}
					else if (j == 0 && k == 2)
					{
						if (delay == 5)
						{
							map[i][j] = ' ';
							map[i][10] = '9';
						}
					}
				}
			}
			std::cout << "|\n";
		}
	}
	std::cout << "---------------------------------------------------------\n";

	counter++;
	delay++;
	std::cout << "x: " << playerX << std::endl;
	std::cout << "y: " << playerY << std::endl;
	std::cout << "Count: " << onLog << std::endl;
	std::cout << "Lives: " << lives << std::endl;
	int c = 0;
	if (_kbhit())
	{
		switch ((c = _getch())) {
		case KEY_UP:
			if (map[playerY - 1][playerX] == '6' || map[playerY - 1][playerX] == '9' || map[playerY - 1][playerX] == 'w')
			{
				alive = false;
				playerY = playerY - 1;
				map[playerY + 1][playerX] = ' ';
				lives = lives - 1;
				onLog = false;
			}
			else if (map[playerY - 1][playerX] == '1')
			{
				direction = 1;
				playerY = playerY - 1;
				map[playerY][playerX] = '2';
				if (onLog == true)
				{
					map[playerY + 1][playerX] = '1';
				}
				else if (onLog == false)
				{
					map[playerY + 1][playerX] = ' ';
					onLog = true;
				}
			}
			else if (map[playerY - 1][playerX] == ' ')
			{
				direction = 1;
				playerY = playerY - 1;
				map[playerY][playerX] = '0';
				if (onLog == true)
				{
					map[playerY + 1][playerX] = '1';
					onLog = false;
				}
				else if (onLog == false)
				{
					map[playerY + 1][playerX] = ' ';
				}
			}

			break;
		case KEY_DOWN:
			if (map[playerY + 1][playerX] == '6' || map[playerY + 1][playerX] == '9' || map[playerY + 1][playerX] == 'w')
			{
				alive = false;
				playerY = playerY + 1;
				map[playerY - 1][playerX] = ' ';
				lives--;
				onLog = false;
			}
			else if (map[playerY + 1][playerX] == '1')
			{
				direction = 4;
				playerY = playerY + 1;
				map[playerY][playerX] = '2';
				if (onLog == true)
				{
					map[playerY - 1][playerX] = '1';
				}
				else if (onLog == false)
				{
					map[playerY - 1][playerX] = ' ';
					onLog = true;
				}
			}
			else if (map[playerY + 1][playerX] == ' ')
			{
				direction = 4;
				playerY = playerY + 1;
				map[playerY][playerX] = '0';
				if (onLog == true)
				{
					map[playerY - 1][playerX] = '1';
					onLog = false;
				}
				else if (onLog == false)
				{
					map[playerY - 1][playerX] = ' ';
				}
			}

			break;
		case KEY_LEFT:
			if (playerX > 0)
			{
				direction = 3;
				playerX = playerX - 1;
				map[playerY][playerX] = '0';
				map[playerY][playerX + 1] = ' ';
			}
			else if (map[playerY][playerX - 1] == '6' || map[playerY][playerX - 1] == '9' || map[playerY][playerX - 1] == 'w')
			{
				alive = false;
				playerX = playerX - 1;
				map[playerY][playerX + 1] = ' ';
				lives--;
				onLog = false;
			}
			else if (map[playerY][playerX - 1] == '1')
			{
				direction = 3;
				playerX = playerX - 1;
				map[playerY][playerX] = '1';
				map[playerY][playerX + 1] = '2';
			}

			break;
		case KEY_RIGHT:
			if (map[playerY][playerX + 1] == '6' || map[playerY][playerX + 1] == '9' || map[playerY][playerX + 1] == 'w')
			{
				alive = false;
				playerX = playerX + 1;
				map[playerY][playerX - 1] = ' ';
				lives--;
				onLog = false;
			}
			else if (playerX < 10)
			{
				direction = 2;
				playerX = playerX + 1;
				map[playerY][playerX] = '0';
				map[playerY][playerX - 1] = ' ';
			}
			else if (map[playerY][playerX + 1] == '1')
			{
				direction = 3;
				playerX = playerX + 1;
				map[playerY][playerX] = '1';
				map[playerY][playerX - 1] = '2';
			}
			break;
		case 'q':
			endGame = true;
			break;
		case 'r':
			setMap();
			direction = 1;
			lives = 3;
			break;
		}
	}
	checkLives();
	if (delay == 6)
	{
		delay = 0;
	}
	//Sleep(50);
}

void checkLives()
{
	if (lives >= 1 && alive == false)
	{
		setMap();
		map[11][5] = '0';
		alive = true;
		direction = 1;
	}
	else
	{
	}
}

int main() {
	//title and typing start location
	title.X = 0;
	title.Y = 1;
	//seting the title to come out big
	SetConsoleTitle("The Slug King");
	SetConsoleTextAttribute(hOut, 6);
	//the console size
	::SendMessage(::GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);
	//setting font for large output
	fontSize(300);
	SetConsoleCursorPosition(hOut, title);
	centreString("The Slug King");
	SetConsoleCursorPosition(hOut, cursorPos);
	//sleep and clear for formatting and output
	Sleep(0);
	system("CLS");
begin:
	while (!endGame) {
	menu:
		//formatting and more output
		fontSize(30);
		cursorPos.Y = 0;
		SetConsoleCursorPosition(hOut, cursorPos);
		centreString("The Slug King\n\n");

		userInput = "";
		cursorPos.Y = 8;
		SetConsoleCursorPosition(hOut, cursorPos);

		//these will take the input of string 
		centreString("Options: (please type your choice)\n");
		centreString("- Story\n");
		centreString("- Infinite\n");
		centreString("Type \"Quit\" to quit the game");

		cursorPos.Y = 13;
		SetConsoleCursorPosition(hOut, cursorPos);
		centreString("\b\b\b");
		//gets input and sets to lowercase for the check
		getline(cin, userInput, '\n');
		userInput = lowerCase(userInput);
		//this is to amke sure proper input is given
		while (userInput != "story" && userInput != "infinite" && userInput != "dlc" && userInput != "quit") {
			centreString("Please use a valid input.");
			Sleep(1000);
			system("CLS");
			goto menu;
		}
		//sets the game mode depending on singlePlayer being true or false
		if (userInput == "story") {
			system("CLS");
			Story = true;
			goto StoryMode;
		}
		else if (userInput == "infinite") {
			system("CLS");
			infinite = true;
			goto Forever;
		}//this is used to exit the game and when the bool is true the program exits
		else if (userInput == "quit") {
			system("CLS");
			endGame = true;
			goto begin;
		}
	StoryMode:
		//Story
		//setting font for small output
		fontSize(30);
		SetConsoleCursorPosition(hOut, title);
		centreString("The long forsaken slug king who has only been talked about in bedtime stories, myths, and legends between many of the slug race.\nHe was a hero to them all, a well respected and loved figure by everyone around the world.\nThe king had a very loving and open heart and when it came to the protection of his people nothing could come in his way.\nHe fought in many great battles and wars, and achieved victory in every single one, except for one - the battle between slugs and humans.\nThis battle was very intense, and the king lost many of his best soldiers, friends and family.\nWhen the battle ended he was all alone and with over half of the slug population gone, the king fled to survive, train, prepare,\nand maybe one day find a way to beat the Humans.");
		Sleep(2500);
		centreString("\nTo this day humans are killing slugs all over the world and using them as food in many places around the world.\nWith the slug population decreasing more rapidly than ever the slugs hoped for that one day where the king would come and save them.\nWell, today is that day, he has returned and is ready for his last and final battle.");
		SetConsoleCursorPosition(hOut, cursorPos);
		//pause and clear
		//get user to type anything to continue
		system("pause");

		system("CLS");
		//plays the music file defined in the other .cpp
		playMusic();


		fontSize(20);
		setMap();
		lives = 3;
		while (endGame == false)
		{
			update(playerY, playerX);
			if (lives <= 0) {
				system("CLS");
				fontSize(100);
				SetConsoleCursorPosition(hOut, title);
				centreString("GAME OVER\n\n");
				Sleep(2500);
				system("CLS");
				goto menu;
			}
		}
	}
Forever:
	//plays the music file defined in the other .cpp
	playMusic();
	//Updating map
	fontSize(20);
	setMap();
	lives = 3;
	while (endGame == false)
	{
		update(playerY, playerX);
		if (lives <= 0) {
			system("CLS");
			fontSize(100);
			SetConsoleCursorPosition(hOut, title);
			centreString("GAME OVER\n\n");
			Sleep(2500);
			system("CLS");
			goto menu;
		}
	}

	return 0;
}