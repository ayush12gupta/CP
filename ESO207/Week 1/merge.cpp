#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int arr2[10000];

void merge1(int arr[], int i, int j, int k){
    // i --> leftmost,  j --> middle , k --> rightmost
    int p=i, q=j+1, r=i;
    int n = sizeof(*arr)/sizeof(arr[0]);
    // int arr2[n];
    for(int in=0; in<n; in++){
        arr2[i] = arr[i];
    }
    
    while(r <= k) {
        if ( p <= j && q <= k){
            if (arr[p]<=arr[q]){
                arr2[r] = arr[p];
                r+=1;
                p+=1;
            }
            else {
                arr2[r] = arr[q];
                r+=1;
                q+=1;
            }
        }
        else if(p>j && q<=k){
            arr2[r] = arr[q];
            q++; r++;
        }
        else if(p<=j && q>k){
            arr2[r] = arr[p];
            p++; r++;
        }
        else{
            cout<<"I don't know !!";
        }
        
    }
    // return arr2;
}

void merge(int arr[], int i, int j, int k){
    // i --> leftmost,  j --> middle , k --> rightmost
    merge1(arr, i, j , k);
    for(int in = i; in<=k; in++){
        arr[in] = arr2[in];
    }
}

void mergesort(int arr[], int i, int j){
    if(i>=j){
        return;
    }
    int k = (j-i)/2;
    k += i;
    mergesort(arr, i, k);
    mergesort(arr, k+1, j);
    merge(arr, i, k, j);
}

int main() {
    int arr[] = {20,13,24,5,6,3,12};
    int n = sizeof(arr)/sizeof(arr[0]);
    mergesort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
