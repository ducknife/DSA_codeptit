#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

vector<int> adj[1005];
bool visited[1005];

int main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        string s; getline(cin >> ws, s);
        stringstream ss(s);
        stack<string> st;
        string word;
        while (ss >> word){
            st.push(word);
        }
        while (!st.empty()){
            cout << st.top() << " ";
            st.pop();
        }
        cout << endl;
    }
    return 0;
}