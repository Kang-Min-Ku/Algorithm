#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
	int len;
	int sum=0;
	string input;
	cin >> len;
	cin >> input;
	for(int i=0;i<len;i++) sum += (int)input.at(i) - (int)'0';
	cout << sum;
}