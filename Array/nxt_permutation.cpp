#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))
#define vl vector<ll>
#define vll vector<vl>
#define pb push_back

// void swap()
void rev(vector<int> &nums, int l, int r) {
	while(l<r) {
		swap(nums[l++], nums[r++]);
	}
}

void nxtpermutation(vector<int> &nums) {
	int n = nums.size();
	int i, j;
	for (i=n-1; i>0; i--) {
		if (nums[i] > nums[i-1]) break;
	}

	if (i==0){
		rev(nums, 0, n-1);
	}
	int x = nums[i-1], sm_ind = i;
	for (j=i+1; j<n; j++) {
		if (nums[j]>x && nums[j] < nums[sm_ind]) sm_ind = j;
	}
	swap(nums[sm_ind], nums[i-1]);
	sort(nums.begin() + i, nums.begin() + n);
	
	return;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    vector<int> nums = {1, 5, 4, 3, 2};
    nxtpermutation(nums);
    for(int i=0; i<nums.size(); i++) {
    	cout<<nums[i]<<" ";
    }
	return 0;
}
