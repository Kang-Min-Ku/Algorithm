#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

typedef struct{
	int numRoom;
	int numFloor;
	int numGuest;
}HOTELINFO;

int main(){
	int numCase;
	cin >> numCase;
	vector<HOTELINFO> ho;
	ho.reserve(numCase);
	for(int i=0;i<numCase;i++) cin >> ho[i].numFloor >> ho[i].numRoom >> ho[i].numGuest;
	
	for(int i=0;i<numCase;i++){
		int floor, room;
		room = int(ceil(double(ho[i].numGuest)/double(ho[i].numFloor)));
		if(ho[i].numGuest % ho[i].numFloor == 0) floor = ho[i].numFloor;
		else floor = ho[i].numGuest - (ho[i].numGuest/ho[i].numFloor) * ho[i].numFloor;
		if(room < 10) cout << floor << "0" << room << endl;
		else cout << floor << room << endl;
	}
}