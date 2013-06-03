#include <iostream>
#include <string>
#include <sstream>
#include <queue>
using namespace std;

#define MAX_ELEMS 250000

int energy;
int start_x, start_y;// initial position
int width, height;// dimensions of the storm
bool visited[MAX_ELEMS];// the visited
int costs[MAX_ELEMS];// the costs of moving in the storm
int steps[MAX_ELEMS];// the total steps to get to a cell
int totals[MAX_ELEMS];// the total cost of getting to a cell



#ifdef DEBUG

	void printm (int * m, int w, int h) {
		for (int i = 0; i < h; ++i) {
			for (int j = 0; j < w; ++j) {
				cout << m[i * w + j] << ' ';
			}
			cout << endl;
		}
	}

#endif



struct point {
	int x;
	int y;
	int s;
	int c;
	int last_x;
	int last_y;

	point() : x(0), y(0), s(0), c(numeric_limits<int>::max()) {}

	point(int x, int y, int s, int c, int last_x, int last_y) :
		x(x), y(y), s(s), c(c), last_x(last_x), last_y(last_y) {}

	bool operator< (const point& p) {
		return c < p.c
		|| (c == p.c && s <  p.s)
		|| (c == p.c && s == p.s && x <  p.x)
		|| (c == p.c && s == p.s && x == p.x && y < p.y);
	}

	bool is_outside () { return x < 0 || x >= width || y < 0 || y >= height; }

	int index () { return y * width + x; }

} best;




void solve () {
	queue<point> q;
	q.push(point(start_x - 1, start_y - 1, 0, 0, start_x, start_y));

	while (!q.empty()) {
		point p = q.front(); q.pop();

		if (p.is_outside()) {

			if (p < best)
				best = p;

		} else {

			int i = p.index();
			int c = p.c + costs[i];

			if (c >= energy) continue;

			if (!visited[i] || c < totals[i]) {
				visited[i] = true;
				totals[i] = c;
				int s = p.s + 1;

				q.push(point(p.x, p.y - 1, s, c, p.x, p.y));
				q.push(point(p.x + 1, p.y, s, c, p.x, p.y));
				q.push(point(p.x, p.y + 1, s, c, p.x, p.y));
				q.push(point(p.x - 1, p.y, s, c, p.x, p.y));
			}
		}
	}
}



int main () {
	string line;
	int n_cases;

	getline(cin, line);
	sscanf(line.c_str(), "%d", &n_cases);

	#ifdef DEBUG
		cout << "#CASES: " << n_cases << endl;
	#endif

	for (int c = 0; c < n_cases; ++c) {
		getline(cin, line);
		sscanf(line.c_str(), "%d %d %d", &energy, &start_x, &start_y);

		getline(cin, line);
		sscanf(line.c_str(), "%d %d", &width, &height);

		for (int i = 0; i < height; ++i) {
			stringstream ss;

			getline(cin, line);
			ss << line;
			for (int j = 0; j < width; ++j) {
				int cost;
				ss >> cost;
				costs[i * width + j] = cost;
			}
		}

		#ifdef DEBUG
			cout << "ENERGY: " << energy << endl;
			cout << "(x,y): " << start_x << ' ' << start_y << endl;
			cout << "w _ h: " << width << ' ' << height << endl; 
			printm(costs, width, height);
		#endif

		best.s = 0;

		solve();

		if (best.s > 0) {
			cout << energy - best.c << ' ' << best.last_x + 1 << ' ' << best.last_y + 1 << ' ' << best.s - 1 << endl;
		} else
			cout << "Goodbye cruel world!" << endl;
	}

	return 0;
}
