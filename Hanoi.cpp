#include <iostream>
#include <queue>
#include <cstring>
#include <array>
#include <algorithm>

using namespace std;

const int MAX_DISCS = 5;
int c[1<<(MAX_DISCS * 2)];

//bitmask makes us use single int variable as array!
int get(int state, int index){
	return ((state >> (index * 2)) & 3);
}

int set(int state, int index, int value){
	return ((state & ~(3 << (index * 2))) | (value << (index * 2)));
}

int main(){

	fill_n(c, 1<<(MAX_DISCS * 2), -1);

	int begin = 0b1010011100;
	int end = 0b1111111111;

	if(begin == end) return 0;
	queue<int> q;
	c[begin] = 0;
	q.push(begin);

	while(!q.empty()){
		int here = q.front(); q.pop();

		//same as int top[4] = {-1, -1, -1, -1}
		array<int, 4> top = {-1, -1, -1, -1};
		for(int i = MAX_DISCS - 1; i >= 0; i--){
			top[get(here, i)] = i;
		}

		for(int i = 0; i < 4; i++){
			if(top[i] != -1){
				for(int j = 0; j < 4; j++){
					if( (i != j) && (top[j] == -1 || (top[i] < top[j])) ){
						int there = set(here, top[i], j);
						//continue if c[there] is already visited
						if(c[there] != -1) continue;
						c[there] = c[here] + 1;
						if(there == end){
							cout << "found!" << endl;
							cout << c[there] << endl;
							cin.get();
							return 0;
						}
						q.push(there);
					}
				}
			}
		}
	}

	return -1;
}