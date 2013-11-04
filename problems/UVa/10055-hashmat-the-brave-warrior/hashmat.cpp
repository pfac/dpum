#include <iostream>
#include <sstream>

#include <cmath>
#include <stdint.h>

#define DIFF(x,y) ((x) > (y) ? (x) - (y) : (y) - (x))

using namespace std;

int main () {
	string line;

	while (getline(cin, line)) {
		stringstream ss;
		int64_t army[2];

		ss << line;
		ss >> army[0] >> army[1];

		int64_t diff = DIFF(army[0], army[1]);

		cout << diff << endl;
	}
	
	return 0;
}
