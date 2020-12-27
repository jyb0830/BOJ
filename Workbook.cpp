//
//  Workbook.cpp
//  BOJ
//
//  Created by 지영본 on 2020/12/27
//  acmicpc.net/problem/1766

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(){
    priority_queue<int,vector<int>,greater<int>> pq;
    vector<vector<int>> v;
        
    int N, M, A, B;
    cin>>N>>M;
    int in[N+1];
    for(int i=0;i<N+1;i++) v.push_back(vector<int>());
    for(int i=0;i<N+1;i++) in[i]=0;
    
    for(int i=0;i<M;i++){
        cin>>A>>B;
        v[A].push_back(B);
        in[B]++;
    }
    
    for(int i=1;i<N+1;i++){
        if(in[i]==0)
            pq.push(i);
    }
    
    while(!pq.empty()){
        int temp = pq.top();
        cout<<temp<<" ";
        pq.pop();
        for(int i=0;i<v[temp].size();i++){
            if(--in[v[temp][i]]==0)
                pq.push(v[temp][i]);
        }
    }
    return 0;
}
