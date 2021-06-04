# pragma once
#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <random>
using namespace std;

class Dictionary
{
	map<string, string> dictionary;

	map<string, string>::iterator it;

	string alphabet = "abcdefghijklmnopqrstuvwxyz";

public:

	Dictionary(map<string, string> new_dict = {}) {

		dictionary = new_dict;

	}

	int size() const { return dictionary.size(); }
	int alphSize() const { return alphabet.size(); }

	const std::vector<std::string> questions ();
	const std::vector<std::string> answers();

	void add_word(string word, string meaning);
	void remove_word(string word);
	void add_dictionary(map<string, string> second_dict);
	
	string find_meaning(string& word) const;
	string find_word(string& meaning) const;
	string find_meaning(int index) const;
	string find_word(int index) const;
	string findWordInList(int index, const vector<string> wordList) const;
	int find_index(string word) const;
	map<string, string> find_by_letter(char first_char);
	
	bool isWordInVector(const string word, const vector<string> vect);
	vector<string> randomAnswers();
	vector<int> numbersWordsWithLetter(const vector<string> answers);
	vector<int> letterFrequencyInWord(const vector<string> answers);
	vector<int> letterScores(const vector<int> numberWords, const vector<int> letterFrequency);
	multimap<int, string, greater<int>> wordScore(const vector<string> answers, const vector<int> letterScores);
	vector<string> sortedAnswers(const multimap<int, string, greater<int>> wordScores);
	vector<string> getRankedRandomAnswers();
	vector<string> getRandomQuestions(const vector<string> answers);

	//void add_dict_file(const string& file_name);

	Dictionary& operator = (const Dictionary& another_dict);
	Dictionary& operator + (const Dictionary& another_dict);
	Dictionary& operator + (const string& word);
	bool operator == (const Dictionary& second_dict);

	friend
		fstream& operator <<(fstream& fs, Dictionary& dict);
	friend
		fstream& operator >>(fstream& fs, Dictionary& dict);

	friend
		ostream& operator << (ostream& os, const Dictionary& dict);
	friend
		istream& operator >>(istream& is, Dictionary& dict);
};

bool operator==(const vector<string> vect1, const vector<string> vect2);
bool operator==(const multimap<int, string> mlmap1, const multimap<int, string> mlmap2);
ostream& operator <<(ostream& ss, const map<string, string>& dict);
map<string, string> input_dict();
