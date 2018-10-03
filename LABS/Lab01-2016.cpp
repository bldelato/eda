
//Blanca de la Torre Fuertes 2�I


#include <string>
#include <iostream>
using namespace std;

const int MAX_STACKS = 10000;
const int MAX_ELEMS = 99999;
int evens(int v[], int num);

int evens(int v[], int num) {
	int counter, i;

	counter = 0;
	i = 0;
	while (i < num) {
		if (v[i] % 2 == 0) {
			counter++;
		}
		i++;
	}
	return counter;
}

// SPECIFICACION: {num > 0}
//				  fun evens(int v[], int num) return int counter
//				  {counter = #q: 0<=q<num: v[q]%2=0}
// COMPLEXITY:  while inside= 3 + 1 + 1(worst case-> enters always the if)
//					  outside= (5 + 1)(n - 1) + 1 = 6n -5
//			    T(n)= 1 + 1 + 6n - 5 = 6n - 3.

int ProcessTestCase0(int c[], int num){
	int aux, result;
	

	if (num < 99999 && num > 0){
		for (int i = 0; i < num; i++){
			cin >> aux;
			c[i] = aux;
		}
	}
	result = evens(c, num);

	return result;
}

// SPECIFICACION: {0<num<100000}
//				  fun ProcessTestCase(int v[], int num) return int result
//				  {result = evens(v,num)}
// COMPLEXITY:  for inside= 1 +1 +1 +1 = 4(i assumed that cin cost 1(?), and added the +1 of the i++)
//					outside= (4+1)(n-1) + 1 + 1 = 5n -3.
//			    T(n)= 5n -3 + (6n -5) = 11n -8.

int main1(){
	int sol, stacks, elems, a;

	int v[MAX_ELEMS];
	
	//RECEIVES THE NUMBER OF STACKS TO BE MADE
	cin >> stacks;

	if (stacks < MAX_STACKS){
		for (int a = 0; a < stacks; a++){
			cin >> elems;
			sol = ProcessTestCase0(v,elems);
			cout << sol << endl;
		}
	}
	cin >> a;

	return 0;
}
