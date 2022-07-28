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
	BOOST_TEST(slidingWindow.searchBuffer.getString() == string(""));
	BOOST_TEST(slidingWindow.lookAheadBuffer.getString() == string("aaax"));
	slidingWindow.Read(1);
	BOOST_TEST(slidingWindow.buffer.getString() == string("aaaxxxeexa"));
	BOOST_TEST(slidingWindow.searchBuffer.getString() == string("a"));
	BOOST_TEST(slidingWindow.lookAheadBuffer.getString() == string("aaxx"));
	slidingWindow.Read(3);
	BOOST_TEST(slidingWindow.buffer.getString() == string("aaaxxxeexa"));
	BOOST_TEST(slidingWindow.searchBuffer.getString() == string("aaax"));
	BOOST_TEST(slidingWindow.lookAheadBuffer.getString() == string("xxee"));
	slidingWindow.Read(3);
	BOOST_TEST(slidingWindow.buffer.getString() == string("aaxxxeexaa"));
	BOOST_TEST(slidingWindow.searchBuffer.getString() == string("aaxxxe"));
	BOOST_TEST(slidingWindow.lookAheadBuffer.getString() == string("exaa"));
	slidingWindow.Read(2);
	BOOST_TEST(slidingWindow.buffer.getString() == string("axxxeexaac"));
	BOOST_TEST(slidingWindow.searchBuffer.getString() == string("xxxeex"));
	BOOST_TEST(slidingWindow.lookAheadBuffer.getString() == string("aac"));
	slidingWindow.Read(1);
	BOOST_TEST(slidingWindow.buffer.getString() == string("axxxeexaac"));
	BOOST_TEST(slidingWindow.searchBuffer.getString() == string("xxeexa"));
	BOOST_TEST(slidingWindow.lookAheadBuffer.getString() == string("ac"));
	slidingWindow.Read(2);
	BOOST_TEST(slidingWindow.buffer.getString() == string("axxxeexaac"));
	BOOST_TEST(slidingWindow.searchBuffer.getString() == string("eexaac"));
	BOOST_TEST(slidingWindow.lookAheadBuffer.getString() == string(""));
	slidingWindow.Close();
}
