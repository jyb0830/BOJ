//
//  find_parent.cpp
//  BOJ
//
//  Created by 지영본 on 2021/02/14.
//  acmicpc.net/problem/11725

#include <iostream>
using namespace std;

int main(){
    int n, cnt=0;
    cin>>n;
    int node1[n-1],node2[n-1];
    int parent[n+1];
    for(int i=0;i<n-1;i++){
        cin>>node1[i]>>node2[i];
    }
    for(int i=0;i<n+1;i++) parent[i]=0;
    
    while(cnt<n-1){
        for(int i=0;i<n-1;i++){
            if(node1[i]==1){    //연결된 노드 중 하나가 1인 경우 무조건 나머지 노드는 1의 자식
                parent[node2[i]]=1;
                node1[i]=node2[i]=0;
                cnt++;
                continue;
            }
            if(node2[i]==1){
                parent[node1[i]]=1;
                cnt++;
                continue;
            }
            if(parent[node1[i]]==0&&parent[node2[i]]==0) continue;   //연결된 두 노드가 모두 부모가 없는 경우 대기
            if(node1[i]==0 && node2[i]==0) continue;    //두 노드의 연결상태를 이미 반영했으면 통과
            
            if(parent[node1[i]]!=0){
                parent[node2[i]]=node1[i];
                node1[i]=node2[i]=0;
                cnt++;
                continue;
            }
            else if(parent[node2[i]]!=0){
                parent[node1[i]]=node2[i];
                node1[i]=node2[i]=0;
                cnt++;
                continue;
            }
        }
    }
    
    for(int i=2;i<n+1;i++) cout<<parent[i]<<"\n";
    
    return 0;
}
