#include <iostream>
#include <string>

using namespace std;

int calScore(string answer){
	int score = 0;
	int stack = 1;
	for(int i=0;i<answer.length();i++){
		if(answer.at(i)=='O'){
			score += stack;
			stack++;
		}
		else{
			stack = 1;
		}
	}
	return score;
}

int main(){
	int len;
	cin >> len;
	string *con = new string[len];
	for(int i=0;i<len;i++){
		cin >> con[i];
	}
	for(int i=0;i<len;i++){
		cout << calScore(con[i]) << endl;
	}
	
}