#include <bits/stdc++.h>

using namespace std;

typedef struct Coordinate {
	int n;
	int m;
} Coordinate;

bool canEscape (int n, int m, vector <Coordinate> enemies) {
    for (int i = 0; i < (int)enemies.size(); i++) {
        if (n == enemies[i].n || m == enemies[i].m)
            return false;
    }

    return true;
}

int main () {
	int R, C, N, i, myCase = 1;
	vector <Coordinate> enemies;
	Coordinate goal, me;
	bool escape = false;

	cin >> R >> C >> N;

	// Executes a round
	while (R && C && N) {
		for (i = 0; i < N; i++) {
			cin >> goal.n >> goal.m;

			enemies.push_back(goal);
		}

		cin >> me.n >> me.m;

		goal = me;

        escape = canEscape(goal.n, goal.m, enemies);

        if (!escape && me.n < R - 1) {
    		// One row down...
    		goal.n = me.n + 1;

    		escape = canEscape(goal.n, goal.m, enemies);
		}

		if (!escape && me.n > 0) {
			// One row up
			goal.n = me.n - 1;

            escape = canEscape(goal.n, goal.m, enemies);
		}

		if (!escape && me.m > 0) {
    		// One left
    	    goal.n = me.n;
			goal.m = me.m - 1;

            escape = canEscape(goal.n, goal.m, enemies);
		}

        if (!escape && me.m < C - 1) {
            // One right
            goal.n = me.n;
            goal.m = me.m + 1;

            escape = canEscape(goal.n, goal.m, enemies);
        }

		if (escape)
			cout << "Case " << myCase << ": Escaped again! More 2D grid problems!" << endl;
		else
			cout << "Case " << myCase <<  ": Party time! Let's find a restaurant!" << endl;

        myCase++; 

		cin >> R >> C >> N;
        enemies.clear();
        escape = true;
	}

	return 0;
}