#pragma GCC optimizer ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
typedef long long int ll;
#define mp(a,b) make_pair(a,b)
#define pii pair<ll, ll>
#define vl vector<int>
#define vll vector<vl>
#define push_back pb
#define w(t) int t;cin>>t;while(t--)
#define rep(i,a,b)  for(ll i=a;i<b;i++)
int main(){
    fastio;
    string s; cin>>s;
    s += "$";
    int n = s.size();
    vector<int> p(n), c(n); // p contains order of string & c contains equivalence classes in order of string
    {
        // k = 0
        vector<pair<char,int>> a(n); // pairs of characters and positions
        rep(i,0,n) a[i] = mp(s[i],i);
        
        sort(a.begin(), a.end());
        
        rep(i,0,n) p[i] = a[i].second; // Storing indices of each 2^k lenght string
        
        c[p[0]] = 0;
        rep(i,1,n){
            if(a[i].first == a[i-1].first){
                c[p[i]] = c[p[i-1]]; 
            }
            else {
                c[p[i]] = c[p[i-1]] + 1;
            }
        }
    }
    
    int k = 0;
    while((1<<k) < n) {
        // k -> k + 1
        vector<pair<pair<int,int>,int>> a(n); // 2 equivalence classes for left and right part and indexing it according to position
        rep(i,0,n) a[i] = {{c[i],c[(i+(1<<k))%n]},i};
        
        sort(a.begin(),a.end());
        
        rep(i,0,n) p[i] = a[i].second; // Storing indices of each 2^k lenght string
        c[p[0]] = 0;
        rep(i,1,n){
            if(a[i].first == a[i-1].first){
                c[p[i]] = c[p[i-1]]; 
            }
            else {
                c[p[i]] = c[p[i-1]] + 1;
            }
        }
        k++;
    }
    rep(i,0,n) cout<<p[i]<<endl;
}
