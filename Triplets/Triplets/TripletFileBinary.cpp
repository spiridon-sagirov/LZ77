
#pragma once
#include "TripletFileBinary.h"
#include "Triplet.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;




void TripletFileBinary::OpenRead(string FileName)
{
	f.open(FileName, ios::in | ios::binary);
	if (!f)
	{
		throw "File creation failed";
	}
}

void TripletFileBinary::OpenWrite(string FileName)
{
	f.open(FileName, ios::out | ios::binary);
	if (!f)
	{
		throw "File creation failed";
	}
}

void TripletFileBinary::Write(Triplet t)
{

	int num = t.back;
	f.write((char*)& num , sizeof(num));
    num = t.forward;
	f.write((char*)& num, sizeof(num));
	char ch = t.theNextChar;
	f.write((char*)& ch, sizeof(ch));
}
void TripletFileBinary::Close()
{
	if (f.is_open())
		f.close();
}

Triplet TripletFileBinary::Read()
{
	return Triplet();
}

bool TripletFileBinary::EndOfFile()
{
	if (!f.eof())
		return false;
	return true;
}
