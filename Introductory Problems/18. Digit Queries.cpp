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

#define PB push_back
#define F first 
#define S second
#define REP(i,a,b) for (ll i = a; i < b; i++)
#define REPR(i,a,b) for (ll i = a; i > b; i--)
#define REPJ(i,a,b,j) for (ll i = a; i < b; i+=j)
#define REPIT(it,o) for (auto it = o.begin(); it != o.end(); it++)
#define REPITR(it,o) for (auto it = o.rbegin(); it != o.rend(); it++)

int main() {
    ll q;
    cin >> q;
    while(q--){
        ull k;
        cin >> k;
        ull working_no = 0;
        ull working_digit = 0;
        map<ull,ull> length_upto;
        for(ull i = 9; i < ULLONG_MAX; i = i*10 + 9){
            if (i == 9){
                length_upto[i] = 9;
            } else {
                ull a = length_upto[i/10] + (i - pow(10, to_string(i).length()-1) + 1) * to_string(i).length();
                length_upto[i] = length_upto[i/10] + (i - pow(10, to_string(i).length()-1) + 1) * to_string(i).length();
            }
            if (k <= length_upto[i]){
                working_no = i;
                working_digit = to_string(i).length();
                break;
            }
        }
        ull actual_no_there = (working_no/10) + ceil((k - length_upto[working_no/10]) / (float) working_digit);
        // cout << "actual_no_there: " << actual_no_there << endl;
        ull dig_of_the_no = ((k - length_upto[working_no/10] -1) % working_digit);
        // cout << "dig_of_the_no: " << dig_of_the_no << endl;
        ull ans = (ull)(actual_no_there / pow(10, working_digit - dig_of_the_no-1) ) % 10;
        cout << ans << "\n";
    }
}

// TODO - WA at high values of k