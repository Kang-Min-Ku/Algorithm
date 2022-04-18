#include <iostream>
#include <vector>

using namespace std;

int main(){
	int xpos, ypos, width, height;
	int disSet[4];
	cin >> xpos >> ypos >> width >> height;
	disSet[0] = xpos;
	disSet[1] = width - disSet[0];
	disSet[2] = ypos;
	disSet[3] = height - disSet[2];
	int min=disSet[0];
	for(int i=0;i<4;i++){
		if(min > disSet[i]) min = disSet[i];
	}
	cout << min;
}