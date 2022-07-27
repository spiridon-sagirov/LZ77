#pragma once
#include "ITripletFile.h"
#include "Triplet.h"


class TripletFileBinary : public ITripletFile
{
	fstream f;
	// Inherited via ITripletFile
public:
	virtual void OpenRead(string FileName) override;
	virtual void OpenWrite(string FileName) override;
	virtual void Write(Triplet t) override;
	virtual void Close() override;
	virtual Triplet Read() override;
	virtual bool EndOfFile() override;
};

