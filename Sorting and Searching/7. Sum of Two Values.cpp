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

ll binary_search(vl v, ll a, ll b, ll t, ll not_index){
    ll m = (a+b+1)/2;
    if (m < a || m > b){
        return -1;
    }
    if (v[m] == t && m != not_index){
        return m;
    } else if (t < v[m]){
        return binary_search(v,a,m-1,t, not_index);
    } else {
        return binary_search(v,m+1,b,t, not_index);
    }
}

int main() {
    ll n, x;
    cin >> n >> x;
    vl a;
    map<ll,sl> m;
    REP(i,0,n){
        ll tmp;
        cin >> tmp;
        if (m.find(tmp) != m.end()){
            m[tmp].insert(i);
        } else {
            sl s{i};
            m[tmp] = s;
        }
        a.PB(tmp);
    }
    sort(a.begin(), a.end());
    REP(i,0,n){
        ll o = binary_search(a,0,n-1,x-a[i],i);
        if (o != -1){
            sl::iterator it1 = m[a[i]].begin();
            cout << *it1++ + 1<< " ";
            if (a[o] == a[i]){
                cout << *it1 + 1;
            } else {
                sl::iterator it2 = m[a[o]].begin();
                cout << *it2++ + 1 << " ";
            }
            return 0;
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}

// TODO - tle