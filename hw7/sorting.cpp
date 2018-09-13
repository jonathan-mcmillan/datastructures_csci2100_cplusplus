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

void Merge(int D[], int left, int middle, int right)
{
    int i, j, k;
    int num1 = middle - left + 1;
    int num2 =  right - middle;
 
    int L[num1], R[num2];
 
    
    for (i = 0; i < num1; i++)
        L[i] = D[left + i];
    for (j = 0; j < num2; j++)
        R[j] = D[middle + 1+ j];
 
    i = 0; 
    j = 0; 
    k = left; 
    while (i < num1 && j < num2)
    {
        if (L[i] <= R[j])
        {
            D[k] = L[i];
            i++;
        }
        else
        {
            D[k] = R[j];
            j++;
        }
        k++;
    }
 
    while (i < num1)
    {
        D[k] = L[i];
        i++;
        k++;
    }
 
    while (j < num2)
    {
        D[k] = R[j];
        j++;
        k++;
    }
}

void MergeSort(int D[], int left, int right) {
	if(left < right){
		int middle = left+(right-left)/2;
		MergeSort(D, left, middle);
		MergeSort(D, middle+1, right);
		Merge(D, left, middle, right);
	}
}

int Partition(int E[], int start, int end) {
	int pivot = E[end];
	int index = (start -1);

	for(int i = start; i <= end -1; i++){
		if(E[i] <= pivot){
			index++;
			swap(E[index],E[i]);
		}
	}
	swap(E[index+1], E[end]);
	return(index +1);
}

void QuickSort(int E[], int start, int end) {
        if(start < end){
		int pIndex = Partition(E, start, end);
         	QuickSort(E, start, pIndex - 1);
        	QuickSort(E, pIndex + 1, end);
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
	cout << "Merge Sorting..." << endl;

	int D[] = {22, 27, 24, 21, 25, 23, 26, 28};
  	MergeSort(D, 0, 7);
    	for (int i=0; i<8; i++){
        	cout << D[i] << " ";
    	}
	cout << endl << endl;

    	cout << "Quick Sorting..." << endl;
    	int E[] = {32, 37, 34, 31, 35, 33, 36, 38};
    	QuickSort(E, 0, 7);
    	for (int i=0; i<8; i++){
        	cout << E[i] << " ";
    	}
	cout << endl << endl;
	
	return 0;
}
