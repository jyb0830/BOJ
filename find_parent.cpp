//
//  find_parent.cpp
//  BOJ
//
//  Created by 지영본 on 2021/02/14.
//  acmicpc.net/problem/11725

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> v;
bool visited[100001];
queue<int> q;
int parent[100001];

void find_parent(){
    visited[1]=true;
    q.push(1);
    
    while(!q.empty()){
        int temp = q.front();
        q.pop();
        
        for(int i=0;i<v[temp].size();i++){
            if(visited[v[temp][i]]) continue;
            
            else{
                parent[v[temp][i]]=temp;
                visited[v[temp][i]]=true;
                q.push(v[temp][i]);
            }
        }
    }
}

int main(){
    int n,node1,node2;
    
    cin>>n;
    for(int i=0;i<n+1;i++) v.push_back(vector<int>());
    
    for(int i=0;i<n-1;i++){
        cin>>node1>>node2;
        v[node1].push_back(node2);
        v[node2].push_back(node1);
    }
    
    find_parent();
    
    for(int i=2;i<n+1;i++) cout<<parent[i]<<"\n";
    
}
