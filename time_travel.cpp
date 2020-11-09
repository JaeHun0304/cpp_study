#include <vector>
#include <iostream>
#include <limits>

using namespace std;

int main(){

	int W = 4, G = 4;
	int MAX_V = 100;
	vector<pair<int, int>> adj[MAX_V];

	adj[1] = { make_pair(0, 4), make_pair(4, -4) };
	adj[2] = { make_pair(0, 4), make_pair(3, 5) };
	adj[3] = { make_pair(2, -7) };
	adj[4] = { make_pair(4, -1) };




}