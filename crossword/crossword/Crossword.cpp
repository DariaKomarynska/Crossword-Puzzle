#include "Crossword.h"

Crossword::Crossword(std::string filepath, std::string crosswordName, bool list_of_words) : name(crosswordName) {
    std::ifstream fileHandle;
    try {
        fileHandle.open(filepath);
    }
    catch (std::exception const& e) {
        cout << "Invalid file error: " << e.what() << endl;
    }

    std::vector <std::string> rows = parseRows(fileHandle);
    fileHandle.close();

    if (list_of_words) {
        Dictionary n_solutions;
        for (auto& row : rows) {
            std::vector <std::string> rowData = parseCSV(row);
            if (rowData.size() != 2) throw InvalidData();

            n_solutions.add_word(rowData.at(1), rowData.at(0));
            
        }
        init(n_solutions);
    }
    else {
        Dictionary n_solutions;
        std::vector< std::vector<int>> n_first_letters;
        std::vector<std::string> n_orientations;

        for (auto& row : rows) {
                std::vector <std::string> rowData = parseCSV(row);
                if (rowData.size() != 5) throw InvalidData();

                n_solutions.add_word(rowData.at(1), rowData.at(0));
                std::vector<int> pos;
                pos.push_back(number(rowData.at(2)));
                pos.push_back(number(rowData.at(3)));
                n_first_letters.push_back(pos);
                n_orientations.push_back(rowData.at(4));
            }

        init(n_solutions, n_first_letters, n_orientations);
    }
}


std::vector <std::string> parseRows(std::ifstream& fileHandle) {
    std::vector <std::string> data;
    std::string temp;

    while (getline(fileHandle, temp)) {
        data.push_back(temp);
    }
    return data;
}


std::vector <std::string> parseCSV(std::string& data) {
    std::vector <std::string> sepData;
    std::string temp;
    std::stringstream s;
    s << data;

    while (getline(s, temp, ',')) {
        sepData.push_back(temp);
    }
    return sepData;
}


Crossword::Crossword(const Dictionary n_solutions, const std::vector< std::vector<int>> first_letters, const std::vector<std::string> n_orientations) {
    init(n_solutions, first_letters, n_orientations);
}


Crossword::Crossword(const Dictionary n_solutions) {
    init(n_solutions);
}


void Crossword::init(const Dictionary n_solutions) {
    solutions = n_solutions;
    answerList = solutions.getRankedRandomAnswers();
    choosePositionPutAnswers();
}

void Crossword::init(const Dictionary n_solutions, const std::vector< std::vector<int>> first_letters, const std::vector<std::string> n_orientations) {
    unsigned size = n_solutions.size();
    if (size != first_letters.size() || size != n_orientations.size()) {
        throw std::invalid_argument("Invalid data size");
    }

    solutions = n_solutions;

    // check if first_letters coords is vector nx2
    for (auto& point : first_letters) {
        if (point.size() != 2) {
            throw std::invalid_argument("Invalid data size");
        }
    }

    firstLettersCoords = first_letters;

    // check if orientations are correct
    for (auto& orient : n_orientations) {
        if (orient != "vertically" && orient != "horizontally") {
            throw std::invalid_argument("Invalid orientation");
        }
    }

    orientations = n_orientations;

    for (unsigned i = 0; i < size; i++) {
        std::string answer = solutions.find_word(i);
        unsigned a_size = answer.size();
        std::string orientation = orientations.at(i);
        std::vector<int> fst_letter_pos = firstLettersCoords.at(i);

        board.createAndSetUpFields(fst_letter_pos.at(0), fst_letter_pos.at(1), a_size, orientation);
    }
    answerList = solutions.answers();
}

//void Crossword::choosePositionPutAnswers() {
//	vector <string> words = solutions.answers();
//	std::vector<string> onBoard;
//	unsigned amountOfWords = solutions.size();
//}


vector <string> Crossword::getRandomAnswers() {
    return answerList;
}


int Crossword::sizeListAnswers() {
    // return solutions.answers().size();
    return answerList.size();
}

