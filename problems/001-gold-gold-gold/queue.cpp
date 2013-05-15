#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <utility>
using namespace std;

#define GLOIN '@'
#define TILE  '#'
#define GOLD  '%'



int rows, cols;
int gloin_r, gloin_c;
vector<string> mapa;
int gold = 0;



#ifdef DEBUG
void print_mapa() {
	for (int r = 0; r < rows; ++r) {
		for (int c = 0; c < cols; ++c)
			cout << mapa[r][c];
		cout << endl;
	}
}
#endif



void fill (int r, int c) {
	queue< pair<int,int> > cells;
	cells.push(make_pair<int,int>(r,c));

	while (!cells.empty()) {
		pair<int,int> cell = cells.front(); cells.pop();
		int r = cell.first;
		int c = cell.second;

		if (r < 0 || r >= rows || c < 0 || c >= cols)
			continue;

		char here = mapa[r][c];
		switch (here) {
			case TILE:
				continue;
			case GOLD:
				gold++;
			default:
				mapa[r][c] = TILE;
		}
		cells.push(make_pair<int,int>(r-1,c));
		cells.push(make_pair<int,int>(r+1,c));
		cells.push(make_pair<int,int>(r,c+1));
		cells.push(make_pair<int,int>(r,c-1));
	}
}



int main () {
	string line;
	
	// read dimensions
	getline(cin, line);
	sscanf(line.c_str(), "%d %d", &cols, &rows);

	#ifdef DEBUG
	cout << rows << endl;
	cout << cols << endl;
	#endif

	for (int r = 0; cin; ++r) {
		int c;
		getline(cin, line);
		c = line.find(GLOIN);
		if (c != (int)string::npos) {
			gloin_r = r;
		 	gloin_c = c;
		}
		mapa.push_back(line);
	}

	fill(gloin_r, gloin_c);

	cout << gold << endl;

	#ifdef DEBUG
	print_mapa();
	#endif

	return 0;
}
