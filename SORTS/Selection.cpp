#include <iostream>
using namespace std;

void selSort(int v[], int num);

void selSort(int v[], int num){
	int i, j, min, aux;

	for (i=0; i<num;i++){
		min = i;
		for(j=i+1;j<num;j++){
			if(v[j]<v[min])
				min = j;
		}
		aux=v[i];
		v[i]=v[min];
		v[min] = aux;
	}
}

int mainSl() {
	int v1[] = {3, -5, -7, 1, 8, 4};

	selSort(v1, 6);

	cout << "The sorted array: ";
	for(int a =0;a < 6;a++){
		cout << v1[a] << "  ";
	}

return 0;
}
