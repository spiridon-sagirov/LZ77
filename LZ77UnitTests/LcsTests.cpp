#include "stdafx.h"
#include "LcsTests.h"
#include "..\LZ77Lib\Lcs.h"

void lcs_test_common_substring_exist()
{
	BOOST_TEST(string("") == stringOfLcs("", "aaax"));
	BOOST_TEST(string("aa") == stringOfLcs("a", "aaxx"));
	BOOST_TEST(string("xx") == stringOfLcs("aaax", "xxee"));
	BOOST_TEST(string("e") == stringOfLcs("axxxe", "exaa"));
	BOOST_TEST(string("") == stringOfLcs("xxxeex", "aac"));
	BOOST_TEST(string("a") == stringOfLcs("xxeexa", "ac"));
	
}

void lcs_test_inputs_are_identical()
{
	BOOST_TEST(string("tamar") == stringOfLcs("tamar", "tamar"));
}

void lcs_test_common_substring_doesnt_exist()
{
	BOOST_TEST(string("") == stringOfLcs("tamar", "qweyqwe"));
}
//
void lcs_test_common_substring_of_1_char()
{
	BOOST_TEST(string("") == stringOfLcs("tamar", "qweaayqwe"));
}

void lcs_test_first_input_is_empty()
{
	BOOST_TEST(string("") == stringOfLcs("", "qweaayqwe"));
}

void lcs_test_second_input_is_empty()
{
	BOOST_TEST(string("") == stringOfLcs("tamar", ""));
}
