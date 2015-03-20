#include <bits/stdc++.h>

using namespace std;

typedef struct Priorities {
	int priority;
	bool mine;
} Priorities;

bool compare (Priorities a, Priorities b) {
	return a.priority >= b.priority;
}

int main () {
	int testCases, n, m, minutes = 0, k;
	list <Priorities> priorities, prioritiesOrdered;
	list <Priorities>::iterator i;
	Priorities p;
	bool imDone = false;
	
	cin >> testCases;
	
	while (testCases--) {
		cin >> n >> m;
		
		for (k = 0; k < n; k++) {
			cin >> p.priority;
			
			if (k == m)
				p.mine = true;
			else
				p.mine = false;
			
			priorities.push_back(p);
			prioritiesOrdered.push_back(p);
		}
		
		prioritiesOrdered.sort(compare);
		
		i = priorities.begin();
		
		while (i != priorities.end() && !imDone) {
			if ((*i).priority == (*prioritiesOrdered.begin()).priority) {
				prioritiesOrdered.pop_front();
				minutes++;
				
				if ((*i).mine == true) {				
					imDone = true;
				}
					
				priorities.pop_front();
			}
			else {
				p = *i;
				
				priorities.pop_front();
				
				priorities.push_back(p);
			}
					
			i = priorities.begin();
		}
		
		cout << minutes << endl;
		
		minutes = 0;
		imDone = false;
		
		priorities.clear();
		prioritiesOrdered.clear();
	}

	return 0;
}
