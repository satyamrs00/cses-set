#include "iostream"
#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp> 

using namespace __gnu_pbds;
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef set<ll> sl;
typedef map<char, ll> mcl;
typedef map<ll, ll> mll;
typedef pair<char, ll> pcl;
typedef pair<ll, ll> pll;
typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;
typedef indexed_set<ll> isl;

#define fastio() ios_base::sync_with_stdio(0);cin.tie(NULL)
#define PB push_back
#define F first 
#define S second
#define REP(i,a,b) for (ll i = a; i < b; i++)
#define REPR(i,a,b) for (ll i = a; i > b; i--)
#define REPJ(i,a,b,j) for (ll i = a; i < b; i+=j)
#define REPIT(it,o) for (auto it = o.begin(); it != o.end(); it++)
#define REPITR(it,o) for (auto it = o.rbegin(); it != o.rend(); it++)

ll search(vl v, ll t, ll l){
    REPR(i,(ll)v.size()-1,max((ll)-1, (ll) v.size()-l-1)){
        if (v[i] == t){
            return i;
        } 
    } return -1;
}
int main() {
    fastio();
    ll n;
    cin >> n;
    vl v;
    ll ans = 0;
    ll curr_size = 0;
    REP(i,0,n){
        ll tmp;
        cin >> tmp;
        ll r = search(v, tmp, curr_size);
        if (r == -1){
            v.PB(tmp);
            curr_size++;
            ans = max(ans,curr_size);
        } else {
            v.PB(tmp);
            curr_size = v.size() - r -1;
        }
    }
    cout << ans;
}

//  TODO -tle