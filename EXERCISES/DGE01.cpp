#include <iostream>
using namespace std;


int Maximos(int &counter) {
	int elements, result, i;
	long long int aux, max;

	cin >> elements;		//1
	max = 0;					//1
	i = 0;						//1
	while(i < elements){		//1
		cin >> aux;				//1
		if (aux > max){			//1
			max = aux;			//1
			counter = 1;		//1
		}
		else if (aux == max) {	//1
			counter++;			//1
		}
		i++;					//1
	}
	return max;
}

//COMPLEXITY-> worst case: every element is bigger than the previous one.
//				while body: 1 + 3 + 1 = 5. it enters always the if
//					  outside: (5 + 1)n + 1= 6n + 1
//				T(n) = 3 + 6n + 1= 6n + 4.


int mainD1(){
	int cases, solution, counter;

	cin >> cases;

	for (int a = 0; a < cases; a++){
		solution = Maximos(counter);
		cout << solution << " " << counter << endl;
	}
	return 0;
}
