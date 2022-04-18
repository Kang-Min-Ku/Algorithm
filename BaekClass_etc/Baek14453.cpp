#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	int time,numWin,maxIdx,max=0;
	char temp;
	cin >> time;
	maxIdx = time - 1;
	vector<vector<int>> hsp(3,vector<int>(time));
	//get input & setup hsp
	// H S P
	for(int i=0;i<time;i++){
		cin >> temp;
		if(i==0){
			switch(temp){
				case 'S':
					hsp[0][0] = 1;
					break;
				case 'P':
					hsp[1][0] = 1;
					break;
				case 'H':
					hsp[2][0] = 1;
					break;
			}
		}
		else{
			switch(temp){
				case 'S':
					hsp[0][i] = hsp[0][i-1]+1;
					hsp[1][i] = hsp[1][i-1];
					hsp[2][i] = hsp[2][i-1];
					break;
				case 'P':
					hsp[0][i] = hsp[0][i-1];
					hsp[1][i] = hsp[1][i-1]+1;
					hsp[2][i] = hsp[2][i-1];
					break;
				case 'H':
					hsp[0][i] = hsp[0][i-1];
					hsp[1][i] = hsp[1][i-1];
					hsp[2][i] = hsp[2][i-1]+1;
					break;
			}
		}
	}
	
	for(int i=0;i<3;i++) if(hsp[i][maxIdx]>max) max = hsp[i][maxIdx];
	for(int idx=1;idx<time;idx++){
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				//i->j
				// 01(HS) 02(HP) 10(SH) 12(SP) 20(PH) 21(PS)
				if(i==j) continue;
				numWin = hsp[i][idx-1]+(hsp[j][maxIdx]-hsp[j][idx-1]);
				if(numWin > max) max = numWin;
			}
		}
	}
	
	cout << max;
}


/*
H > S
S > P
P > H
S P H
  P P H P S
H 0 0 0 0 1
S 1 2 2 3 3
P 0 0 1 1 1

CASE : HS, HP, SH, SP, PH, PS
ANSWER : S S S S H

HS[i] = H에서 S로 i번째에 바꿀 때 이긴 횟수
HS[i] = H[i-1] + (S[MAX_IDX]-S[i-1])

SH[4] = S[3] + (H[4]-H[3])
SH[3] = 3 + (1 - 0)
*/