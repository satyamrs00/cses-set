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

bool com (pll a, pll b){
    if (a.S == b.S) return a.F < b.F;
    return a.S < b.S;
}
int main() {
    ll n;
    cin >> n;
    vector<pll> m;
    REP(i,0,n){
        pll tmp;
        cin >> tmp.F >> tmp.S;
        m.PB(tmp);
    }
    sort(m.begin(), m.end(), com);
    ll curr_time = 0, ans = 0;
    REP(i,0,n){
        if (m[i].F >= curr_time){
            ans++;
            curr_time = m[i].S;
        }
    }
    cout << ans;
}

// - initial approach 
// sort by ending time of movies and count how many you can watch in that order
// ac