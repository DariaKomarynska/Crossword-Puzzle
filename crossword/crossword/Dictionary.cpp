#include "Dictionary.h"
#include <iostream>
#include <fstream>
#include <vector>


void Dictionary::add_word(string word, string meaning)
{
	// add new word with small letters in word
	transform(word.begin(), word.end(), word.begin(), ::tolower);
	dictionary[word] = meaning;
}

string Dictionary::find_meaning(string& word) const
{
	// find meaning by word
	transform(word.begin(), word.end(), word.begin(), ::tolower);
	for (auto& it : dictionary) {
		if (it.first == word) {
			return it.second;
		}
	}
	return "There is no such word in the dictionary";
}


string Dictionary::find_meaning(int index) const {
	int count = 0;
	for (auto& it : dictionary) {
		if (count == index) {
			return it.second;
		}
		count++;
	}
	return "There is no such a question in the dictionary";
}

string Dictionary::find_word(int index) const {
	int count = 0;
	for (auto& it : dictionary) {
		if (count == index) {
			return it.first;
		}
		count++;
	}
	return "There is no such a word in the dictionary";
}

int Dictionary::find_index(string word) const {
	int index = 0;
	for (auto it : dictionary) {
		if (it.first == word) {
			return index;
		}
		index++;
	}
	//return 0;
};

string Dictionary::find_word(string& meaning) const
{
	// find word using its meaning
	transform(meaning.begin(), meaning.end(), meaning.begin(), ::tolower);
	for (auto& it : dictionary) {
		if (it.second == meaning) {
			return it.first;
		}
	}
	return "There is no word with this meaning in the dictionary";
}

map<string, string> Dictionary::find_by_letter(char first_char)
{
	// find all words starting from that letter(character)
	first_char = tolower(first_char);
	map<string, string> list_of_words;
	for (auto& pair : dictionary) {
		if (pair.first[0] == first_char) {
			list_of_words.emplace(pair);
		}
	}
	return list_of_words;
}


void Dictionary::remove_word(string word)
{
	// remove word and its meaning
	transform(word.begin(), word.end(), word.begin(), ::tolower);
	it = dictionary.find(word);
	if (it != dictionary.end()) {
		dictionary.erase(word);
	}
}


void Dictionary::add_dictionary(map<string, string> second_dict)
{
	// pair by pair adding words fromanother dictionary to our
	for (auto& pair : second_dict) {
		add_word(pair.first, pair.second);
	}
}


const std::vector<std::string> Dictionary::questions() {
	std::vector<std::string> ques;
	for (auto& pair : dictionary) {
		ques.push_back(pair.second);
	}
	return ques;
}


const std::vector<std::string> Dictionary::answers() {
	std::vector<std::string> ans;
	for (auto& pair : dictionary) {
		ans.push_back(pair.first);
	}
	return ans;
}


Dictionary& Dictionary::operator = (const Dictionary& another_dict)
{
	// operator for assignment object: dict_1 = dict2;
	this->dictionary = another_dict.dictionary;
	return *this;
}


Dictionary& Dictionary::operator + (const Dictionary& another_dict)
{
	// adding words with meaning from another dictionary to our dictionary: dict_1 + dict_2;
	this->add_dictionary(another_dict.dictionary);
	return *this;
}


Dictionary& Dictionary::operator + (const string& word)
{
	// adding word without meaning
	this->add_word(word, "");
	return *this;
}

bool Dictionary::operator==(const Dictionary& second_dict)
{
	// compare contents of two dictionaries
	return this->dictionary == second_dict.dictionary;
}

bool operator==(const vector<string> vect1, const vector<string> vect2)
{
	bool result;
	// compare contents of two vectors
	result = std::equal(vect1.begin(), vect1.end(), vect2.begin());
	return result;
}

istream& operator >>(istream& is, Dictionary& dict)
{
	// input the pair into dictionary
	string words;
	getline(is, words);
	auto pos = words.find("\t");
	if (pos != string::npos)
	{
		string word = words.substr(0, pos);
		string meaning = words.substr(pos + 1);
		dict.add_word(word, meaning);
	}
	return is;
}

