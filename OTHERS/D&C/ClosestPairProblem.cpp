/*
 Given n points in a two dimensional space, n=2, find a pair
of points with the smallest euclidean distance between them
(if there are more than two points with the same distance,
then any pair is a valid solution).
 */

#include <iostream>
#include <math.h>
using namespace std;

struct Point {
	double x;
	double y;
};

double minimum(double x, double y){
	double z;

	if (x<=y) { z = x;}
	else {z=y;}
	return z;
}

double dist(Point p1, Point p2){
	return (sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y)));
}

double absolute(double x){
	if(x>=0){return x;}
	else {return -x;}
}

//Solves the base cases, when there are 2 or 3 points

void directSolution(Point p[], int c, int f, int indY[], int &ini, double &d, int &p1, int &p2){
	double d1, d2, d3;

	if(f==c+1){
		d=dist(p[c], p[f]);
		if((p[c].y)<= (p[f].y)){
			ini =c;
			indY[c]= f;
			indY[f]=-1;
			p1=c;
			p2=f;
		}
		else {
			ini =f;
			indY[f]= c;
			indY[c]=-1;
			p1=f;
			p2=c;
		}
	}
	else if(f==c+2){
		//Minimum distance and points
		d1=dist(p[c], p[c+1]);
		d2=dist(p[c], p[c+2]);
		d3=dist(p[c+1], p[c+2]);
		d=minimum(minimum(d1,d2), d3);

		if(d==d1){
			p1=c;
			p2=c+1;
		}
		else if(d==d2){
			p1=c;
			p2=c+2;
		}
		else {
			p1=c+1;
			p2=c+2;
		}
		//Sort
		if(p[c].y <= p[c+1].y){
			if(p[c+1].y <= p[c+2].y){
				ini=c;
				indY[c]=c+1;
				indY[c+1]=c+2;
				indY[c+2]=-1;
			}
			else if(p[c].y <= p[c+2].y){
				ini=c;
				indY[c]=c+2;
				indY[c+1]=-1;
				indY[c+2]=c+1;
			}
			else{
				ini=c+2;
				indY[c]=c+1;
				indY[c+1]=-1;
				indY[c+2]=c;
			}
		}
		else{
			if(p[c+1].y > p[c+2].y){
				ini=c+2;
				indY[c]=-1;
				indY[c+1]=c;
				indY[c+2]=c+1;
			}
			else if(p[c].y > p[c+2].y){
				ini=c+1;
				indY[c]=-1;
				indY[c+1]=c+2;
				indY[c+2]=c;
			}
			else{
				ini=c+1;
				indY[c]=c+2;
				indY[c+1]=c;
				indY[c+2]=-1;
			}
		}
	}
}

/*receives in indY two lists of links that start in ini1 and ini2,
 which represent the sorting according to the y coordinate of the points
 of the left subset and the right subset, respectively, and merges them in order
to get one sorted list with the links to all the points of the set
*/

void sortedMerge(Point p[], int ini1, int ini2, int indY[], int &ini){
	int i=ini1, j=ini2, k;

	if(p[i].y <= p[j].y){
		ini=ini1;
		k=ini1;
		i=indY[i];
	}
	else {
		k=ini2;
		ini=ini2;
		j=indY[j];
	}
	while((i!= -1) && (j!= -1)){
		if(p[i].y <= p[j].y){
			indY[k]=i;
			k=i;
			i=indY[i];
		}
		else{
			indY[k]=j;
			k=j;
			j=indY[j];
		}
	}

	if(i==-1){ indY[k]=j;}
	else { indY[k]=i;}
}

//p[] -> vector of points
//c and f -> limits of the set of points we r considering
//d -> distance between the closest pair of points
//p1 and p2 -> closest points
//indY -> vector of positions that represents the way points are sorted according to the y coordinate
//ini -> initial index (p[ini] i the one with the lowest y coordinate

void closestPair(Point p[], int c, int f, int indY[], int &ini, double &d, int &p1, int &p2){
	int m, i, j, ini1, ini2, p11, p12, p21, p22;
	double d1, d2;

	if ((f-c+1)<4){
		directSolution(p,c,f,indY,ini,d,p1,p2);
	}

	else {
		m = (c+f)/2;
		closestPair(p, c, m, indY, ini1, d1, p11, p12);
		closestPair(p, m+1, f, indY, ini2, d2, p21, p22);

		if(d1<=d2){
			d=d1;
			p1=p11;
			p2=p12;
		}
		else{
			d=d2;
			p1=p21;
			p2=p22;
		}
//		sorted merge according to y coordinate
		sortedMerge(p, ini1, ini2, indY, ini);

//		Filter the list
		i = ini;
		while(absolute(p[m].x - p[i].x) > d){
			i=indY[i];
		}

		int iniA=i;
		int indF[f-c+1];
		for(int l=0;l<=(f-c+1); l++){indF[l]=-1;}

		int k=iniA;

		while(i!=-1){
			if(absolute(p[m].x - p[i].x) <= d){
				indF[k]=i;
				k=i;
			}
			i = indY[i];
		}

//		Calculate distances
		i = iniA;
		while(i!=-1){
			int count=0;
			j=indF[i];
			while((j!=-1) && (count<7)){
				double daux=dist(p[i], p[j]);
				if(daux<d){
					d=daux;
					p1=i;
					p2=j;
				}
				j=indF[j];
				count=count+1;
			}
			i=indF[i];
		}
	}
}


// A Brute Force method to return the smallest distance between two points
// in P[] of size n
double bruteForce(Point P[], int n){
    double min = 10000000;
    for (int i = 0; i < n; ++i)
        for (int j = i+1; j < n; ++j)
            if (dist(P[i], P[j]) < min)
                min = dist(P[i], P[j]);
    return min;
}



int mainCP(){
	Point P[] = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
	int n = sizeof(P) / sizeof(P[0]);
	int indY[n];
	int ini = 0;
	double d=100000;
	int p1, p2;

	cout << "The smallest distance by brute force is " << bruteForce(P, n);


	closestPair(P, 0, (n-1), indY, ini, d, p1, p2);
	cout << "The smallest distance by D&C is " << d << endl;

	return 0;
}
