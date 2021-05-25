//
//  ship.cpp
//  BOJ
//
//  Created by 지영본 on 2021/05/23.
//  acmicpc.net/problem/1092

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(){
    int N, M, cnt=0;
    cin>>N;
    
    vector<int> crane, box;
    
    for(int i=0;i<N;i++){
        int num;
        cin>>num;
        crane.push_back(num);
    }
    
    cin>>M;
    
    
    for(int i=0;i<M;i++){
        int num;
        cin>>num;
        box.push_back(num);
    }
    
    sort(box.begin(), box.end());
    sort(crane.begin(), crane.end());
    
    if(box[box.size()-1]>crane[crane.size()-1]){
        cout<<-1<<"\n";
        return 0;
    }
    
    while(!box.empty()){
        for(int i=(int)crane.size()-1;i>=0;i--){
            for(int j=(int)box.size()-1;j>=0;j--){
                if(box[j]<=crane[i]){
                    box.erase(box.begin()+j);
                    break;
                }
            }
            if(box.empty()) break;
        }
        
        cnt++;
    }
    
    cout<<cnt<<"\n";
    
    return 0;
}
