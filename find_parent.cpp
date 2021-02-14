//
//  find_parent.cpp
//  BOJ
//
//  Created by 지영본 on 2021/02/14.
//  acmicpc.net/problem/11725

#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, cnt=0;
    vector<vector<int>> v;
    
    cin>>n;
    int node1[n],node2[n];
    for(int i=0;i<n+1;i++) {
        v.push_back(vector<int>());
        v[i].assign(1,0);
    }
    
    for(int i=0;i<n-1;i++){
        cin>>node1[i]>>node2[i];
        if(node1[i]==1){
            v[1].push_back(node2[i]);
            v[node2[i]][0]=1;
            cnt++;
            node1[i]=node2[i]=0;
            continue;
        }
        else if(node2[i]==1){
            v[1].push_back(node1[i]);
            v[node1[i]][0]=1;
            cnt++;
            node1[i]=node2[i]=0;
            continue;
        }
    }
    while(cnt!=n-1){
        for(int i=0;i<n-1;i++){
            if(node1[i]==0 && node2[i]==0) continue;
            if(v[node1[i]][0]==0 && v[node2[i]][0]==0) continue;
            else{
                if(v[node1[i]][0]==0){
                    v[node2[i]].push_back(node1[i]);
                    v[node1[i]][0]=node2[i];
                    cnt++;
                }
                else if(v[node2[i]][0]==0){
                    v[node1[i]].push_back(node2[i]);
                    v[node2[i]][0]=node1[i];
                    cnt++;
                }
            }
        }
    }
    
    for(int i=2;i<=n;i++){
        cout<<v[i][0]<<"\n";
    }
    
    return 0;
}