void Crossword::choosePositionPutAnswers() {
    unsigned amountOfWords = sizeListAnswers();
    std::vector<std::string> onBoard;
    for (unsigned i = 0; i < amountOfWords; i++) {

        std::string answer = answerList[i];
        unsigned answerSize = answer.size();

        if (i == 0) {
            // put first word on the board
            putFirstWord(answer);
        }
        else {
            putAnotherWord(answer, answerSize, onBoard);
        }
        onBoard.push_back(answer);
    }
}


void Crossword::putFirstWord(const string answer) {
    std::vector <int> coordinates;
    string orientation = "horizontally";
    int row = 0, col = 0;
    int answerSize = answer.size();
    if (answerSize % 2 == 0) { row = 6; col = 6; }
    else { row = 6; col = 7; }
    // (row, y) = (7, 7) or (7, 8) on the board
    fillCrossword(row, col, answer, orientation);
}


void Crossword::putAnotherWord(const string answer, const int answerSize, const vector<string> onBoard) {
    bool placed = false;
    pair<vector<int>, string> position;
    vector<int> coords;
    string orientation;
    int lastJ = 0;
    for (int i = 0; i < onBoard.size(); i++) { // iterate vector of words which are already on board
        string preWord = onBoard[i];
        if (placed == false) {
            lastJ = 0;
            for (int j = 0; j < answerSize; j++) { // iterate letter of current word
                lastJ++;
                if (placed == false) {
                    for (int k = 0; k < preWord.size(); k++) { // iterate letter of previous word
                        if (answer[j] == preWord[k]) {
                            placed = foundCommonLetter(answer, preWord, j, k);
                            if (placed == true) {
                                break;
                            }
                            else {
                                continue;
                            }
                        }

                    }
                }
            }
        }
        if ((lastJ == answerSize) && (i == onBoard.size()-1) && (placed == false)) {
            notFoundCommonLetter(answer, preWord);
            placed = true;
            break;
        }
    }
}

vector<int> Crossword::putWordRandomly(const string curWord)
{
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    std::uniform_int_distribution<> distr(board.getNORows() / 2, board.getNORows() * 2); // define the range
    int randRow = distr(gen);
    int randCol = distr(gen);
    std::vector <int> coordinates = { randRow, randCol };
    return coordinates;
}


bool Crossword::isNotLastAnswer(const string answer) {
    int index = getIndexAnswerList(answer);
    if (index != sizeListAnswers() - 1) {
        return true;
    }
    return false;
}


void Crossword::notFoundCommonLetter(const string answer, const string preWord) {
    bool placed = false;
    pair<vector<int>, string> position;
    vector<int> coords;
    string orientation;
    while (!placed) {
        position = chooseRandomPosition(answer, preWord);
        coords = position.first;
        orientation = position.second;
        bool isBad = isBadPosition(coords, answer, orientation);
        if (isBad == true) {
            continue;
        }
        else {
            int row = coords[0];
            int col = coords[1];
            fillCrossword(row, col, answer, orientation);
            placed = true;
        }
    }
}


pair<vector<int>, string>Crossword::chooseRandomPosition(const string curWord, const string prevWord) {
    string orientation;
    vector<int> coordinates;
    if (checkOrientation(prevWord) == "horizontally") {
        orientation = "vertically";
    }
    else if (checkOrientation(prevWord) == "vertically") {
        orientation = "horizontally";
    }
    coordinates = putWordRandomly(curWord);
    return (make_pair(coordinates, orientation));
}


bool Crossword::foundCommonLetter(const string answer, const string preWord, const int ansIndex, const int prevIndex) {
    bool found = false;
    pair<vector<int>, string> position;
    vector<int> coords;
    string orientation;
    position = choosePosition(answer, preWord, ansIndex, prevIndex);
    coords = position.first;
    orientation = position.second;
    int row = coords[0];
    int col = coords[1];
    bool isBad = isBadPosition(coords, answer, orientation);

    if (isBad == true) {
        return found; // false
    }
    else {
        fillCrossword(row, col, answer, orientation);
        found = true;
        return found;
    }
}

