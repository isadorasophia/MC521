#include <bits/stdc++.h>

using namespace std;

int byeDays (vector <int> hartal, int days) {
	int calendar[days + 1], i, day, count = 0;
	
	for (i = 0; i < days + 1; i++) {
		calendar[i] = 0;
	}
	
	for (i = 6; i < days + 1; i += 7) {
		calendar[i] = 1;
	}
	
	for (i = 7; i < days + 1; i += 7) {
		calendar[i] = 1;
	}
	
	for (i = 0; i < (int)hartal.size(); i++) {
		day = hartal[i];
		
		while (day <= days) {
			if (calendar[day] == 0) {
				calendar[day] = 1;
				count++;
			}
			
			day += hartal[i];
		}
	}
	
	return count;
}

int main () {
	int testN, days, hartalsSize, h;
	vector <int> hartal;
	
	cin >> testN;
	
	while (testN--) {
		cin >> days >> hartalsSize;
		
		while (hartalsSize--) {
			cin >> h;
			
			hartal.push_back(h);
		}
		
		cout << byeDays(hartal, days) << endl;
		
		hartal.clear ();
	}
	
	return 0;
}
