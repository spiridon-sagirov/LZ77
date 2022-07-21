#include "stdafx.h"

#include "TriplateFile.h"
#include "Triplate.h"




void TriplateFile::OpenWrite(string FileName)
{
	f.open(FileName, ios::out);
	if (!f)
	{
		throw "File creation failed";
	}
}

void TriplateFile::OpenRead(string FileName)
{
	f.open(FileName, ios::in);
	if (!f)
	{
		throw "File creation failed";
	}
}

void TriplateFile::Write(Triplate t)
{
	if (f.is_open())
		f << "(" << t.back << "," << t.forward << "," << t.theNextChar << ")" << "\n";
	else
		throw "The file is closed, you need to open it";
}

void TriplateFile::Close()
{
	if (f.is_open())
		f.close();
}
void TriplateFile::Read()
{
	if (f.is_open()) {
		char mychar;
		while (f) {
			mychar = f.get();
			cout << mychar;
		}
		//return triplate();
	}
}

bool TriplateFile::EndOfFile()
{
	if (!f.eof())
		return false;
    return true;
}
