#include "iostream"
#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef vector<ll> vl;

#define PB push_back
#define REP(i,a,b) for (int i = a; i < b; i++)

int main() {
    string s;
    cin >> s;
    ll cur = 1;
    ll maxm = 0;
    ll l = s.length();
    REP(i,1,l){
        if (s[i] == s[i-1]){
            cur++;
        } else {
            maxm = max(maxm, cur);
            cur = 1;
        }
    }
    maxm = max(maxm, cur);
    cout << maxm;
}