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

void drawSlug(int) {
	std::cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNmhyooo++yhmMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << std::endl
		<< "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNdhs+osyyhhhhyo/:/smMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << std::endl
		<< "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMdssso+++++////+oyhhs:-+NMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << std::endl
		<< "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMdyys+::::-------::/+shdy/:yMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << std::endl
		<< "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNsyy+/--------------:://ohds/oMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << std::endl
		<< "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMmshs/:---.....---------::/+ohdooMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << std::endl
		<< "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMhyho:-----......-....-:+o++//+sdy+MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << std::endl
		<< "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMhsdo:------.........-/ydmmNNmys++syodNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << std::endl
		<< "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMdod+:---...--......--omNMNNNNNNNdyo+ydhsydmMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << std::endl
		<< "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNod+------.---------/yNNmdhhhhhhhhyso+omNmhyooyhdNNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << std::endl
		<< "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNhsdo-----....--:://+hhydhyyysssssssoooo++yNMNNdhysosshyddmNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << std::endl
		<< "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNy+shNy:------::/oyhddmNNdsyysoooooooooooooo++oymMMMMNNmmhysoo+ohdmMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << std::endl
		<< "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMmhs+ohNMh::---:+yhdmNNNMMMNmyosoo+++++oooooo+++++++oymMMMMMMMNNmmhs++++hmMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << std::endl
		<< "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNmh++ohmNMMh:---::/+syhddddmmddho+soo+ssyo--/oyso+++++++++sdNMMMMMMMmhysso+//+:mMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << std::endl
		<< "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMmdhs+++ymNMMMNy:---::/+++++++yyhhsyh+/sy/-yhhy:-:/soo++////////+ohNMMNms//+ooosy+/:+mMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << std::endl
		<< "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMmyy//:/oydNNMMMMNs:---:::/+oo-.`/ydhs:sy///oo/ooo+//+/////////////////+ymNs//ooooooodh+//yMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << std::endl
		<< "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMd/:--:ohdNNMMMMMMm+----:::://++::::o+o+++/::::::://///////////////////+++++shy+osoooo+ymds/:oNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << std::endl
		<< "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMd/-::+sdNNMMMMMMMNh/------::::::::::::::::::::::::::::::://////:://///////+++++oyyoooooo+NNdy/-yMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << std::endl
		<< "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMm/.-:+sddhyhdNMMMMmo:-----::::::::::::::--------::::::::::::://////////////++++/+++ossooo+/mMNmy//NMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << std::endl
		<< "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMm-.-/oddo+//-:+hNMh/---:-::::::::::-::------------:::::::::::///+++++/+++///+++++++++++so+++NNNNms:oMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << std::endl
		<< "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMm-.:+ymNo+////:-oms:-:::::::--------::----------------:::::::////++oo+++++++++++++++++++++++dMNNNMm+.NMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << std::endl
		<< "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMm-.:ohmNm////+o:od+:::::::::---:::::::-----------------::::::////+++ossooooo+++++++++++++++++ymMNNNMh.sMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << std::endl
		<< "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMN:`:+hmNMd://++/sy:::::::::::::::::///::::----------:::::::////++++oooyyyyyssssoo+++++++++++++++yNMNNN/NMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << std::endl
		<< "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNs.:ymNMMm::///so:::::::::::::::///++/:::::::::::::::::://///++++oooosNNNNmmmmddhysoo+++////+++++odNNMsMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << std::endl
		<< "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMy-odNMMMMo-:/o/:::::::::::////+++ooo//::::::::///////////+++oooosssymMMNNNNNNmmmmmdyso+++///+/+++/yNNsMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << std::endl
		<< "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM+-ymMMMMNmo:::::-::::::://++osyyhhdho//////////////++++++ooooosssyhNMMMMNMNNNNNNmNmmdyso+//////+++/od/MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << std::endl
		<< "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM+:dMMMNNNMNo::::::::://+oshdmmNMMMNNms+++++++++++++++ooooossssyyhmMMMMMMMMMNMMNNNNNNNmdy++/////++++++.dMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << std::endl
		<< "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM+:mNMNNNNNo-:-::::://+oydmmNNMMMMMNNNNhsoooooooooooooosssssyydmNMMMMMMMMMMMNMMMMNNNNNNmds++/////+++++/+MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << std::endl
		<< "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM+-mMMNNNm+-:::::::/+oydmmNNNNMMNMNNNMNMNmdyyysssssssyyyhdmmNMMMMMMMMMMMMNMMMMMMMNNNNNNNmso++/////+++++/hMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << std::endl
		<< "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNomMMNNm/--:-::::/+ydmmmNNNNNNMNNNNNNNNNNMMMNNNNNNNNNMMMMMMMMMMMMMMMMMMNMMNMNNMMMMNNNNNmyo++/////++++++:oMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << std::endl
		<< "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMmyNMNm:--::::::/oymmmNmNNNNNNNNNNNNNMNNMNNNMNNNMMMMMNMNMMMMMMMMMMMMMMMMMMMMMNMMMMMNNNNNyo++/////+++++++:+NMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << std::endl
		<< "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM+dMm:---:::::/ohmmNNNNNNMNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNmmmmNmmNNNMMMMMMMMMMMMMMMNNNNNmyo++////+++++oo++/:+yhydmMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << std::endl
		<< "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMN/h/----:::::+ymmNNNNNNNNNNNNNNNNmNNNmmmmdddddmmmddddddddddmmNNMMMMMMMMMMMMMMMMNNNNNNdso+++//++++ooooo++++hmmdyoyhMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << std::endl
		<< "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMo------::::/odmmmNNNNNNNNNNMNNNNmmdddhdyssooooso+++//++oooshmmNMMMNNNMMMMMMMMMNNMMNmhso++++++++oooooooooooyNNdhhsodNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << std::endl
		<< "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMN-::----::::/ommmNNNNNNNNNNMMMMMNmmy+/:/---..--::-------::/+shdmmdddmNMMMMMMMMMNMNNmdyo+++//++++oooooossssssydhhhhhy+sNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << std::endl
		<< "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM+::::-::::::/ommmNNNNNNNNNNNNMMNdso--..-``````./....-:://+osyyyyyyyhdNMMMMMMMMMNNNmdys++++/+++ooooossssyysyyhhhhhhhhhy+sNMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << std::endl
		<< "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMs::::::::::::/omNmNNNNMNNmddhyyyhyso::-----::::/+/+++oooooooooooooshdNNMMMMMMMMNNmmdys++////+++oooossssyyyhhhhhhhhhhhhhhy+oNMMMMMMMMMMMMMMMMMMMMMMMMMMM" << std::endl
		<< "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMd-::::::::::::/ohNNNNMMMNmdhyo+//::////:/::::://////////////////+osydNMMMMMMMMNNmmdhso++//+++++ooooossyyyhhhhhhhhhhhhhhhhhhyohMMMMMMMMMMMMMMMMMMMMMMMMMM" << std::endl
		<< "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMm/:::::::::::::/+sdNNNMMMNmhs+/::::-------------:::::::::::::///+oydNMMMMMMNNNNmdhyso+++//+++++oooossyyhyhhhhhhhhhhhhhhhhhhhhhooNMMMMMMMMMMMMMMMMMMMMMMMM" << std::endl
		<< "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMmhyss/-::::::::::::::/ohmNNMMMNdyo/:-------------------------:::/+oshdNNMMMMMMNNmmdhysoo++///++++++oossyyhhhhhhhhhhhhhhhhhhhhhhhhhhhy+NMMMMMMMMMMMMMMMMMMMMMMM" << std::endl
		<< "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNhhsssyyhy/::::::::::::::::/oydNMMMMNdyo/:::------------------:::/+oshmNNNNNNNNNNNNmmdhysoo+++/////+++osyyyhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh:MMMMMMMMMMMMMMMMMMMMMMM" << std::endl
		<< "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNdysssyhhhhddh/:::::::::::---::::/+shNMNMNNmdhhys+///::-------:://+osyhmmNNNNmmmmmmmmdddhyyso+++//////+osyyyhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhsssmMMMMMMMMMMMMMMMMMMMMMMM" << std::endl
		<< "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNdhsssyhhhhhhdmmy:::::::::::-------:::/+odmmNNNmNmmmddhhhhysoossyyyhddmmNNmmmddddddddddhyyssooo++/////+osyyyhhhhhhhhhhhhhhhhhhhhhhhhhhhhddddmmmmmohNMMMMMMMMMMMMMMMMMMMMMMMM" << std::endl
		<< "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMmyoosyyhhhhhhddmmho:::::::::::::--------:::/+ossysossyyddmmmmmddmmmmdmmdddddhhhhhhhhhhyyysooo+++/////+osyyyhhhhhhhhhhhhhhhhhhhhhhhhhdddmmmmmmmmddddddy+oMMMMMMMMMMMMMMMMMMMMMMM" << std::endl
		<< "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNdoossyyhhhhhhddmNyoo::::::::::::::----------::::///::::://+ooosssyhyyyyyyyyyyyyyyyyysssoooo+++/////+osyyyhhhhhhhhhhhhhhhhhhhhhhhhhddmmmmdddddhhhhhhhhhhhho+hMMMMMMMMMMMMMMMMMMMMM" << std::endl
		<< "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMNmyosssyyyhhhhhhhdmmhoos/:::::::::::----------------:::::::::///+++oooossssssssssssoooooo+++++///////+syyyyyhyhhhhhhhhhhhhhhhhhhhhddmmmddhhhhhhhhhhhhhhhhhhhhhhyo+hNMMMMMMMMMMMMMMMMMM" << std::endl
		<< "MMMMMMMMMMMMMMMMMMMMMMMMMMNdsooosyyyyhhhhhhhdmNmso:oo::---------------------------------::::////+++++++++++++++++//////////::/+syyyyyyyyyyhhhhhhyhhhhhhhhhddmmmddhhhhhhhhhhhhhhhhhhhhhhhhhhhhhyo+dMMMMMMMMMMMMMMMMM" << std::endl
		<< "MMMMMMMMMMMMMMMMMMMMMMMmhsosssssyyhhhhhhhhdmNNy+o/+o/:--------------------------------------:::::::::::::///////::::::::::+osyyyyyyyyyyyyyyhhhhhyhhhhhdmmmddhhhhyyyyyyyyhhhhhhhhhhhhhhhhhhhhhhhhyyshmMMMMMMMMMMMMMM" << std::endl
		<< "MMMMMMMMMMMMMMMMMMMMdyooossssyyyyhhhhhhhdmNNmh+/o:o/:--------------------------------------------:::::::::::::::::::::/+syyyyyyyyyyyyyyyyyyyyyhhhddmmddhhhhyyyyyyyyyyyyyyyyyyyyyyhhhhhhhhhhhhhhhhhhysodmMMMMMMMMMMM" << std::endl
		<< "MMMMMMMMMMMMMMMNNmhsoosssssyyyhhhhhhhhdmNmhs+:/+//+::-------------------------------------------------------------:/osyyyyyyyyyyyyyyyyyyyyhhhddmddhhhyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyhhhhhhhhhhhhhhhhyssdmMMMMMMMM" << std::endl
		<< "MMMMMMNmmmhdyso+++ossssssyyhhhhhhhhhdmmdyo/:/+/+:+/:----------------------------------------------------------:/+syyyyyyyyyyyyyyyyyyyyhhhdddddhhyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyhhhhhhhhhhhhhhhhhhysyhNMMMMM" << std::endl
		<< "hyysoosoosooossssssssssyyyhhhhhhhhdmmdy+/:--:+/o://:------------------------------------------------------:/+osyyyyyyyyyyyyyyyyyyyyhhddmddhhyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyhyhhhhhhhhhhhhhhhhhhyosdNMM" << std::endl
		<< "sssssssssssssssyyssssyyyhhhhhhhhddmdy+/:----/:-o:+/:-------------------------------------------------://:oyyyyyyyyyyyyyyyyyyyyyhhddmddhyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyhhhhhhhhhhddhhhhhhhyo+hN" << std::endl;

}
