// SquareRootStringMath.cpp : Defines the entry point for the console application.
// Dallas Johnson
// Defines square root mathematics on strings.

#ifndef __SROOT__
#define __SROOT__
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char* argv); //Main method, what makes everything happen
string subtract(string a, string b); //This method is powered by 9's compliment, which was easy to implement.
string remlzero(string s); //Removes leading zeroes, not really much of an issue.
bool stringEquality(string A, string B); //Tests is string A is larger than string B.
void squareRoot(string value); //does the square root of the number, and it's super complex how it happens using the second method showed to us in class.
string mult(string a, string b); //Pre-written multiplication method using additon
string sum(string a, string b); //Pre-written method for addition of string numbers.
#endif __SROOT__
