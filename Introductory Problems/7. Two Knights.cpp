#include "iostream"
#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef vector<ll> vl;

#define PB push_back
#define REP(i,a,b) for (ll i = a; i < b; i++)
#define REPJ(i,a,b,j) for (ll i = a; i < b; i+=j)

int main() {
    ll n;
    cin >> n;
    ll base = 0;
    REP(i,1,n+1){
        ll ans;
        if (i > 3) {
            ans = base + 3*(i*i - 2 - 1) + 4*(i*i - 3 -1) + (2*i-1-7)*(i*i-4-1) - 2*(2*i-1-2) - 1*(i-1) - (i-3)*(2*i-1-1); // 3 for corner boxes, 4 for boxes that are adjacent to corner, (2*i-1-7) for the rest
            // during exclusion, 2 for two boxes form the common one, 1 for the common one, (i-3) for the rest
        } else if (i ==3){
            ans = base + 5*(i*i - 2 - 1) - 2*(2*i-1-2) - 1*(2*i-1-1)/2;
        } else if (i==2){
            ans = base + 3*(i*i - 1) - 3;
        } else {
            ans = base;
        }
        cout << ans << "\n";
        base = ans;
    }
}