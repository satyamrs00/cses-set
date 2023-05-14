#include "iostream"
#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef set<ll> sl;

#define PB push_back
#define REP(i,a,b) for (ll i = a; i < b; i++)
#define REPR(i,a,b) for (ll i = a; i > b; i--)
#define REPJ(i,a,b,j) for (ll i = a; i < b; i+=j)

int main() {
    ll t;
    cin >> t;
    while(t--){
        ll a,b;
        cin >> a >> b;
        if (((a %3 + b%3) %3 == 0) && abs(a-b) <= min(a,b)){
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}