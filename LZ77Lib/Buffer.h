#pragma once
class Buffer
{
public:
	char* firstByte;
	int size;

	Buffer(char* firstByte, int size);

	string getString();
};

