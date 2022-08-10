#pragma once

class Triplet
{

public:
	unsigned short int back;
	unsigned short int forward;
	char theNextChar;
	Triplet();
	Triplet(unsigned short int back, unsigned short int forward, char theNextChar);

	bool equals(const Triplet& other);
};
