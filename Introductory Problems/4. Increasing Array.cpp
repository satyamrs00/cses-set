#include "iostream"
#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef vector<ll> vl;

#define PB push_back
#define REP(i,a,b) for (int i = a; i < b; i++)

int main() {
    ll n;
    cin >> n;
    vl v;
    ll ans = 0;
    ll prevBump = 0;
    REP(i,0,n){
        ll tmp;
        cin >> tmp;
        v.PB(tmp);
        if (i == 0) continue;
        if(tmp < v[i-1] + prevBump){
            prevBump = v[i-1] +prevBump-tmp;
            ans += prevBump;
        } else {
            prevBump = 0;
        }
    }
    cout << ans;
}