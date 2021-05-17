# pragma once
#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;

class Dictionary
{
	map<string, string> dictionary;

	map<string, string>::iterator it;

public:

	Dictionary(map<string, string> new_dict = {}) {

		dictionary = new_dict;

	}

	int size() const { return dictionary.size(); }

	const std::vector<std::string> questions ();
	const std::vector<std::string> answers();

	void add_word(string word, string meaning);

	void remove_word(string word);

	void add_dictionary(map<string, string> second_dict);

	string find_meaning(string& word) const;

	string find_word(string& meaning) const;

	string find_meaning(int index) const;

	string find_word(int index) const;

	map<string, string> find_by_letter(char first_char);

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

	friend
		void menu(Dictionary& dict);

};

bool operator==(const vector<string> vect1, const vector<string> vect2);

ostream& operator <<(ostream& ss, const map<string, string>& dict);

map<string, string> input_dict();

string input();

string ask_file_name();
