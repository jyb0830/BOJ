//
//  q4.cpp
//  BOJ
//
//  Created by 지영본 on 2021/03/06.
//

#include <iostream>

using namespace std;

int n;
int arr[100];
bool visited[100];

int ans(int idx, int cnt){
    if(visited[idx]==true) return cnt+1;
    
    visited[idx]= true;
    
    int answer=ans(idx+arr[idx], cnt+1);
    
    return answer;
}


int main(){
    cin>>n;
    int answer[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) visited[j]=false;
        
        answer[i]=ans(i,0);
        cout<<"answer["<<i<<"] : "<<answer[i]<<"\n";
    }
    int max_num=0;
    
    for(int i=0;i<n;i++) max_num=max(max_num, answer[i]);
    
    cout<<max_num<<"\n";
    
    return 0;
}