ostream& operator<<(ostream& os, const Dictionary& dict)
{
	// output the dictionary - object of class
	for (auto& element : dict.dictionary) {
		os << element.first << "\t" << element.second << endl;
	}
	return os;
}

string ask_file_name()
{
	string path;
	cout << "Enter file name: ";
	cin >> path;
	cin.ignore();
	return path;
}

fstream& operator >>(fstream& fs, Dictionary& dict)
{
	// input dicitionary from file
	string path = ask_file_name();
	fs.open(path, fstream::in);
	cout << "ok";
	string words;
	if (fs.is_open()) {
		while (getline(fs, words)) {
			auto pos = words.find("\t");
			if (pos != string::npos)
			{
				string word = words.substr(0, pos);
				string meaning = words.substr(pos + 1);
				dict.add_word(word, meaning);
			}
		}
	}
	fs.close();
	return fs;
}

fstream& operator <<(fstream& fs, Dictionary& dict)
{
	// save dictionary in file
	string path = ask_file_name();
	fs.open(path, fstream::out);
	for (auto& element : dict.dictionary) {
		fs << element.first << "\t" << element.second << endl;
	}
	fs.close();
	return fs;
}


ostream& operator<<(ostream& ss, const map<string, string>& dict)
{
	// output map - for printing for example map of words with one first letter
	for (auto& element : dict) {
		ss << element.first << "\t" << element.second << endl;
	}
	return ss;
}


map<string, string> input_dict() {

	// input dictionary
	int num;
	string word, meaning;
	map<string, string> new_dict;
	cout << "Enter number of words: ";
	cin >> num;
	cin.ignore();
	for (int i = 1; i <= num; i++) {
		cout << i << ") ";
		cout << "Enter a word: ";
		getline(cin, word);
		cout << "Enter a meaning: ";
		getline(cin, meaning);
		new_dict[word] = meaning;
	}
	return new_dict;
}

string input() {
	// input word
	string word;
	cout << "Enter a word: ";
	getline(cin, word);
	return word;
}

void menu(Dictionary& dict) {

	// menu for user

	string word, meaning;
	bool works = true;

	cout << "Your Dictionary\nChoose:\n";
	cout << "1 - See all words\n";
	cout << "2 - Add a new word\n";
	cout << "3 - Add a word without meaning\n";
	cout << "4 - Remove a word\n";
	cout << "5 - Add a dictionary\n";
	cout << "6 - Find a definiton\n";
	cout << "7 - Find a word by definition\n";
	cout << "8 - Find words with first letter..\n";
	cout << "0 - Exit\n";

	while (works) {
		cout << "Enter your choice: ";
		int choice;
		cin >> choice;
		cin.ignore();
		cout << endl;

		switch (choice) {

		case 1:
			cout << dict << endl;
			break;

		case 2:
			word = input();
			cout << "Enter a definition: ";
			getline(cin, meaning);
			dict.add_word(word, meaning);
			break;

		case 3:
			word = input();
			dict + word;
			break;

		case 4:
			word = input();
			cout << endl;
			dict.remove_word(word);
			break;

		case 5: {
			map<string, string>dict_2 = input_dict();
			Dictionary second_dict(dict_2);
			second_dict = input_dict();
			dict + second_dict;
			cout << endl;
			break; }

		case 6:
			word = input();
			cout << endl;
			meaning = dict.find_meaning(word);
			cout << meaning << endl;
			break;

		case 7:
			meaning = input();
			cout << endl;
			word = dict.find_word(meaning);
			cout << word << endl;
			break;

		case 8:
			char f_letter;
			cout << "Enter a letter to start with: ";
			cin >> f_letter;
			cout << dict.find_by_letter(f_letter) << endl;
			break;

		case 0:
			works = false;
			break;

		default:
			cout << "Choose another number!" << endl;
			break;
		}

	}

}
