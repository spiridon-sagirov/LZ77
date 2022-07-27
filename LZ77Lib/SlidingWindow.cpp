#include "stdafx.h"
#include "SlidingWindow.h"

SlidingWindow::SlidingWindow(int searchBufferSize, int lookAheadBufferSize)
	: buffer(new char[searchBufferSize + lookAheadBufferSize], searchBufferSize + lookAheadBufferSize)
	, searchBuffer(NULL, 0)
	, lookAheadBuffer(NULL, 0)
{
	this->searchBufferSize = searchBufferSize;
	this->lookAheadBufferSize = lookAheadBufferSize;
}

SlidingWindow::~SlidingWindow()
{
	delete this->buffer.firstByte;
}

void SlidingWindow::OpenRead(string filePath)
{    
	 pointer = fstream(filePath, ios::binary | ios::in);
	 pointer.read(buffer.firstByte, buffer.size);
	 //searchBuffer = buffer;
	 //lookAheadBuffer = buffer;
	 //pointer.seekg(size + 1,ios::beg);
}

void SlidingWindow::Read(int bytesCount)
{
	//if (lookAheadBuffer + bytesCount + lookAheadBufferSize < &buffer[size - 1])
	//{
	//	lookAheadBuffer += bytesCount;
	//}
	//else 
	//{
	//	buffer = &(buffer[bytesCount]);
	//	pointer.read(&buffer[size-bytesCount], bytesCount);
	//	pointer.seekg(bytesCount, ios::cur);
	//}
}

bool SlidingWindow::EndOfFile() 
{
	return pointer.eof();	
}

void SlidingWindow::Close() 
{
	pointer.close();
}
