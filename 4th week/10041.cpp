#include <bits/stdc++.h>

using namespace std;

int main () {
	int t, r, i, j;
	int minSum, aux, home;
	vector <int> rel;
	
	cin >> t;
	
	while (t--) {
		minSum = 0;
		
		scanf("%d", &r);
		
		for (i = 0; i < r; i++) {
			scanf("%d", &aux);
			
			rel.push_back(aux);
		}
		
		sort (rel.begin(), rel.end());
		
		home = rel[r/2];
		
		for (j = 0; j < r; j++) {
			minSum += abs(home - rel[j]);
		}
		
		printf("%d\n", minSum);
		
		rel.clear();
	}

	return 0;
}
