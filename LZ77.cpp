// LZ77.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int Lz77(string sourseFile, int buffer) {
	fstream my_file;
	ofstream destination("destinationFile.Bin");
	my_file.open(sourseFile, ios::in);
	if (!my_file) {
		cout << "No such file";
	}
	else {
		char ch;
		while (!my_file.eof())
		{
			string res = "";
			for (int i = 0; i < buffer; i++)
			{
				my_file >> noskipws >> ch;
				if (my_file.eof())
					break;
				res += ch;
			}
			destination << res;
		}
	}
	my_file.close();
	return 0;
}


int main() {
	Lz77("binfile.Bin", 3);
}

