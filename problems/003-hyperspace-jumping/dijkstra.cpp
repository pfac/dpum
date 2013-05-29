#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

/* The maximum number of systems */
#define N_LIMIT 10000

/* A jump in the hyperspace (or an edge in the graph if you rather think
 * about it that way), here represented by a pair of system IDs, the origin
 * and the destiny (wormholes are one way only, m'kay?)
 */
typedef pair<int,int> jump;

/* A system, here represented by the vector of wormholes you can follow once
 * you get there.
 */
typedef vector<jump> solar_system;

/* The Universe, here represented as an array of systems (we can't get
 * anywhere else so this must be it as far as universes go).
 */
solar_system universe[N_LIMIT];

/* A travel destiny, the cost of reaching a system and the destiny system ID.
 * The cost comes first so we can order the destinies by cost.
 */
typedef pair<int,int> destiny;

/* The collection of destinies, in ascendant order of cost. Because your poor
 * and you know it. Shame on you.
 */
typedef priority_queue<destiny, vector<destiny>, greater<destiny> > destinies;

/* Our collection of affordable traveling destinys, ordered by their ID */
priority_queue<int, vector<int>, greater<int> > found;

int energy;

typedef pair<int,int> ccad;// cumulative_cost_and_destiny



void dijkstra (int start) {
	destinies ds;// The queue
	int costs[N_LIMIT];// the cost to reach each system
	int visited[N_LIMIT] = {0};

	ds.push(make_pair(0, start));// add the origin

	// fill the system costs 
	memset(costs, 127, sizeof(int) * N_LIMIT);

	// set the cost of the origin to zero
	costs[start] = 0;
	
	while (!ds.empty()) {
		// get the next destiny
		destiny current = ds.top();
		ds.pop();

		// get it's index
		int i = current.second;

		// check if we were already here, no need to do it twice
		if (visited[i]) continue;

		// does this, the next cheapest destiny exceed our available energy?
		// if yes, just stop everything, we are not getting better than this
		if (costs[i] > (energy - 1)) break;

		// otherwise, add it to our collection of affordable traveling destinies
		found.push(i);

		// and mark it as visited, no need to do it twice
		visited[i] = 1;

		// now let's check it's exit wormholes
		for (unsigned j = 0; j < universe[i].size(); ++j) {
			// know thy neighbor
			int neighbor = universe[i][j].first;

			// and the cost of traveling there
			int cost = universe[i][j].second;

			// and add it to the cost so far
			int cost2neighbor = costs[i] + cost;

			// is this neighbor unvisited, or is this new cost better?
			if (!visited[neighbor] || costs[neighbor] > cost2neighbor) {
				// if yes, push it to our amazing possible destiny collection
				ds.push(make_pair(cost2neighbor, neighbor));

				// and set this possible destiny cost
				costs[neighbor] = cost2neighbor;
			}
			// otherwise just pretend you never saw this neighbor *innocent whistling*
		}
	}
}



int main () {
	string line;
	int n_nodes, start, n_edges;

	getline(cin, line);
	sscanf(line.c_str(), "%d", &n_nodes);

	getline(cin, line);
	sscanf(line.c_str(), "%d", &energy);

	getline(cin, line);
	sscanf(line.c_str(), "%d", &start);

	getline(cin, line);
	sscanf(line.c_str(), "%d", &n_edges);

	for (int e = 0; e < n_edges; ++e) {
		int origin, destiny, cost;
		getline(cin, line);
		sscanf(line.c_str(), "%d %d %d", &origin, &destiny, &cost);
		universe[origin].push_back(make_pair(destiny, cost));
	}

	#ifdef DEBUG
	cout
		<< "#NODES: " << n_nodes << endl
		<< "ENERGY: " << energy << endl
		<< "START: " << start << endl
		<< "#EDGES: " << n_edges << endl
		;

	for (int n = 1; n <= n_nodes; ++n) {
		for (unsigned e = 0; e < universe[n].size(); ++e) {
			cout << "EDGE FROM " << n << " TO " << universe[n][e].first << " COSTING " << universe[n][e].second << endl;
		}
	}
	#endif

	dijkstra(start);

	// print it decently, without that extra space in the end
	if (!found.empty()) {
		cout << found.top();
		found.pop();
		while (!found.empty()) {
			cout << ' ' << found.top();
			found.pop();
		}
	}
	cout << endl;

	return 0;
}
