#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


int main(){
	int size, cycle;
	cin >> size >> cycle;
	vector<int> queue(size), order;
	order.reserve(size);
	for(int i=0;i<size;i++) queue[i] = i+1;
	while(queue.size()>0){
		for(int i=0;i<cycle;i++){
			int temp = queue.front();
			queue.erase(queue.begin());
			if(i == cycle-1) order.push_back(temp);
			else queue.push_back(temp);
		}
	}
	
	cout << "<";
	for(int i=0;i<order.size();i++){
		cout << order[i];
		if(i<order.size()-1) cout << ", ";
	}
	cout << ">";
}