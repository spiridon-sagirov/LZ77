#include "stdafx.h"
#include "TripletFileBinary.h"
#include "Triplet.h"


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
	f.write((char*)& t.back, sizeof(t.back));
	f.write((char*)& t.forward, sizeof(t.forward));
	f.write((char*)& t.theNextChar, sizeof(t.theNextChar));
}

void TripletFileBinary::Close()
{
	if (f.is_open())
		f.close();
}

Triplet TripletFileBinary::Read()
{
	Triplet t;
	if (!f.eof())
	{
		f.read((char*)& t.back, sizeof(t.back));
		f.read((char*)& t.back, sizeof(t.back));
		f.read((char*)& t.theNextChar, sizeof(t.theNextChar));
		return t;
	}
	else
	{
		throw "The file is empty";
	}

}

bool TripletFileBinary::EndOfFile()
{
	return f.eof();
}
