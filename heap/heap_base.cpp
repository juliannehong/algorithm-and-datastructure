// https://www.hackerearth.com/practice/data-structures/trees/heapspriority-queues/tutorial/
#include <iostream>
#include <vector>
using namespace std;

void swap(int& x, int& y){
  int temp = x;
  x = y;
  y = temp;
}

void heapify(vector<int>& v, int index){
	int left = 2*index, int right = 2*index+1, max = i;
	int N = v.size();
	if (left <= N && v[left] > v[max]){
		max = left;
	}

	if (right <= N && v[right] > v[max]){
		max = right;
	}

	if (max != i){
		swap(v[i], v[max]);
		heapify(v, max);
	}
}

void build_max_heap(vector<int>& v){
	int N = v.size();
	for (int i = N/2; i >= 1; i--){
		heapify(v, i);
	}
}

void heap_sort(vector<int>& v){
	build_max_heap(v);
	int N = v.size();
	for (int i = N; i >= 1; i--){
		swap(v[1], v[i]);
		N -= 1;
		heapify(v, 1);
	}
}