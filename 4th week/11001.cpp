#include <bits/stdc++.h>

using namespace std;

int main () {
	double maxLenght, lenght, Vtotal, V0, currentV, dif;
	int N, maxN;
	bool unique;
	
	scanf("%lf %lf", &Vtotal, &V0);
	
	while (Vtotal || V0) {
		currentV = Vtotal;
		maxLenght = 0;
		maxN = 0;
		unique = true;
		
		if (V0 != 0) {
			for (N = 1; currentV > V0; currentV = Vtotal/++N) {
				lenght = (0.3 * sqrt(currentV - V0)) * N;
				
				dif = lenght - maxLenght;
				
				if (abs(dif) <= pow(10, -6)) {
					unique = false;
				} else if (dif > pow (10, -6)) {
					unique = true;			
					maxLenght = lenght;
					maxN = N;
				}
			}
		}
		
		if (unique)
			printf("%d\n", maxN);
		else
			printf("0\n");
		
		scanf("%lf %lf", &Vtotal, &V0);
	}
	

	return 0;
}
