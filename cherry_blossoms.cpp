//
//  cherry_blossoms.cpp
//  BOJ
//
//  Created by 지영본 on 2021/02/02.
//  acmicpc.net/problem/17127

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int arr[10],sum[4];
int N;
queue<int> q;
vector<vector<int>> v;
int ans(int idx){
    //cout<<"idx : "<<idx<<"\n";
    
    int temp[4];
    v.clear();
    for(int i=0;i<4;i++) {
        v.push_back(vector<int>());
        temp[i]=1;
    }
    
    for(int i=0;i<N;i++) q.push(arr[i]);
    
    for(int i=0;i<4;i++){
        if(i==idx){
            for(int j=0;j<N-3;j++){
                v[i].push_back(q.front());
                q.pop();
            }
        }
        else{
            v[i].push_back(q.front());
            q.pop();
        }
    }
    for(int i=0;i<4;i++){
        for(int j=0;j<v[i].size();j++){
            //cout<<"v["<<i<<"]["<<j<<"] : "<<v[i][j]<<"\n";
            temp[i]*=v[i][j];
        }
        sum[idx]+=temp[i];
    }
    return sum[idx];
}

int main(){
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>arr[i];
        q.push(arr[i]);
    }
    int max_sum=0;
    for(int i=0;i<4;i++){
        max_sum=max(max_sum,ans(i));
    }
    cout<<max_sum<<"\n";
    return 0;
}
