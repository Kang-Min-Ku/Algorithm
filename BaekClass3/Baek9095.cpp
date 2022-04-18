#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int combination(int head, int tail){
	int result = 1;
	if(tail > head/2) tail = head-tail;
	for(int i = head;i>head-tail;i--) result *= i;
	for(int i=tail;i>0;i--) result /= i;
	return result;
}

int NumberOfCase(int num3, int num2, int num1){
	int result = 1;
	int total = num1 + num2 + num3;
	result *= combination(total, num1);
	total -= num1;
	result *= combination(total, num2);
	return result;
}

int main(){
	int len;
	cin >> len;
	vector<int> input(len);
	for(int i=0;i<len;i++) cin >> input[i];
	for(int i=0;i<len;i++){
		int num3 = input[i] / 3, num2, num1, result=0;
		for(num3;num3>=0;num3--){
			num2 = (input[i] - 3*num3) / 2;
			for(num2;num2>=0;num2--){
				num1 = (input[i] - 3*num3 - 2*num2);
				result += NumberOfCase(num3, num2, num1);
			}
		}
		cout << result << endl;
	}
}