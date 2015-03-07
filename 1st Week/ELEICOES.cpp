#include <iostream>
#include <map>

using namespace std;

typedef struct Vote {
    int votes;
    int candidate;
} Vote;

int main () {
    int N, vote;
    map <int, int> candidates;
    Vote highest;
    
    cin >> N;
    
    highest.votes = 0;
    
    while (N--) {
        cin >> vote;
        
        if (candidates.find(vote) != candidates.end()) {
            candidates[vote] ++;
        }
        else
            candidates[vote] = 1;
        
        if (candidates[vote] > highest.votes) {
            highest.votes = candidates[vote];
            highest.candidate = vote;
        }
    }
    
    cout << highest.candidate << endl;
    
    return 0;
}