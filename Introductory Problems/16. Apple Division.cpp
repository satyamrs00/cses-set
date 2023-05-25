#include "iostream"
#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef set<ll> sl;
typedef map<string, ll> msl;
typedef map<ll, ll> mll;
typedef unordered_map<ll, ll> umll;
typedef pair<string, ll> psl;
typedef pair<ll, ll> pll;

#define fastio() ios_base::sync_with_stdio(0);cin.tie(NULL)
#define PB push_back
#define F first 
#define S second
#define I iterator
#define REP(i,a,b) for (ll i = a; i < b; i++)
#define REPR(i,a,b) for (ll i = a; i > b; i--)
#define REPJ(i,a,b,j) for (ll i = a; i < b; i+=j)
#define REPIT(it,o) for (auto it = o.begin(); it != o.end(); it++)
#define REPITR(it,o) for (auto it = o.rbegin(); it != o.rend(); it++)
#define ALL(a) a.begin(),a.end()
#define ALLR(a) a.rbegin(),a.rend()

int main() {
    ll n;
    cin >> n;
    vl s;
    s.PB(0);
    ll sum = 0;
    REP(i,0,n){
        ll tmp;
        cin >> tmp;
        ll l = s.size();
        REP(j,0,l){
            s.PB(s[j]+tmp);
        }
        sum += tmp;
    }

    ll cur = 0;
    REPIT(it,s){
        if (*it == sum/2) {
            cur = *it;
            break;
        }
        if (abs(sum/2-cur) > abs(sum/2-*it)) cur = *it;
    }
    cout << abs(sum-cur-cur);
}
