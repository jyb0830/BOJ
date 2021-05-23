//
//  card_shuffle.cpp
//  BOJ
//
//  Created by 지영본 on 2021/05/23.
//  acmicpc.net/problem/1091

#include <iostream>

using namespace std;

int N;
int p[48], s[48], card[48];

bool check(){
    bool ch=true;
    for(int i=0;i<N;i++){
        if(i%3!=p[card[i]]){
            ch=false;
            break;
        }
    }
    return ch;
}

bool check2(){
    bool ch=true;
    for(int i=0;i<N;i++){
        if(card[i]!=i){
            ch=false;
            break;
        }
    }
    return ch;
}

void shuffle(){
    int temp[N];
    
    for(int i=0;i<N;i++){
        temp[i]=card[i];
    }
    
    for(int i=0;i<N;i++){
        card[s[i]]=temp[i];
    }
}

int main(){
    cin>>N;
    int cnt=0;
    for(int i=0;i<N;i++){
        int num;
        cin>>num;
        p[i]=num;
        card[i]=i;
    }
    
    for(int i=0;i<N;i++){
        int num;
        cin>>num;
        s[i]=num;
    }
    
    while(!check()){
        if(cnt!=0 && check2()){
            cnt=-1;
            break;
        }
        shuffle();
        cnt++;
    }
    
    cout<<cnt<<"\n";
    
    return 0;
}
