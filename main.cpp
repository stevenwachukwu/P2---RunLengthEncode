/*Steve Nwachukwu
Data Structures and Algorithmns
Spring 2023
P2 - RunLengthEncode*/

#include <iostream> //input/output library
#include <fstream> //library for file stream
using namespace std;

int main() {
	char PriorChar; //char variable for PriorChar
	char CurrentChar; //char variable for CurrentChar
	short int RunCount = 1; //initialization and declaration of the run counter 
	ifstream FileInput ("uncompressed.txt"); //File input for "uncompressed.txt"
	ofstream FileOutput ("consoleOutput.txt"); //File output for "consoleOutput.txt"

	FileInput >> noskipws >> PriorChar; //reading the input character into PriorChar without skipping whitespace

	while (true) {
		FileInput >> noskipws >> CurrentChar; //reading the input character into CurrentChar without skipping whitespace
		if (FileInput.eof()) {
			break;
		}
		if (CurrentChar == PriorChar) {
			if (RunCount == 255) {
				cout << 0x7f << PriorChar << RunCount;
				FileOutput << 0x7f << PriorChar << RunCount;
				RunCount = 1;
			} //once the counter reaches to 255 then it will printout the triplet byte onto the console and output file
			else {
				RunCount++;
			} //else statement is used to increase the run counter
		} //if statement is used if CurrentChar is the same as PriorChar
		else {
			if (RunCount == 1 || RunCount ==  2 || RunCount == 3) {
				for (int i = 0; i < RunCount; i++) {
					cout << PriorChar;
					FileOutput << PriorChar;
				}
				RunCount = 1;
				PriorChar = CurrentChar;
			} //PriorChar gets written out n number of times depending on RunCount
			else if (RunCount >= 4) {
				cout << 0x7f << PriorChar << RunCount;
				FileOutput << 0x7f << PriorChar << RunCount;
				RunCount = 1;
				PriorChar = CurrentChar;
			} //else statement is used to write out the triplet and to reinitialize the RunCount
		} //else statement is used if CurrentChar is different from PriorChar
	} //processing loop of the program

	//The if and else if statements are used to help the RunCount when giving the right output for the program
	if (RunCount == 1 || RunCount == 2 || RunCount == 3) {
		for (int i = 0; i < RunCount; i++) {
			cout << PriorChar;
			FileOutput << PriorChar;
		}
	}
	else if (RunCount >= 4) {
		cout << 0x7f << PriorChar << RunCount;
		FileOutput << 0x7f << PriorChar << RunCount;
	}
}
