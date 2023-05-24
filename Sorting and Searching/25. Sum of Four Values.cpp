#include "iostream"
#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef set<ll> sl;
typedef map<string, ll> msl;
typedef map<ll, ll> mll;
typedef unordered_map<ll, ll> umll;
typedef pair<string, ll> psl;
typedef pair<ll, ll> pll;

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
#define ALL(a) a.begin(),a.end()
#define ALLR(a) a.rbegin(),a.rend()

int main() {
    fastio();
    ll n,x;
    cin >> n >> x;
    vl v;
    map<ll,sl> m;
    REP(i,0,n){
        ll t;
        cin >> t;
        v.PB(t);
        if (m.count(t)){m[t].insert(i);} else {sl s; s.insert(i); m[t] = s;}
    }
    vl vc (v);
    sort(ALL(v));
    REP(i,0,n){
        REP(j,i+1,n){
            ll i1 = 0;
            ll i2 = n-1;
            while(i1 < i2 && i1 < n && i2 >= 0){
                if (v[i1]+v[i2] == x-v[i]-v[j]){
                    if (i2 == i || i2 == j){ 
                        i2--; continue; 
                    }
                    if (i1 == i || i1 == j){ 
                        i1++; continue; 
                    }
                    sl::I it1 = m[v[i]].begin();
                    cout << *it1+1 << ' ';
                    sl::I it2;
                    if (v[j] == v[i]) { it2 = ++it1; } else { it2 = m[v[j]].begin(); } 
                    cout << *it2+1 << ' ';

                    sl::I it3;
                    if (v[i1] == v[j]) { it3 = ++it2; } else if (v[i1] == v[i]){ it3 = ++it1; } else { it3 = m[v[i1]].begin(); } 
                    cout << *it3+1 << ' ';

                    sl::I it4;
                    if (v[i2] == v[i1]) { it4 = ++it3; } else if (v[i2] == v[j]){ it4 = ++it2; } else if (v[i2] == v[i]){ it4 = ++it1; } else { it4 = m[v[i2]].begin(); } 
                    cout << *it4+1 << ' ';

                    return 0;
                } else if (v[i1]+v[i2] > x-v[i]-v[j]){
                    i2--;
                } else if (v[i1]+v[i2] < x-v[i]-v[j]){
                    i1++;
                }
            }
        }
    }
    cout << "IMPOSSIBLE\n";
}

// - initial approach
// sort , keep a copy, loop over all pairs - use two pointer to find the other two values, find the position of those values in the copy
// tle
// - third approach
// sort , keep a map of value to set of indices, loop over all pairs - use two pointer to find the other two values, find the position in the map
// ac
