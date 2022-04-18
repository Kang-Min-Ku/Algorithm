#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	int num, s, e;
	int dist, maxSpeed;
	cin >> num;
	for(int i=0;i<num;i++){
		cin >> s >> e;
		int time=0;
		dist = e-s;
		maxSpeed = (int)sqrt(dist);
		
		time += 2*maxSpeed - 1;
		dist -= (int)pow(maxSpeed,2);
		time +=	(int)(dist/maxSpeed);
		if(dist%maxSpeed>0) time += 1;
		cout << time << endl;
	}
}