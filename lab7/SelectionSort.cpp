#include <array>
#include <iostream>
using namespace std;

void SelectionSort(Array A,int n){
	for(int i = 0; i < n-2; i++){
		int iMin = i;
		for(int j = i+1; j < n-1; j++){
			if(A[j] < A[iMin]){
				iMin = j;
			}
			int temp = A[i];
			A[i] = A[iMin];
			A[iMin] = temp;
		}
	}
}
nt main(){
        int A[] = {2,7,4,1,5,3};
        SelectionSort(A,6);
        for(int 1 = 0; i < 6; i++){
                cour << A[i] << ' ';
        }
        cout << endl;

        return 0;
}

int main(){
	int A[] = {2,7,4,1,5,3};
	SelectionSort(A,6);
	for(int 1 = 0; i < 6; i++){
		cour << A[i] << ' ';
	}
	cout << endl;

	return 0;
}
