#include <iostream>
using namespace std;

void insSort(int v[], int num);

void insSort(int v[], int num){
	int i, j, x;

	for (i=1; i<num;i++){
		x = v[i];								// 2
		j = i-1;								// 2
		while((j>=0) && (v[j] > x)){			// 4
			v[j+1] = v[j];						// 4
			j = j-1;							// 2
		}
		v[j+1]=x;								// 3
	}
}

int mainI() {
	int v1[] = {3, 5, -7, 1, 8, 4};

	insSort(v1, 6);

	cout << "The sorted array: ";
	for(int a =0;a < 6;a++){
		cout << v1[a] << "  ";
	}

return 0;
}
