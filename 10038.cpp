#include <bits/stdc++.h>

using namespace std;

bool isJolly (vector <int> sequence) {
	vector <int> diff;
	int i;
	bool numbers[(int)sequence.size()];
	
	for (i = 0; i < (int)sequence.size(); i++) {
		numbers[i] = false;
	}
	
	for (i = 0; i < (int)sequence.size() - 1; i++) {
		diff.push_back(abs(sequence[i + 1] - sequence[i]));
	}
	
	for (i = 0; i < (int)sequence.size() - 1; i++) {
		if (diff[i] != 0 && diff[i] < (int)sequence.size() && numbers[diff[i]] == false) {
			numbers[diff[i]] = true;
		} else {
			return false;
		}
	}
	
	return true;
}

int main () {
	int size, number, i;
	vector <int> sequence;
	
	while (!(cin >> size).eof()) {
		for (i = 0; i < size; i++) {
			cin >> number;
			
			sequence.push_back(number);
		}
		
		if (isJolly (sequence)) {
			cout << "Jolly" << endl;
		} else {
			cout << "Not jolly" << endl;
		}
		
		sequence.clear();
	}

	return 0;
}
