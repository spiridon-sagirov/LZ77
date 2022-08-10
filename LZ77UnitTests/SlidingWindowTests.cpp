#include "stdafx.h"
#include "LZ77UnitTests.h"
#include "SlidingWindowTests.h"

#include "..\LZ77Lib\SlidingWindow.h"

void sliding_window_test_sample()
{

	SlidingWindow slidingWindow(6,4);
	slidingWindow.OpenRead(getUnitTestsDataPath() + "SlidingWindowRead02_input.txt");
	BOOST_TEST(!slidingWindow.EndOfFile());
	BOOST_TEST(slidingWindow.buffer.getString() == string("eedfrrrfdd"));
	BOOST_TEST(slidingWindow.searchBuffer.getString() == string(""));
	BOOST_TEST(slidingWindow.lookAheadBuffer.getString() == string("eedf"));
	slidingWindow.Read(1);
	BOOST_TEST(!slidingWindow.EndOfFile());
	BOOST_TEST(slidingWindow.buffer.getString() == string("eedfrrrfdd"));
	BOOST_TEST(slidingWindow.searchBuffer.getString() == string("e"));
	BOOST_TEST(slidingWindow.lookAheadBuffer.getString() == string("edfr"));
	slidingWindow.Read(2);
	BOOST_TEST(!slidingWindow.EndOfFile());
	BOOST_TEST(slidingWindow.buffer.getString() == string("eedfrrrfdd"));
	BOOST_TEST(slidingWindow.searchBuffer.getString() == string("eed"));
	BOOST_TEST(slidingWindow.lookAheadBuffer.getString() == string("frrr"));
	slidingWindow.Read(1);
	BOOST_TEST(!slidingWindow.EndOfFile());
	BOOST_TEST(slidingWindow.buffer.getString() == string("eedfrrrfdd"));
	BOOST_TEST(slidingWindow.searchBuffer.getString() == string("eedf"));
	BOOST_TEST(slidingWindow.lookAheadBuffer.getString() == string("rrrf"));
	slidingWindow.Read(1);
	BOOST_TEST(!slidingWindow.EndOfFile());
	BOOST_TEST(slidingWindow.buffer.getString() == string("eedfrrrfdd"));
	BOOST_TEST(slidingWindow.searchBuffer.getString() == string("eedfr"));
	BOOST_TEST(slidingWindow.lookAheadBuffer.getString() == string("rrfd"));
	slidingWindow.Read(3);
	BOOST_TEST(!slidingWindow.EndOfFile());
	BOOST_TEST(slidingWindow.buffer.getString() == string("dfrrrfddrf"));
	BOOST_TEST(slidingWindow.searchBuffer.getString() == string("dfrrrf"));
	BOOST_TEST(slidingWindow.lookAheadBuffer.getString() == string("ddrf"));
	slidingWindow.Read(3);
	BOOST_TEST(slidingWindow.EndOfFile());
	BOOST_TEST(slidingWindow.buffer.getString() == string("rrfddrfddf"));
	BOOST_TEST(slidingWindow.searchBuffer.getString() == string("rrfddr"));
	BOOST_TEST(slidingWindow.lookAheadBuffer.getString() == string("fddf"));
	slidingWindow.Close();


	SlidingWindow slidingWindow2(6,4);
	slidingWindow2.OpenRead(getUnitTestsDataPath() + "SlidingWindowRead01_input.txt");

	BOOST_TEST(slidingWindow2.buffer.getString() == string("aaaxxxeexa"));
	BOOST_TEST(slidingWindow2.searchBuffer.getString() == string(""));
	BOOST_TEST(slidingWindow2.lookAheadBuffer.getString() == string("aaax"));
	slidingWindow2.Read(1);
	BOOST_TEST(slidingWindow2.buffer.getString() == string("aaaxxxeexa"));
	BOOST_TEST(slidingWindow2.searchBuffer.getString() == string("a"));
	BOOST_TEST(slidingWindow2.lookAheadBuffer.getString() == string("aaxx"));
	slidingWindow2.Read(3);
	BOOST_TEST(slidingWindow2.buffer.getString() == string("aaaxxxeexa"));
	BOOST_TEST(slidingWindow2.searchBuffer.getString() == string("aaax"));
	BOOST_TEST(slidingWindow2.lookAheadBuffer.getString() == string("xxee"));
	slidingWindow2.Read(3);
	BOOST_TEST(slidingWindow2.buffer.getString() == string("aaxxxeexaa"));
	BOOST_TEST(slidingWindow2.searchBuffer.getString() == string("aaxxxe"));
	BOOST_TEST(slidingWindow2.lookAheadBuffer.getString() == string("exaa"));
	slidingWindow2.Read(2);
	BOOST_TEST(slidingWindow2.buffer.getString() == string("axxxeexaac"));
	BOOST_TEST(slidingWindow2.searchBuffer.getString() == string("xxxeex"));
	BOOST_TEST(slidingWindow2.lookAheadBuffer.getString() == string("aac"));
	slidingWindow2.Read(1);
	BOOST_TEST(slidingWindow2.buffer.getString() == string("axxxeexaac"));
	BOOST_TEST(slidingWindow2.searchBuffer.getString() == string("xxeexa"));
	BOOST_TEST(slidingWindow2.lookAheadBuffer.getString() == string("ac"));
	slidingWindow2.Read(2);
	BOOST_TEST(slidingWindow2.buffer.getString() == string("axxxeexaac"));
	BOOST_TEST(slidingWindow2.searchBuffer.getString() == string("eexaac"));
	BOOST_TEST(slidingWindow2.lookAheadBuffer.getString() == string(""));
	slidingWindow2.Close();

	/*SlidingWindow slidingWindow1(6);
	slidingWindow1.OpenWrite("newDestination.txt");
	slidingWindow1.Write("a");
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
	slidingWindow1.Close();*/


	


}

