#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

vector<int> adj[1005];
bool visited[1005];

void dfs(int u){
    visited[u] = true;
    for (int v : adj[u]){
        if (!visited[v]) dfs(v);
    }
}
int main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        memset(visited, false, sizeof(visited));
        for (auto &i : adj) i.clear();
        int n, m; cin >> n >> m;
        for (int i = 1; i <= m; i++){
            int x, y; cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        int cnt_bf = 0;
        for (int i = 1; i <= n; i++){
            if (!visited[i]){
                cnt_bf++;
                dfs(i);
            }
        }
        for (int i = 1; i <= n; i++){
            memset(visited, false, sizeof(visited));
            visited[i] = 1;
            int cnt_af = 0;
            for (int j = 1; j <= n; j++){
                if (!visited[j]){
                    cnt_af++;
                    dfs(j);
                }
            }
            if (cnt_af > cnt_bf) cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}