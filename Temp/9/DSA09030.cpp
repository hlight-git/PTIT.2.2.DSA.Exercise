#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ONLY_CPP ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

typedef double ld;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> II;

const ld pi=2*acos(0);
const int im = INT_MAX;
const int in = INT_MIN;
const int limit = 1e5+5;
const ll M = 1e9+7;

int n,m;
vi a[1004];
int color[1004];

bool BFS(int u){
    queue <int> q;
    q.push(u);
    color[u] = 1;
    while(q.size()){
        int s = q.front(); q.pop();
        for(auto v : a[s]){
            if(v == s)
                return false;
            if(color[v] == -1){
                color[v] = 1 - color[s];
                q.push(v);
            }
            else if(color[v] == color[s])
                return false;
        }
    }
    return true;
} 

bool check(){
    for(int i = 1 ; i <= n ; i++){
        if(color[i] == -1){
            if(BFS(i) == false)
                return false; 
        }
            
    }
    return true;
}

int main ()
{
    ONLY_CPP
    int T;
    cin>>T;
    while(T--){
        cin>>n>>m;
        for(int i = 1 ; i <= n ; i++){
            a[i].clear();
        }
        memset(color,-1,sizeof(color));
        for(int i = 0,x,y; i < m ; i++){
            cin >> x >> y;
            a[x].push_back(y);
            a[y].push_back(x);
        }
        if(check()) cout << "YES"<<endl;
        else cout <<"NO"<<endl;
    }
    return 0;
}