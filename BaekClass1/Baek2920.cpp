#include <iostream>
#include <string>

using namespace std;

int main(){
	int *scale = new int[8];
	bool state;
	for(int i=0;i<8;i++) cin >> scale[i];
	
	if(scale[0] - scale[1] > 0) state = false; //descending
	else state = true; //ascending
	
	for(int i=0;i<7;i++){
		if(scale[i] - scale[i+1] > 0 && !state) ;
		else if(scale[i] - scale[i+1] < 0 && state) ;
		else{
			cout << "mixed";
			return 0;
		}
	}
	
	if(state) cout << "ascending";
	else cout << "descending";
}