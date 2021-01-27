//
//  moo_game.cpp
//  BOJ
//
//  Created by 지영본 on 2021/01/28.
//  acmicpc.net/problem/5904

#include <iostream>
#include <vector>
using namespace std;
vector<int64_t> v;

void moo(int64_t N){
    int idx=0;
    for(int i=0;i<v.size();i++){
        if(v[i]>=N){
            idx=i;
            break;
        }
    }
    if(idx==0){
        if(N==1){
            cout<<'m'<<"\n";
            return;
        }
        else{
            cout<<'o'<<"\n";
            return;
        }
            
    }
    
    
    if(N-v[idx-1]==1){
        cout<<'m'<<"\n";
        return;
    }
    if(N-v[idx-1]>1&&N-v[idx-1]<=idx+3){
        cout<<'o'<<"\n";
        return;
    }
    else moo(N-v[idx-1]-idx-3);
}

int main(){
    int64_t N;
    
    cin>>N;
    
    v.push_back(3);
    for(int i=0;v[i]<N;i++){
        v.push_back(2*v[i]+i+4);
    }
    moo(N);
    return 0;
}
