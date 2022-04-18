#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
	int len, min, max;
	cin >> len;
	vector<int> input_(len);
	for(int i=0;i<len;i++){
		cin >> input_.at(i);
		if(i==0){
			min = input_.at(i);
			max = min;
		}
	}
	for(int i=0;i<len;i++){
		if(input_.at(i)>max) max = input_.at(i);
		else if(input_.at(i)<min) min = input_.at(i);
	}
	cout << min << " " << max;
}