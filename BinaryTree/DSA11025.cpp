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
#define oo INT_MAX
const int Mod = 1e9+7;
/*Declare*/
using namespace std;
typedef long long ll;
typedef double db;

/*Initialize*/
int test, n;
struct Node{
    int value;
    Node* left;
    Node* right;
    Node(int v){
        value = v;
        left = right = NULL;
    }
};
Node* createBST(int* a, int start, int end){
    if(start > end) return NULL;
    int mid = (start + end)/2;
    Node* tmp = new Node(a[mid]);
    tmp->left = createBST(a, start, mid - 1);
    tmp->right = createBST(a, mid + 1, end);
    return tmp;
}
void preorder(Node* root){
    if(root == NULL)    return;
    cout << root->value << ' ';
    preorder(root->left);
    preorder(root->right);
}
/*Function*/
void init(){
    cin >> n;
}
void solve(){
    int a[n];
    cinArr(a, n);
    sort(a, a+n);
    Node* tmp = createBST(a, 0, n-1);
    preorder(tmp);
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