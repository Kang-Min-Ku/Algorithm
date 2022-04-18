#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
class coordinate{
public:
	int x;
	int y;
	coordinate(int x_, int y_){x=x_;y=y_;}
	coordinate(){;}
};

bool comp(coordinate a, coordinate b){
	if(a.x == b.x) return a.y < b.y;
	return a.x < b.x;
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int len;
	cin >> len;
	coordinate *cdSet = new coordinate[len];
	for(int i=0;i<len;i++){
		int tempX, tempY;
		cin >> tempX >> tempY;
		cdSet[i]=coordinate(tempX,tempY);
	}
	sort(cdSet,cdSet+len, comp);
	for(int i=0;i<len;i++) cout << cdSet[i].x << " " << cdSet[i].y << "\n";
}