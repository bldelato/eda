#include <iostream>
using namespace std;

const int MAX_ELEMS = 100000;

int colones(int v[], int num){
	int result, j, aux;
	
	j = num -1;	//2					
	aux = v[j]; //2
	result = 0; //1

	while (j > 0){ //1
		if (v[j - 1] < aux){ //3
			aux = v[j - 1];  //3
		}
		else if (v[j - 1]> aux) { //3
			result++;			  //1
		}		
		j--; //1
	}
	return result;
}
//COMPLEXITY -> worst case: always enters the else if
//				while body:  3 + 3 +1 + 1= 8
//					outside: (1+ 8)(n - 1) + 1 + 2+2+1 = 9n - 3.


int  ProcessTestCase(){
	int elements;
	int v[MAX_ELEMS];

	cin >> elements;
	if (elements <= MAX_ELEMS){
		for (int a = 0; a < elements; a++){
			cin >> v[a];
		}
	}
	return colones(v, elements);
}

int mainA3(){
	int cases, n, solution, a;

	cin >> cases;
	for (int i = 0; i < cases; i++){
		solution = ProcessTestCase();
		cout << solution << endl;
	}
	cin >> a;

	return 0;
}
