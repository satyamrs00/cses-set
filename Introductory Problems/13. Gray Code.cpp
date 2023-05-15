#include "iostream"
#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef set<ll> sl;
typedef map<char, ll> mcl;
typedef pair<char, ll> pcl;

#define PB push_back
#define F first 
#define S second
#define REP(i,a,b) for (ll i = a; i < b; i++)
#define REPR(i,a,b) for (ll i = a; i > b; i--)
#define REPJ(i,a,b,j) for (ll i = a; i < b; i+=j)
#define REPIT(it,o) for (auto it = o.begin(); it != o.end(); it++)
#define REPITR(it,o) for (auto it = o.rbegin(); it != o.rend(); it++)

vs rec(ll n){
    if (n == 1) {
        vs x {"0", "1"};
        return x;
    }

    vs ans;
    vs prev = rec(n-1);
    ll l = prev.size();
    REP(i,0,l){
        ans.PB("0" + prev[i]);
    }
    REP(i,0,l){
        ans.PB("1" + prev[l-1-i]);
    }
    return ans;
}

int main() {
    ll n;
    cin >> n;
    vs v = rec(n);
    REPIT(it, v){
        cout << *it << "\n";
    }
}