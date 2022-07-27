#include "stdafx.h"
#include "TripletFileText.h"
#include "Triplet.h"


void TripletFileText::OpenRead(string FileName)
{
	f.open(FileName, ios::in);
	if (!f)
	{
		throw "File creation failed";
	}
}

void TripletFileText::OpenWrite(string FileName)
{
	f.open(FileName, ios::out);
	if (!f)
	{
		throw "File creation failed";
	}
}

void TripletFileText::Write(Triplet t){
	if (f.is_open())
	{
		f << "(" << t.back << "," << t.forward << "," << t.theNextChar << ")" << "\n";
	}
	else
	{
		throw "The file is closed, you need to open it";
	}
}

void TripletFileText::Close()
{
	if (f.is_open())
		f.close();
}

Triplet TripletFileText::Read()
{
	string text;
	f >> text;
	Triplet t1;
	auto it = ++text.rbegin();
	t1.theNextChar = *it;
	it += 2;
	string str = "";
	for (it; it != text.rend() && *it != '(' && *it != ','; it++)
	{
		str = *it + str;
	}
	t1.forward = stoi(str);
	str = "";
	for (++it; it != text.rend() && *it != '(' && *it != ','; it++)
	{
		str = *it + str;
	}
	t1.back = stoi(str);
	return t1;
}

bool TripletFileText::EndOfFile()
{
	return f.eof();
}
