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
#define REP(i,a,b) for (ll i = a; i < b; i++)
#define REPR(i,a,b) for (ll i = a; i > b; i--)
#define REPJ(i,a,b,j) for (ll i = a; i < b; i+=j)
#define REPIT(it,o) for (auto it = o.begin(); it != o.end(); it++)
#define REPITR(it,o) for (auto it = o.rbegin(); it != o.rend(); it++)

int main() {
    ll n;
    cin >> n;
    vl a;
    REP(i,0,n){
        ll tmp;
        cin >> tmp;
        a.PB(tmp);
    }
    ll ans = LLONG_MIN;
    ll prev_sum = 0;
    REP(i,0,n){
        if (prev_sum+a[i] > a[i]){
            prev_sum = prev_sum+a[i];
        } else {
            prev_sum = a[i];
        }
        ans= max(ans, prev_sum);
    }
    cout << ans;
}

// - initial approach
// iterate over the vector and upto each element max subarray sum = itself or prev max subarray + itself
// ac