#include <bits/stdc++.h>

using namespace std;

int main () {
	string code;
	int i, j, position;
	bool successor;
	char aux;
	
	cin >> code;
	
	while (code.compare("#") != 0) {
		successor = false;
		
		for (i = (int)code.size() - 1; i >= 0 && !successor; i--) {
			for (j = i - 1; j >= 0 && !successor; j--) {
				if (code[j] < code[i]) {
					aux = code[i];
					code[i] = code[j];
					code[j] = aux;
					
					position = j;
					
					successor = true;
				}
			}
		}
		
		if (successor) {
			sort(code.begin() + position + 1, code.end());
			cout << code << endl;
		}
		else
			cout << "No Successor" << endl;
			
		code.clear();
		cin >> code;
	}

	return 0;
}