pair<vector<int>, string>Crossword::choosePosition(const string curWord, const string prevWord, const int curIndex, const int prevIndex) {

    // int curPos = letterPosition(curWord, curWord[curIndex]);	// position of letter in current answer
    string orientation;
    vector<int> coordinates;
    if (checkOrientation(prevWord) == "horizontally") {
        coordinates = putWordVertically(curWord, prevWord, curIndex, prevIndex);
        orientation = "vertically";
    }
    else if (checkOrientation(prevWord) == "vertically") {
        coordinates = putWordHorizontally(curWord, prevWord, curIndex, prevIndex);
        orientation = "horizontally";
    }
    return (make_pair(coordinates, orientation));
}

vector<int> Crossword::putWordHorizontally(const string answer, const string preWord, const int curIndex, const int preIndex) {
    int comCol = getLetterCol(preWord);
    int comRow = getLetterRow(preWord, preWord[preIndex]);
    int col = comCol - (curIndex);
    int row = comRow;
    std::vector <int> coordinates = { row, col, comRow, comCol };
    return coordinates;
}


vector<int> Crossword::putWordVertically(const string answer, const string preWord, const int curIndex, const int preIndex) {

    int comCol = getLetterCol(preWord, preWord[preIndex]);
    int comRow = getLetterRow(preWord);
    int col = comCol;
    int row = comRow - (curIndex);
    std::vector <int> coordinates = { row, col, comRow, comCol };
    return coordinates;
}


void Crossword::fillCrossword(const int beginRow, const int beginCol, const string answer, const string orientation) {

    orientations.push_back(orientation);
    vector<int> coordinates = { beginRow , beginCol };
    firstLettersCoords.push_back(coordinates);
    unsigned aSize = answer.size();
    board.createAndSetUpFields(beginRow, beginCol, aSize, orientation);
}


void Crossword::fillAnswer(const int NOQuestion, const std::string answer) {
    board.fillFields(getFirstLetterRow(NOQuestion), getFirstLetterCol(NOQuestion), answer, getOrientation(NOQuestion));
}

void Crossword::getCorrectBoard() {
    for (int i = 0; i < sizeListAnswers(); i++) {
        fillAnswer(i, answerList[i]);
    }
}


string Crossword::checkOrientation(const string word) {
    // return what orientation has word on the board
    int index = getIndexAnswerList(word);
    return getOrientation(index);
}


string Crossword::correctAnswer(const int NOQuestion) {
    // answer by number of position in dictionary
    return solutions.findWordInList(NOQuestion, answerList);
}


bool Crossword::isCorrectAnswer(const int NOQuestion, const std::string answer) {
    // check: is answer correct or no
    return (answer == correctAnswer(NOQuestion));
}


bool Crossword::isNumberOfQuestion(const int NOQuestion) {
    // check whether input number is one of number of question
    return (0 < NOQuestion && NOQuestion < sizeListAnswers() + 1);
}


void Crossword::fillField(const int row, const int col, const char value) {
    // fill one field on the board with input value
    board.fillField(row, col, value);
}


std::ostream& operator<<(std::ostream& os, Crossword& c) {
    os << '\n' << c.board;

    int index = 0;

    // for (auto& question : c.getQuestions()) {
    for (auto& question : c.getRandomQuestions()) {
        os << '\n' << index + 1 << ". " << question;
        if (question.size() < 15) {		// distance should be changed
            os << '\t';
        }
        os << '\t' << "(" << c.getFirstLetterRow(index) + 1 << ", " << c.getFirstLetterCol(index) + 1 << ")";
        index++;
    }
    return os;
}

//std::ostream& operator<<(std::ostream& os, Crossword& c) {
//	os << '\n' << c.board;
//
//	int index = 0;
//
//	for (auto& question : c.getRandomQuestions()) {
//		os << '\n' << index + 1 << ". " << question;
//		if (question.size() < 15) {		// distance should be changed
//			os << '\t';
//		}
//		os << '\t' << "(" << c.getFirstLetterRow(index) + 1 << ", " << c.getFirstLetterCol(index) + 1 << ")";
//		index++;
//	}
//	return os;
//}


