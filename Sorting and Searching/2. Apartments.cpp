#include "iostream"
#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef set<ll> sl;
typedef map<char, ll> mcl;
typedef map<ll, ll> mll;
typedef pair<char, ll> pcl;

#define PB push_back
#define F first 
#define S second
#define REP(i,a,b) for (ll i = a; i < b; i++)
#define REPR(i,a,b) for (ll i = a; i > b; i--)
#define REPJ(i,a,b,j) for (ll i = a; i < b; i+=j)
#define REPIT(it,o) for (auto it = o.begin(); it != o.end(); it++)
#define REPITR(it,o) for (auto it = o.rbegin(); it != o.rend(); it++)


int main() {
    ll n,m,k;
    cin >> n >> m >> k;
    vl tenants;
    vl apartments;
    REP(i,0,n){
        ll tmp;
        cin >> tmp;
        tenants.PB(tmp);
    }
    REP(i,0,m){
        ll tmp;
        cin >> tmp;
        apartments.PB(tmp);
    }
    ll ans = 0;
    sort(apartments.begin(), apartments.end());
    sort(tenants.begin(), tenants.end());
    ll t = 0;
    ll a = 0;
    while(a < apartments.size()){
        if (t >= tenants.size()){
            break;
        }
        if (apartments[a] >= tenants[t] - k && apartments[a] <= tenants[t] + k){
            t++;
            a++;
            ans++;
        } else if (tenants[t] < apartments[a]){
            t++;
        } else {
            a++;
        }
    }
    cout << ans;
}

// - first approach 
// sort both lists. nested loop to find the soln
// tle
// - second approach
// sort both. loop over apartments and search for tenants using a binary search algo(logn). if found remove that tenant from the list
// tle
// - third approach
// sort both. loop over simultaneously, check for eligibility and skip over whichevers value is less
// ac