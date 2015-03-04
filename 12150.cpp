#include <bits/stdc++.h>

using namespace std;

#define LIMIT 1000

typedef struct Car {
	int number;
	int positions;
} Car;

int main () {
	int N, i;
	int initial[LIMIT];
	
	Car final[LIMIT];
	Car temp;
	
	bool impossible = false;
	
	cin >> N;
	
	fill (initial, initial + LIMIT, 0);
	
	// Proceeds to calculate for the following race until its over
	while (N) {
		// Input
		for (i = 0; i < N; i++) {
			cin >> temp.number >> temp.positions;
			
			final[i] = temp;
		}
		
		for (i = 0; i < N && !impossible; i++) {
			if (final[i].positions == 0) {
				initial[i] = final[i].number;
			}
			else {
				if ((final[i].positions + i) >= 0 && (final[i].positions + i) < N 
					&& initial[final[i].positions + i] == 0) {
					initial[final[i].positions + i] = final[i].number;
				} else {
					impossible = true;
				}
			}
		}
		
		if (!impossible) {
			for (i = 0; i < N - 1 && !impossible; i++) {
				cout << initial[i] << " ";
			}
			
			cout << initial[i] << endl;
		} else {
			cout << -1 << endl;
		}
		
		impossible = false;
		fill (initial, initial + N, 0);
		
		cin >> N;
	}

	return 0;
}
