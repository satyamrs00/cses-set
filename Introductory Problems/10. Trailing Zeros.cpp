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
    ll zeros = 0;
    REPJ(i,5,n+1,5){
        ll x = i;
        while(x%5 == 0){
            x /= 5;
            zeros++;
        }
    }
    cout << zeros;
}