// LZ77UnitTests.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "LcsTests.h"
#include "TripletFileTests.h"


test_suite* init_unit_test_suite(int argc, char* argv[])
{
	framework::master_test_suite().add(BOOST_TEST_CASE(&lcs_test_common_substring_exist));
	framework::master_test_suite().add(BOOST_TEST_CASE(&lcs_test_inputs_are_identical));
	framework::master_test_suite().add(BOOST_TEST_CASE(&lcs_test_common_substring_doesnt_exist));
	framework::master_test_suite().add(BOOST_TEST_CASE(&lcs_test_common_substring_of_1_char));
	framework::master_test_suite().add(BOOST_TEST_CASE(&lcs_test_first_input_is_empty));
	framework::master_test_suite().add(BOOST_TEST_CASE(&lcs_test_second_input_is_empty));

	framework::master_test_suite().add(BOOST_TEST_CASE(&triplet_test_sample));
	return 0;
}
