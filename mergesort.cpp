#include <iostream>
using namespace std;

// [l...m] and [m+1...r]
void merge(int A[], int l, int m, int r){
    int len1 = m-l+1;
    int len2 = r-m;
    int L[len1], R[len2];
    for (int i=l,j=0;i<=m;i++,j++){
        L[j]=A[i];
    }
    for (int j=0;j<len2;j++){
        R[j]=A[j+m+1];
    }
    int li = 0, ri = 0, k = l;
    while (li<len1 && ri<len2)
    {
        if (L[li]<=R[ri]){
            A[k] = L[li];
            li++;
        }
        else {
            A[k] = R[ri];
            //cout<<A[k]<<"  nn  ";
            ri++;
        }
        k++;
    }
    
    while(li<len1){
        A[k] = L[li];
        k++;
        li++;
    }
    
    while(ri<len2){
        A[k] = R[ri];
        k++;
        ri++;
    }
    //cout<<A[0]<<" "<<A[1];

}

void mergesort(int A[], int l, int r){
    if (l < r){
        int m = (r+l)/2;
        mergesort(A, l, m);
        mergesort(A, m+1, r);

        merge(A, l, m, r);
    }
}

int main(){
    int n;
    cout<<"Enter the size of array to be sorted: ";
    cin>>n;
    int A[n];
    cout<<"Enter the elements of the array: ";
    // Input 
    for(int i=0;i<n;i++){
        cin>>A[i];
    }

    // Sorting
    mergesort(A, 0, n-1);
    for (int i=0;i<n;i++){
        cout<<A[i]<<" ";
    }
}