#include "iostream"
#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef vector<ll> vl;
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
    string s;
    cin >> s;
    mcl m;
    for (char c : s){
        if (m[c] == NULL) {
            m[c] = 1;
        } else {
            m[c]++;
        }
    }
    pcl odd_pair;
    string ams = "";
    REPIT(it, m){
        if (it->S % 2 == 0) {
            REP(i,0,it->S/2){
                ams += it->F;
            }
        } else {
            if (odd_pair.F == NULL) {
                odd_pair = *it;
            } else {
                cout << "NO SOLUTION\n";
                return 0;
            }
        }
    }
    REP(i,0,odd_pair.S){
        ams += odd_pair.F;
    }
    REPITR(it, m){
        if (it->S % 2 == 0) {
            REP(i,0,it->S/2){
                ams += it->F;
            }
        }
    }
    cout << ams;
}