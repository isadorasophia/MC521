#include <bits/stdc++.h>

using namespace std;

int main () {
	int i, j, stacks = 0, priority = 0, numberCase = 0;
	string input;
	vector <int> req;
	bool newStack;
	
	cin >> input;
	
	while (input.compare("end") != 0) {
		numberCase++;
		stacks = 0;
		
		for (i = 0; i < (int)input.size(); i++) {
			newStack = true;
			priority = 0;
			
			// First, assigns a priority	
			for (j = i + 1; j < (int)input.size(); j++) {
				if (input[i] >= input[j] && input[j] > priority)
					priority = input[j];
			}
			
			for (j = 0; j < (int)req.size() && newStack; j++) {
				// Meaning it is proper to use for req
				if (input[i] == req[j]) {
					newStack = false;
					req[j] = priority;
				}
			}
			
			if (newStack) {
				stacks++;
				req.push_back(priority);
			}
		}
			
		input.clear();
		req.clear();

		cout << "Case " << numberCase << ": " << stacks << endl;
		cin >> input;
	}

	return 0;
}
