#include <iostream>
using namespace std;

int main(){
    int board[8][8] = {0};
    int r = 0, c = 0;
    board[0][0] = {1};
    
    
    nextCol: 
        c++;
        if (c == 8) 
            goto print;   //once everything is finished
        r = -1;
   
    nextRow:
        r++;
        if (r == 8)
            goto backtrack;
        for (int i = 0; i < c; i++)
            if (board[r][i] == 1)
                goto nextRow;               // to see conflict on west
        
        for (int i = 1; (r - i) >= 0 && (c - i) >= 0; i++)
            if (board[r - i][c - i] == 1)
                goto nextRow;               // to see conflict on northwest
                
        for (int i = 1; (r + i) < 8 && (c - i) >= 0; i++)
            if (board[r + i][c - i] == 1)
                goto nextRow;               // to see conflict on southwest
                
        board[r][c] = 1;
            goto nextCol;
            
    backtrack: 
        c--;
        if (c == -1)
            return 0;
        
        r = 0;
        while (board[r][c] == 0)
            r++;
        board[r][c] = 0;
        goto nextRow;
   
    print:
        static int numSolutions = 0;
        cout << "Solution #" << ++numSolutions << ":\n";
        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++){
                cout << board[i][j] << " ";
                if (j == 7) cout << endl;
            }
        }
        goto backtrack;
}


