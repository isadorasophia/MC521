#include <bits/stdc++.h>

using namespace std;

int main () {
	int N, i, peaks = 0;
	int loop[10000], magnitude[1000];
	
	cin >> N;
	
	while (N) {
		peaks = 0;
		
		for (i = 0; i < N; i++)
			cin >> loop[i];
		
		for (i = 0; i < N - 1; i++)
			magnitude[i] = loop[i] - loop[i + 1];
			
		magnitude[i] = loop[i] - loop[0];
			
		for (i = 0; i < N - 1; i++) {
			if (magnitude[i] > 0 && magnitude[i + 1] < 0)
				peaks++;
			else if (magnitude[i] < 0 && magnitude[i + 1] > 0)
				peaks++;
		}
				
		if (magnitude[i] > 0 && magnitude [0] < 0)
			peaks++;
		else if (magnitude[i] < 0 && magnitude [0] > 0)
			peaks++;
		
		cout << peaks << endl;
		
		cin >> N;
	}

	return 0;
}
