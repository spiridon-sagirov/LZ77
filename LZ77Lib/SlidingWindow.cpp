#include "stdafx.h"
#include "SlidingWindow.h"

SlidingWindow::SlidingWindow(unsigned int searchBufferSize, unsigned int lookAheadBufferSize)
	: buffer(new char[searchBufferSize + lookAheadBufferSize + 1], searchBufferSize + lookAheadBufferSize)
	, searchBuffer(NULL, 0)
	, lookAheadBuffer(NULL, 0)
{
	this->searchBufferSize = searchBufferSize;
	this->lookAheadBufferSize = lookAheadBufferSize;
}
SlidingWindow::SlidingWindow(unsigned int searchBufferSize)
	: buffer(new char[searchBufferSize +100], searchBufferSize)
	, searchBuffer(NULL, 0)
	, lookAheadBuffer(NULL, 0)
{
	this->searchBufferSize = searchBufferSize;
}

SlidingWindow::~SlidingWindow()
{
	delete this->buffer.firstByte;
}

void SlidingWindow::OpenRead(string filePath)
{    
	 pointer = fstream(filePath, ios::binary | ios::in);
	 pointer.read(buffer.firstByte, buffer.size);
	 searchBuffer.firstByte = buffer.firstByte;
	 searchBuffer.size = 0;
	 lookAheadBuffer.firstByte = buffer.firstByte;
	 lookAheadBuffer.size = lookAheadBufferSize;
}

void SlidingWindow::Read(unsigned int bytesCount)
{
	if (searchBuffer.size + bytesCount <= searchBufferSize)
	{
		searchBuffer.size += bytesCount;
		lookAheadBuffer.firstByte = &(buffer.firstByte[searchBuffer.size]);
		return;
	}

	int x = searchBuffer.size + bytesCount - searchBufferSize;
	if (pointer.eof()) 
	{
		searchBuffer.firstByte += bytesCount;
		lookAheadBuffer.firstByte = searchBuffer.firstByte + searchBufferSize;
		lookAheadBuffer.size = max((int)(lookAheadBuffer.size - bytesCount),0);
		return;
	}

	int as = pointer.tellp();
	pointer.seekg(0, ios::end);
	int ii = pointer.tellg();
	if ( ii-as >= x)
	{
		pointer.seekg((as));
		int aas=pointer.tellg();
		for (unsigned int i = 0; i < buffer.size - x ; i++)
		{
			buffer.firstByte[i] = buffer.firstByte[i + x];
		}
		searchBuffer.firstByte = buffer.firstByte;
		searchBuffer.size = searchBufferSize;
		pointer.read(&(buffer.firstByte[buffer.size - x ]), x);
		lookAheadBuffer.firstByte = &(buffer.firstByte[searchBuffer.size]);
	}
	else
	{
		pointer.seekg((as));
		int y = ii - pointer.tellg();
		for (unsigned int i = 0; i <= buffer.size - y - 1; i++)
		{
			buffer.firstByte[i] = buffer.firstByte[i + y];
		}
		searchBuffer.firstByte = &(buffer.firstByte[bytesCount - y]);
		searchBuffer.size = searchBufferSize;
		pointer.read(&(buffer.firstByte[buffer.size - y]), y + 1);
		lookAheadBuffer.firstByte = y + &(buffer.firstByte[searchBuffer.size]);
		lookAheadBuffer.size = max((int)(lookAheadBuffer.size - bytesCount + y), 0);
	}
}

bool SlidingWindow::EndOfFile() 
{
	//return lookAheadBuffer.size == 0;
	int a = pointer.tellp();
	pointer.seekg(0, ios::end);
	int ii = pointer.tellp();
	pointer.seekg((a));
	return a==ii;
}

void SlidingWindow::OpenWrite(string filePath)
{
	pointer = fstream(filePath, ios::binary | ios::out);
	searchBuffer.size = 0;
	searchBuffer.firstByte=buffer.firstByte;
}

void SlidingWindow::Write(string str)
{
	if (searchBuffer.size + str.length() <= searchBufferSize)
	{
		for (unsigned int i = 0; i < str.length(); i++)
		{
			searchBuffer.firstByte[searchBuffer.size] =str[i];
			searchBuffer.size ++;
		}
	}
	else
	{
		unsigned int missingSize = searchBuffer.size + str.length() - searchBufferSize;
		for (int j = 0; j < missingSize; j++) 
		{
			pointer << searchBuffer.firstByte[j];
			searchBuffer.size--;
		}
		for (unsigned int i = missingSize, j = 0; i < searchBufferSize ; i++, j++)
		{
			searchBuffer.firstByte[j] = searchBuffer.firstByte[i];
		}
		for (unsigned int i = 0; i < str.length(); i++)
		{
			searchBuffer.firstByte[searchBuffer.size] = str[i];
			searchBuffer.size++;
		}
    }
}

void SlidingWindow::Close() 
{
	for(int i=0;i<searchBufferSize;i++)
	{
		pointer << searchBuffer.firstByte[i];
	}
	pointer.close();
}
