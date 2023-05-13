#include "iostream"
#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef vector<ll> vl;

#define PB push_back
#define REP(i,a,b) for (ll i = a; i < b; i++)
#define REPJ(i,a,b,j) for (ll i = a; i < b; i+=j)

int main() {
    ll t;
    cin >> t;
    while(t--){
        ll y, x;
        cin >> y >> x;
        ll baseEdge = max(y,x)-1;
        ll ans = (max(y,x)-1) * (max(y,x)-1);
        if (baseEdge % 2 == 0){
            if (y < x){
                ans += x + (x-y);
            } else {
                ans += x;
            }
        } else {
            if (y > x){
                ans += y + (y-x);
            } else {
                ans += y;
            }
        }
        cout << ans << endl;
    }
}