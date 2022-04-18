#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class MEETING{
private:
	int start_time;
	int end_time;
public:
	MEETING(int st, int et){
		start_time = st;
		end_time = et;
	}
	int getST(){return start_time;}
	int getET(){return end_time;}
	void print(){cout << start_time << " " << end_time << endl;}
};

bool compare(MEETING x, MEETING y){
	if(x.getET() == y.getET()) return x.getST() < y.getST();
	else return x.getET() < y.getET();
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int len, result=1;
	int sT, eT;
	vector<MEETING> meeting_set;
	cin >> len;
	meeting_set.reserve(len);
	for(int i=0;i<len;i++){
		cin >> sT >> eT;
		meeting_set.push_back(MEETING(sT, eT));		
	}
	sort(meeting_set.begin(), meeting_set.end(), compare);
	//for(int i=0;i<meeting_set.size();i++) meeting_set[i].print();
	eT = meeting_set[0].getET();
	for(int i=1;i<len;i++){
		if(meeting_set[i].getST() >= eT){
			//meeting_set[i].print();
			result+=1;
			eT = meeting_set[i].getET();
		}
	}
	cout << result << '\n';
	
}