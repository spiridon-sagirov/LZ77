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

	SlidingWindow slidingWindow1(6);
	slidingWindow1.OpenWrite("newDestination.txt");
	slidingWindow1.Write("a");
	/*fstream file;
	file.open("newDestination.txt", ios::in);
	string str = "";
	BOOST_TEST(file << str == );*/
	BOOST_TEST(slidingWindow1.searchBuffer.getString() == string("a"));
	slidingWindow1.Write("aax");
	BOOST_TEST(slidingWindow1.searchBuffer.getString() == string("aaax"));
	slidingWindow1.Write("xxe");
	BOOST_TEST(slidingWindow1.searchBuffer.getString() == string("aaxxxe"));
	slidingWindow1.Write("ex");
	BOOST_TEST(slidingWindow1.searchBuffer.getString() == string("xxxeex"));
	slidingWindow1.Write("a");
	BOOST_TEST(slidingWindow1.searchBuffer.getString() == string("xxeexa"));
	slidingWindow1.Write("ac");
	BOOST_TEST(slidingWindow1.searchBuffer.getString() == string("eexaac"));

}
