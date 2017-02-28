/*
 * Sequential.cpp
 *
 *  Created on: 12 oct. 2016
 *      Author: blanca
 */

#include <iostream>
using namespace std;

int seqSearch(int v[], int num, int x);

int seqSearch(int v[], int num, int x){
	int j;
	bool found;

	j = 0;								//1
	found = false;						//1

	while((j<num) && !found){			// 3
		found = (v[j] == x);			// 3
		j++;							// 1
	}
	return found;
}

int mainSq() {
	int v1[] = {1,3,5,7,8,9};
	int aux = 2;

	bool found = seqSearch(v1, 6, aux);
	if (found){
		cout << "FOUNDED " << endl;
	}
	else {cout << "NOT FOUNDED!";}

return 0;
}



