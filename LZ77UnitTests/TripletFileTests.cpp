#include "stdafx.h"
#include "LZ77UnitTests.h"
#include "TripletFileTests.h"

#include "..\LZ77Lib\Triplet.h"
#include "..\LZ77Lib\TripletFileText.h"

string readFileContent(const string& filePath)
{
	ifstream fileStream(filePath);
	stringstream stringStream;
	stringStream << fileStream.rdbuf();
	return stringStream.str();
}

void triplet_test_write()
{
	string actualFilePath(getUnitTestsDataPath() + "TripletWrite01_actual.txt");
	string expectedFilePath(getUnitTestsDataPath() + "TripletWrite01_expected.txt");

	TripletFileText tf;
	tf.OpenWrite(actualFilePath);
	tf.Write(Triplet(21, 12, 'g'));
	tf.Write(Triplet(34, 43, 'f'));
	tf.Close();

	string actualContent = readFileContent(actualFilePath);
	string expectedContent = readFileContent(expectedFilePath);

	BOOST_TEST(expectedContent == actualContent);
}

void triplet_test_read()
{
	string inputFilePath(getUnitTestsDataPath() + "TripletRead01_input.txt");

	TripletFileText tf;
	tf.OpenRead(inputFilePath);

	BOOST_TEST(!tf.EndOfFile());

	Triplet triplet1 = tf.Read();
	Triplet triplet2 = tf.Read();

	BOOST_TEST(triplet1.equals(Triplet(21, 12, 'g')));
	BOOST_TEST(triplet2.equals(Triplet(34, 43, 'f')));

	tf.Read();
	BOOST_TEST(tf.EndOfFile());

	tf.Close();
}
