#include <iostream>
#include <iostream>
#include <cmath>
#include <numeric>
#include <sstream>
#include "Player.h"


Player::Player(std::string newName) {
	Player::setName(newName);
}


void Player::setName(std::string newName) {
	Player::name = newName;
}


void Player::substractPoints(unsigned int noPoints) {
	if (noPoints > points) points = 0;
	else points -= noPoints;
}


int Player::getAveragePoints() {
	const std::vector<int>& stats = Player::pointList;
	return 1.0 * std::accumulate(stats.begin(), stats.end(), 0) / stats.size();
}


void Player::endGame() {
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