#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class POINT{
public:
	int val;
	int pos;
	int compressed;
	POINT(int v, int p){val=v;pos=p;compressed=0;}
};

bool compVal(POINT x, POINT y){
	return x.val < y.val;
}

bool compPos(POINT x, POINT y){
	return x.pos < y.pos;
}

int main(){
	int len, temp, dup=0;
	cin >> len;
	vector<POINT> pointSet;
	pointSet.reserve(len);
	for(int i=0;i<len;i++){
		cin >> temp;
		pointSet.push_back(POINT(temp, i));
	}
	sort(pointSet.begin(), pointSet.end(), compVal);
	for(int i = 1;i<len;i++){
		if(pointSet[i].val==pointSet[i-1].val){
			pointSet[i].compressed = pointSet[i-1].compressed;
			dup+=1;
		}
		else
			pointSet[i].compressed = i-dup;
	}
	sort(pointSet.begin(), pointSet.end(), compPos);
	for(int i=0;i<len;i++){
		cout << pointSet[i].compressed;
		if(i<len-1) cout << " ";
	}
}