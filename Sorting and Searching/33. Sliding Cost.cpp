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
    fastio();
    ll n,k; cin >> n >> k;
    vl v (n,0);
    multiset<ll> s;
    REP(i,0,k){
        ll t = v[i];
        cin >> t;
        v[i] = t;
        s.insert(t);
    }
    sl::I it;
    it = s.begin();
    advance(it,(k-1)/2);
    cout << *it << ' ';

    REP(i,k,n){
        ll t = v[i];
        cin >> t;
        v[i] = t;
        s.insert(t);
        if (s.size()%2 == 0 && t < *it){
            it--;
        }
        if (s.size()%2 != 0 && t >= *it){
            it++;
        }
        if (s.size()%2 == 0){
            if (v[i-k] == *it){
                it = s.erase(it);
            } else if (v[i-k] < *it){
                it++; s.erase(s.find(v[i-k]));
            } else {
                s.erase(s.find(v[i-k]));
            }
        } else {
            if (v[i-k] == *it){
                it = s.erase(it); it--;
            } else if (v[i-k] > *it){
                it--; s.erase(s.find(v[i-k]));
            } else {
                s.erase(s.find(v[i-k]));
            }
        }
        
        // REPIT(x,s){
        //     cout << *x << ' ';
        // } cout << endl;

        cout << *it << ' ';
    }
}

// - initial approach