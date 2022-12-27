//Copyright 2022 Andrey Karagodin

#include <gtest.h>
#include <../lib_polish/polish.h>

TEST(test_lib_polish, can_create_parser) {
	ASSERT_NO_THROW(Parser p());
}

TEST(test_lib_polish, can_create_PolishConvertor) {
	ASSERT_NO_THROW(PolishConvertor p());
}

TEST(test_lib_polish, can_create_Calculator) {
	ASSERT_NO_THROW(Calculator c());
}

TEST(test_lib_polish, can_parser_check_iscorrect) {
	Parser p;
	ASSERT_NO_THROW(p.check("1 + 1"));
}

TEST(test_lib_polish, can_parser_check_correctly) {
	Parser p;
	EXPECT_TRUE(p.check("1 + 1"));
}

TEST(test_lib_polish, can_parser_check_isincorrect) {
	Parser p;
	EXPECT_FALSE(p.check("1 + 1 * ( 3 * 12))"));
}

TEST(test_lib_polish, can_parser_parse) {
	Parser p;
	ASSERT_NO_THROW(p.parse("1 + 1", 1));
}

TEST(test_lib_polish, cant_parser_parse_incorrect) {
	Parser p;
	ASSERT_ANY_THROW(p.parse("1 + 1 * ())", 1));
}

TEST(test_lib_polish, can_parser_return_lexems) {
	Parser p;
	p.parse("1 + 1 * ()", 1);
	ASSERT_NO_THROW(p.getLexemList());
}

TEST(test_lib_polish, can_polish_convertor_convert) {
	Parser p;
	PolishConvertor pc;
	p.parse("1 + 1 * ()", 1);
	ASSERT_NO_THROW(pc.convert(p.getLexemList()));
}

TEST(test_lib_polish, can_calculator_calc) {
	Calculator c;
	string ex = "1 + 1";
	ASSERT_NO_THROW(c.calculate(ex, 1););
}

TEST(test_lib_polish, can_calculator_calc_correctly) {
	string expl = "3+4/2*(x-(4-5))*9";
	float expres = 39;
	Calculator cal;
	float result;
	result = cal.calculate(expl, 1);
	EXPECT_EQ(expres, result);
}