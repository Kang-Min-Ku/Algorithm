#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define MIL 1000000
using namespace std;

int numW=0, numB=0;

int numCP(vector<vector<bool>> &table, int sR, int sC, int size){
	bool isone = true, color=table[sR][sC];
	if(size>0){
		for(int i=sR;i<sR+size;i++){
			for(int j=sC;j<sC+size;j++){
				if(color!=table[i][j]){
					isone = false;
					break;
				}
			}
			if(!isone) break;
		}
		if(isone) {
			if(color) numB+=1;
			else numW+=1;
			return 1;
		}
		else return numCP(table, sR, sC, size/2) + numCP(table, sR+size/2, sC, size/2) + 									numCP(table, sR, sC+size/2, size/2) + numCP(table, sR+size/2, 										sC+size/2, size/2);
	}
	else return 0;
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int len, result;
	bool temp;
	vector<vector<bool>> table;
	cin >> len;
	table.reserve(len);
	for(int i=0;i<len;i++) table[i].reserve(len);
	for(int i=0;i<len;i++){
		for(int j=0;j<len;j++){
			cin >> temp;
			table[i].push_back(temp);
		}
	}
	result = numCP(table, 0, 0, len);
	cout << numW << "\n" << numB << "\n";
	
}