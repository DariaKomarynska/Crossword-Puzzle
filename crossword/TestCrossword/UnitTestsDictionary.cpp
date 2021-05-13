#include "..\crossword\Dictionary.h"
#include "..\crossword\Dictionary.cpp"
#include "CppUnitTest.h"

using namespace std;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Dictionarytest
{
	TEST_CLASS(Dictionarytest)
	{
	public:

		TEST_METHOD(find_meaning)
		{
			map<string, string> dict1 = { {"apple", "fruit"}, {"pen", "writing instrument"} };
			Dictionary dict_a(dict1);
			string word, meaning;
			word = "apple";
			meaning = dict_a.find_meaning(word);

			string apple_meaning;
			apple_meaning = "fruit";

			Assert::AreEqual(meaning, apple_meaning);
		}

		TEST_METHOD(find_not_existing_meaning)
		{
			map<string, string> dict1 = { {"apple", "fruit"}, {"pen", "writing instrument"} };
			Dictionary dict_a(dict1);
			string word, meaning;
			word = "horse";
			meaning = dict_a.find_meaning(word);

			string horse_meaning;
			horse_meaning = "There is no such word in the dictionary";

			Assert::AreEqual(meaning, horse_meaning);
		}

		TEST_METHOD(find_word)
		{
			map<string, string> dict1 = { {"apple", "fruit"}, {"pen", "writing instrument"} };
			Dictionary dict_a(dict1);
			string word, meaning;
			meaning = "writing instrument";
			word = dict_a.find_word(meaning);

			string found_word;
			found_word = "pen";

			Assert::AreEqual(word, found_word);
		}

		TEST_METHOD(find_not_existing_word)
		{
			map<string, string> dict1 = { {"apple", "fruit"}, {"pen", "writing instrument"} };
			Dictionary dict_a(dict1);
			string word, meaning;
			meaning = "instruments";
			word = dict_a.find_word(meaning);

			string found_word;
			found_word = "There is no word with this meaning in the dictionary";

			Assert::AreEqual(word, found_word);
		}

		TEST_METHOD(find_words_with_letter_diff_lettercase)
		{
			map<string, string> dict1 = { {"apple", "fruit"}, {"april", "spring month"}, {"pen", "writing instrument"} };
			Dictionary dict_a(dict1);
			char small_a = 'a';
			char big_a = 'A';
			map<string, string> words_a = dict_a.find_by_letter(small_a);
			map<string, string> words_big_a = dict_a.find_by_letter(big_a);

			map<string, string> found_words = { {"apple", "fruit"}, {"april", "spring month"} };

			Assert::IsTrue(words_a == found_words);
			Assert::IsTrue(words_big_a == found_words);
		}

		TEST_METHOD(find_words_with_not_existing_letter)
		{
			map<string, string> dict1 = { {"apple", "fruit"}, {"april", "spring month"}, {"pen", "writing instrument"} };
			Dictionary dict_a(dict1);
			char m = 'm';
			map<string, string> words_a = dict_a.find_by_letter(m);

			map<string, string> found_words = {};

			Assert::IsTrue(words_a == found_words);
		}
		TEST_METHOD(remove_word)
		{
			map<string, string> dict1 = { {"apple", "fruit"}, {"pen", "writing instrument"} };
			Dictionary dict_a(dict1);
			string word;
			word = "apple";
			dict_a.remove_word(word);

			map<string, string> dict2 = { {"pen", "writing instrument"} };
			Dictionary dict_b(dict2);

			Assert::IsTrue(dict_a == dict_b);
		}

		TEST_METHOD(remove_not_existing_word)
		{
			map<string, string> dict1 = { {"apple", "fruit"}, {"pen", "writing instrument"} };
			Dictionary dict_a(dict1);
			string word;
			word = "horse";
			dict_a.remove_word(word);

			map<string, string> dict2 = { {"apple", "fruit"}, {"pen", "writing instrument"} };
			Dictionary dict_b(dict2);

			Assert::IsTrue(dict_a == dict_b);
		}

		TEST_METHOD(remove_word_upper_case)
		{
			map<string, string> dict1 = { {"apple", "fruit"}, {"pen", "writing instrument"} };
			Dictionary dict_a(dict1);
			string word;
			word = "Apple";
			dict_a.remove_word(word);

			map<string, string> dict2 = { {"pen", "writing instrument"} };
			Dictionary dict_b(dict2);

			Assert::IsTrue(dict_a == dict_b);

		}

		TEST_METHOD(assignment_operator)
		{
			map<string, string> dict1 = { {"apple", "fruit"}, {"pen", "writing instrument"} };
			Dictionary dict_a(dict1);

			map<string, string> dict2 = { { "april", "spring month" } };
			Dictionary dict_b(dict2);

			dict_a = dict_b;

			Assert::IsTrue(dict_a == dict_b);
			Assert::IsTrue(&dict_a != &dict_b);
		}

		TEST_METHOD(add_operator)
		{
			map<string, string> dict1 = { {"apple", "fruit"}, {"pen", "writing instrument"} };
			Dictionary dict_a(dict1);

			map<string, string> dict2 = { { "april", "spring month" } };
			Dictionary dict_b(dict2);

			dict_a + dict_b;

			map<string, string> dict3 = { {"apple", "fruit"}, { "april", "spring month" }, {"pen", "writing instrument"} };
			Dictionary dict_result(dict3);

			Assert::IsTrue(dict_a == dict_result);
		}


		TEST_METHOD(Correct_add_word)
		{
			map<string, string> dict1 = { {"a", "a"}, {"ba", "n"} };
			Dictionary dict_a(dict1);
			string word, meaning;
			word = "horse";
			meaning = "big animal";
			dict_a.add_word(word, meaning);

			map<string, string> dict2 = { {"a", "a"}, {"ba", "n"}, {"horse", "big animal"} };
			Dictionary dict_b(dict2);

			Assert::IsTrue(dict_a == dict_b);
		}

		TEST_METHOD(Same_add_word)
		{
			map<string, string> dict1 = { {"apple", "fruit"}, {"pen", "writing instrument"} };
			Dictionary dict_a(dict1);
			string word, meaning;
			word = "apple";
			meaning = "big animal";
			dict_a.add_word(word, meaning);

			map<string, string> dict2 = { {"apple", "big animal"}, {"pen", "writing instrument"} };
			Dictionary dict_b(dict2);

			Assert::IsTrue(dict_a == dict_b);
		}


		TEST_METHOD(Delete_meaning)
		{
			map<string, string> dict1 = { {"apple", "fruit"}, {"pen", "writing instrument"} };
			Dictionary dict_a(dict1);
			string word, meaning;
			word = "apple";
			dict_a + word;

			map<string, string> dict2 = { {"apple", ""}, {"pen", "writing instrument"} };
			Dictionary dict_b(dict2);

			Assert::IsTrue(dict_a == dict_b);
		}

		TEST_METHOD(Add_new_word_without_meaning)
		{
			map<string, string> dict1 = { {"apple", "fruit"}, {"pen", "writing instrument"} };
			Dictionary dict_a(dict1);
			string word, meaning;
			word = "horse";
			dict_a + word;

			map<string, string> dict2 = { {"apple", "fruit"}, {"horse", ""}, {"pen", "writing instrument"} };
			Dictionary dict_b(dict2);

			Assert::IsTrue(dict_a == dict_b);
		}

	};
}