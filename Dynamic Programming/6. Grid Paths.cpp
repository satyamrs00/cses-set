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
#define MP make_pair
#define LB lower_bound
#define UB upper_bound
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
    ll n; cin >> n;
    vector<vl> g (n, vl(n,0));
    REP(i,0,n){
        string s; cin >> s;
        REP(j,0,n){
            if (s[j] == '*') {continue;}
            if (i == 0 && j == 0){ g[i][j] = 1; continue; }
            if (i-1 >= 0){ g[i][j] = (g[i][j] + g[i-1][j]) % 1000000007; }
            if (j-1 >= 0){ g[i][j] = (g[i][j] + g[i][j-1]) % 1000000007; }
        }
    }
    cout << g[n-1][n-1];
}

// - initial approach
// dp - steps upto a pos = steps upto a pos above + steps upto a pos left
// ac