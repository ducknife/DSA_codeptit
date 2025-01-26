#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

vector<int> adj[1005];
bool visited[1005];
int parent[1005], n, m;
void INIT(){
    for (int i = 1; i <= n; i++){
        parent[i] = i; /* ban dau, dai dien la chinh no */
    }
}

int FIND(int u){ /* tim dai dien tap hop*/
    if (parent[u] == u) return u;
    else return parent[u] = FIND(parent[u]); 
}

bool UNION(int u, int v){ /* gop lai thanh tap hop */
    u = FIND(u);
    v = FIND(v); /* tim dai dien cua u, v */
    if (u == v) return false; /* cung tap hop roi, k phai gop nua */
    else if (u < v) parent[v] = u;
    else parent[u] = v;
    return true; /* gop duoc */
}
int main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        cin >> n >> m;
        INIT();
        int cnt = n;
        for (int i = 1; i <= m; i++){
            int x, y; cin >> x >> y;
            if (UNION(x, y)){
                cnt--; /* neu gop duoc thi giam 1 tplt */
            }
        }
        cout << cnt << endl;
    }
    return 0;
}