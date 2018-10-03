
#include <iostream>
using namespace std;

const int l1 = 4; 
const int l2 = 3;   // l1>= l2 >= 0

bool subString(char v1[], char v2[], int l1, int l2);

bool subString(char v1[], char v2[], int l1, int l2) {
	bool contained = true, ok = false;
	int y = 0, x = 0;

	while (y < l2 && contained == true){
		x = 0;
		ok = false;
		while (x < l1 && ok == false && y < l2){
			if (v2[y] == v1[x]){
				contained = true;
				ok = true;
				y++;
				x++;
			}
			else{
				contained = false;
				ok = false;
				x++;
			}
		}
	}
	return contained;
}


int main0() {
	char v1[4] = { 'a', 'b', 'c', 'd' };
	char v2[3] = { 'a', 'c', 'e' };
	bool oke;

	oke = subString(v1, v2, l1, l2);
	if (oke == true){
		cout << "true";
	}
	else {cout << "false";}
	return 0;
}

// SPECIFICATION:   { l1 >= l2 >= 0}
//                  fun subString(char v1[], char v2[], int l1, int l2) return bool contained;
//                  {contained = true ↔ (para todo y: 0 <= y <= l1: existe x: 0 <= x <= l2 : v2[y] = v1[x]}

// COMPLEXITY:   worst case->  T(n) = initializations + big while loop = 2 + l2(13*l1 + 5) + 5 = 13*l1*l2 + 5*l2 + 7
//                                    big while loop = (small while loop*cost of iterations) + initializations = l2(13*l1 + 5) + 3 + 2
//                                    small while loop = if and else*cost of iterations = l1(8 + 5) + 5
//                                    if and else = max(fcondition(n), fifbody(n), felsebody(n)) = fcondition(n) + fifbody(n) + felsebody(n) = 2 + 3 + 3
