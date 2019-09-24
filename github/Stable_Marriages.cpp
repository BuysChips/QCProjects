#include <iostream>
using namespace std;

bool ok(int q[], int col){
    static int manPreferences[3][3] = {
        {0, 2, 1},
        {0, 2, 1},
        {1, 2, 0},
    };
    
    static int womanPreferences[3][3] = {
        {2, 1, 0},
        {0, 1, 2},
        {2, 0, 1},
    };
    
    for (int i = 0; i < col; i++){
        if (q[i] == q[col]) return false;
    }
    
    for (int i = 0; i < col; i++){
        if (manPreferences[i][q[col]] < manPreferences[i][q[i]] &&
            womanPreferences[q[col]][i] < womanPreferences[q[col]][col]) 
            return false;
    }
    
    for (int i = 0; i < col; i++){
        if (manPreferences[col][q[i]] < manPreferences[col][q[col]] &&
            womanPreferences[q[i]][col] < womanPreferences[q[i]][i])
            return false;
    }
    return true;
}

void print (int q[]){
    static int numSolutions = 0;
    cout << "Solution #" << ++numSolutions << ": " << endl;
    for (int i = 0; i < 3; i++){
        cout << q[i] << " ";
    }
    cout << endl;
}

void backtrack(int &col){
    col--;
    if (col < 0) exit(0);
}

int main() {
    //initialization
	int q[3], c = -1;
	for (int i = 0 ; i < 3; i++)
	    q[i] = -1;
	
    while (true){
	    c++;
	    if (c == 3){
	        print(q);
	        backtrack(c);
	    }
        while (true){
            q[c]++;
            //check for out of bound
            if (q[c] == 3){
                //reset the row position and backtrack
                q[c] = -1;
                backtrack(c);
                continue;
            }
            
            //check if it is ok
            if (ok(q,c)){
                break;
            }
            else {
                continue;
            }
        }
    }
	return 0;
}


