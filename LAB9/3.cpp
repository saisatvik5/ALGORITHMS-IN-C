#include <bits/stdc++.h> 
using namespace std; 
#define N 100000 
  
vector<int> gr1[N], gr2[N]; 
  
bool vis1[N], vis2[N], i; 
  
void Add_edge(int u, int v) 
{ 
    gr1[u].push_back(v); 
    gr2[v].push_back(u); 
} 
  
void dfs1(int x) 
{ 
    vis1[x] = true; 
  
    for (auto i : gr1[x]) 
        if (!vis1[i]) 
            dfs1(i); 
} 
  
void dfs2(int x) 
{ 
    vis2[x] = true; 
  
    for (auto i : gr2[x]) 
        if (!vis2[i]) 
            dfs2(i); 
} 
  
bool Is_Connected(int n) 
{ 
    memset(vis1, false, sizeof vis1); 
    dfs1(1); 
  
    memset(vis2, false, sizeof vis2); 
    dfs2(1); 
  
    for (int i = 1; i <= n; i++) { 
  

        if (!vis1[i] and !vis2[i]) 
            return false; 
    } 
  
    return true; 
} 
  
int main() 
{ 
    int n = 4; 
  
    Add_edge(1, 2); 
    Add_edge(1, 3); 
    Add_edge(2, 3); 
    Add_edge(3, 4); 
  
    if (Is_Connected(n)) 
        cout << "Yes"; 
    else
        cout << "No"; 
  
    return 0; 
}
