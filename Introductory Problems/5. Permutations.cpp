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
    if (n == 1) {
        cout << 1;
        return 0;
    }
    if (n < 4) {
        cout << "NO SOLUTION";
        return 0;
    }
    REPJ(i,2,n+1,2){
        cout << i << " ";
    }
    REPJ(i,1,n+1,2){
        cout << i << " ";
    }
}