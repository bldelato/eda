#include <iostream>
using namespace std;

const int MAX=10000;

int maxs(int v[], int n, int &counter) {
	long long int max;

	max = v[0];					//1
	counter=1;
	int i = 1;						//1
	while(i < n){			//1
		if (v[i] > max){			//1
			max = v[i];			//1
			counter = 1;		//1
		}
		else if (v[i] == max) {	//1
			counter++;			//1
		}
		i++;					//1
	}
	return max;
}


int mainE1(){
	int cases, solution, counter, elements;
	int v[MAX];

	cin >> cases;

	for (int a = 0; a < cases; a++){
		counter=0;
		cin >> elements;
		for(int g=0;g<elements;g++) cin >> v[g];
		solution = maxs(v, elements, counter);
		cout << solution << " " << counter << endl;
	}
	return 0;
}
