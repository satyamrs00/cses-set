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
    ll n,m, tmp;
    cin >> n >> m;
    sl h;
    mll count;
    vl t;
    REP(i,0,n){
        cin >> tmp;
        if (count[tmp]){
            count[tmp]++;
        } else {
            count[tmp] = 1;
        }
        h.insert(tmp);
    }
    REP(i,0,m){
        cin >> tmp;
        t.PB(tmp);
    }
    REP(i,0,m){
        sl::iterator it = h.upper_bound(t[i]);
        if (it == h.begin()){
            cout << -1 << "\n";
            continue;
        }
        cout << *--it << "\n";
        if (count[*it] > 1){
            count[*it]--;
        } else {
            h.erase(it);
        }
    }
}

// - first approach
// stored count of tickets in a map, stored the prices in set, for every customer find upperbound value-1 (if exists) then cout -> reduce count from map , if it gets to 0 remove from set
// ac