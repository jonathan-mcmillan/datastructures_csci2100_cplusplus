#include <iostream>
#include <algorithm>

using namespace std;

void SelectionSort(int A[], int n){
	for(int i = 0; i < n-2; i++){
		int iMin = i;
		for(int j = i + 1; j < n - 1; j++){
			if(A[j] < A[iMin]){
				iMin = j;
			}
			swap(&A[iMin],&A[i]);
		}
	}
}

int main(){
	int A[] = {2,7,4,1,5,3};
	cout << "Selection Sorting..." << endl;
	SelectionSort(A, 6);
	for(int i = 0; i < 6; i++){
		cout << A[i] << " ";
	}
	cout << endl << endl;

	return 0;
}
