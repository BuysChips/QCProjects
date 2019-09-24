#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int q[8], c = 0;
	q[0] = 0;
	
	NC:	c++;
		if (c == 8) goto print;
		q[c] = -1;
		
	NR:	q[c]++;
		if (q[c] == 8) goto backtrack;
		for (int i = 0; i < c; i++){
			if (q[c] == q[i]) goto NR;
			
			if((c - i) == abs (q[c] - q[i])) goto NR;
		
		}
		goto NC;
	
	backtrack:	
		c--;
		if (c == -1) return 0;
		goto NR;
		
	print:
		static int numSolutions = 0;
		cout << "Solution #" << ++numSolutions << ":\n";
		for (int i = 0; i < 8; i++){
			cout << q[i] << " ";
		}	
		cout << endl;
		goto backtrack;
}
