//
//  dfs_and_bfs.cpp
//  BOJ
//
//  Created by 지영본 on 2021/01/03.
//  acmicpc.net/problem/1260

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> v;
int visited[1001];
queue<int> q;
void dfs(int V){
    cout<<V<<" ";
    visited[V]=1;
    for(int i=0;i<v[V].size();i++){
        if(!visited[v[V][i]])
            dfs(v[V][i]);
    }
}

void bfs(int V){
    visited[V]=1;
    q.push(V);
    
    while(!q.empty()){
        V=q.front();
        q.pop();
        cout<<V<<" ";
        
        for(int i=0;i<v[V].size();i++){
            if(!visited[v[V][i]]){
                q.push(v[V][i]);
                visited[v[V][i]]=1;
            }
        }
    }
}


int main(){
    int N, M, V, dot1, dot2;

    cin>>N>>M>>V;
    
    for(int i=0;i<N+1;i++) v.push_back(vector<int>());
    
    for(int i=0;i<M;i++){
        cin>>dot1>>dot2;
        v[dot1].push_back(dot2);
        v[dot2].push_back(dot1);
    }
    for(int i=1;i<N+1;i++)
    sort(v[i].begin(),v[i].end());
    
    dfs(V);
    cout<<"\n";
    
    for(int i=1;i<=N;i++)
    visited[i]=0;
    
    bfs(V);
    
    return 0;
}
