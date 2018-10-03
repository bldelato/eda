#include <iostream>
using namespace std;

const long long int MAX_P = 1000000;

void convex(long long int v[], int ini, int end, long long int &min, long long int &pos);

int main5(){
	int points;
	long long int min, pos;
	long long int *v= new long long int [MAX_P];

	cin >> points;

	while (points != 0 && points <= MAX_P) {
		for (int i = 0; i < points; i++){
			cin >> v[i];
		}
		convex(v, 0, (points-1), min, pos);
		cout << pos << " " << min << endl;

		cin >> points;
	}
	delete[] v;

	return 0;
}


void convex(long long int v[], int ini, int end, long long int &min, long long int &pos){
	int d= end - ini;

	if(d<2){ //less than 3 elements
		if(d==1){ //2 elements
			if(v[ini]<v[end]){ pos=ini;}
			else {pos = end;}
		}
		else{ pos = ini;} //1 element
		min = v[pos];
	}

	else  {	//3 elements at least
		int m = (d/2) + ini; //half

		if((v[m-1]< v[m]) && (v[m]< v[m+1])){
			convex(v,ini, m, min, pos);
		}
		else if ((v[m-1]> v[m]) && (v[m]> v[m+1])){
			convex(v,m, end, min, pos);
		}
		else {
			pos=m;
			min =v[pos];
		}
	}
}

//COMPLEXITY-> worst case: enters the if in the last value of the array
//					(n-2)(3+4+1) + (3+4+1+1) + 3 +2+1+1+1+2+2 = 8(n-2) + 9 + 12 = 8n + 5.

//SPECIFICATION->   PRE {0<n <= 1000000}
//					proc convex(long long int v[], int n, out long long int min,pos)
//					POST {min=minimum(v)^ v[pos]=min }

