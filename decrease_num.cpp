//
//  decrease_num.cpp
//  BOJ
//
//  Created by 지영본 on 2021/02/22.
//  acmicpc.net/problem/1038

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int cnt=0, n;
int64_t ans=0;
int dec_num[10][10];        //dec_num[i][j] : 최고자리수가 i인 j+1자리 수의 갯수 ex)dec_num[2][2] : 2 _ _ --> 1개

void decrease(int num, int digit){
    if(dec_num[num][digit]==0){
        for(int i=digit-1;i<num;i++){
            dec_num[num][digit]+=dec_num[i][digit-1];
        }
    }
    
    if(cnt+dec_num[num][digit]==n){
        for(int i=num, j=digit;j>=0;i--, j--){
            ans+=i * pow(10,j);
        }
        cnt+=dec_num[num][digit];
        return;
    }
    else if(cnt+dec_num[num][digit]<n) {
        cnt+=dec_num[num][digit];
        return;
    }
    
    else{
        n-=cnt;
        cnt=0;
        ans+=num*pow(10,digit);
        for(int i=digit-1;i<num;i++){
            if(cnt==n) break;
            
            decrease(i,digit-1);
        }
        return;
    }
}

int main(){
    cin>>n;
    for(int i=0;i<9;i++){
        for(int j=0;j<10;j++){
            dec_num[i][j]=0;
        }
    }
    
    for(int i=0;i<10;i++) dec_num[i][0]=1;
    if(n<10) {
        cout<<n<<"\n";
        return 0;
    }
    cnt=9;
    for(int i=1;i<10;i++){
        for(int j=i;j<10;j++){
            if(ans!=0) break;
            decrease(j, i);
        }
        if(ans!=0) break;
    }
    if(ans==0) cout<<-1<<"\n";
    else cout<<ans<<"\n";
    
    return 0;
}
