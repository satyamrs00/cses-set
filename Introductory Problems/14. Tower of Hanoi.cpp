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

void rec(ll n, string primary, string secondary, string intermediate){
    if (n == 1){
        cout << primary << " " << secondary << "\n";
        return;
    }
    rec(n-1, primary, intermediate, secondary);
    cout << primary << " " << secondary << "\n";
    rec(n-1, intermediate, secondary, primary);
}

int main() {
    ll n;
    cin >> n;
    cout << pow(2,n)-1 << "\n";
    rec(n,"1", "3", "2");
}