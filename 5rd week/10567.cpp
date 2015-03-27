#include <bits/stdc++.h>

using namespace std;

int main () {
	string S, SS;
	int Q, i;
	map <char, vector <int> pos> qtS, qtSS;
	bool matched;

	cin >> S >> Q;
	
	for (i = 0; i < (int)S.size(); i++) {
		qtS[S[i]].push_back(i);
	}
	
	while (Q--) {
		cin >> SS;
		
		matched = true;
	
		for (i = 0; i < (int)SS.size(); i++) {
			qtSS[SS[i]].push_back(i);
		}
		
		for (map::iterator it = qtSS.begin(); it != qtSS.end(); it++) {
			if (qtS[it->first] != qtS.end() && qtS
		}
	}

	return 0;
}
