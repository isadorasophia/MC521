#include <bits/stdc++.h>

using namespace std;

int main () {
	int T, i, current = 0;
	string proibida, bracelete;
	bool found = false, cycled = false;

	cin >> T;
	
	while (T--) {
		cin >> proibida >> bracelete;
		
		current = 0;
		cycled = false;
	
		for (i = 0; i < (int)bracelete.size() && !found; i++) {
			if (current == 0 && cycled == true) {
				break;
			}
			
			if (bracelete[i] == proibida[current]) {
				current++;
				
				if (i + 1 >= (int)bracelete.size()) {
					i = -1;
					cycled = true;
				}
			} else {
				current = 0;
			}
			
			if (current == (int)proibida.size()) {
				found = true;
			}
		}
		
		cycled = false;
		current = 0;
		
		// Now go check backwards
		for (i = bracelete.size() - 1; i >= 0 && !found; i--) {			
			if (current == 0 && cycled == true) {
				break;
			}
			
			if (bracelete[i] == proibida[current]) {
				current++;
				
				if (i - 1 < 0) {
					i = bracelete.size();
					cycled = true;
				}
			} else {
				current = 0;
			}
			
			if (current == (int)proibida.size()) {
				found = true;
			}
		}
		
		if (found)
			cout << "S" << endl;
		else
			cout << "N" << endl;
		
		found = false;
		proibida.clear();
		bracelete.clear();
	}

	return 0;
}
