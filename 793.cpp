#include <bits/stdc++.h>

using namespace std;

typedef struct Vertex {
	int n;
	bool checked;
} Vertex;

typedef vector <Vertex> vi;

int findInter (vector <vi> list, int a, int b) {
	int i;
	bool found;

	for (i = 0; i < (int)list[a].size(); i++) {		
		if (list[a][i].n == b) {
			found = 1;
			break;
		}
		
		if (list[a][i].checked == false) {
			list[a][i].checked = true;
			found = findInter (list, list[a][i].n, b);
		}
		
		list[a][i].checked = false;
	}
	
	return found;
}

int main () {
	vector <vi> AdList;
	char command;
	int n, a, b, suc = 0, unsuc = 0;
	Vertex temp;
	
	temp.checked = false;
	
	cin >> n;
	
	AdList.assign(n + 1, vi());
	
	while (cin >> command) {
		cin >> a >> b;
		
		switch (command) {
			case 'c':
				if (a <= n && b <= n) {
					temp.n = b;
					
					AdList[a].push_back(temp);
					
					temp.n = a;
					
					AdList[b].push_back(temp);
				}
				
				break;
			case 'q':
				if (findInter(AdList, a, b))
					suc++;
				else
					unsuc++;
					
				break;
		}
	}
	
	cout << suc << "," << unsuc << endl;

	return 0;
}
