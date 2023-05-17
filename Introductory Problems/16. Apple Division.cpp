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
    ll n = 10;
    // cin >> n;
    vl p {238, 224, 861, 461, 558, 860, 318, 93, 347, 402};
    // REP(i,0,n){
    //     ll tmp;
    //     cin >> tmp;
    //     p.PB(tmp);
    // }
    ll diff = 0;
    sort(p.rbegin(), p.rend());
    REP(i,0,n){
        ll index_to_remove = -1;
        ll tmp_diff = 1000000000;
        REP(j,0,n-i){
            if (diff < 0){
                if( abs(diff+p[j]) < tmp_diff){
                    tmp_diff = diff+p[j];
                    index_to_remove = j;
                }
            } else {
                if( abs(diff-p[j]) < tmp_diff){
                    tmp_diff = diff-p[j];
                    index_to_remove = j;
                }
            }
        }
        diff = tmp_diff;
        vl::iterator it;
        it = p.begin();
        REP(x,0,index_to_remove){
            it++;
        }
        p.erase(it);
    }
    cout << abs(diff);
}

// TODO - its wrong rn 