#include <bits/stdc++.h>

using namespace std;

int main () {
	int n, command;
	int x;
	
	stack<int> myStack;
	queue<int> myQueue;
	priority_queue<int> pOrder;
	
	bool isQueue, isPriorityQueue, isStack;
	
	while ((!(cin >> n).eof())) {
		isQueue = isPriorityQueue = isStack = true;

		// Reads input
		while (n--) {
			cin >> command >> x;
			
			if (command == 1) {
				myStack.push(x);
				myQueue.push(x);
				pOrder.push(x);
			} 
			else if (command == 2) {						
				if (isStack && (myStack.empty() || x != myStack.top())) {
					isStack = false;
				} else if (isStack && !myStack.empty())
					myStack.pop ();
				
				if (isQueue && (myQueue.empty() || x != myQueue.front())) {
					isQueue = false;
				} else if (isQueue && !myQueue.empty())
					myQueue.pop ();
				
				if (isPriorityQueue && (pOrder.empty() || x != pOrder.top())) {
					isPriorityQueue = false;
				} else if (isPriorityQueue && !pOrder.empty())
					pOrder.pop ();
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
			
		while (!myQueue.empty())
			myQueue.pop();
	
		while (!myStack.empty())
			myStack.pop();
	}

	return 0;
}
