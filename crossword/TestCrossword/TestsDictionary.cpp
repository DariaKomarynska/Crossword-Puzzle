#include "..\crossword\Dictionary.h"
#include "..\crossword\Dictionary.cpp"
#include "CppUnitTest.h"

using namespace std;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Dictionarytest
{
	TEST_CLASS(TestDictionary)
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

		TEST_METHOD(find_index)
		{
			map<string, string> dict1 = { {"apple", "fruit"}, {"pen", "writing instrument"} };
			Dictionary dict_a(dict1);
			string word, meaning;
			word = "pen";
			int index = dict_a.find_index(word);

			int found_index;
			found_index = 1;

			Assert::AreEqual(index, found_index);
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

		TEST_METHOD(Questions_together)
		{
			map<string, string> dict1 = { {"apple", "sweet fruit"}, {"pen", "writing instrument"} };
			Dictionary dict_a(dict1);
			std::vector<std::string> all_ques;
			all_ques = dict_a.questions();

			std::vector<std::string> correct_ques = { "sweet fruit" , "writing instrument" };

			Assert::IsTrue(all_ques == correct_ques);
		}

		TEST_METHOD(Answers_together)
		{
			map<string, string> dict1 = { {"apple", "sweet fruit"}, {"pen", "writing instrument"} };
			Dictionary dict_a(dict1);
			std::vector<std::string> all_ques;
			all_ques = dict_a.answers();

			std::vector<std::string> correct_ques = { "apple" , "pen" };

			Assert::IsTrue(all_ques == correct_ques);
		}

		TEST_METHOD(Word_in_vector)
		{
			const vector<string> vect = { "apple", "banana", "peach" };
			Dictionary dict_a;
			bool isWord = dict_a.isWordInVector("apple", vect);

			Assert::IsTrue(isWord);
		}

		TEST_METHOD(Word_not_in_vector)
		{
			const vector<string> vect = { "apple", "banana", "peach" };
			Dictionary dict_a;
			bool isWord = dict_a.isWordInVector("pineapple", vect);

			Assert::IsFalse(isWord);
		}

		TEST_METHOD(Numbers_Words_With_Letter)
		{
			const vector<string> words = { "apple", "banana", "peach" };
			Dictionary dict_a;
			const vector<int> correct = { 3,1,1,0,2,0,0,1,0,0,0,1,0,1,0,2,0,0,0,0,0,0,0,0,0,0 };
			const vector<int> numbers = dict_a.numbersWordsWithLetter(words);

			Assert::IsTrue(correct == numbers);
		}

		TEST_METHOD(Letter_Frequency)
		{
			const vector<string> words = { "apple", "banana", "peach" };
			Dictionary dict_a;
			const vector<int> correct = { 5,1,1,0,2,0,0,1,0,0,0,1,0,2,0,3,0,0,0,0,0,0,0,0,0,0 };
			const vector<int> numbers = dict_a.letterFrequencyInWord(words);

			Assert::IsTrue(correct == numbers);
		}

		TEST_METHOD(Letter_Score)
		{
			const vector<string> words = { "apple", "banana", "peach" };
			Dictionary dict_a;
			const vector<int> number_of_words = dict_a.numbersWordsWithLetter(words);
			const vector<int> frequency = dict_a.letterFrequencyInWord(words);
			
			const vector<int> scores = dict_a.letterScores(number_of_words, frequency);
			const vector<int> correct = { 10,0,0,0,2,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0 };
			Assert::IsTrue(correct == scores);
		}

		/*TEST_METHOD(Word_Score)
		{
			const vector<string> words = { "apple", "banana", "peach" };
			Dictionary dict_a;
			vector<int> number_of_words = dict_a.numbersWordsWithLetter(words);
			vector<int> frequency = dict_a.letterFrequencyInWord(words);
			vector<int> letterScores = dict_a.letterScores(number_of_words, frequency);
			multimap<int, string> wordScores = dict_a.wordScore(words, letterScores);
			multimap<int, string> correct = { {15, "peach"}, {18, "apple"}, {30, "banana"} };
			multimap<int, string>::iterator it1 = wordScores.begin();
			multimap<int, string>::iterator it2 = correct.begin();
			for (it2; it2 != correct.end(); ++it2) {
				Assert::AreEqual(it1->first, it2->first);
				Assert::AreEqual(it1->second, it2->second);
				it1++;
			}
			
		}*/

		/*TEST_METHOD(Sorted_answers)
		{
			const vector<string> words = { "apple", "banana", "peach" };
			Dictionary dict_a;
			multimap<int, string> wordScores = { {15, "peach"}, {18, "apple"}, {30, "banana"} };
			vector<string> correct = { "peach" , "apple" , "banana" };
			vector<string> answers = dict_a.sortedAnswers(wordScores);
			Assert::IsTrue(correct == answers);
		}*/

		TEST_METHOD(Answer_not_alpha)
		{
			const char* expected_msg = "Answer has unalloved character.";
			map<string, string> dict1 = { {"apple", "fru1t"}, {"pen", "writinginstrument"} };
			try {
				Dictionary dict_a(dict1);
			}
			catch(const std::invalid_argument& err){
				Assert::AreEqual(expected_msg, err.what());
			}
		}


		TEST_METHOD(Answer_space)
		{
			const char* expected_msg = "Answer has unalloved character.";
			map<string, string> dict1 = { {"red apple", "fruit"}, {"pen", "writing instrument"} };
			Dictionary dict_a(dict1);

			std::string s1 = "red apple";
			std::string s2 = "fruit";

			std::string s3 = "pen";
			std::string s4 = "writing instrument";


			Assert::AreEqual(s1, dict_a.find_word(s2));
			Assert::AreEqual(s3, dict_a.find_word(s4));
		}
	};
}