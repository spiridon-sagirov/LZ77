#include "stdafx.h"
#include "LZ77UnitTests.h"
#include "TripletFileBTests.h"

#include "..\LZ77Lib\Triplet.h"
#include "..\LZ77Lib\TripletFileBinary.h"

string readFileContentB(const string& filePath)
{
	fstream fileStream1(filePath, ios::binary);
	stringstream stringStream1;
	stringStream1 << fileStream1.rdbuf();
	return stringStream1.str();

}

void triplet_binary_test_write()
{
	string actualFilePath(getUnitTestsDataPath() + "TripletWrite01_actual.bin");
	string expectedFilePath(getUnitTestsDataPath() + "TripletWrite01_expected.bin");

	TripletFileBinary tf;
	tf.OpenWrite(actualFilePath );
	tf.Write(Triplet(21, 12, 'g'));
	tf.Write(Triplet(34, 43, 'f'));
	tf.Close();

	string actualContent = readFileContentB(actualFilePath);
	string expectedContent = readFileContentB(expectedFilePath);

	BOOST_TEST(expectedContent == actualContent);
}

void triplet_binary_test_read()
{
	string inputFilePath(getUnitTestsDataPath() + "TripletRead01_input.bin");

	TripletFileBinary tfb;
	tfb.OpenRead(inputFilePath);

	BOOST_TEST(!tfb.EndOfFile());

	Triplet triplet1 = tfb.Read();
	Triplet triplet2 = tfb.Read();

	BOOST_TEST(triplet1.equals(Triplet(21, 12, 'g')));
	BOOST_TEST(triplet2.equals(Triplet(34, 43, 'f')));
	Triplet triplet3 = tfb.Read();
	BOOST_TEST(tfb.EndOfFile());

	tfb.Close();
}
