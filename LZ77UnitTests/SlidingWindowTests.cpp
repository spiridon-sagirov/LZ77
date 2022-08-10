#include "stdafx.h"
#include "LZ77UnitTests.h"
#include "SlidingWindowTests.h"

#include "..\LZ77Lib\SlidingWindow.h"
//string InFile()
//{
//	string str = "";
//	char ch[2];
//	fstream file;
//	file.open("newDestination.txt", ios::in);
//	while (!file.eof())
//	{
//		file >> noskipws >> ch;
//		str += ch;
//	}
//	return str;
//}

void sliding_window_test_sample()
{
	string inputFilePath(getUnitTestsDataPath() + "SlidingWindowRead01_input.txt");

	SlidingWindow slidingWindow(6,4);
	slidingWindow.OpenRead(inputFilePath);
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


	/*SlidingWindow slidingWindow(6, 4);
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
	slidingWindow.Close();*/

	/*string inFile = "";
	SlidingWindow slidingWindow1(6);
	slidingWindow1.OpenWrite("newDestination.txt");
	slidingWindow1.Write("a");
	inFile = InFile();
	BOOST_TEST( inFile == "");
	BOOST_TEST(slidingWindow1.searchBuffer.getString() == string("a"));
	slidingWindow1.Write("aax");
	inFile = "";
	inFile = InFile();
	BOOST_TEST(inFile == "");
	BOOST_TEST(slidingWindow1.searchBuffer.getString() == string("aaax"));
	slidingWindow1.Write("xxe");
	inFile = "";
	inFile = InFile();
	BOOST_TEST(inFile == "a");
	BOOST_TEST(slidingWindow1.searchBuffer.getString() == string("aaxxxe"));
	slidingWindow1.Write("ex");
	inFile = "";
	inFile = InFile();
	BOOST_TEST(inFile == "aaa");
	BOOST_TEST(slidingWindow1.searchBuffer.getString() == string("xxxeex"));
	slidingWindow1.Write("a");
	inFile = "";
	inFile = InFile();
	BOOST_TEST(inFile == "aaax");
	BOOST_TEST(slidingWindow1.searchBuffer.getString() == string("xxeexa"));
	slidingWindow1.Write("ac");
	inFile = "";
	inFile = InFile();
	BOOST_TEST(inFile == "aaaxxx");
	BOOST_TEST(slidingWindow1.searchBuffer.getString() == string("eexaac"));
	slidingWindow1.Close();*/
	


}

