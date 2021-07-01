/*Cre: HlighT*/
#include <bits/stdc++.h>
#define IOS() ios::sync_with_stdio(false);
#define tie() cin.tie(NULL); cout.tie(NULL);
/*Compact*/
#define pb push_back
#define pob pop_back
#define mp make_pair
#define fi first
#define se second
#define all(Object) Object.begin(), Object.end()
#define Fu(tmp,L,R,Jump)	for(int tmp=L; tmp<R; tmp+=Jump)
#define Fd(tmp,R,L,Jump)	for(int tmp=R; tmp>=L; tmp-=Jump)
#define cinArr(Array, N)	for(int i=0; i<N; ++i)  cin >> Array[i];
#define coutArr(Array, N)	for(int i=0; i<N; ++i)	cout << Array[i] << ' ';
#define Re0(Object) memset(Object, 0, sizeof(Object))
/*Constant*/
#define Pi atan(1)*4
#define lim 100005
#define im INT_MAX
#define in INT_MIN
const int Mod = 1e9+7;
/*Declare*/
using namespace std;
typedef long long ll;
typedef double db;

/*Initialize*/
int test;
int V, E, u, goal;
int U[1005];
class Graph{
    public:
        map < int, vector <int> > a;
        stack <int> S;
        void addEdge(int x, int y);
        void DFS(int v);
};
/*Function*/
void init(){
    cin >> V >> E >> u >> goal;
    Re0(U);
}
void Graph::addEdge(int x, int y){
    a[x].pb(y);
    a[y].pb(x);
}
void Graph::DFS(int v){
    S.push(v);
    U[v] = -1;
    while(!S.empty()){
        int x = S.top();
        S.pop();
        Fu(i, 0, a[x].size(), 1)
            if(!U[a[x][i]]){
                U[a[x][i]] = x;
                S.push(x);
                S.push(a[x][i]);
                break;
            }
    }
}
void solve(){
    int x, y;
    Graph g;
    Fu(i, 0, E, 1){
        cin >> x >> y;
        g.addEdge(x, y);
    }
    g.DFS(u);
    if(U[goal]){
        vector <int> res;
        int tmp = goal;
        while(U[tmp] > 0){
            res.pb(tmp);
            tmp = U[tmp];
        }
        res.pb(u);
        Fd(i, res.size()-1, 0, 1)
            cout << res[i] << ' ';
    }
    else cout << -1;
}
/*Main program*/
int main(){
    IOS()
    cin >> test;
    while(test--){
        init();
        solve();
        cout << endl;
    }
    return 0;
}

/*Source: From HlighT*/