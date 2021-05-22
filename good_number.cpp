//
//  good_number.cpp
//  BOJ
//
//  Created by 지영본 on 2021/04/29.
//  acmicpc.net/problem/1060

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

struct compare{
    bool operator()(pair<int, int> a, pair<int,int> b){
        return a.second>b.second;
    }
};

int main(){
//    priority_queue<pair<int,int>, vector<pair<int, int>>, compare> pq;
    int L,n;
    
    cin>>L;
    
    vector<int> v, answer;
    v.push_back(0);
    for(int i=0;i<L;i++){
        int num;
        cin>>num;
        v.push_back(num);
    }
    cin>>n;
    
    for(int i=1;i<L+1;i++){                 //집합 S의 원소 정답벡터에 push
        answer.push_back(v[i]);
    }
    for(int i=0;i<L;i++){
        if(v[i+1]-v[i]==2)
            answer.push_back(v[i]+1);       //구간의 갯수가 0인 수 정답벡터에 push
    }
    sort(answer.begin(), answer.end());     //정답벡터 정렬
    
    if(answer.size()>=n){                   //
        for(int i=0;i<n;i++){
            cout<<answer[i]<<" ";
        }
        return 0;
    }
    
    vector<pair<int64_t,int>> p_v;
    
    for(int i=0;i<L;i++){
        int size=v[i+1]-v[i]-1;
        if(size==1)
            continue;
        for(int j=v[i]+1;j<v[i+1];j++){
            int sec_num=(j-v[i]-1)*(v[i+1]-j)+v[i+1]-j-1;
            p_v.push_back(make_pair(sec_num, j));
        }
    }
    sort(p_v.begin(),p_v.end());

    if(n<=v[v.size()-1]){
        int s=(int)answer.size();
        for(int i=0;i<n-s;i++){
            answer.push_back(p_v[i].second);
        }
    }
    
    else{
        for(int i=0;i<p_v.size();i++){
            answer.push_back(p_v[i].second);
        }
        
        n=n-v[v.size()-1];
        
        for(int i=1;i<=n;i++){
            answer.push_back(v[v.size()-1]+i);
        }
    }

    for(int i=0;i<answer.size();i++){
        cout<<answer[i]<<" ";
    }
    
    return 0;
}
