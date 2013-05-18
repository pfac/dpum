/** NOTA: esta implementação não consegue resolver o problema "Hyperspace Jumping" na sua versão original, por isso não passa no Mooshak.
 */
#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

#define N_LIMIT 10000

vector<int> universe[N_LIMIT];
priority_queue<int> found;
int visited[N_LIMIT] = {0};



void flood (int start) {
	queue<int> q;
	q.push(start);
	
	while (!q.empty()) {
		int current = q.front();
		q.pop();

		if (visited[current]) continue;

		found.push(- current);
		visited[current] = 1;

		for (unsigned n = 0; n < universe[current].size(); ++n)
			q.push(universe[current][n]);
	}
}



int main () {
	string line;
	int n_nodes, energy, start, n_edges;

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
		universe[origin].push_back(destiny);
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
			cout << "EDGE FROM " << n << " TO " << universe[n][e] << endl;
		}
	}
	#endif

	flood(start);

	while (!found.empty()) {
		cout << - found.top() << ' ';
		found.pop();
	}
	cout << endl;

	return 0;
}
