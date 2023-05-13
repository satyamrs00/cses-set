#include "iostream"
#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef vector<ll> vl;

#define PB push_back

int main() {
    ll n;
    cin >> n;
    vl v;
    for(ll i = 0; i < n-1; i++) {
        ll tmp;
        cin >> tmp;
        v.PB(tmp);
    }
    v.PB(0);
    v.PB(n+1);
    sort(v.begin(), v.end());
    for(int i = 1; i < n+1; i++){
        if (v[i]-v[i-1] != 1){
            cout << v[i]-1<< "\n";
            break;
        }
    }
}