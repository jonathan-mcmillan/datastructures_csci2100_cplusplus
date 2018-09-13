#include <iostream>
#include <array>
using namespace std;

void BubbleSort([] A,int n ){
	for(int i = 0; i < n-1; i++){
		int iMin = i;
		for(int j = 0; j< n-i-1; j++){
			if(A[j] >  A[i+1]){
				swap(A[i], A[i+1]);
			}
		}
	}
}

int main(){
        int A[] = {2,7,4,1,5,3};
        BubbleSort(A,6);
        for(int 1 = 0; i < 6; i++){
                cour << A[i] << ' ';
        }
        cout << endl;

        return 0;
}
