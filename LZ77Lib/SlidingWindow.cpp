#include "stdafx.h"
#include "SlidingWindow.h"
void SlidingWindow::OpenRead(string filePath )
{    
	 pointer=fstream(filePath, ios::binary | ios::in);
	 size = searchBufferSize + lookAheadBufferSize;
	 buffer = new char[size];
	 searchBuffer = buffer;
	 lookAheadBuffer = buffer;
	 pointer.read(buffer, size);
	 pointer.seekg(size + 1,ios::beg);
}

void SlidingWindow::Read(int bytesCount)
{
	if (lookAheadBuffer + bytesCount + lookAheadBufferSize < &buffer[size - 1])
	{
		lookAheadBuffer += bytesCount;

	}
	else 
	{
		buffer = &(buffer[bytesCount]);
		pointer.read(&buffer[size-bytesCount], bytesCount);
		pointer.seekg(bytesCount, ios::cur);
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