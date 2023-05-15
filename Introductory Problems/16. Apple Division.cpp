#include "iostream"
#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef set<ll> sl;
typedef map<char, ll> mcl;
typedef pair<char, ll> pcl;

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
    vl p;
    REP(i,0,n){
        ll tmp;
        cin >> tmp;
        p.PB(tmp);
    }
    ll diff = 0;
    sort(p.begin(), p.end());
    REP(i,0,n){
        ll val = 0;
        ll min_d = 1000000000;
        REP(j,0,n-i){
            if (diff > 0){
                if (abs(diff-p[j]) < min_d) {
                    min_d = abs(diff-p[j]);
                    val = p[j];
                }
            } else {
                if (abs(diff+p[j]) < min_d) {
                    min_d = abs(diff+p[j]);
                    val = p[j];
                }
            }
        }
        diff = min_d;
        p.erase(p.begin() + binary_search(p.begin(), p.end(), val));
    }
    cout << abs(diff);
}

// TODO - its wrong rn