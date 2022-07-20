
#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Triplate.h"

using namespace std;


class TriplateFile
{
public:
	fstream f;
	void Open(string FileName);
	void Write(Triplate t);
	void Close();
	void Read();
	bool EndOfFile();

};


