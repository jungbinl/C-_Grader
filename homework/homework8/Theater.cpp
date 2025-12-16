#include "Theater.h"
#include "Guest.h"
#include <string>

Theater::Theater() {
	width = 8;
	height = 5;
	for (int i = 0; i < height;i++) {
		for (int j = 0; j < width; j++) {
			guests[i][j] = Guest();
		}
	}
}
void Theater::updateGuest(int x, int y, Guest m) {
	//if (guests[y][x].getName() == "" || guests[y][x].getPriority() == -1){
		guests[y][x] = m;
	//}
}
void Theater::swap(Guest& m1, Guest& m2) {
	
}
bool Theater::moveTo(int x0, int y0, int x1, int y1) { 
	if (guests[y1][x1].getName() == "" || guests[y1][x1].getPriority() == -1) {
		Guest temp1 = guests[y0][x0];
		guests[y0][x0] = guests[y1][x1];
		guests[y1][x1] = temp1;
		return true;
	}
	else {
		return false;
	}
}
void Theater::shift(char cmd) {
	Guest temp[8];
	switch (cmd) {
	case 'W':
		for (int j = 0; j < width; j++) {
			temp[j] = guests[0][j];
		}
		for (int i = 0; i < height-1; i++) {
			for (int j = 0; j < width; j++) {
				guests[i][j] = guests[i + 1][j];
			}
		}
		for (int w = 0; w < width; w++) {
			guests[height - 1][w] = temp[w];
		}
		break;
	case'A':
		for (int j = 0; j < height; j++) {
			temp[j] = guests[j][0];
		}
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width-1; j++) {
				guests[i][j] = guests[i][j+1];
			}
		}
		for (int w = 0; w < height; w++) {
			guests[w][width-1] = temp[w];
		}
		break;
	case'S':
		for (int j = 0; j < width; j++) {
			temp[j] = guests[4][j];
		}
		for (int i = height-1; i >0; i--) {
			for (int j = 0; j < width; j++) {
				guests[i][j] = guests[i-1][j];
			}
		}
		for (int w = 0; w < width; w++) {
			guests[0][w] = temp[w];
		}
		break;
	case'D':
		for (int j = 0; j < height; j++) {
			temp[j] = guests[j][width-1];
		}
		for (int i = 0; i < height; i++) {
			for (int j = width -1; j >0; j--) {
				guests[i][j] = guests[i][j-1];
			}
		}
		for (int w = 0; w < height; w++) {
			guests[w][0] = temp[w];
		}
		break;
	}
}


string Theater::displayGuests() {
	string out = "";
	int minP = 999999;
	int maxP = -999999;

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			int p = guests[i][j].getPriority();
			if (guests[i][j].getName() != "" && p != -1) {
				if (p < minP) minP = p;
				if (p > maxP) maxP = p;
			}
		}
	}
	int count = 0;
	for (int p = minP; p <= maxP; p++) {
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				if (guests[i][j].getName() != "" && guests[i][j].getPriority() == p) {
					out += to_string(guests[i][j].getPriority()) + " " + guests[i][j].getName() + " (" + to_string(j) + "," + to_string(i) + ")" + "\n";
					count++;
				}
			}
		}
	}
	return out; 
}
string Theater::displayTheater() {
	string out = "";
	for (int i = 0; i <= height; i++) {
		for (int j = 0; j <= width; j++) {
			if (i == 0 && j == 0) {
				out = out + "   ";
			}
			else if (i == 0) {
				if (j == 8) {
					out = out + "[" + to_string(j - 1) + "]";
				}
				else {
					out = out + "[" + to_string(j - 1) + "] ";
				}
			}
			else if (j == 0) {
				out = out + "[" + to_string(i-1) + "] ";
			}
			else {
				out = out +  guests[i-1][j-1].getInfo();
			}
		}
		out += "\n";
	}
	return out; 
}