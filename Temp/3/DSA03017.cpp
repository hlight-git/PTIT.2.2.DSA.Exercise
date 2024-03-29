#include<bits/stdc++.h>
using namespace std;
#define setIO() ios::sync_with_stdio(false); cin.tie(0);
#define all(a) a.begin(),a.end()
#define fill(x,b) memset((x),b,sizeof((x)))
#define fill2D(x,r,c,b) memset((x),b, sizeof(x[0][0]) * r * c)
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<ii> vpii;
int test = 1 , MULTI_TEST = 1; 
int k;
string s;
void Input(){
    cin >> k >> s;
}   
void Solve(){
    int cnt[26] = {0};
    for(int i = 0 ; i < s.length() ; i++) cnt[s[i]-'A']++;
    priority_queue <int,vi> q;
    for(int i = 0; i < 26; i++){
        if(cnt[i] != 0) q.push(cnt[i]);
    }
    while(k--){
        int x = q.top(); q.pop();
        q.push(x-1);
    }
    ll res = 0;
    while(!q.empty()){
        int x = q.top(); q.pop();
        res += 1LL*x*x;
    }
    cout << res << '\n';
}
int main(){
    setIO();
    if(MULTI_TEST == 1) cin >> test;
    for(int i = 1 ; i <= test ; i++){Input(); Solve();}
    return 0;
}