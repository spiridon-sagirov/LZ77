#include "stdafx.h"
#include "SlidingWindow.h"




void SlidingWindow::OpenRead(string filePath, int searchBufferSize, int lookAheadBufferSize)
{    
	 searchBuffer=fstream(filePath, ios::binary | ios::in);
	//lookAheadBuffer=fstream (filePath, ios::binary | ios::in);
	this->size = searchBufferSize + lookAheadBufferSize;
	buffer = new int[size];
	searchBuffer.seekg(0, ios::beg);
	//lookAheadBuffer.seekg(0, ios::beg);
}
bool SlidingWindow::EndOfFile() 
{
	return lookAheadBuffer.eof();	
}