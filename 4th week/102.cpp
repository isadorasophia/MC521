#include <bits/stdc++.h>

using namespace std;

typedef struct Bin {
	long long int b;
	long long int g;
	long long int c;
} Bin;

int main () {
	Bin bin[3];
	string order = "BGC", correctOrder;
	int i;
	long long int minMoved, moved;
	
	while (!(cin >> bin[0].b >> bin[0].g >> bin[0].c >> bin[1].b
			>> bin[1].g >> bin[1].c >> bin[2].b >> bin[2].g >> bin[2].c).eof()) {
		minMoved = 9 * pow(2, 31);
		
		order = "BCG";
		
		do {
			moved = 0;
			
			for (i = 0; i < 3; i++) {
				if ('B' == order[i]) {
					moved += bin[i].g + bin[i].c;
				}
				else if ('G' == order[i]){
					moved += bin[i].b + bin[i].c;
				}
				else if ('C' == order[i]) {
					moved += bin[i].g + bin[i].b;
				}
			}
			
			if (moved < minMoved) {
				minMoved = moved;
				
				correctOrder = order;
			}
		} while (next_permutation(order.begin(), order.end()));
		
		cout << correctOrder;
		
		printf(" %lld\n", minMoved);
	}

	return 0;
}
