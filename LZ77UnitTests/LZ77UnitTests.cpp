// LZ77UnitTests.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#include "..\LZ77Lib\Triplate.h"
#include "..\LZ77Lib\TriplateFile.h"


void free_test_function()
{
	//fstream f1;
	//f1.open("pppppppppp", std::ios_base::app);
	//if (!f1)
	//{
	//	cout << "File creation failed";
	//}
	////	f1 << "hello";
	//char  num;
	//f1 >> num;
	//cout << "The next number is " << num;
	//f1.close();
	///*Triplate t1(21, 12, 'g');
	//TriplateFile tf;
	//tf.Open("qwertyuiop");
	//tf.Write(t1);
	//tf.Close();
	//cout << tf.EndOfFile();*/

	BOOST_TEST(true /* test assertion */);
}


test_suite* init_unit_test_suite(int /*argc*/, char* /*argv*/[])
{
	framework::master_test_suite().add(BOOST_TEST_CASE(&free_test_function));
	return 0;
}
