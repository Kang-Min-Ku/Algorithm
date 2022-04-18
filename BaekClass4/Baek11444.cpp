#include <iostream>
#include <vector>
using namespace std;
typedef unsigned long long INT64;
typedef vector<vector<INT64>> MATRIX;
INT64 DIVIDER = 1000000007;

MATRIX multiMatrix(MATRIX m1, MATRIX m2){
	INT64 size = m1.size();
	MATRIX rm(size,vector<INT64>(size));
	
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			for(int k=0;k<size;k++){
				rm[i][j] += (m1[i][k]*m2[k][j]);
			};
			rm[i][j]%=DIVIDER;
		}
	}
	return rm;
}

int main(){
	INT64 n;
	cin >> n;
	n-=1;
	MATRIX m = {{1,1},{1,0}};
	MATRIX ans = {{1,0},{0,1}};
	while(n>0){
		if(n%2==1) ans = multiMatrix(ans,m);
		m = multiMatrix(m,m);
		n/=2;
	}
	cout << ans[0][0];
}
//39 아이디어 따른데 쓸 수 이씅ㄹ 듯?
/*
Fn+2      1  1   Fn+1 
	   =        
Fn+1      1  0   Fn

Fn+2      1  1     F2
	   = (     )^n 
Fn+1      1  0     F1

F6			   F2
	   = M^4 
F5             F1
*/
/*
void print(MATRIX m){
	for(int i=0;i<m.size();i++){
		for(int j=0;j<m[i].size();j++){
			cout << m[i][j] << " ";
		}
		cout << endl;
	}
}
*/