std::vector<std::string> Crossword::getQuestions() {
    // return vector of questions
    return solutions.questions();
}


std::vector<std::string> Crossword::getRandomQuestions() {
    // return vector of questions
    return solutions.getRandomQuestions(answerList);
}


std::string Crossword::getOrientation(const int NOQuestion) {
    // return orientation of word by index
    return orientations[NOQuestion];
}


std::vector<int> Crossword::getFirstLetterCoords(const int NOQuestion) {
    // return vector of x,y position of first letter of the word
    return firstLettersCoords[NOQuestion];
}


int Crossword::getIndexAnswer(const string word) {
    // return index of answer in dictionary
    return solutions.find_index(word);
}


int Crossword::getIndexAnswerList(const string word) {
    // return index of answer in dictionary
    for (int i = 0; i < sizeListAnswers(); i++) {
        if (answerList[i] == word) {
            return i;
        }
    }
}

int Crossword::letterPosition(const string word, const char letter) {
    // return position of letter in the word
    int position = 0;
    for (int i = 0; i < word.size(); i++) {
        if (word[i] == letter) {
            position = i;
            return position;
        }
    }
    throw std::out_of_range("No letter");
}

int Crossword::getLetterRow(const string word, const char letter) {
    // return X position of word`s letter on the board
    int NOQuestion = getIndexAnswerList(word);
    string orientation = getOrientation(NOQuestion);
    int row = getFirstLetterRow(NOQuestion);
    int position = letterPosition(word, letter);
    if (orientation == "vertically") {
        row += position;
    }
    return row;
}

int Crossword::getLetterCol(const string word, const char letter) {
    // return Y position of word`s letter on the board
    int NOQuestion = getIndexAnswerList(word);
    string orientation = getOrientation(NOQuestion);
    int col = getFirstLetterCol(NOQuestion);
    int position = letterPosition(word, letter);
    if (orientation == "horizontally") {
        col += position;
    }
    return col;
}


int Crossword::getLetterRow(const string word) {
    // return X position of first word`s letter
    int NOQuestion = getIndexAnswerList(word);
    int row = getFirstLetterRow(NOQuestion);
    return row;
}


int Crossword::getLetterCol(const string word) {
    // return Y position of first word`s letter
    int NOQuestion = getIndexAnswerList(word);
    int col = getFirstLetterCol(NOQuestion);
    return col;
}


int Crossword::getFirstLetterRow(const int NOQuestion) {
    // return X position of first word`s letter by index
    return getFirstLetterCoords(NOQuestion)[0];
}


int Crossword::getFirstLetterCol(const int NOQuestion) {
    // return Y position of first word`s letter by index
    return getFirstLetterCoords(NOQuestion)[1];
}

int Crossword::sizeWord(const int NOQuestion) {
    // get size of answer using index in list
    string word = correctAnswer(NOQuestion);
    return word.size();
}


char Crossword::checkLetter(const int index, const int nextRow, const int nextCol) {
    // return letter in word by column or row
    // return '-' if using working with word
    if (!checkCoordinate(index, nextRow, nextCol)) {
        return '-';
    }
    if (nextRow == -1) {
        return getLetterByColumn(index, nextCol);
    }
    else if (nextCol == -1) {
        return getLetterByRow(index, nextRow);
    }
}

char Crossword::getLetterByColumn(const int NOQuestion, const int col) {
    // get letter in horizontal word
    string preWord = correctAnswer(NOQuestion);
    int begCol = getFirstLetterCol(NOQuestion);
    for (int i = 0; i < preWord.size() ; i++) {
        if ((i + begCol) == col) {
            return preWord[i];
        }
    }
}

char Crossword::getLetterByRow(const int NOQuestion, const int row) {
    // get letter in vertical word
    string preWord = correctAnswer(NOQuestion);
    int begRow = getFirstLetterRow(NOQuestion);
    for (int i = 0; i < preWord.size(); i++) {
        if ((i + begRow) == row) {
            return preWord[i];
        }
    }
}


