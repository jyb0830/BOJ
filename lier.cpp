//
//  lier.cpp
//  BOJ
//
//  Created by 지영본 on 2021/02/26.
//  acmicpc.net/problem/1043

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, t_n, ans=0;
vector<vector<int>> v;
vector<int> truth;

void bfs(){
    queue<int> q;
    for(int i=0;i<truth.size();i++) q.push(truth[i]);
    
    while(!q.empty()){
        int temp=q.front();
        q.pop();
        
        for(int i=0;i<m;i++){
            int check=false;
            for(int j=0;j<v[i].size();j++){
                if(check){
                    q.push(v[i][j]);
                }
                
                if(v[i][j]==temp){
                    v[i].erase(v[i].begin()+j);
                    check=true;
                    j = -1;
                }
            }
            if(check) v[i].clear();
        }
    }
}


int main(){
    cin>>n>>m;
    cin>>t_n;
    int num;
    for(int i=0;i<t_n;i++){
        cin>>num;
        truth.push_back(num);
    }
    for(int i=0;i<m;i++){
        cin>>num;
        v.push_back(vector<int>());
        for(int j=0;j<num;j++){
            int temp;
            cin>>temp;
            v[i].push_back(temp);
        }
    }
    
    if(truth.size()==0){
        for(int i=0;i<m;i++){
            if(v[i].size()!=0)
                ans++;
        }
        cout<<ans<<"\n";
        return 0;
    }
    bfs();
    
    for(int i=0;i<m;i++){
        if(v[i].size()>0) {
            ans++;
        }
    }
    
    cout<<ans<<"\n";
    
    return 0;
}
