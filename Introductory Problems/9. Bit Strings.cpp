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
    ll n;
    cin >> n;
    ll step = 1;
    REP(i,1,n+1){
        step = (step * 2) % (1000000007);
    }
    cout << step;
}