bool Crossword::checkCoordinate(const int index, const int row, const int col) {
    // checking: is  x or y in correct range of answer`s coordinates
    int begin, coord;
    if (row == -1) {
        begin = getFirstLetterCol(index);
        coord = col;
    }
    else if (col == -1) {
        begin = getFirstLetterRow(index);
        coord = row;
    }
    return isInRange(index, begin, coord);
}


bool Crossword::isInRange(const int index, const int begin, const int coord) {
    // checking given coordinate in range
    int size = sizeWord(index);
    for (int i = 0; i < size ; i++) {
        if ((i + begin) == coord) {
            return true;
        }
    }
    return false;
}

bool Crossword::isSameLetter(const int row, const int col, const char letter) {
    // checking letter on field with given row and column
    char newLetter = '#';
    string curOrientation = "";
    for (int i = 0; i < firstLettersCoords.size(); i++) {
        if (row == firstLettersCoords[i][0]) {
            newLetter = checkLetter(i, -1, col); // check by col, rows are same
            curOrientation = "horizontally";
        }
        else if (col == firstLettersCoords[i][1]) {
            newLetter = checkLetter(i, row, -1); // check by row, cols are same
            curOrientation = "vertically";
        }
        if ((newLetter != '#') && (newLetter != '-')) {
            return AreSameLetters(newLetter, letter);
        }
    }
    return false;
}

bool Crossword::AreSameLetters(const char letter1, const char letter2) {
    // comparing two given letters
    return (letter1 == letter2);
}

bool Crossword::isCorrectField(const int row, const int col, const char letter) {
    // value in field shoud be # or same letter
    if (board.getValue(row, col) == '#') {
        return true;
    }
    else if (isSameLetter(row, col, letter)) {
        return true;
    }
    return false;
}

bool Crossword::isBadPosition(vector<int> coordinates, const std::string answer, const std::string orientation) {
    int dx = 0, dy = 0, comRow, comCol;
    bool notCommon = true; // without common letters
    string comLetterOrientation = "";
    if (orientation == "vertically") { dy = 1; comLetterOrientation = "horizontally"; }
    else if (orientation == "horizontally") { dx = 1; comLetterOrientation = "vertically"; }
    else { throw InvalidOrientation(); }

    if (coordinates.size() == 4) {
        // if letter, to put, has common letter with another word
        comRow = coordinates[2];
        comCol = coordinates[3];
        notCommon = false;
    }
    int y = coordinates[0];
    int x = coordinates[1];
    for (unsigned i = 0; i < answer.size(); i++) {
        try {
            if (!notCommon) {
                if (x == comCol && y == comRow) {
                    if (notContinueAnswer(y, x, comLetterOrientation, answer[i])) {
                        x += dx;
                        y += dy;
                        continue;
                    }
                    else { return true; }
                }
            }
            if (isCorrectField(y, x, answer[i])) {
                x += dx;
                y += dy;
            }
            else { return true; }
        }
        catch (const FieldNotSettedUp&) {
            x += dx;
            y += dy;
            continue;
        }
        catch (const std::out_of_range&) { break; }

    }
    return false;
}

string Crossword::answerOnBoard(const int NOQuestion) {
    // get answer from board by index
    int row = getFirstLetterRow(NOQuestion);
    int col = getFirstLetterCol(NOQuestion);
    int size = sizeWord(NOQuestion);
    string answer = "";
    string orientation = getOrientation(NOQuestion);
    if (orientation == "horizontally") {
        for (int i = 0; i < size ; i++) {
            answer += board.getValue(row, col);
            col += 1;
        }
    }
    else if (orientation == "vertically") {
        for (int i = 0; i < size ; i++) {
            answer += board.getValue(row, col);
            row += 1;
        }
    }
    return answer;
}


