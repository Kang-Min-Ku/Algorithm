#include <iostream>
#include <string>

using namespace std;

typedef struct{
	int t;
	string w;
}CONTAINER;

int main(){
	int len;
	cin >> len;
	CONTAINER *con = new CONTAINER[len];
	for(int i=0;i<len;i++){
		cin >> con[i].t >> con[i].w;
	}
	
	for(int i=0;i<len;i++){
		for(int j=0;j<con[i].w.length();j++){
			for(int k=0;k<con[i].t;k++){
				cout << con[i].w.at(j);
			}
		}
		cout << endl;
	}
	
	delete[] con;
}