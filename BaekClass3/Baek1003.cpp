#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define MAX 40
using namespace std;

class TIMECHECK{
public:
	int time0;
	int time1;
	TIMECHECK(int a, int b){
		time0 = a;
		time1 = b;
	}
};

int main(){
	int len;
	cin >> len;
	vector<int> input(len);
	vector<TIMECHECK> piboTime;
	piboTime.reserve(MAX);
	piboTime.push_back(TIMECHECK(1,0));
	piboTime.push_back(TIMECHECK(0,1));
	for(int i=0;i<len;i++) cin >> input[i];
	
	for(int i=0;i<len;i++){
		if(piboTime.size()-1 < input[i]){
			while(piboTime.size()-1<input[i]){
				int m = piboTime.size();
				piboTime.push_back(TIMECHECK(piboTime[m-1].time0+piboTime[m-2].time0,piboTime[m-1].time1+piboTime[m-2].time1));
			}
			cout << piboTime[input[i]].time0 << " " << piboTime[input[i]].time1 << endl;
		}
		else cout << piboTime[input[i]].time0 << " " << piboTime[input[i]].time1 << endl;
	}
}