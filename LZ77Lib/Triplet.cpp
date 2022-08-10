#include "stdafx.h"
#include "Triplet.h"


Triplet::Triplet()
{
}

Triplet::Triplet( int back,  int forward, char theNextChar)
{
	this->back = back;
	this->forward = forward;
	this->theNextChar = theNextChar;
}

bool Triplet::equals(const Triplet& other)
{
	return (this->back == other.back)
		&& (this->forward == other.forward)
		&& (this->theNextChar == other.theNextChar);
}
