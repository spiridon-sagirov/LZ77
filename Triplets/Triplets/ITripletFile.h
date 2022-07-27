#pragma once
#include <string>
#include "Triplet.h"
#include <fstream>
using namespace std;

__interface ITripletFile
{
	void OpenRead(string FileName);
	void OpenWrite(string FileName);
	void Write(Triplet t);
	void Close();
	Triplet Read();
	bool EndOfFile();
};
