#include "Master.h" 
 
#include <iostream>  
#include <string>  
#include <conio.h>  
 
#define KEY_UP 72  
#define KEY_DOWN 80  
#define KEY_LEFT 75  
#define KEY_RIGHT 77  
 
const char x = 11; 
const char y = 12; 
 
bool end = false; 
 
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
				if (map[i][j] == '0' && k == 0) 
					std::cout << " \\_/ "; 
				if (map[i][j] == '0' && k == 1) 
					std::cout << " ||  "; 
				if (map[i][j] == '0' && k == 2) 
					std::cout << " \\/  "; 
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
			playerY = playerY - 1; 
			map[playerY][playerX] = '0'; 
			map[playerY + 1][playerX] = ' '; 
		} 
		break; 
	case KEY_DOWN: 
		if (map[playerY + 1][playerX] == ' ') 
		{ 
			playerY = playerY + 1; 
			map[playerY][playerX] = '0'; 
			map[playerY - 1][playerX] = ' '; 
		} 
		break; 
	case KEY_LEFT: 
		if (playerX > 0) 
		{ 
			playerX = playerX - 1; 
			map[playerY][playerX] = '0'; 
			map[playerY][playerX + 1] = ' '; 
		} 
		break; 
	case KEY_RIGHT: 
		if (playerX < 10) 
		{ 
			playerX = playerX + 1; 
			map[playerY][playerX] = '0'; 
			map[playerY][playerX - 1] = ' '; 
		} 
		break; 
	} 
 
} 
 
int main() 
{ 
	setMap(); 
	while (end == false) 
	{ 
		update(); 
	} 
	return 0; 
}