#pragma once
#include "Buffer.h"
#include "TripletFileText.h"
#include "Triplet.h"

class SlidingWindow
{
public:
	fstream pointer;
	Buffer buffer;
	Buffer searchBuffer;
	Buffer lookAheadBuffer;
	unsigned int searchBufferSize;
	unsigned int lookAheadBufferSize;

	SlidingWindow(unsigned int searchBufferSize, unsigned int lookAheadBufferSize);
	SlidingWindow(unsigned int searchBufferSize);
	~SlidingWindow();

	void OpenRead(string filePath);
	void Read(unsigned int bytesCount);
	bool EndOfFile();
	void OpenWrite(string filePath);
	void Write(string str);
	void Close();

};