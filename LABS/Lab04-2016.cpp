#include <iostream>
using namespace std;

const long long int MAX_P = 1000000;

void convex(long long int v[], int n, long long int &min, long long int &pos);

int main4(){
	int points;
	long long int min, pos;
	long long int *v= new long long int [MAX_P];

	cin >> points;

	while (points != 0 && points <= MAX_P) {
		for (int i = 0; i < points; i++){
			cin >> v[i];
		}
		convex(v, points, min, pos);
		cout << pos << " " << min << endl;
		
		cin >> points;
	}
	delete[] v;

	return 0;
}


void convex(long long int v[], int n, long long int &min, long long int &pos){

	pos = 0;						  //1
	min = v[pos];					  //2
	int aux = 0;					  //1
	bool done=false; 				  //1

	while (aux < n && done == false){ //3
		if (v[aux] < v[aux+1]){       //4
			done = true;			  //1
		}
		else{ aux++;}				  //1
	}

	if(n > 1) {				  //1
		if(!done){
			pos = aux-1;
			min = v[pos];
			}
		else{
			pos = aux;			  //2
			min = v[pos];		  //2
		}
	}
}

//COMPLEXITY-> worst case: enters the if in the last value of the array
//					(n-2)(3+4+1) + (3+4+1+1) + 3 +2+1+1+1+2+2 = 8(n-2) + 9 + 12 = 8n + 5.

//SPECIFICATION->   PRE {0<n <= 1000000}
//					proc convex(long long int v[], int n, out long long int min,pos)
//					POST {min=minimum(v)^ v[pos]=min }

//INVARIANT-> {(0<aux<=n: done= (v[aux] > v[aux-1])}
