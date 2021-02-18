//
//  connected_component.cpp
//  BOJ
//
//  Created by 지영본 on 2021/02/18.
//  acmicpc.net/problem/11724

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

queue<int> q;
vector<vector<int>> v;

bool visited[1001];
int connected=0;

void bfs(int n){
    for(int i=1;i<n+1;i++){
        if(visited[i]) continue;
        else{
            connected++;
            q.push(i);
            
            while(!q.empty()){
                int temp=q.front();
                q.pop();
                if(visited[temp]) continue;
                visited[temp]=true;
                
                for(int j=0;j<v[temp].size();j++){
                    if(!visited[v[temp][j]]) q.push(v[temp][j]);
                }
            }
        }
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    
    for(int i=0;i<n+1;i++) v.push_back(vector<int>());
    
    for(int i=0;i<m;i++){
        int idx1, idx2;
        cin>>idx1>>idx2;
        v[idx1].push_back(idx2);
        v[idx2].push_back(idx1);
    }
    
    bfs(n);
    
    cout<<connected<<"\n";
    return 0;
}
