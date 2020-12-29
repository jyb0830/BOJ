//
//  tournament.cpp
//  BOJ
//
//  Created by 지영본 on 2020/12/29.
//  acmicpc.net/problem/1057

#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int N, Kim, Lim, k=0;
    
    cin>>N>>Kim>>Lim;
    
    while(N>pow(2,k)) k++;
    k--;
    
    for(int i=k;i>=0;i--){
        if(Kim<=pow(2,i) && Lim<=pow(2,i))
            continue;
        
        else if(Kim<=pow(2,i) && Lim > pow(2,i)){
            cout<<i+1;
            break;
        }
        else if(Kim>pow(2,i) && Lim<=pow(2,i)){
            cout<<i+1;
            break;
        }
        else if(Kim>pow(2,i) && Lim>pow(2,i)){
            Kim=Kim%(int)pow(2,i);
            if(Kim==0) Kim=pow(2,i);
            Lim=Lim%(int)pow(2,i);
            if(Lim==0) Lim=pow(2,i);
        }
        
    }
    
    
    return 0;
}
