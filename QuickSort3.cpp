// Devide and Conquor
// 3-way partition QuickSort Algorithm
// Average Case running time O(nlog(n))
// Worst Case running time O(n^2)
// Space Complexity O(log(n))

#include <iostream>
#include <vector>
using namespace std;


void partition(vector<int> &a, int begin, int end, int &m1, int &m2){

	if(end - begin <= 1){
		if(a[end] < a[begin])
			swap(a[begin], a[end]);
		m1 = begin;
		m2 = end;
		return;
	}

	int mid = begin;
	int pivot = a[end];

	while(mid <= end){

		if(a[mid] < pivot)
			swap(a[begin++], a[mid++]);
		else if(a[mid] == pivot)
			mid++;
		else if(a[mid] > pivot)
			swap(a[mid], a[end--]);

	}

	m1 = begin - 1;
	m2 = mid;
	
}

void QuickSort(vector<int> &a, int begin, int end){

	if(begin < end){

		int m1, m2;

		partition(a, begin, end, m1, m2);

		QuickSort(a, begin, m1);
		QuickSort(a, m2, end);

	}

	return;

}



int main(){

	int n;

	cin >> n;

	vector<int> array(n);

	for(int i=0; i<n; ++i){
		cin >> array[i];
	}

	QuickSort(array, 0, n-1);

	for(int i=0; i<n; ++i)
		cout << array[i] << " ";
	cout << "\n";

	return 0;
}