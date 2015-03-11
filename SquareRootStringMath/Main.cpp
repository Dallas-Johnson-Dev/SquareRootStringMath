// SquareRootStringMath.cpp : Defines the entry point for the console application.
// Dallas Johnson
// Defines square root mathematics on strings.

#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include "Main.h"

using namespace std;

int main(int argc, char* argv) {
	string Input = "";
	cout << "Insert a number to take the Square Root of: ";
	getline(cin, Input);
	squareRoot(Input);
	//system("pause");
	return 0;
}

string subtract(string a, string b) {
	while (a.length() < b.length()) {
		a = '0' + a;
	}
	while (b.length() < a.length()) {
		b = '0' + b;
	}
	string tempString;
	for (int i = a.length() - 1; i >= 0; i--) {
		int Compliment = 9 - (a[i] - '0');
		char ComplimentChar = Compliment + '0';
		tempString = ComplimentChar + tempString;
	}
	tempString = sum(tempString, b);
	string difference = "";
	for (int i = tempString.length() - 1; i >= 0; i--) {
		int Compliment = 9 - (tempString[i] - '0');
		char ComplimentChar = Compliment + '0';
		difference = ComplimentChar + difference;
	}
	difference = remlzero(difference);
	return difference;
}

string remlzero(string s) {
	string input = s;
	while (input != "" && input[0] == '0') input = input.substr(1);
	if (input == "") input = "0";
	return input;
}

//How this works: If true is returned then A is larger, if false is returned then they're equal or B is larger;
bool stringEquality(string Alpha, string Beta) {
	string A = remlzero(Alpha);
	string B = remlzero(Beta);
	if (A.length() > B.length()) {
		return true;
	}
	else if (A.length() < B.length()) { //Going to add this in case it's needed, this broke somewhere and I haven't found where yet.
		return false;
	}
	if (A.length() == B.length()) { //If the lengths are equal, then we need to handle the case here.
		for (int i = 0; i < A.length(); i++) {
			if (A[i] != B[i]) { //We need to know if the position that the first break is discovered in is less than or greater than each other.
				if (A[i] > B[i]) {
					return true;
				}
				else {
					return false;
				}
			}
		}
		return true;
	}
	else { 
		return false; 
	}
	return false;
}

void squareRoot(string value) {
	string answer = "0";
	string remainder = value;
	vector<string> fourList;
	fourList.push_back("1");

	//We need to begin pushing back the multiples of four.
	int index = 0;
	while (stringEquality(remainder, mult(fourList[index], "4"))) {
		fourList.push_back(mult(fourList[index], "4"));
		fourList[index] = remlzero(fourList[index]); //adding this line to make sure we dont' get the leading zeroes issue.
		index++;
	}
	//now we go and actually do the calculating!
	string equalStringCheck;
	while (index > -1) {
		equalStringCheck = mult(fourList[index], sum(mult("4",answer),"1"));

		if (stringEquality(remainder, equalStringCheck)) {
			remainder = subtract(remainder, equalStringCheck);
			answer = sum(mult(answer, "2"), "1");
			index--;
		}
		else {
			answer = mult(answer, "2");
			index--;
		}
	}
	//Clean up our final results. We want to make sure that we dont' have any zeroes left on if for some reason they were input into the function.
	answer = remlzero(answer);
	remainder = remlzero(remainder);
	string input = remlzero(value);

	//our final result print.
	cout << "Square root for " << input << ":" << endl;
	cout << "Answer: " << answer << endl;
	cout << "Remainder: " << remainder << endl;
}

string mult(string a, string b) {
	//makes a place for us to store our output
	string out = "";
	//interates through the both the strings
	for (int i = 0; i < (int)a.length(); i++){
		for (int j = 0; j < (int)b.length(); j++) {
			//multiplies each value
			int p = (a[i] - '0')*(b[j] - '0');
			//breaks that value into the first digit and the second digit
			string pstr = ((string)"") + (char)(p / 10 + '0') + (char)(p % 10 + '0');
			//adds zeroes to get to the place that i is at
			for (int k = 0; k < (int)a.length() - i - 1 + (int)b.length() - j - 1; k++)
				pstr += "0";
			//adds the output of that case of multiplication to the output
			out = sum(out, pstr);
			}
		}
	out = remlzero(out);
	return out;
}

string sum(string a, string b) {
	string out = "";
	while (a.length() < b.length()) a = "0" + a;
	while (b.length() < a.length()) b = "0" + b;
	int carry = 0;
	for (int i = a.length() - 1; i >= 0; i--) {
		int l = a[i] - '0' + b[i] - '0' + carry;
		carry = l / 10;
		l %= 10;
		out = ((char)(l + '0')) + out;
	}
	if (carry == 1){
		out = "1" + out;
	}
	out = remlzero(out);
	return out;
}
