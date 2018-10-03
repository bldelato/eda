#include <iostream>
using namespace std;

const int MAX_C = 100;

bool isfib(long long int v[], int num){
	bool sol=true;		  //1
	long long int f1=-1, f2=1, f3 = f1+f2;  //4

	int a = 0;			  //1
	while (a<num && sol){ //3
		f3 = f1 + f2;	  //2
		if (v[a] < f3){   //2
			sol = false;  //1
		}
		f1 = f2;		  //1
		f2 = f3;		  //1
		a++;			  //1
	}

	return sol;
}

//SPECIFICATION: PRE= {0<num<=100}
//				 bool isfib(int v[], int num) return sol
//				 POST= {sol = Vi:0<=i<num: v[i]>= fib(i)}
			  
//				 PRE{num>= 0}
//  			 int fib(int num) return result
//				 POST= {result = v[i] ^ Vi:2<=i< num: v[i] = v[i-1] + v[i-2] ^ v[0]=0 ^ v[1]=1}

//Invariant={(0<=a<num)^(Vi:2<=i<=a: v[i] = v[i-1] + v[i-2] ^ v[0]=0 ^ v[1]=1^ f3 = v[i] ^ f2=v[i-1] ^ f1=v[i-2]) ^ (sol= Vj:0<=j<=a:v[j] >= f3)}

//COMPLEXITY-> while body=2+2+1+1+1 = 7
//					  outside=(3 + 7)n + 3 = 10n +31
//				T(n)= 6 + 10n +3 = 10n + 9





int main3(){
	int chapters;
	long long int v[MAX_C];
	
	cin >> chapters;

	while (chapters != 0 && chapters <= MAX_C){
		for (int i = 0; i < chapters; i++){
			cin >> v[i];
		}
		if (isfib(v, chapters)){
			cout << "YES"<< endl;
		}
		else {
			cout << "NO" << endl;
		}

		cin >> chapters;
	}

	return 0;
}
