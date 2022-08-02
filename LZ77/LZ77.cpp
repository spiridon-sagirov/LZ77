// LZ77.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "../LZ77Lib/SlidingWindow.h"
#include "../LZ77Lib/Lcs.h"
#include "../LZ77Lib/Triplet.h"
#include "../LZ77Lib/TripletFileText.h"
//#include "../LZ77Lib/TripletFileBinary.h"

int Lz77(string sourseFile, string destinationFile, int buffer) {
	/*fstream in(sourseFile, ios::binary | ios::in);
	fstream out(destinationFile, ios::binary | ios::out);*/

	TripletFileText tf;
	Triplet t;
	SlidingWindow s(6, 4);
	s.OpenRead(sourseFile);
	tf.OpenWrite(destinationFile);
	while ()
	{
		string str = lcs(s.searchBuffer.firstByte, s.lookAheadBuffer.firstByte);
		int byteCount = str.length();
		s.Read(byteCount);
		t.back = ;
		t.forward = byteCount;
		t.theNextChar = ;
		tf.Write(t);
	}
}
 
	/*char ch;
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
}*/

//void main(string comand,string pathDecompress,string pathCompress,int buffer) {
void main(int argc, char** argv) {
	string command(argv[1]);
	string pathCompress(argv[2]);
	string pathDecompress(argv[3]);
	int buffer = atoi(argv[4]);

    cout << "work";
	if (command == "compress")
		Lz77(pathDecompress, pathCompress, buffer);
	else if(command == "decompress")
		Lz77(pathCompress,pathDecompress, buffer);
}
//int main() {
//
//	shelllz77("compress", "image.jpg", "destinationFile.jpg",3);
//
//	shelllz77("compress", "source.jpg", "destination.jpg",3);
//
//}

