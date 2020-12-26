//
//  Line.cpp
//  BOJ
//
//  Created by 지영본 on 2020/12/26.
//  acmicpc.net/problem/2252

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
    int N,M,A,B;
    queue<int> q;
    vector<vector<int>> v;
    
    cin>>N>>M;
    int in[N+1];
    for(int i=0;i<N+1;i++) in[i]=0;
    
    for(int i=0;i<N+1;i++) v.push_back(vector<int>());
    
    for(int i=0;i<M;i++){
        cin>>A>>B;
        v[A].push_back(B);
        in[B]++;
    }
    for(int i=1;i<N+1;i++){
        if(in[i]==0)
            q.push(i);
    }
    
    while(!q.empty()){
        int temp=q.front();
        cout<<temp<<" ";
        q.pop();
        for(int i=0;i<v[temp].size();i++){
            if(--in[v[temp][i]]==0)
                q.push(v[temp][i]);
        }
    }
    
    return 0;
}
