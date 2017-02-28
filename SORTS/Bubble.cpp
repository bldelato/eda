#include <iostream>
using namespace std;

void bubbleSort(int v[], int num);

void bubbleSort(int v[], int num){
	int i, j, aux;
	bool modified;

	i=0;
	modified = true;
	while ((i<num-1) && modified){
		modified = false;
		for (j=num-1;j>i;j--){
			if(v[j]<v[j-1]){
				aux=v[j];
				v[j]=v[j-1];
				v[j-1]=aux;
				modified = true;
			}
		}
		i++;
	}
}

int mainBu() {
	int v1[] = {3, 5, -7, 1, 8, 4};

	bubbleSort(v1, 6);

	cout << "The sorted array: ";
	for(int a =0;a < 6;a++){
		cout << v1[a] << "  ";
	}

return 0;
}
