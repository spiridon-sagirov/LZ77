#include "stdafx.h"
#include "..\LZ77Lib\Lcs.cpp"


string unitTestsDataPath("..\\LZ77UnitTests\\UnitTestsData\\");
char X[] = "tamarrrewqa";
char Y[] = "rrtamadewq";
char * res=lcs(X, Y);
