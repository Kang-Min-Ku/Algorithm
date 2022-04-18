#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	int size;
	cin >> size;
	int lid=0, rid=size-1;
	int minlid=0, minrid=size-1;
	vector<int> w;
	w.reserve(size);
	for(int i=0;i<size;i++){
		int temp;
		cin >> temp;
		w.push_back(temp);
	}
	
	while(lid < rid){
		if(abs(w[minlid]+w[minrid]) > abs(w[lid]+w[rid])){
			minlid = lid;
			minrid = rid;
		}
		
		if(w[lid]+w[rid]>0) rid--;
		else if(w[lid]+w[rid]<0) lid++;
		else break;
	}
	
	cout << w[minlid] << " " << w[minrid];
}

