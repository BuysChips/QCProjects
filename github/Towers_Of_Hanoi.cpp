#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> t[3];
    int n;
    cout << "Please enter the number of rings to move: ";
    cin >> n;
    cout << endl;
    // The initial value of to depends on whether n is odd or even
    int close = (n % 2 == 0 ? 2 : 1), far = (n % 2 == 0 ? 1 : 2);
    int from = 0, to = close, candidate = 1, move = 0;
   
    // Initialize the towers
    for(int i = n + 1; i >= 1; --i)
        t[0].push_back(i);
    t[1].push_back(n+1);
    t[2].push_back(n+1);
   
    while (t[1].size() < n+1) { // while t[1] does not contain all of the rings
        cout << "Move #" << ++move << ": Transfer ring " << candidate << " from tower " << char(from+'A') << " to tower " << char(to+'A') << "\n";
      
        // Move the ring from the "from tower" to the "to tower" (first copy it, then delete it from the "from tower")
        t[to].push_back(t[from].back());
        t[from].pop_back();
      
        if (t[(to+1) % 3].back() < t[(to+2) % 3].back()) 
            from = (to+1) % 3;
        else
            from = (to+2) % 3;
        candidate = t[from].back();                     
         
        if (t[(from+close) % 3].back() > candidate)
            to = (from+close) % 3;                  
        else
            to = (from+far) % 3;
   }
   return 0;
}