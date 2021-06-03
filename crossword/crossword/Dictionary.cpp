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
	throw std::out_of_range("Invalid index");
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


bool Dictionary::isWordInVector(const string word, const vector<string> vect) {
	for (auto& i : vect) {
		if (i == word) {
			return true;
		}
	}
	return false;
}


vector<string> Dictionary::randomAnswers() {
	// random number of words 
	vector<string> randomAnswers;
	string answer;
	std::random_device rd; // obtain a random number from hardware
	std::mt19937 gen(rd()); // seed the generator
	std::uniform_int_distribution<> distr(1, size()-1); // define the range
	int randAmount = distr(gen); // random amount of words

	for(int i = 0; randomAnswers.size() != randAmount; i++){
		int randNumber = distr(gen); // random number of word in dictionary
		answer = find_word(randNumber);
		if (i != 0) {
			if (!isWordInVector(answer, randomAnswers)) {
				randomAnswers.push_back(answer);
			}
		}
		else { randomAnswers.push_back(answer); }
	}
	return randomAnswers;
}

vector<int> Dictionary::numbersWordsWithLetter(const vector<string> answers) {
	// in how many words letter appears
	vector<int> numberOfWords;
	for (char& letter : alphabet) {
		int countWord = 0;
		for (auto& answer : answers) {
			int countLetter = 0;
			for (auto& letterInWord : answer) {
				if (letterInWord == letter) {
					countLetter++;
				}
			}
			if (countLetter != 0) {
				countWord++;
			}
		}
		numberOfWords.push_back(countWord);
	}
	return numberOfWords;

}


vector<int> Dictionary::letterFrequencyInWord(const vector<string> answers) {
	// how many times letter appears in word
	// {1, 5, 3} - letter A appears 1 time in all words, B - 5 times
	vector<int> letterFrequencies;
	for (auto& letter : alphabet) {
		int countLetter = 0, countWord = 0;
		for (auto& answer : answers) {
			for (auto& letterInWord : answer) {
				if (letterInWord == letter) {
					countLetter++;
				}
			}
		}
		letterFrequencies.push_back(countLetter);
	}
	return letterFrequencies;
} 


vector<int> Dictionary::letterScores(const vector<int> numberWords, const vector<int> letterFrequency) {
	// calculate value of each letter
	vector<int> letterScore;
	int score = 0;
	for (int i = 0; i < alphSize(); i++) {
		score = (numberWords[i] - 1) * letterFrequency[i];
		letterScore.push_back(score);
	}
	return letterScore;
} 


map<int, string> Dictionary::wordScore(const vector<string> answers, const vector<int> letterScores) {
	// calculate value of each word
	map<int, string> scores;
	for (auto& word : answers) {
		int score = 0;
		for (auto& letterInWord : word) {
			for (int i = 0; i < alphSize(); i++) {
				if (letterInWord == alphabet[i]) {
					score += letterScores[i];
				}
			}
		}
		scores[score] = word;
	}
	return scores;
}


vector<string> Dictionary::sortedAnswers(const map<int, string> wordScores) {
	// sorted list of words, from least
	map<int, string> wordsRank = wordScores;
	vector<string> answers;
	for (auto& pair : wordsRank) {
		answers.push_back(pair.second);
	}
	return answers;
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
			auto pos = words.find(",");
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

