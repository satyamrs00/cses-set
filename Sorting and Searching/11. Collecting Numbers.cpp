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
#define I iterator
#define REP(i,a,b) for (ll i = a; i < b; i++)
#define REPR(i,a,b) for (ll i = a; i > b; i--)
#define REPJ(i,a,b,j) for (ll i = a; i < b; i+=j)
#define REPIT(it,o) for (auto it = o.begin(); it != o.end(); it++)
#define REPITR(it,o) for (auto it = o.rbegin(); it != o.rend(); it++)

int main() {
    ll n;
    cin >> n;
    vl a;
    vl x;
    REP(i,0,n){
        ll tmp;
        cin >> tmp;
        a.PB(tmp);
        x.PB(i+1);
    }
    ll ans = 1;
    vl::I xi = x.begin();
    vl::I ai = a.begin();
    while(xi != x.end()){
        if (ai == a.end()){
            ans++; ai = a.begin();
        }
        if (*ai == *xi){
            xi++;
        } 
        ai++;
    }
    cout << ans;
}

//  TODO - incomplete