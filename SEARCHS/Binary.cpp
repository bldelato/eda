
#include <iostream>
using namespace std;

int binSearch(int v[], int num, int x);

int binSearch(int v[], int num, int x){
	int lef, rig, centre;

	lef = -1; 						// 1
	rig = num;						// 1

	while(rig != lef+1){			// 2
		centre = (lef+rig)/2;		// 3
		if(v[centre] <=x){			// 2
			lef=centre;				// 1
		}
		else {rig = centre;}		// 1
	}
	return lef;
}

int recursivebinSearch(int v[], int num, int a, int b){
	int p, m;

	if(a==b+1){
		p=a-1;
	}
	else if(a<=b){
		m=(a+b)/2;
		if(v[m]<=num)
			p=recursivebinSearch(v, num, m+1, b);
		else
			p=recursivebinSearch(v, num, a, m-1);
	}
	return p;
}

int recursivebinSearch(int v[], int n, int x){
	return recursivebinSearch(v, x, 0, n-1);
}


int mainBi() {
	int v1[] = {1,3,5,7,8,9};
	int aux = 2;

	int pos = recursivebinSearch(v1, 6, aux);
	if (v1[pos] == aux){
		cout << "FOUNDED " << endl;
		cout << "It's in position " << pos;
	}
	else {cout << "NOT FOUNDED!";}

return 0;
}

// SPECIFICATION:   { num > 0}
//                  fun binSearch(int v[],int num, int x) return int lef;
//                  {contained = true ↔ (para todo y: 0 <= y <= l1: existe x: 0 <= x <= l2 : v2[y] = v1[x]}

// COMPLEXITY:  while loop inside: 3 + 2 + 1 (o coge el if o el else)
//						   outside: (6+2)log(n) + 2 -> logn porque estamos dividiendo el array en mitades, y el ultimo 2 por checkear la condicion y salirse
//
