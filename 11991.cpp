#include <bits/stdc++.h>

using namespace std;

typedef struct Number {
	int freq;
	vector <int> pos;
} Number;

int main () {
	int i, n, m , k, v, aux;
	map <int, Number> numbers;
	Number input;
	
	while (cin >> n >> m) {
		for (i = 0; i < n; i++) {
			cin >> aux;
			
			if (numbers.find(aux) != numbers.end()) {
				numbers[aux].freq++;
				numbers[aux].pos.push_back(i + 1);
			} else {
				input.freq = 1;
				input.pos.push_back(i + 1);
				
				numbers[aux] = input;
				
				input.pos.clear();
			}
		}
		
		for (i = 0; i < m; i++) {
			cin >> k >> v;
			
			if (numbers.find(v) != numbers.end()) {
				if (k <= numbers[v].freq)
					cout << numbers[v].pos[k - 1] << endl;
				else
					cout << "0" << endl;
			}
			else {
				cout << "0" << endl;
			}
		}
		
		numbers.clear();
	}

	return 0;
}
