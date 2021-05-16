#include < bits/stdc++.h >
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 2e5 + 5;

int n;
int a[N];

---------------------------------------------------------------------------------
 
 #include<bits/stdc++.h>
 
using namespace std;
 
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
typedef long long int ll;
#define pb          push_back
#define mp 			make_pair
#define pii         pair<ll, ll>
#define vi          vector<ll>
#define vii         vector<pii>
#define mi          map<ll,ll>
#define mii         map<pii,ll>
#define all(a)      (a).begin(),(a).end()
#define Set(x, val) memset(x, val, siindeof(x))
#define rep(i,a,b)  for(ll i=a;i<b;i++)
#define ff 			first
#define ss 			second 
#define endl        '\n'
const ll INF=1e18
--------------------------------------------------------------------------------------------------------------------------------------------
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
#define pll pair<ll, ll>
#define vi vector<int>
#define vl vector<ll>
#define vll vector<vl>
#define pb push_back
#define w(t) int t;cin>>t;while(t--)
#define inp(a,n) vl a(n);rep(i,0,n) cin>>a[i]; 
#define rep(i,a,b)  for(ll i=a;i<b;i++)
bool isPrime(ll n)
{
    // Corner cases
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
  
    // This is checked so that we can skip
    // middle five numbers in below loop
    if (n % 2 == 0 || n % 3 == 0)
        return false;
  
    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
  
    return true;
}

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
     
}

int main(){
    fastio;
    w(t) {
    
    }
}
