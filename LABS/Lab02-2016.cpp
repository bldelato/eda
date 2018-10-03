//Blanca de la Torre Fuertes 2�I

#include <iostream>
using namespace std;

const int MAX_ELEMS = 10000;
int  ProcessTestCase(int v[]);
int possibleMoves(int v[], int num);

int  ProcessTestCase(int v[]){
	int elements;

	cin >> elements;
	if (elements <= MAX_ELEMS){
		for (int a = 0; a < elements; a++){
			cin >> v[a];
		}
	}
	return possibleMoves(v, elements);
}

int possibleMoves(int v[], int num){
	int j, sum, counter;
	
	counter = 0;
	sum = 0;
	j = num -1;		//2

	while (j >= 0){		  //1
		if (v[j] == sum){ //2
			counter++;	  //1
		}
		sum = sum + v[j]; //3
		j--;			  //1
	}
	return counter;
}

//COMPLEXITY = while body: 2 + 1 +3 +1 = 7
//				while outside: (1 + 7)n + 1= 8n + 1
//				T= 4 + 8n + 1 = 8n +5.

//Invariant = {counter = #j: 0<=j<num;sum = S(v[]): v[j] = sum; }

int main2(){
	int levels, solution, a;
	int v[MAX_ELEMS];

	cin >> levels;
	for (int i = 0; i < levels; i++){
		solution = ProcessTestCase(v);
		cout << solution << endl;
	}
	cin >> a;

	return 0;
}
