#include <iostream>
#include <fstream>
#include "Guest.h"
#include "Theater.h"
void printMenu() {
	cout << "\nCommand Options\n"
		<< "-----------------------------------\n"
		<< "A: create new theater\n"
		<< "B: set the guests\n"
		<< "C: shift the guests\n"
		<< "D: upgrade a guest\n"
		<< "E: display the guests (sorted)\n"
		<< "?: display the menu\n"
		<< "Q: quit this program\n" << endl;
} // end of the printMenu method
int main() {
	char command;
	string input = ""; // for file name
	ifstream fin; // for reading file
	int num1, num2, num4; // for x, y inputs
	string num3;
	cout << "*** Start of Program ***" << endl;
	Theater theater;
	do {
		// ask a user to choose a command
		cout << "[Please enter a command or ?] " << endl;
		cin >> command;
		command = toupper(command);
		cin.ignore(20, '\n');
		switch (command) {
		case 'A':
			cout << "A:[create new theater]" << endl;
			theater = Theater();
			cout << theater.displayTheater() << endl;
			break;
		case 'B':
			cout << "B:[set the guests]" << endl;
			cout << "	[Type the file name]:" << endl;
			cin >> input;
			fin.open(input);
			while (!fin.eof()) {
				fin >> num1 >> num2 >> num3 >> num4;
				Guest guest = Guest(num3, num4);
				theater.updateGuest(num1, num2, guest);
			}
			fin.close();
			cout << theater.displayTheater() << endl;
			break;
		case 'C':
			char cmd;
			cout << "C:[shift the guests] " << endl;
			cout << "\t[Input the direction W,A,S, or D]:" << endl;
			cin >> cmd;
			theater.shift(cmd);
			cout << theater.displayTheater() << endl;
			break;
		case 'D':
			cout << "D:[upgrade a guest] " << endl;
			cout << "\t[Type x and y of Guest's position]:" << endl;
			cin >> num1 >> num2;
			int num5;
			cout << "    [Type x and y of position to move]:" << endl;
			cin >> num4 >> num5;
			if (theater.moveTo(num1, num2, num4, num5)) {
				cout << "*** Move was done! ***" << endl;
				cout << theater.displayTheater() << endl;
			}
			else cout << "*** Move was failed! ***" << endl;
			break;
		case 'E':
			cout << "E:[display the guests (sorted)] " << endl;
			cout << theater.displayGuests() << endl;
			break;
		case '?':
			printMenu();
			break;
		case 'Q':
			break;
		default:
			cout << "[Invalid input] " << endl;
			break;
		}
	} while (command != 'Q');
	cout << "\n ****** End of Program ******" << endl;
	return 0;
}