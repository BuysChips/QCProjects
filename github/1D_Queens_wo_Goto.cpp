#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

bool isOK(int q[], int c){
	for (int i = 0; i < c; i++){
		if (q[c] == q[i] || (c - i) == abs(q[c] - q[i]))
			return false;
	}	
	return true;
}

void print (int q[]){
    static int numSolutions = 0;
    cout << "Solution #" << ++numSolutions << ": " << endl;
    for (int i = 0; i < 8; i++){
        for (int j = 0 ; j < 8; j++)
            if (q[j] == i) cout << "1 ";
            else cout << "0 ";
        cout << endl;
    }
    cout << endl;
}

void backtrack(int &col){
    col--;
    if (col < 0) exit(0);
}

int main() {
    //initialization
	int q[8], c = -1;
	for (int i = 0 ; i < 8; i++)
	    q[i] = -1;
	
    while (true){
	    c++;
	    if (c == 8){
	        print(q);
	        backtrack(c);
	    }
        while (true){
            q[c]++;
            //check for out of bound
            if (q[c] == 8){
                //reset the row position and backtrack
                q[c] = -1;
                backtrack(c);
                continue;
            }
            
            //check if it is ok to place queen here
            if (isOK(q,c)){
                break;
            }
            else {
                continue;
            }
        }
    }
	return 0;
}









