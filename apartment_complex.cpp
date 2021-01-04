//
//  apartment_complex.cpp
//  BOJ
//
//  Created by 지영본 on 2021/01/05.
//  acmicpc.net/problem/2667

#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int cplx_num=0;
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
int complex[25][25];
bool visited[25][25];
vector<int> v;
void bfs(int x, int y){
    queue<pair<int, int>> q;
    visited[x][y]=1;
    int cnt=1;
    complex[x][y]=cplx_num+1;
    
    q.push(make_pair(x, y));
    
    while(!q.empty()){
        x=q.front().first;
        y=q.front().second;
        
        q.pop();
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            
            if(nx>=0 && nx<25 && ny>=0 && ny<25)
                if(complex[nx][ny]&&!visited[nx][ny]){
                    complex[nx][ny]=cplx_num+1;
                    visited[nx][ny]=1;
                    cnt++;
                    q.push(make_pair(nx, ny));
                }
        }
    }
    cplx_num++;
    v.push_back(cnt);
}

int main(){
    int N;
    cin>>N;
    
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++){
            scanf("%1d", &complex[i][j]);
            visited[i][j]=0;
    }
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(!visited[i][j]&&complex[i][j])
                bfs(i, j);
        }
    }
    sort(v.begin(),v.end());
    
    cout<<cplx_num<<"\n";
    
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<"\n";
    
    return 0;
}
