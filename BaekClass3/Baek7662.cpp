#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int binarySearch(vector<int> queue, int num){
	int start = 0, end = queue.size() - 1, mid = 0;
	while(start <= end){
		mid = (start+end)/2;
		if(queue[mid] > num){
			end = mid-1;
		}
		else if(queue[mid] < num){
			start = mid+1;
		}
		else return mid+1;
	}
	mid = (start+end)/2;
	if(queue.size()>0 && queue[mid] < num) mid++; 
	return mid;
}
//erase가 O(n)임
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int num_test, com_len, num, idx;
	string command;
	vector<int> queue;
	cin >> num_test;
	for(int i=0;i<num_test;i++){
		cin >> com_len;
		queue.clear();
		queue.reserve(com_len);
		for(int j=0;j<com_len;j++){
			cin >> command >> num;
			if(command == "I"){
				idx = binarySearch(queue, num);
				queue.insert(queue.begin()+idx,num);
			}
			else if((command == "D" && num == 1) && !queue.empty()){
				queue.pop_back();
			}
			else if((command == "D" && num == -1) && !queue.empty()){
				queue.erase(queue.begin());
			}
			//for(int i=0;i<queue.size();i++) cout << queue[i] << " ";
			//cout << "\n";
		}
		if(queue.empty()) cout << "EMPTY\n";
		else cout << queue[queue.size()-1] << " " << queue[0] << "\n";
	}
}