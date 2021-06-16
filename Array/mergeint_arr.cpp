#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))
#define vl vector<ll>
#define vll vector<vl>
#define pb push_back

bool combine(vector<int> first, vector<int> second) {
	return first[0]<second[0];
}

vector<vector<int>> merge(vector<vector<int>>& intervals) {
	int n = intervals.size();
	sort(intervals.begin(), intervals.end(), combine);
	vector<vector<int>> res;
	for (int i=0; i<intervals.size(); i++) {
		int strt =  intervals[i][0];
		int end = intervals[i][1];
		if (i==intervals.size()-1) {
			res.pb(intervals[i]);
			continue;
		}
		while(i<intervals.size() && end>=intervals[i][0]) {
			
			if (end<=intervals[i][1]){
				end = intervals[i][1];
			}
			i++;
		}
		vector<int> tmp = {strt, end};
		res.pb(tmp);

		i--;
	}
	return res;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    vector<vector<int>> a = {{1,4},{4,5}};
    
	vector<vector<int>> res = merge(a);
    for(int i=0; i<res.size(); i++) {
    	cout<<"{ ";
    	for(int j=0; j<res[i].size(); j++) {
    		cout<<res[i][j]<<" ";
    	}
    	cout<<"}";
    }
	return 0;
}
