#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>

using namespace std;

int main () {
    string command;
    int t, qt, scenario, appear, lowest, aux, i, j;
    
    vector< queue <int> > teams (5000);
    map <int, int> teamKey;
    map <int, int> teamOrder;
    
    scenario = 1;
    
    cin >> t;
    
    while (t) {
        for (i = 0; i < t; i++) {
            cin >> qt;
            
            for (j = 0; j < qt; j++) {
                cin >> aux;
                
                teamKey[aux] = i;
            }
        }
        
        cout << "Scenario #" << scenario << endl;
        cin >> command;
        
        appear = 0;
        lowest = 0;
        
        while (command.compare("STOP") != 0) {
            if (command.compare("ENQUEUE") == 0) {
                cin >> aux;
                
                // If there is this team in the team order contabilizator...
                if (teamOrder.find(teamKey[aux]) == teamOrder.end())
                    teamOrder[teamKey[aux]] = appear++;
                
                teams[teamOrder[teamKey[aux]]].push(aux);
            }
            else if (command.compare("DEQUEUE") == 0) {
				if (lowest < appear) {
					aux = teams[lowest].front();
					
					cout << aux << endl;
						
					teams[lowest].pop();
					
					if (teams[lowest].empty()) {
						teamOrder.erase(teamKey[aux]);
						lowest++;
					}
				}
            }
            
            cin >> command;
        }
        
        // Clean structures
        teamKey.clear();
        teamOrder.clear();
        for (i = lowest; i < appear; i++) {
            while (!teams[i].empty())
                teams[i].pop();
        }
        
        cout << endl;
        cin >> t;
        scenario++;
    }
    
    return 0;
}
