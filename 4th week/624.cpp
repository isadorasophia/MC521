#include <bits/stdc++.h>

using namespace std;

int totalTracks[22];
int totalIndex;

int findSum (int index, bool used[], int tracks[], int max, int maxIndex, int *maxSum) {
	int sum1 = 0, sum2 = 0;
	
	if (index == maxIndex) {
		int i;
		
		for (i = 0; i < maxIndex; i++) {
			if (used[i] == true)
				sum1 += tracks[i];
		}
		
		if (sum1 > *maxSum && sum1 <= max) {
			*maxSum = sum1;
			totalIndex = 0;
			
			for (i = 0; i < maxIndex; i++) {
				if (used[i] == true) {
					totalTracks[totalIndex++] += tracks[i];
				}
			}
		}
		
		if (sum1 <= max)
			return sum1;
		else
			return 0;
	}
		
	used[index] = false;
	sum1 = findSum(index + 1, used, tracks, max, maxIndex, maxSum);
	
	used[index] = true;
	sum2 = findSum(index + 1, used, tracks, max, maxIndex, maxSum);
	
	if (sum1 > sum2)
		return sum1;
	else
		return sum2;
}

int main () {
	int N, t, i;
	int tracks[22], maxSum;
	bool used[22];
	
	while (!(cin >> N >> t).eof()) {
		maxSum = 0;
		
		for (i = 0; i < t; i++) {
			scanf("%d", &tracks[i]);
		}
		
		cout << "sum:" << findSum (0, used, tracks, N, t, &maxSum) << endl;
	}

	return 0;
}
