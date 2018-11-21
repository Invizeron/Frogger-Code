//Include header with forward declared function
#include "String.h"
#include <string>

//The function (declared in the header)
void centreString(std::string inputString)
{
	//Gets the screen size of the console output and centers
	COORD ConsoleSize = GetLargestConsoleWindowSize(GetStdHandle(STD_OUTPUT_HANDLE));
	//Length is required for centering
	int length = inputString.length();
	//using console length and for loop the position is set to the center
	int position = static_cast<int>((ConsoleSize.X - length) / 2);

	for (int i = 0; i < position; i++) {
		std::cout << " ";
	}
	//Output
	std::cout << inputString;
}
//Function for font size
void fontSize(int size) {
	PCONSOLE_FONT_INFOEX lpConsoleCurrentFontEx = new CONSOLE_FONT_INFOEX();
	lpConsoleCurrentFontEx->cbSize = sizeof(CONSOLE_FONT_INFOEX);

	GetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), false, lpConsoleCurrentFontEx);
	lpConsoleCurrentFontEx->dwFontSize.X = size;
	lpConsoleCurrentFontEx->dwFontSize.Y = size;
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), false, lpConsoleCurrentFontEx);
}

//function for setting to lowercase
std::string lowerCase(std::string input) {
	for (int i = 0; i < input.length(); i++) {
		input[i] = tolower(input[i]);
	}

	return input;
}