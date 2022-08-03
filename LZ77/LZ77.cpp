// LZ77.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "../LZ77Lib/SlidingWindow.h"
#include "../LZ77Lib/Lcs.h"
#include "../LZ77Lib/Triplet.h"
#include "../LZ77Lib/TripletFileText.h"
//#include "../LZ77Lib/TripletFileBinary.h"

int Lz77(string sourceFile, string destinationFile, int buffer) {
	/*fstream in(sourseFile, ios::binary | ios::in);
	fstream out(destinationFile, ios::binary | ios::out);*/

	/*TripletFileText tf;*/
	//Triplet t;
	SlidingWindow s(6, 4);
	s.OpenRead(sourceFile);
	/*tf.OpenWrite(destinationFile);*/
	while (!s.EndOfFile())
	{
		unsigned int index = 0;
		unsigned int length = 0;
		string sb= s.searchBuffer.getString();
		string slb = s.lookAheadBuffer.getString();
		lcs(sb, slb, &index, &length);
		//t.back =s.searchBuffer.size-index;
		//t.forward = length;
		if(length==s.lookAheadBuffer.size)
		{
			s.Read(1);
			length--;
		}
		//t.theNextChar = s.lookAheadBuffer.firstByte[length];
		/*tf.Write(t);*/
		s.Read(length+1);
	}
	/*tf.Close();*/
	return 0;
}
 
	

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

