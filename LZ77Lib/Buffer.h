#pragma once
class Buffer
{
public:
	char* firstByte;
	unsigned int size;

	Buffer(char* firstByte, unsigned int size);

	string getString();
};

