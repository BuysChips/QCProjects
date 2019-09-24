#include <iostream>
using namespace std;

bool equivalent (int a[], int b[], int n){
    for (int i = 0; i < n; i++){
        if (a[0] == b[i]);                                  //to find the offset value
            int offset = i; 
            for (int j = 0; j < n; j++){
                if ( a[j % n] != b[(offset + j) % n] )      //the index will never go higher than n
                    break;                                  //if the entries dont match, break out of the loop
                if (j == n - 1) return true;                //if j reaches n, return true
            }
    }
    return false;                                           //this false statement lies outside of the loop that
                                                            //checks the offset value
}
    

                
int main(){
    
    cout << boolalpha;
    
    int a1[5] = {1, 2, 3, 4, 5};
   int a2[5] = {3, 4, 5, 1, 2};
   cout << equivalent(a1, a2, 5) << endl; // true
   
   int b1[3] = {1, 2, 3};
   int b2[3] = {2, 3, 3};
   cout << equivalent(b1, b2, 3) << endl; // false
   
   int c1[4] = {2, 3, 4, 1};
   int c2[4] = {1, 4, 3, 2};
   cout << equivalent(c1, c2, 4) << endl; // false
   
   int d1[4] = {3, 2, 3, 1};
   int d2[4] = {3, 1, 3, 2};
   cout << equivalent(d1, d2, 4) << endl; // true
   
   int e1[5] = {1, 1, 1, 1, 2};
   int e2[5] = {1, 1, 1, 2, 1};
   cout << equivalent(e1, e2, 5) << endl; // true
   
   return 0;
}


