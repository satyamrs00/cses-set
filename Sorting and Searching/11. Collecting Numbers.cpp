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
#define I iterator
#define REP(i,a,b) for (ll i = a; i < b; i++)
#define REPR(i,a,b) for (ll i = a; i > b; i--)
#define REPJ(i,a,b,j) for (ll i = a; i < b; i+=j)
#define REPIT(it,o) for (auto it = o.begin(); it != o.end(); it++)
#define REPITR(it,o) for (auto it = o.rbegin(); it != o.rend(); it++)

int main() {
    ll n;
    cin >> n;
    sl a;
    ll ans = 1;
    REP(i,0,n){
        ll tmp;
        cin >> tmp;
        if (a.count(tmp+1)){
            ans++;
        }
        a.insert(tmp);
    }
    cout << ans;
}

// - initial approach
// maintain a var last i.e. last counted no. loop over repeatedly over the array until last == 1
// tle
// - second approach
// loop over the array, for x, if x+1 is before the ele, increase the rounds
// ac