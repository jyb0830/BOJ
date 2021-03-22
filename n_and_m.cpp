//
//  n_and_m.cpp
//  BOJ
//
//  Created by 지영본 on 2021/03/22.
//  acmicpc.net/problem/15649

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int n, m;
stack<int> s;
vector<int> v;

void back_tracking(int idx, int cnt, int path){
    if(cnt==m) {
        for(int i=0;i<v.size();i++){
            cout<<v[i]<<" ";
        }
        cout<<"\n";
        v.pop_back();
        return;
    }
    
    for(int i=1;i<=n;i++){
        if((1<<i&path)==0){
            v.push_back(i);
            back_tracking(i, cnt+1, path|1<<i);
        }
    }
    v.pop_back();
}

int main(){
    cin>>n>>m;
    
    for(int i=1;i<=n;i++){
        v.clear();
        v.push_back(i);
        back_tracking(i, 1, 1<<i);
    }
    
    return 0;
}
