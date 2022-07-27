#include "stdafx.h"
#include "LcsTests.h"
#include "..\LZ77Lib\Lcs.h"

void lcs_test_common_substring_exist()
{
	BOOST_TEST(string("tama") == lcs("tamarrrewqa", "rrtamadewq"));
}

void lcs_test_inputs_are_identical()
{
	BOOST_TEST(string("tamar") == lcs("tamar", "tamar"));
}

void lcs_test_common_substring_doesnt_exist()
{
	BOOST_TEST(string("") == lcs("tamar", "qweyqwe"));
}

void lcs_test_common_substring_of_1_char()
{
	BOOST_TEST(string("a") == lcs("tamar", "qweaayqwe"));
}

void lcs_test_first_input_is_empty()
{
	BOOST_TEST(string("") == lcs("", "qweaayqwe"));
}

void lcs_test_second_input_is_empty()
{
	BOOST_TEST(string("") == lcs("tamar", ""));
}
