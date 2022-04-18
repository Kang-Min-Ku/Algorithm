#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>

#define MAXCOMMAND 10*4
using namespace std;

typedef struct{
	string command;
	int num;
}COMMAND;
//사실 만들 때 주소적으로? 만들면 더 빠르게 가능할 것 같음.
class commandQueue{
private:
	int *queue;
	int queueSize;
public:
	commandQueue(){
		queue = new int[MAXCOMMAND]();
		memset(queue, 0, MAXCOMMAND);
		queueSize=0;
	}
	void push_front(int X){
		for(int i=queueSize;i>0;i--) queue[i] = queue[i-1];
		queue[0] = X;
		queueSize+=1;
	}
	void push_back(int X){
		queue[queueSize] = X;
		queueSize+=1;
	}
	void pop_front(){
		if(queueSize==0) cout << -1 << "\n";
		else{
			cout << queue[0] << "\n";
			for(int i=0;i<queueSize-1;i++){
				queue[i] = queue[i+1];
			}
			queueSize-=1;
		}
	}
	void pop_back(){
		if(queueSize==0) cout << -1 << "\n";
		else{
			cout << queue[queueSize-1] << "\n";
			queueSize-=1;
		}
	}
	void size(){
		cout << queueSize << "\n";
	}
	void empty(){
		if(queueSize) cout << 0 << "\n";
		else cout << 1 << "\n";
	}
	void front(){
		if(queueSize) cout << queue[0] << "\n";
		else cout << -1 << "\n";
	}
	void back(){
		if(queueSize) cout << queue[queueSize-1] << "\n";
		else cout << -1 << "\n";
	}
	void de(){
		delete [] queue;
	}
};

int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int len;
	cin >> len;
	COMMAND comSet[MAXCOMMAND];
	commandQueue q = commandQueue();
	for(int i=0;i<len;i++){
		cin >> comSet[i].command;
		if(comSet[i].command == "push_front" || comSet[i].command == "push_back") 
			cin >> comSet[i].num;
	}
	for(int i=0;i<len;i++){
		if(comSet[i].command=="push_front") q.push_front(comSet[i].num);
		else if(comSet[i].command=="push_back") q.push_back(comSet[i].num);
		else if(comSet[i].command=="pop_front") q.pop_front();
		else if(comSet[i].command=="pop_back") q.pop_back();
		else if(comSet[i].command=="size") q.size();
		else if(comSet[i].command=="empty") q.empty();
		else if(comSet[i].command=="front") q.front();
		else if(comSet[i].command=="back") q.back();
	}
	q.de();
	return 0;
}