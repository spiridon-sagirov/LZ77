// LZ77.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "../LZ77Lib/SlidingWindow.h"
#include "../LZ77Lib/Lcs.h"
#include "../LZ77Lib/Triplet.h"
#include "../LZ77Lib/TripletFileText.h"
//#include "../LZ77Lib/TripletFileBinary.h"

int Lz77(string command,string sourceFile, string destinationFile, int buffer) {
	if (command == "compress")
	{
		TripletFileText tf;
		Triplet t;
		SlidingWindow s(6,4);
		s.OpenRead(sourceFile);
		tf.OpenWrite(destinationFile);
		while (s.lookAheadBuffer.size!=0)
		{
			unsigned int index = 0;
			unsigned int length = 0;
			string sb = s.searchBuffer.getString();
			string slb = s.lookAheadBuffer.getString();
			lcs(sb, slb, &index, &length);
			if (length == 0) 
			{
				t.back = 0;
			}
			else
			{
				t.back = s.searchBuffer.size - index;
			}
			t.forward = length;
			if (length == s.lookAheadBuffer.size)
			{
				s.Read(1);
				length--;
			}
			t.theNextChar = s.lookAheadBuffer.firstByte[length];
			tf.Write(t);
			s.Read(length + 1);
		}
		tf.Close();
		return 0;
	}
	else
	{
		TripletFileText tf;
		Triplet t;
		SlidingWindow s(6);
		string str = "";
		s.OpenWrite(destinationFile);
		tf.OpenRead(sourceFile);
		while (!tf.EndOfFile())
		{
			t = tf.Read();
			if (t.back==0 && t.forward==0 && t.theNextChar == '/n')
			{
				str = str;
			}
			else if (t.back == 0 && t.forward == 0 && t.theNextChar !='/n')
			{
				str = t.theNextChar;
			}
			else
			{
				for (int i = 0; i < t.forward; i++)
				{
					if((s.searchBuffer.size - t.back + i) < s.searchBuffer.size)
					{
						str += s.searchBuffer.firstByte[s.searchBuffer.size - t.back + i];
					}
					else
					{
						str += s.searchBuffer.firstByte[s.searchBuffer.size - t.back];
					}
				}
				str += t.theNextChar;
			}
			s.Write(str);
			
			str = "";
		}
		s.Close();
		return 0;
	}
}

//void main(string comand,string pathDecompress,string pathCompress,int buffer) {
void main(int argc, char** argv) {
	string command(argv[1]);
	string pathCompress(argv[2]);
	string pathDecompress(argv[3]);
	int buffer = atoi(argv[4]);

    cout << "comand:"<<command<<" pathCompress:"<< pathCompress<<" pathDecompress:"<< pathDecompress<<" buffer size:"<< buffer<<endl;
	if (command == "compress")
		Lz77(command,pathCompress, pathDecompress, buffer);
	else if(command == "decompress")
		Lz77(command,pathCompress,pathDecompress, buffer);
}

