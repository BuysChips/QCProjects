#include <iostream>
#include <cmath>
using namespace std;

bool ok(int q[], int c) {
    static int adj_table[8][5] = {          //the table of indexes for
        {-1},                               //neighboring squares        
        {0, -1},
        {0, 1, -1},
        {0, 2, -1},
        {1, 2, -1},
        {1, 2, 3, 4, -1},
        {2, 3, 5, -1},
        {4, 5, 6, -1}
    };
    
    for (int i = 0; i < c; i++){
        if (q[c] == q[i]) return false;
    }
    
    for (int i = 0; adj_table[c][i] != -1; i++){
        if (abs(q[adj_table[c][i]] - q[c]) == 1)  
                return false;
    }
    return true;
}

void print(int q[]) {
    static int numSolutions = 0;
    
    cout << "Solution #: " << ++numSolutions << endl;
        
    cout << " " << q[1] << q[4] << " " << endl
         << q[0] << q[2] << q[5] << q[7] << endl
         << " " << q[3] << q[6] << " " << endl;
    
}

void next(int q[], int c) {
    if (c == 8)
        print(q);
    else for (q[c] = 1; q[c] < 9; ++q[c])
        if (ok(q, c))
            next(q, c+1);
}

int main() {
   int q[8];
   next(q, 0);
   return 0;
}