int Crossword::countPoints() {
    // count points for each word, comparing given with correct
    int points = 0;
    for (int i = 0; i < firstLettersCoords.size(); i++) {
        if (isCorrectAnswer(i) && notGuessed(i)) {
            points += 10;
            guessed.push_back(i);
            }
    }
    return points;
}


bool Crossword::isCorrectAnswer(const int question_index) {
    return answerOnBoard(question_index) == answerList[question_index];
}


bool Crossword::notGuessed(int index) {
    for (int i = 0; i < guessed.size(); i++) {
        if (i == index) return false;
    }
    return true;
}


int Crossword::maxPoints() {
    // count points for each word, comparing given with correct
    int points = 0;
    for (int i = 0; i < firstLettersCoords.size(); i++) {
        points += 10;
    }
    return points;
}


std::vector <std::vector<int>> Crossword::getFieldsOfQuestion(const int index) {
    std::vector <std::vector<int>> fields;
    std::vector<int> pair = firstLettersCoords.at(index);;
    std::string orientation = orientations.at(index);

    int dx = 0;
    int dy = 0;
    if (orientation == "vertically") dy = 1;
    else if (orientation == "horizontally") dx = 1;

    for (unsigned i = 0; i < solutions.find_word(index).length(); i++) {
        fields.push_back(pair);
        pair.at(0) += dy;
        pair.at(1) += dx;
    }
    return fields;
}


void Crossword::makeCSVFile() {
    // makes CSV File named [name].csv

    std::ofstream c_file(name + ".csv");

    for (int i = 0; i < answerList.size(); i++) {
        c_file << solutions.questions().at(i) << ',';
        c_file << solutions.answers().at(i) << ',';
        c_file << firstLettersCoords.at(i).at(0) << ',';
        c_file << firstLettersCoords.at(i).at(1) << ',';
        c_file << orientations.at(i) << '\n';
    }

    c_file.close();
}


std::vector <Crossword> getCrosswords() {
    ifstream fileH("crosswordNamesData.txt");
    std::vector <std::string> data = parseRows(fileH);
    std::vector <Crossword> crosswords;
    for (auto& rowdata : data) {
        std::vector <std::string> vecrowdata = parseCSV(rowdata);
        if (vecrowdata.size() != 2) throw std::out_of_range("Invalid crossword names data");

        Crossword c = Crossword(vecrowdata.at(0), vecrowdata.at(1));
        crosswords.push_back(c);
    }
    fileH.close();
    return crosswords;
}


bool Crossword::notContinueAnswer(const int row, const int col, const string lastOrientation, const char letter) {
    // can common letter continue previous or next word
    char newLetter = '#';
    for (int i = 0; i < firstLettersCoords.size(); i++) {
        if (lastOrientation == "horizontally") {
            if (col == firstLettersCoords[i][1]) {
                newLetter = checkLetter(i, row, -1); // check by row, cols are same
            }
        }
        else if (lastOrientation == "vertically") {
            if (row == firstLettersCoords[i][0]) {
                newLetter = checkLetter(i, -1, col); // check by col, rows are same
            }
        }
        if ((newLetter != '#') && (newLetter != '-')) {
            if (AreSameLetters(newLetter, letter)) {
                return false;
            };
        }
    }
    return true;
}


std::vector< std::vector<int>> Crossword::getDoubleCoords() {
    std::vector< std::vector<int>> output;
    std::vector< std::vector<int>> v = firstLettersCoords;
    for (int index = 0; index < v.size(); index++) {
        if (twoTimesInVector(v, index) && !isInVector(output, v[index])) {
            output.push_back(v[index]);
        }
    }
    return output;
}


bool isInVector(std::vector< std::vector<int>> v, std::vector<int> ob) {
    return std::find(v.begin(), v.end(), ob) != v.end();
}


bool twoTimesInVector(std::vector< std::vector<int>> v, const int index) {
    std::vector< std::vector<int>>::iterator begin = index + v.begin() + 1;
    std::vector< std::vector<int>>::iterator end = index + v.begin();
    return std::find(begin, v.end(), v[index]) != v.end() || std::find(v.begin(), end, v[index]) != end;
}
