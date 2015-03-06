#include <bits/stdc++.h>

using namespace std;

int findHighest (int numbers[], int size, int highest) {
	int newHighest = 0;
	
	for (int i = 0; i < size; i++)
		if (numbers[i] > newHighest && numbers[i] < highest)
			newHighest = numbers[i];
			
	return newHighest;
}

int main () {
	int n, command, rem = 0, size;
	int x;
	
	int insOrder[1000];
	priority_queue<int> pOrder;
	
	bool isQueue, isPriorityQueue, isStack;
	
	while ((!(cin >> n).eof())) {
		isQueue = isPriorityQueue = isStack = true;
		rem = size = 0;
		
		// Reads input
		while (n--) {
			cin >> command >> x;
			
			if (command == 1) {
				insOrder[size++] = x;
				pOrder.push(x);
			} 
			else if (command == 2) {						
				if (rem >= size) {
					isQueue = isPriorityQueue = isStack = false;
				}
				
				if (isStack && x != insOrder[size - 1 - rem]) {
					isStack = false;
				} 
				
				if (isQueue && x != insOrder[rem]) {
					isQueue = false;
				}
				
				if (isPriorityQueue && !pOrder.empty() && x != pOrder.top()) {
					isPriorityQueue = false;
				}
				else
					pOrder.pop();
				
				rem ++;
			}
		}
		
		if ((isStack && isQueue) || (isStack && isPriorityQueue)
			|| (isQueue && isPriorityQueue))
			cout << "not sure" << endl;
		else if (isQueue)
			cout << "queue" << endl;
		else if (isPriorityQueue)
			cout << "priority queue" << endl;
		else if (isStack)
			cout << "stack" << endl;
		else
			cout << "impossible" << endl;
			
		while (!pOrder.empty())
			pOrder.pop();
	}

	return 0;
}
