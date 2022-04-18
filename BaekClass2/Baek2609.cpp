#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

#define SEARCHMAX 10000

using namespace std;

//숫자가 최대 10000인데 10000이하면 100까지의 소수가 뭔지만 알면 됨 왜냐면 채로 걸러졌는데 남은건 소수일거임
int main(){
	int num1, num2;
	cin >> num1 >> num2;
	//채로 한 번 거를게유 erase 쓰는 법 익히기 100까지의 소수 구하기
	int prePrimeSet[25] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
	vector<int> primeSet;
	primeSet.reserve(SEARCHMAX);
	for(int i=2;i<SEARCHMAX;i++){
		bool isPrime = true;
		for(int j=0;j<25;j++){
			if(i%prePrimeSet[j]==0&&i!=prePrimeSet[j]){
				isPrime = false;
				break;
			}
		}
		if(isPrime) primeSet.push_back(i);
	}
	int count=1;
	int idx=0;
	while(idx < primeSet.size()){
		if(primeSet[idx]==0) idx+=1;
		else if(num1%primeSet[idx]==0&&num2%primeSet[idx]==0) {
			count*=primeSet[idx];
			num1 /= primeSet[idx];
			num2 /= primeSet[idx];
		}
		else idx+=1;
	}
	cout << count << endl << count * num1 * num2;
}