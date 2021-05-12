#include <iostream>
#include <iostream>
#include <cmath>
#include <numeric>
#include <sstream>
#include <string>
#include "Player.h"


Player::Player(const std::string newName) {
	Player::setName(newName);
}


void Player::setName(const std::string newName) {
	Player::name = newName;
}


void Player::substractPoints(const unsigned int noPoints) {
	if (points < noPoints) {
		points = 0;
	}
	else {
		points -= noPoints;
	}
	// points = std::max(zero, points - noPoints);
}


int Player::getAveragePoints() {
	const std::vector<int>& stats = Player::pointList;
	return 1.0 * std::accumulate(stats.begin(), stats.end(), 0) / stats.size();
}


void Player::newGame() {
	pointList.push_back(points);
	resetPoints();
}


std::string Player::getStatistisc() {
	const std::vector <int>& stats = Player::pointList;
	if (stats.empty()) {
		return "No statistics to show\n";
	}

	std::stringstream records;
	records << "Game\tPoints\n";
	for (std::size_t i = 0; i < stats.size(); ++i) {

		records << i + 1 << '\t' << stats.at(i) << '\n';
	}
	return records.str();
}


Player& Player::operator+=(const int rhs) {
	addPoints(rhs);
	return *this;
}


Player& Player::operator-=(const int rhs) {
	substractPoints(rhs);
	return *this;
}


Player& Player::operator++() {
	points++;
	return *this;
}


Player& Player::operator--() {
	if (points < 1) return *this;
	points--;
	return *this;
}


Player Player::operator++(int) {
	Player temp = *this;
	++* this;
	return temp;
}


Player Player::operator--(int) {
	Player temp = *this;
	--* this;
	return temp;
}


Player operator+(const Player& player1, const Player& player2) {
	Player player;

	player.setName(player1.getName());
	player.setPoints(player1.getPoints() + player2.getPoints());


	player.pointList.insert(player.pointList.begin(), player1.pointList.begin(), player1.pointList.end());
	player.pointList.insert(player.pointList.end(), player2.pointList.begin(), player2.pointList.end());

	return player;
}


inline void InvalidPointsMessage() {
	std::cout << "Invalid number of points ";
}


bool stringDigit(std::string data) {
	for (char character : data) {

		if (!std::isdigit(character)) {
			InvalidPointsMessage();
			return false;
		}
	}
	return true;
}


std::ostream& operator<<(std::ostream& os, const Player& player)
{
	os << player.name << "," << player.points;
	for (int points : player.pointList) {
		os << "," << points;
	}
	os << '\n';
	return os;
}


std::istream& operator>>(std::istream& input, Player& player)
{
	std::vector <std::string> data;
	std::string temp;
	while (getline(input, temp, ',')) {
		data.push_back(temp);
	}

	if (data.size() < 2) {
		std::cout << "Invalid data";
		return input;
	}

	player.setName(data.at(0));

	if (!stringDigit(data.at(1))) return input;
	player.setPoints(stoi(data.at(1)));

	for (int i = 2; i < data.size(); i++) {
		if (!stringDigit(data.at(i))) return input;
		player.pointList.push_back(stoi(data.at(i)));
	}
	return input;
}
