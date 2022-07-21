#include "stdafx.h"
#include "TripletFileTests.h"

#include "..\LZ77Lib\Triplate.h"
#include "..\LZ77Lib\TriplateFile.h"

string unitTestsDataPath("..\\LZ77UnitTests\\UnitTestsData\\");

string readFileContent(const string& filePath)
{
	ifstream fileStream(filePath);
	stringstream stringStream;
	stringStream << fileStream.rdbuf();
	return stringStream.str();
}

void triplet_test_sample()
{
	string actualFilePath(unitTestsDataPath + "TripletWrite01_actual.txt");
	string expectedFilePath(unitTestsDataPath + "TripletWrite01_expected.txt");

	TriplateFile tf;
	tf.OpenWrite(actualFilePath);
	tf.Write(Triplate(21, 12, 'g'));
	tf.Write(Triplate(34, 43, 'f'));
	tf.Close();

	string actualContent = readFileContent(actualFilePath);
	string expectedContent = readFileContent(expectedFilePath);

	BOOST_TEST(expectedContent == actualContent);
}
