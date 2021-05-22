//
//  card_sort.cpp
//  BOJ
//
//  Created by 지영본 on 2021/05/22.
//  acmicpc.net/problem/1715

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(){
    int N;
    cin>>N;
    int cost=0;
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for(int i=0;i<N;i++){
        int num;
        cin>>num;
        pq.push(num);
    }
    
    if(pq.size()==1){
        cout<<0<<"\n";
        return 0;
    }
    
    while(pq.size()>1){
        int a,b;
        a=pq.top();
        pq.pop();
        b=pq.top();
        pq.pop();
        cost+=a+b;
        pq.push(a+b);
    }
    
    cout<<cost<<"\n";
    
    return 0;
}
