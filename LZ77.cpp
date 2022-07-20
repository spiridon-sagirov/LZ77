// LZ77.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int Lz77(string sourceFile,string destinationFile, int buffer) {
	fstream my_file;
	ofstream destination(destinationFile);
	my_file.open(sourceFile, ios::binary);
	if (!my_file) 
		return 0;
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
	my_file.close();
	return 0;
}

void shelllz77(string comand,string pathDecompress,string pathCompress,int buffer) {
	if (comand._Equal("compress"))
		Lz77(pathDecompress, pathCompress, buffer);
	else if(comand._Equal("decompress"))
		Lz77(pathCompress,pathDecompress, buffer);

}
int main() {
	shelllz77("compress", "image.jpg", "destinationFile.jpg",3);
}

