#include <bits/stdc++.h>

using namespace std;

typedef struct Specimen {
	int mass;
	int pos;
} Specimen;

bool myComp (const Specimen &a, const Specimen &b) {
	return a.mass < b.mass;
}

struct find_id {
    int id;
    
    find_id (int id) : id(id) { }
    
    bool operator() (const Specimen &m) const {
        return m.mass == id;
    }
};

int main () {
	int nChambers, nSpecimen, i, sum, alone, nSet, second;
	double AM, CM, imbalance;
	vector <int> specimen;
	vector <Specimen> orderedSpecimen;
	vector <Specimen>::iterator it;
	vector <int>::iterator it2;
	Specimen aux;
	
	nSet = 0;
	
	while(!(cin >> nChambers >> nSpecimen).eof()) {
		nSet++;
		sum = CM = imbalance = 0;
		
		for (i = 0; i < nSpecimen; i++) {
			cin >> aux.mass;
			aux.pos = i;
			
			specimen.push_back(aux.mass);
			
			orderedSpecimen.push_back(aux);
			
			sum += aux.mass;
		}
		
		AM = (double) sum/nChambers;
		
		sort (orderedSpecimen.begin(), orderedSpecimen.end(), myComp);
		
		if (nSpecimen % 2) {
			alone = orderedSpecimen[(int)orderedSpecimen.size() - 1].mass;
			
			orderedSpecimen.pop_back();
		}
		
		printf("\nSet #%d\n", nSet);
		
		for (i = 0; i < (int)specimen.size(); i++) {
			if (specimen[i] == alone) {
				printf(" %d: %d\n", i, specimen[i]);
				
				CM = specimen[i];
			} else {
				it = find_if(orderedSpecimen.begin(), orderedSpecimen.end(), find_id(specimen[i]));
				
				second = orderedSpecimen[(int)orderedSpecimen.size() - 1 - (int) distance(orderedSpecimen.begin(), it)].mass;
				
				printf(" %d: %d %d\n", i, specimen[i], second);
				
				CM = specimen[i] + second;
				
				it2 = find(specimen.begin(), specimen.end(), second);
				
				specimen.erase(specimen.begin() + (int) distance(specimen.begin(), it2));
			}
						
			imbalance += abs(CM - AM);
		}

		printf("IMBALANCE = %.5f\n", imbalance);
		
		specimen.clear();
		orderedSpecimen.clear();
	}
	
	return 0;
}
