// LZ77UnitTests.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "TripletFileTests.h"


test_suite* init_unit_test_suite(int argc, char* argv[])
{
	framework::master_test_suite().add(BOOST_TEST_CASE(&triplet_test_sample));
	return 0;
}
