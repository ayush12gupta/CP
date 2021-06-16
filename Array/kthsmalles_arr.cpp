#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))
#define vl vector<ll>
#define vll vector<vl>
#define pb push_back

int kthSmallest(int arr[], int l, int r, int k)
{
	cout<<arr.size();
	return 0;        
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int a[] = {7, 10, 4, 3, 20, 15};
    int sm = kthSmallest(a, 0, 5, 2);
return 0;
}
