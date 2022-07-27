#pragma once
#include "Buffer.h"

class SlidingWindow
{
public:
	fstream pointer;

	Buffer buffer;
	//char* searchBuffer;
	//char* lookAheadBuffer;
	Buffer searchBuffer;
	Buffer lookAheadBuffer;

	int searchBufferSize;
	int lookAheadBufferSize;

	SlidingWindow(int searchBufferSize, int lookAheadBufferSize);
	~SlidingWindow();

	void OpenRead(string filePath);
	void Read(int bytesCount);
	bool EndOfFile();
	//Write(buffer)
	void Close();

};