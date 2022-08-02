#pragma once
#include "Buffer.h"
#include "TripletFileText.h";
#include "Triplet.h";

class SlidingWindow
{
public:
	fstream pointer;
	Buffer buffer;
	Buffer searchBuffer;
	Buffer lookAheadBuffer;
	int searchBufferSize;
	int lookAheadBufferSize;

	SlidingWindow(int searchBufferSize, int lookAheadBufferSize);
	~SlidingWindow();

	void OpenRead(string filePath);
	void Read(int bytesCount);
	bool EndOfFile();
	void OpenWrite(string filePath);
	void Write(Triplet triplet);
	void Close();

};