#include <bits/stdc++.h>

using namespace std;

int main () {
	int i;
	string text;
	list <char> answer;
	list <char>::iterator cursor;
	
	// Reads each input
	while (!(cin >> text).eof()) {
		cursor = answer.begin();
		
		for (i = 0; i < (int)text.size(); i++) {
			if (text[i] == '[')
				cursor = answer.begin();
			else if (text[i] == ']')
				cursor = answer.end();
			else
				answer.insert(cursor, text[i]);
		}
		
		for (cursor = answer.begin(); cursor != answer.end(); cursor++)
			cout << *cursor;
		cout << endl;
		
		answer.clear();
		text.clear();
	}
	
	return 0;
}
