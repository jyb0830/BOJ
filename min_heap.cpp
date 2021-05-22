//
//  min_heap.cpp
//  BOJ
//
//  Created by 지영본 on 2021/05/22.
//  acmicpc.net/problem/1927

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(){
    int N;
    priority_queue<int, vector<int>, greater<int>> pq;
    cin>>N;
    vector<int> answer;
    for(int i=0;i<N;i++){
        int num;
        cin>>num;
        if(num==0){
            if(pq.empty()){
                answer.push_back(0);
            }
            else{
                answer.push_back(pq.top());
                pq.pop();
            }
        }
        else{
            pq.push(num);
        }
    }
    
    for(int i=0;i<answer.size();i++){
        cout<<answer[i]<<"\n";
    }
    
    return 0;
}
