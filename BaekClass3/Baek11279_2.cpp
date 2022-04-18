#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

#define MAX 100005
using namespace std;

void swap(int *x, int *y){
	int temp = *x;
	*x = *y;
	*y = temp;
}

int insertNode(int *HEAP, int size, int num){
	size+=1;
	int rv = size;
	HEAP[size] = num;
	while(size>1 && HEAP[size] > HEAP[(int)size/2]){
		swap(HEAP[size], HEAP[(int)size/2]);
		size /= 2;
	}
	return rv;
}

int deleteNode(int *HEAP, int size){
	if(size==0){
		cout << 0 << "\n";
		return 0;
	}
	cout << HEAP[1] << "\n";
	int idx = 1;
	HEAP[idx] = HEAP[size];
	HEAP[size] = 0;
	size -= 1;
	while(idx*2 <= size && (HEAP[idx] < HEAP[idx*2] || HEAP[idx] < HEAP[idx*2+1])){
		if(HEAP[idx*2+1] < HEAP[idx*2]){
			swap(HEAP[idx], HEAP[idx*2]);
			idx *= 2;
		}
		else{
			swap(HEAP[idx], HEAP[idx*2+1]);
			idx = idx*2 + 1;
		}
	}
	return size;
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int len, size=0, com;
	int HEAP[MAX] = {0,};
	cin >> len;
	for(int i=0;i<len;i++){
		cin >> com;
		if(com == 0) size = deleteNode(HEAP, size);
		else size = insertNode(HEAP, size, com);
	}
	return 0;
}