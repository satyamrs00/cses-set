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
    vl ar;
    vl lv;
    REP(i,0,n){
        ll a, b;
        cin >> a >> b;
        ar.PB(a);
        lv.PB(b);
    }
    sort(ar.begin(), ar.end());
    sort(lv.begin(), lv.end());
    ll cur = 0;
    ll maxc = 0;
    ll arp = 0, lvp = 0;
    while(arp < ar.size() && lvp < lv.size()){
        if(ar[arp] < lv[lvp]){
            maxc = max(maxc, cur+1);
            cur++;
            arp++;
        } else if (ar[arp] > lv[lvp]){
            cur--;
            lvp++;
        } else {
            arp++; lvp++;
        }
    }
    cout << maxc;
}

// - first approach 
// arrivals array, leavings array. leap over simultaneously if someone arrives +1, if someone leaves -1, maintain max value
// ac