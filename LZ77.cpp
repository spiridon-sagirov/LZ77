// LZ77.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int Lz77(string sourseFile,string destinationFile, int buffer) {
	fstream in(sourseFile, ios::binary | ios::in);
	fstream out(destinationFile, ios::binary | ios::out);
 
	char ch;
	while (!in.eof())
	{
		string res = "";
		for (int i = 0; i < buffer; i++)
		{
			in >> noskipws >> ch;
			if (in.eof())
				break;
			res += ch;
		}
		out << res;
	}
	in.close();
	out.close();
	return 0;
}

void shelllz77(string comand,string pathDecompress,string pathCompress,int buffer) {
	if (comand == "compress")
		Lz77(pathDecompress, pathCompress, buffer);
	else if(comand == "decompress")
		Lz77(pathCompress,pathDecompress, buffer);
}
int main() {

	shelllz77("compress", "image.jpg", "destinationFile.jpg",3);

	shelllz77("compress", "source.jpg", "destination.jpg",3);

}

