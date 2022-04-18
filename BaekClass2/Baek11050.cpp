#include <iostream>
#include <vector>

using namespace std;

int facto(int k){
	if(k>1) return k*facto(k-1);
	else return k;
}

int facto_ver2(int k, int b){
	if(b>0) return k*facto_ver2(k-1, b-1);
	else return 1;
}

int main(){
	int a, b;
	cin >> a >> b;
	if(b > a/2) b = a-b;
	cout << facto_ver2(a, b) / facto(b);
}