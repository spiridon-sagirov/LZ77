
#pragma once
#include "Triplate.h"

#include <iostream>
#include <fstream>
using namespace std;


class TriplateFile
{
public:
	fstream f;
	void OpenWrite(string FileName);
	void OpenRead(string FileName);
	void Write(Triplate t);
	void Close();
	void Read();
	bool EndOfFile();

};


