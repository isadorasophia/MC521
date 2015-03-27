#include <bits/stdc++.h>

using namespace std;

typedef Struct People {
	int time;
	bool left;
	bool right;
} People;

int main () {
	int nCases, n;
	People people[1005];
	int totalTime;
	bool left, right;
	
	cin >> nCases;
	
	while (nCases--) {
		totalTime = 0;
		letf = true;
		right = false;
		
		cin >> n;
		
		for (i = 0; i < n; i++) {
			cin >> people[i].time;
			people[i].left = true;
			people[i].right = false;
		}
		
		sort (people, people + n);
		
		totalTime += people[0].time + people[1].time;
		right = true;
		left = false;
		
		for (i = n; i > 1; i -= 2) {
			if (right) {
				totalTime += people[i - 1] + people[i];
				totalTime += people[0]
			} else if (left) {
				
			}
		}
	}

	return 0;
}
