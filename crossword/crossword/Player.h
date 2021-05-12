#pragma once
#include <iostream>
#include <vector>


class Player {
private:
	std::string name = "";
	unsigned int points = 0;
	std::vector< int > pointList;

	void setPoints(unsigned int noPoints) { points = noPoints; }

public:
	Player() {};
	Player(const std::string newName);
	std::string getName() { return name; }
	const std::string getName() const { return name; }
	int getPoints() { return points; }
	const int getPoints() const { return points; }
	std::vector< int > getPointList() { return pointList; };

	void setName(const std::string newName);

	void addPoints(const unsigned int noPoints) { points += noPoints; }
	void resetPoints() { points = 0; }
	void substractPoints(const unsigned int noPoints);
	int getAveragePoints();
	std::string getStatistisc();

	void newGame();

	Player& operator+=(const int rhs);
	Player& operator-=(const int rhs);
	Player& operator++();
	Player& operator--();
	Player operator++(int);
	Player operator--(int);
	friend Player operator+(const Player& player1, const Player& player2);
	friend std::ostream& operator<<(std::ostream& os, const Player& player);
	friend std::istream& operator>>(std::istream& input, Player& player);

};

