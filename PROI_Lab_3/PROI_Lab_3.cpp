#include "Board.h"
#include <iostream>

int main()
{
	// create board
    Board a(2, 2);
	std::cout << a << std::endl;

	// print board column and row length
	std::cout << a.get_col_len() << a.get_row_len() << std::endl;

	// fill board
	std::cin >> a;
	std::cout << a << std::endl;

	// fill board by .fill_field()
	a.fill_field(0, 0, "a"[0]);
	a.fill_field(0, 1, " "[0]);
	a.fill_field(1, 0, "c"[0]);
	a.fill_field(1, 1, "d"[0]);

	// add two boards
	Board b(2, 2);
	Board c = b + a;
	std::cout << c << std::endl;

	// increment board
	Board d = a++;
	std::cout << d << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;

	// decrement board
	Board e = a--;
	std::cout << e << std::endl;
	std::cout << --a << std::endl;
	std::cout << a << std::endl;
}

