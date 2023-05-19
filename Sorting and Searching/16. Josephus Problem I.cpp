#include "iostream"
#include "bits/stdc++.h"
// #include "ext/pb_ds/assoc_container.hpp"

// using namespace __gnu_pbds;
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
// typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;
// typedef indexed_set<ll> isl;

#define fastio() ios_base::sync_with_stdio(0);cin.tie(NULL)
#define PB push_back
#define F first 
#define S second
#define I iterator
#define REP(i,a,b) for (ll i = a; i < b; i++)
#define REPR(i,a,b) for (ll i = a; i > b; i--)
#define REPJ(i,a,b,j) for (ll i = a; i < b; i+=j)
#define REPIT(it,o) for (auto it = o.begin(); it != o.end(); it++)
#define REPITR(it,o) for (auto it = o.rbegin(); it != o.rend(); it++)

int main() {
    fastio();
    ll n;
    cin >> n;
    sl v;
    REP(i,0,n){
        v.insert(i+1);
    }
    for(sl::I it = v.begin(); v.size() > 0; it=it){
        if (it == v.end()){
            it = v.begin();
        }
        it++;
        if (it == v.end()){
            it = v.begin();
        }
        cout << *it << " ";
        it = v.erase(it);
    }
}

// - initial approach
// get a vector (1-n) keep iterating to erase every other element until v.size != 0
// correct ans but tle
// - second approach
// iterate over a diff var that goes 2,4,8,16 and inside this loop iterate startpoint-n jumping diff values print i+1 
// couldn't work because cant find the startpoint properly for each diff value 
// - third approach
// get a set (1-n) keep iterating to erase every other element until s.size != 0
// ac