#pragma once
#include "TriplateFile.h"
#include "Triplate.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


void TriplateFile::Open(string FileName)
{
	f1.open(FileName, ios::out | ios::in);
	if (!f1)
	{
		cout << "File creation failed";
	}
	else
	{
		cout << "New file created \n";
	}
}

//void TriplateFile::Write(Triplate t)
//{
//	File << "(" << t.Back << "," << t.Forward << "," << t.TheNextChar << ")";
//}
//
//void TriplateFile::Close()
//{
//	File.close();
//}
//
////Triplate TriplateFile::Read()
////{
////	return triplate();
////}
//
//bool TriplateFile::EndOfFile()
//{
//	if (!File.eof())
//		return false;
//	else
//		return true;
//}
