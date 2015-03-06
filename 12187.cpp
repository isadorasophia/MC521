#include <bits/stdc++.h>

using namespace std;

typedef struct Land {
	int owner;
	int pastOwner;
} Land;

int main () {
	int N, R, C, K, i, j;
	int hated;
	Land land[100][100];
	
	cin >> N >> R >> C >> K;
	
	while (N != 0 && R != 0 && C != 0 && K!= 0) {
		for (i = 0; i < R; i++) {
			for (j = 0; j < C; j++) {
				cin >> land[i][j].pastOwner;
				land[i][j].owner = land[i][j].pastOwner;
				
			}
		}
		
		while (K--) {
			for (i = 0; i < R; i++) {
				for (j = 0; j < C; j++) {
					if (land[i][j].pastOwner != N - 1)
						hated = land[i][j].pastOwner + 1;
					else {
						hated = 0;
					}	
					
					if (j != C - 1 && land[i][j + 1].pastOwner == hated)
						land[i][j + 1].owner = land[i][j].pastOwner;
						
					if (i != R - 1 && land[i + 1][j].pastOwner == hated)
						land[i + 1][j].owner = land[i][j].pastOwner;
						
					if (i != 0 && land[i - 1][j].pastOwner == hated)
						land[i - 1][j].owner = land[i][j].pastOwner;
						
					if (j != 0 && land[i][j - 1].pastOwner == hated)
						land[i][j - 1].owner = land[i][j].pastOwner;
				}
			}
			
			for (i = 0; i < R; i++) {
				for (j = 0; j < C; j++) {
					land[i][j].pastOwner = land[i][j].owner;
				}
			}
		}
		
		for (i = 0; i < R; i++) {
			for (j = 0; j < C; j++) {
				if (j == C - 1)
					cout << land[i][j].owner;
				else 
					cout << land[i][j].owner << " ";
			}
			
			cout << endl;
		}
		
		cin >> N >> R >> C >> K;
	}

	return 0;
}
