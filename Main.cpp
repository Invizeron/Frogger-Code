#include "Master.h"

//Simple messages/outputs the program gives title.
const HANDLE hIn = GetStdHandle(STD_INPUT_HANDLE);
const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
COORD title;
COORD cursorPos;

//Main Menu and required bools
static bool Story = false, infinite = false, endGame = false, DLC = false;

string userInput;

#define KEY_UP 72 
#define KEY_DOWN 80 
#define KEY_LEFT 75 
#define KEY_RIGHT 77 

int direction = 1;

const char x = 11;
const char y = 12;

const char mapGrid[y][x] = {
	{ ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ', ' ',},
	{ ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ', ' ',},
	{ ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ', ' ',},
	{ ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ', ' ',},
	{ ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ', ' ',},
	{ ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ', ' ',},
	{ ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ', ' ',},
	{ ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ', ' ',},
	{ ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ', ' ',},
	{ ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ', ' ',},
	{ ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ', ' ',},
	{ ' ',' ',' ',' ',' ','0',' ',' ',' ',' ', ' ',},
};

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

void update()
{

	system("cls");
	int playerY = 0, playerX = 0;
	for (int i = 0; i < y; i++)
	{
		std::cout << "---------------------------------------------------------\n";
		for (int k = 0; k < 3; k++)
		{
			std::cout << "|";
			for (int j = 0; j < x; j++)
			{
				if (map[i][j] == '0')
				{
					playerX = j;
					playerY = i;
				}
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
						std::cout << " /-\\";
				}
				if (map[i][j] == ' ')
				{
					std::cout << "     ";
				}

			}
			std::cout << "|\n";
		}
	}
	std::cout << "---------------------------------------------------------\n";

	std::cout << "x: " << playerX << std::endl;
	std::cout << "y: " << playerY << std::endl;
	int c = 0;
	switch ((c = _getch())) {
	case KEY_UP:
		if (map[playerY - 1][playerX] == ' ')
		{
			direction = 1;
			playerY = playerY - 1;
			map[playerY][playerX] = '0';
			map[playerY + 1][playerX] = ' ';
		}
		break;
	case KEY_DOWN:
		if (map[playerY + 1][playerX] == ' ')
		{
			direction = 4;
			playerY = playerY + 1;
			map[playerY][playerX] = '0';
			map[playerY - 1][playerX] = ' ';
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
		break;
	case KEY_RIGHT:
		if (playerX < 10)
		{
			direction = 2;
			playerX = playerX + 1;
			map[playerY][playerX] = '0';
			map[playerY][playerX - 1] = ' ';
		}
		break;
	case 'q':
		endGame = true;
		break;
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
	Sleep(5650);
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
			Story = true;
			system("CLS");
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
		SetConsoleCursorPosition(hOut, cursorPos);
		//sleep and clear for formatting and output
		Sleep(20650);
		system("CLS");


		//setting font for large output
		fontSize(30);
		SetConsoleCursorPosition(hOut, title);
		centreString("To this day humans are killing slugs all over the world and using them as food in many places around the world.\nWith the slug population decreasing more rapidly than ever the slugs hoped for that one day where the king would come and save them.\nWell, today is that day, he has returned and is ready for his last and final battle.");
		SetConsoleCursorPosition(hOut, cursorPos);
		//sleep and clear for formatting and output
		Sleep(10650);
		system("CLS");


		//plays the music file defined in the other .cpp
		playMusic();


		fontSize(20);
		setMap();
		while (endGame == false)
		{
			update();
		}
	Forever:
		//plays the music file defined in the other .cpp
		playMusic();
		//Updating map
		fontSize(20);
		setMap();
		while (endGame == false)
		{
			update();
		}
	}


	return 0;
}