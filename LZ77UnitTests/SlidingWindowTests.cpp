#include "stdafx.h"
#include "LZ77UnitTests.h"
#include "SlidingWindowTests.h"

#include "..\LZ77Lib\SlidingWindow.h"

void sliding_window_test_sample()
{
	string inputFilePath(getUnitTestsDataPath() + "SlidingWindowRead01_input.txt");

	SlidingWindow slidingWindow(6, 4);
	slidingWindow.OpenRead(inputFilePath);

	BOOST_TEST(slidingWindow.buffer.getString() == string("aaaxxxeexa"));
	//BOOST_TEST(slidingWindow.searchBuffer.getString() == string(""));
	//BOOST_TEST(slidingWindow.lookAheadBuffer.getString() == string("aaax"));

	slidingWindow.Close();
}
