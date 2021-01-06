//
//  prime_num_path.cpp
//  BOJ
//
//  Created by 지영본 on 2021/01/03.
//  acmicpc.net/problem/1963

#include <iostream>
#include <queue>
using namespace std;

bool prime[10000];
int visited[10000];
int bfs(int a, int b){
    queue<int> q;
    visited[a]=1;
    q.push(a);
    
    while(!q.empty()){
        int temp=q.front();
        if(temp==b)
            return visited[temp]-1;
        
        q.pop();
        int thousand=temp%1000;
        int hundred=temp-thousand/100*100;
        int ten=temp-hundred/10%10*10;
        int one=temp-temp%10;
        for(int i=0;i<10;i++){
            if(prime[thousand+1000*i]&&!visited[thousand+1000*i]){
                q.push(thousand+1000*i);
                visited[thousand+1000*i]=visited[temp]+1;
            }
            if(prime[hundred+100*i]&&!visited[hundred+100*i]){
                q.push(hundred+100*i);
                visited[hundred+100*i]=visited[temp]+1;
            }
            if(prime[ten+10*i]&&!visited[ten+10*i]){
                q.push(ten+10*i);
                visited[ten+10*i]=visited[temp]+1;
            }
            if(prime[one+i]&&!visited[one+i]){
                q.push(one+i);
                visited[one+i]=visited[temp]+1;
            }
        }
    }
    return 0;
}


int main(){
    int T;
    
    for(int i=0;i<10000;i++)
        prime[i]=true;
    
    for(int i=2;i*i<10000;i++){
        if(prime[i])
            for(int j=i*i;j<10000;j+=i)
                prime[j]=false;
    }
    for(int i=2;i<1000;i++) prime[i]=false;
    cin>>T;
    
    int ans[T];
    
    for(int i=0;i<T;i++){
        int num1,num2;
        cin>>num1>>num2;
        
        for(int j=0;j<10000;j++) visited[j]=0;
        
        ans[i]=bfs(num1,num2);
    }
    for(int i=0;i<T;i++) cout<<ans[i]<<"\n";
    
    return 0;
}
