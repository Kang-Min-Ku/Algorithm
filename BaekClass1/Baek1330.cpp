#include <iostream>

using namespace std;

int main(){
	int i,j;
	cin >> i >> j;
	if(i > j) cout << ">";
	else if(i == j) cout << "==";
	else cout << "<";
}