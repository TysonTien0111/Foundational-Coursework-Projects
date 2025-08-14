/*
 * Unit tests for the pig latin translator using the CUnit framework.
 */
#include <CUnit/Basic.h>

#include "translator_tools.h"

void TestSplitSentenceIntoWords()
{
  CU_ASSERT(**SplitSentenceIntoWords("      The dog barks      "));
  CU_ASSERT(**SplitSentenceIntoWords("THE DOG BARKS"));
  CU_ASSERT(**SplitSentenceIntoWords("THEDOGBARKS"));
}

void TestWordHasOnlyLetters()
{
	CU_ASSERT(WordHasOnlyLetters("Thedogbarks"));
  CU_ASSERT(WordHasOnlyLetters("THEDOGBARKS"));
  CU_ASSERT(!WordHasOnlyLetters("THEDOG1234567BARKS"));
  CU_ASSERT(!WordHasOnlyLetters("THEDOG$^#&#^(@#^(!@3@(BARKS"));
}

void TestToLowerCase()
{
  char some_string[] = "BarKs";
  ToLowerCase(some_string);
  CU_ASSERT(strcmp(some_string, "barks") == 0);
}

void TestIsVowel()
{
  CU_ASSERT(!IsVowel('t'));
  CU_ASSERT(IsVowel('o'));
}

void TestGetConsonantCluster()
{
  char a_string[] = "";
  CU_ASSERT(*GetConsonantCluster("the dog barks"));
  *GetConsonantCluster(a_string);
  CU_ASSERT(a_string == NULL);
}

void TestStripString()
{
  CU_ASSERT(*StripString("the dog barks", 4));
}

void TestStringConcat()
{
  CU_ASSERT(*StringConcat("the dog barks", "ben"));
}

int main(void)
{
	// Initialize CUnit
	CU_initialize_registry();
	CU_pSuite pSuite = CU_add_suite("TranslatorToolsTests", NULL, NULL);

	// Register unit tests
	CU_add_test(pSuite, "SplitSentenceIntoWords", TestSplitSentenceIntoWords);
	CU_add_test(pSuite, "WordHasOnlyLetters", TestWordHasOnlyLetters);
	CU_add_test(pSuite, "ToLowerCase", TestToLowerCase);
	CU_add_test(pSuite, "IsVowel", TestIsVowel);
  CU_add_test(pSuite, "GetConsonantCluster", TestGetConsonantCluster);
	CU_add_test(pSuite, "StripString", TestStripString);
	CU_add_test(pSuite, "StringConcat", TestStringConcat);

	// Run all tests
	CU_basic_run_tests();

	// Clean up & exit
	CU_cleanup_registry();
	return 0;
}
