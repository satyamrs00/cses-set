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
typedef pair<ll, ll> pll;

#define PB push_back
#define F first 
#define S second
#define REP(i,a,b) for (ll i = a; i < b; i++)
#define REPR(i,a,b) for (ll i = a; i > b; i--)
#define REPJ(i,a,b,j) for (ll i = a; i < b; i+=j)
#define REPIT(it,o) for (auto it = o.begin(); it != o.end(); it++)
#define REPITR(it,o) for (auto it = o.rbegin(); it != o.rend(); it++)

ll search(vl v, ll t){
    REP(i,0,v.size()){
        if (v[i] == t){
            return i;
        } 
    } return -1;
}
int main() {
    ll n;
    cin >> n;
    vl v;
    ll ans = 0;
    REP(i,0,n){
        ll tmp;
        cin >> tmp;
        ll r = search(v, tmp);
        if (r == -1){
            v.PB(tmp);
            ans = max(ans,(ll) v.size());
        } else {
            vl::iterator it = v.begin();
            REP(j,0,r){
                it++;
            }
            it++;
            v.erase(v.begin(), it);
            v.PB(tmp);
        }
    }
    cout << ans;
}

//  TODO -tle