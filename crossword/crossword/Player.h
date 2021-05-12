#pragma once
#include <iostream>
#include <vector>


class Player {
private:
	std::string name="";
	unsigned int points=0;
	std::vector< int > pointList;

public:
	Player() {};
	Player(std::string newName);
	inline std::string getName() { return name; }
	inline int getPoints() { return points; }
	inline std::vector< int > getPointList() { return pointList; };

	void setName(std::string newName);
	
	inline void addPoints(unsigned int noPoints) { points += noPoints; }
	inline void resetPoints() { points = 0; }
	void substractPoints(unsigned int noPoints);
	int getAveragePoints();
	std::string getStatistisc();

	void endGame();
	
};
