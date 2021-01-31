//
//  colored_papaer.cpp
//  BOJ
//
//  Created by 지영본 on 2021/01/31.
//  acmicpc.net/problem/2630

#include <iostream>
using namespace std;

char paper[128][128];
int color[2];
void cut(int x, int y, int N){
    bool same=true;
    char temp=paper[x][y];
    for(int i=x;i<x+N;i++){         //범위내의 색종이가 같은 색인지 검사
        for(int j=y;j<y+N;j++){
            if(paper[i][j]!=temp){
                same=false;
                break;
            }
        }
        if(same==false)
            break;
    }
    if(same==true) {
        color[temp-'0']++;
        return;
    }
    else{
        cut(x,y,N/2);
        cut(x,y+N/2,N/2);
        cut(x+N/2,y,N/2);
        cut(x+N/2,y+N/2,N/2);
    }
}

int main(){
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>paper[i][j];
        }
    }
    cut(0,0,N);
    cout<<color[0]<<"\n";
    cout<<color[1]<<"\n";
    return 0;
}
