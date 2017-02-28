#include <iostream>
using namespace std;

const int MAX=100;

typedef struct {
	int row;
	int column;
} Cell;


void maze(bool Maze[][MAX], int N, bool marks[][MAX], bool &found, int &steps, int &realsteps, Cell &pos, Cell dest);

int mainMa(){
	int N, steps=0, realsteps=0;
	bool found=false;
	Cell pos, dest;

	cin >>N;

	bool Maze[MAX][MAX];
	bool marks[MAX][MAX];

	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			cin >> Maze[i][j];

	for(int i = 0; i < N; i ++)
		for(int j = 0; j < N; j ++)
			marks[i][j] = false;

	pos.column=0;
	pos.row=0;
	dest.column=N-1;
	dest.row=0;

	maze(Maze, N, marks, found, steps, realsteps, pos, dest);

	if(found) cout << realsteps << endl;
	else cout << "Noup" << endl;
	return 0;
}

void maze(bool Maze[][MAX], int N, bool marks[][MAX], bool &found, int &steps, int &realsteps, Cell &pos, Cell dest){
	if(found) return;
	if(pos.row==dest.row && pos.column==dest.column){
		found=true;
		realsteps=steps;
	}
	else{
		if((pos.row-1>=0) && !Maze[pos.row-1][pos.column]){
			if(!marks[pos.row-1][pos.column]){
				marks[pos.row][pos.column]=true;
				pos.row=pos.row-1;
				steps++;
				maze(Maze, N, marks, found, steps, realsteps, pos, dest);
				steps--;
				pos.row=pos.row+1;
				marks[pos.row][pos.column]=false;
			}
		}
		if((pos.column-1>=0) && !Maze[pos.row][pos.column-1]){
			if(!marks[pos.row][pos.column-1]){
				marks[pos.row][pos.column]=true;
				pos.column=pos.column-1;
				steps++;
				maze(Maze, N, marks, found, steps, realsteps, pos, dest);
				steps--;
				pos.column=pos.column+1;
				marks[pos.row][pos.column]=false;
			}
		}
		if((pos.row+1<N) && !Maze[pos.row+1][pos.column]){
			if(!marks[pos.row+1][pos.column]){
				marks[pos.row][pos.column]=true;
				pos.row=pos.row+1;
				steps++;
				maze(Maze, N, marks, found, steps, realsteps, pos, dest);
				steps--;
				pos.row=pos.row-1;
				marks[pos.row][pos.column]=false;
			}
		}
		if((pos.column+1<N) && !Maze[pos.row][pos.column+1]){
			if(!marks[pos.row][pos.column+1]){
				marks[pos.row][pos.column]=true;
				pos.column=pos.column+1;
				steps++;
				maze(Maze, N, marks, found, steps, realsteps, pos, dest);
				steps--;
				pos.column=pos.column-1;
				marks[pos.row][pos.column]=false;
			}
		}

	}

}
