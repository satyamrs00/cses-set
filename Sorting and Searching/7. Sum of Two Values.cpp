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

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL)
#define PB push_back
#define F first 
#define S second
#define REP(i,a,b) for (ll i = a; i < b; i++)
#define REPR(i,a,b) for (ll i = a; i > b; i--)
#define REPJ(i,a,b,j) for (ll i = a; i < b; i+=j)
#define REPIT(it,o) for (auto it = o.begin(); it != o.end(); it++)
#define REPITR(it,o) for (auto it = o.rbegin(); it != o.rend(); it++)

int main() {
    fastio();
    ll n, x;
    cin >> n >> x;
    mll m;
    REP(i,0,n){
        ll tmp;
        cin >> tmp;
        if (m.count(x-tmp)){
            cout << i+1 << " " << m[x-tmp] +1 ;
            return 0;
        }

        if (!m.count(tmp)){
            m[tmp] = i;
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}
