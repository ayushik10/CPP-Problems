#include <iostream>
using namespace std;

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int X ,Y;
	    cin >> X >> Y;
	    
	    int possible = 0;
	    possible = X*5;
	    
	    if(possible >= Y){
	        cout << "YES" << endl;
	    }
	    else{
	        cout << "NO" << endl;
	    }
	}
	return 0;
}
