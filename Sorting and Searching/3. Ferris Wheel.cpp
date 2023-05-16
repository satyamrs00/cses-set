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
    ll n,x;
    cin >> n >> x;
    vl p;
    REP(i,0,n){
        ll tmp;
        cin >> tmp;
        p.PB(tmp);
    }
    sort(p.begin(), p.end());
    ll ans = 0;
    ll f = 0, b = p.size()-1;
    while(f <= b){
        if (p[f] + p[b] <= x && f != b){
            ans++;
            f++; b--;
        } else {
            ans++;
            b--;
        }
    }
    cout << ans;
}