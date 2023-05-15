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
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    ll div_factor = 1;
    ll total_pers = 1;
    ll cur = 1;
    ll l = s.length();
    REP(i, 1, l){
        if (s[i] == s[i-1]) {
            cur++;
        } else {
            cur = 1;
        }
        div_factor *= cur;
        total_pers *= i+1;
    }

    cout << total_pers/div_factor << "\n";
    do {
        cout << s << "\n";
    } while(next_permutation(s.begin(), s.end()));
}