#pragma once

#include "Triplet.h"


__interface ITripletFile
{
	void OpenRead(string FileName);
	void OpenWrite(string FileName);
	void Write(Triplet t);
	void Close();
	Triplet Read();
	bool EndOfFile();
};
