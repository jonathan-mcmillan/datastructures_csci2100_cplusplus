#include <iostream>
#include <algorithm>

using namespace std;

void SelectionSort(int A[], int n){
	int i, j, iMin;
	for (i = 0; i < n-1; i++){
		iMin = i;
		for(j = i + 1; j < n; j++){
			if(A[j] < A[iMin]){
				iMin = j;
			}
		}	
		swap(A[iMin],A[i]);
	}
}

void BubbleSort(int B[], int n){
	int i, j;
	for (i = 1; i < n-1; i++) {
		for (j = 0; j <(n-i); j++) {
			if (B[j] >  B[j+1]){
				 swap(B[j], B[j + 1]);
			}
		}
	}
}

void InsertionSort(int C[], int n) {
	for (int i = 1; i < n; i++) {
		int value = C[i];
		int j = i - 1;

		while (j >= 0 && C[j] > value) {
			C[j+1] = C[j];
			j = j - 1;
		}
		C[j+1] = value;
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

	int B[] = { 12, 17, 14, 11, 15, 13 };
	cout << "Bubble Sorting..." << endl;
	BubbleSort(B, 6);
	for (int i = 0; i<6; i++){
		cout << B[i] << " ";
	}
	cout << endl << endl;
	
	cout << "Insertion Sorting..." << endl;
	int C[] = { 22, 27, 24, 21, 25, 23 };
	InsertionSort(C, 6);
	for (int i = 0; i<6; i++){
		cout << C[i] << " ";
	}	
	cout << endl << endl;
	return 0;
}
