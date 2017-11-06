#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int A[] = {2, 7, 4, 1, 5, 3};
    cout << "Selection Sorting..." << endl;
    SelectionSort(A, 6);
    for (int i=0; i<6; i++)
        cout << A[i] << " ";
    cout << endl << endl;
    
    int B[] = {12, 17, 14, 11, 15, 13};
    cout << "Bubble Sorting..." << endl;
    BubbleSort(B, 6);
    for (int i=0; i<6; i++)
        cout << B[i] << " ";
    cout << endl << endl;
    
    cout << "Insertion Sorting..." << endl;
    int C[] = {22, 27, 24, 21, 25, 23};
    InsertionSort(C, 6);
    for (int i=0; i<6; i++)
        cout << C[i] << " ";
    cout << endl << endl;
    
    cout << "Merge Sorting..." << endl;
    int D[] = {22, 27, 24, 21, 25, 23, 26, 28};
    MergeSort(D, 0, 7);
    for (int i=0; i<8; i++)
        cout << D[i] << " ";
    cout << endl << endl;
    
    cout << "Quick Sorting..." << endl;
    int E[] = {32, 37, 34, 31, 35, 33, 36, 38};
    QuickSort(E, 0, 7);
    for (int i=0; i<8; i++)
        cout << E[i] << " ";
    cout << endl << endl;
    
    return 0;
}
