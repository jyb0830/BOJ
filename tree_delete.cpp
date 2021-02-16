//
//  tree_traversal.cpp
//  BOJ
//
//  Created by 지영본 on 2021/02/13.
//  acmicpc.net/problem/1068

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> v;
queue<int> q;
int parent[50];
int leaf_node=0;
void delete_node(int node){
    q.push(node);
    
    for(int i=0;i<v[parent[node]].size();i++){
        if(v[parent[node]][i]==node) {
            v[parent[node]].erase(v[parent[node]].begin()+i);
            break;
        }
    }
    while(!q.empty()){
        int temp = q.front();
        q.pop();
        
        for(int i=0;i<v[temp].size();i++){
            q.push(v[temp][i]);
        }
        v[temp].clear();
    }
}

void count_leaf(int root){
    q.push(root);
    
    while(!q.empty()){
        int temp=q.front();
        q.pop();
        
        if(v[temp].size()==0){
            leaf_node++;
            continue;
        }
        else{
            for(int i=0;i<v[temp].size();i++){
                q.push(v[temp][i]);
            }
        }
    }
}

int main(){
    int n, root=0, node;
    cin>>n;
    
    for(int i=0;i<n;i++) v.push_back(vector<int>());
    
    for(int i=0;i<n;i++){
        cin>>parent[i];
        if(parent[i]==-1) root=i;
        else v[parent[i]].push_back(i);
    }
    cin>>node;
    if(node==root) cout<<0<<"\n";
    else{
    delete_node(node);
    count_leaf(root);
    cout<<leaf_node<<"\n";
    }
    
    return 0;
}
