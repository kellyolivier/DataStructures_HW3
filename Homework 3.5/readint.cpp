#include "readint.h"
#include <iostream>
#include <stdexcept>
using namespace std;

int read_int(const string &prompt, int low, int high)
{
	cin.exceptions(ios_base::failbit);
	int range = 0;
	if (low >= high) {
		throw(invalid_argument("Invalid range: High less than low or low is greater than high"));
	}

	while (true) {
		try {
			cout << prompt;
			cin >> range;

			if (range <= low || range >= high)
			{
				throw(range_error("The range number inputed is out of range/n"));
			}
			return range;
		}

		catch (range_error& e) { cout << e.what(); }
		catch (ios_base::failure &ex) {
			cout << "you entered invalid input" << endl;
			cin.clear();
			cin.ignore(numeric_limits<int>::max(), '\n');
		}
	}
}
