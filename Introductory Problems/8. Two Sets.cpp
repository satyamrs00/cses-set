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

    sl s1, s2;
    ll s1sum = 0, s2sum = 0;
    REPR(i, n, 0){
        if (s1sum > s2sum){
            s2.insert(i);
            s2sum += i;
        } else {
            s1.insert(i);
            s1sum += i;
        }
    }
    if (s1sum != s2sum) {
        cout << "NO" << "\n";
        return 0;
    }
    cout << "YES" << "\n";
    cout << s1.size() << "\n";
    for(auto it = s1.begin(); it != s1.end(); it++){
        cout << *it << " ";
    }
    cout << "\n" << s2.size() << "\n";
    for(auto it = s2.begin(); it != s2.end(); it++){
        cout << *it << " ";
    }
}