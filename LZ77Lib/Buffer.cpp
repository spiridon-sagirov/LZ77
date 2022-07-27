#include "stdafx.h"
#include "Buffer.h"

Buffer::Buffer(char* firstByte, int size)
{
	this->firstByte = firstByte;
	this->size = size;
}

string Buffer::getString()
{
	return string(this->firstByte, this->size);
}
