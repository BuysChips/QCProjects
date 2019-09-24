#include <iostream>
#include <cmath>
using namespace std;
    
bool isOK(int q[], int c){
	for (int i = 0; i < c; i++){
		if (q[c] == q[i] || (c - i) == abs(q[c] - q[i]))
			return false;
	}	
	return true;
}

void print(int q[]){
    static int solution = 0;
    int i, j, k, l;
    typedef char box[5][7];
    box bb, wb, *board[8][8];
    
    //to fill in black box and white box
    for (i = 0; i < 5; i++){
        for (j = 0; j < 7; j++){
            wb[i][j] = ' ';
            bb[i][j] = char(219);
        }
        
    }
    
    //to fill in black box w/ queen & white box w/ queen
    static box bq = {{char(219),char(219),char(219),char(219),char(219),char(219),char(219)},
                     {char(219),' '      ,char(219),' '      ,char(219),' '      ,char(219)},
                     {char(219),' '      ,' '      ,' '      ,' '      ,' '      ,char(219)},
                     {char(219),' '      ,' '      ,' '      ,' '      ,' '      ,char(219)},
                     {char(219),char(219),char(219),char(219),char(219),char(219),char(219)} };
               
    static box wq = {{' '      ,' '      ,' '      ,' '      ,' '      ,' '      ,' '      },
                     {' '      ,char(219),' '      ,char(219),' '      ,char(219),' '      },
                     {' '      ,char(219),char(219),char(219),char(219),char(219),' '      },
                     {' '      ,char(219),char(219),char(219),char(219),char(219),' '      },
                     {' '      ,' '      ,' '      ,' '      ,' '      ,' '      ,' '      } };
    
    //fill the board with points to bb and wb in alternating positions
    for (i = 0; i < 8; i++){
        for (j = 0; j < 8; j++){
            if ((i + j) % 2 == 0)
               	board[i][j] = &wb;
            	
            
			else
				board[i][j] = &bb;
				
		
        }
    }
    
    for (i = 0; i < 8; i++){
        if ((i + q[i]) % 2 == 0)
            board[q[i]][i] = &wq;
        else
            board[q[i]][i] = &bq;
    }
    //print the board via the pointers in array board
    
    
    cout << "Solution #: " << ++solution << ";\n";
    
    //print upper border
    cout << "  ";
    for (i = 0; i < 7 * 8; i++)
        cout << "_";
    cout << endl;
    
    //now print the board
    for (i = 0; i < 8; i++){  //move to next row in outer array
        for (k = 0; k < 5; k++){  //move to next row in inner array
            cout << "  " << char(179); //this prints the left border
            for (j = 0; j < 8; j++){  //move to next col in outer array
                for (l = 0; l < 7; l++){ //move to next col in inner array
                    cout << (*board[i][j])[k][l];
                }
            }
            cout << char(179) << endl; //at the end of line print bar and then new line
        }
    }
    
    //print lower border
    cout << "  ";
    for (i = 0; i < 7 * 8; i++)
        cout << char(196);
    cout << endl;

}

void next(int q[], int c){
    if (c == 8)
        print (q);
    else for (q[c] = 0; q[c] < 8; ++q[c])
        if (isOK(q,c))
            next (q, c + 1);
}

int main(){
    int q[8];
    next(q, 0);
    return 0;
}


