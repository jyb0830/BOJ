//
//  cabbage.cpp
//  baekjoon
//
//  Created by 지영본 on 2020/07/24.
//  Copyright © 2020 지영본. All rights reserved.
//

#include <iostream>

using namespace std;
int M,N;
int cab[51][51];
int visited[51][51];

void search(int y, int x){
    visited[y][x]=1;
    if(y+1<N&&cab[y+1][x]==1&&visited[y+1][x]==0)
        search(y+1,x);
    if(x+1<M&&cab[y][x+1]==1&&visited[y][x+1]==0)
        search(y,x+1);
    if(y-1>=0&&cab[y-1][x]==1&&visited[y-1][x]==0)
        search(y-1,x);
    if(x-1>=0&&cab[y][x-1]==1&&visited[y][x-1]==0)
        search(y,x-1);
}
int main(){
    int T, K; //T : test case, M : 가로 길이, N : 세로 길이, K : 배추 갯수
    
    cin>>T;
    int bug[T];
    for(int i=0;i<T;i++)
    {
        int X,Y;    //X : 오른쪽 방향, Y : 아래 방향
        bug[i]=0;
        cin>>M>>N>>K;
        for(int j=0;j<N;j++)
        {
            for(int k=0;k<M;k++)
            {
                cab[j][k]=0;        //배열 초기화
                visited[j][k]=0;
            }
        }
        for(int j=0;j<K;j++)
        {
            cin>>X>>Y;
            cab[Y][X]=1;        //배추 심기
        }
        for(int j=0;j<N;j++)
            for(int k=0;k<M;k++)
            {
                if(cab[j][k]==1&&visited[j][k]==0)
                {
                    search(j,k);
                    bug[i]++;
                }
            }
    }
    for(int i=0;i<T;i++)
        cout<<bug[i]<<"\n";
    return 0;
}
