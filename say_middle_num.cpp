//
//  say_middle_num.cpp
//  BOJ
//
//  Created by 지영본 on 2021/05/22.
//  acmicpc.net/problem/1655

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(){
    int N;
    cin>>N;
    vector<int> answer;
    priority_queue<int> max_q;
    priority_queue<int, vector<int>, greater<int>> min_q;
    
    for(int i=0;i<N;i++){
        int num;
        cin>>num;
        if(min_q.size()==max_q.size()){
            max_q.push(num);
        }
        else{
            min_q.push(num);
        }
        if(i==0){
            answer.push_back(num);
            continue;
        }
        
        if(max_q.top()>min_q.top()){
            int temp=min_q.top();
            min_q.pop();
            min_q.push(max_q.top());
            max_q.pop();
            max_q.push(temp);
        }
        
        answer.push_back(max_q.top());
    }
    
    for(int i=0;i<answer.size();i++){
        cout<<answer[i]<<"\n";
    }
    
    return 0;
}
