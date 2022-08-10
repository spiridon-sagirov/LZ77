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

    Triplet t1;
    if (!f.eof())
    {
        string test;
        f >> test;
        cout << test << "\n";
        unsigned int i = 1, back = 0, k = 1, forward = 0;
        while (isdigit(test[i]))
        {
            back = (back * k) + test[i] - 48;
            i++;
            k *= 10;
        }
        t1.back = back ;
        i++;
        k = 1;
        while (isdigit(test[i]))
        {
            forward = (forward * k) + test[i] - 48;
            i++;
            k *= 10;
        }
        t1.forward = forward;
        char theNextChar = test[++i];
       t1.theNextChar = theNextChar;
    }
	return t1;
}

bool TripletFileText::EndOfFile()
{
	return f.eof();
}