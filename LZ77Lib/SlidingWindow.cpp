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
	 searchBuffer.firstByte = buffer.firstByte;
	 lookAheadBuffer.firstByte = buffer.firstByte;
	 lookAheadBuffer.size = lookAheadBufferSize;
}

void SlidingWindow::Read(int bytesCount)
{
	
	if (searchBuffer.size + bytesCount <= searchBufferSize)
	{
		searchBuffer.size += bytesCount;
		lookAheadBuffer.firstByte = &(buffer.firstByte[searchBuffer.size]);
	}
	else
	{
		int x = searchBuffer.size + bytesCount - searchBufferSize;
		if (pointer.eof()) {
			searchBuffer.firstByte += bytesCount;
			lookAheadBuffer.firstByte = searchBuffer.firstByte + searchBufferSize;
			lookAheadBuffer.size -= bytesCount;
		}
		//cout << &pointer.end<<endl;
		//cout << &pointer.cur<<endl;

		else if (pointer.end - pointer.cur >= x )
		{
			for (int i = 0; i < buffer.size - x - 1; i++)
			{
				buffer.firstByte[i] = buffer.firstByte[i + x];
			}
			searchBuffer.firstByte = buffer.firstByte;
			searchBuffer.size = searchBufferSize;
			pointer.read(&(buffer.firstByte[buffer.size - x - 1]), x);
			lookAheadBuffer.firstByte = &(buffer.firstByte[searchBuffer.size]);
		}
		else
		{
			
			int y = pointer.end - pointer.cur;
			for (int i = 0; i <= buffer.size - y - 1; i++)
			{
    				buffer.firstByte[i] = buffer.firstByte[i + y];
			}
			searchBuffer.firstByte = &(buffer.firstByte[bytesCount - y]);
			searchBuffer.size = searchBufferSize;
			pointer.read(&(buffer.firstByte[buffer.size -y ]), y+1);
			lookAheadBuffer.firstByte = y + &(buffer.firstByte[searchBuffer.size]);
			lookAheadBuffer.size -= y;

			

		}
	}
}

bool SlidingWindow::EndOfFile() 
{
	return pointer.eof();	
}

void SlidingWindow::Close() 
{
	pointer.close();
}

/*if (lookAheadBuffer + bytesCount + lookAheadBufferSize < &buffer[size - 1])
	{
		lookAheadBuffer += bytesCount;
	}
	else
	{
		buffer = &(buffer[bytesCount]);
		pointer.read(&buffer[size-bytesCount], bytesCount);
		pointer.seekg(bytesCount, ios::cur);
	}*/
