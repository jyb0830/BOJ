//
//  sum_large_num.cpp
//  BOJ
//
//  Created by 지영본 on 2021/02/02.
//

#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;


int main(){
    char A[10001],B[10001],ans[10001];
    int flag=0, num1=0, num2=0, idx=0;
    
    scanf("%s%s",A,B);
    
    int a_len=int(strlen(A));
    int b_len=int(strlen(B));
    
    while(a_len>0 || b_len>0 || flag>0){
        if(a_len>0) num1=A[a_len-1]-'0';
        if(b_len>0) num2=B[b_len-1]-'0';
        //cout<<"num1 : "<<num1<<"    num2 : "<<num2<<"   a_len : "<<a_len<<"   b_len : "<<b_len<<"   flag : "<<flag<<"\n";
        ans[idx++] = (num1+num2+flag)%10+'0';
        flag=(num1+num2+flag)>=10?1:0;
        a_len--;
        b_len--;
        num1=0;
        num2=0;
    }
    for(int i=idx-1;i>=0;i--){
        cout<<ans[i];
    }
    
    return 0;
}
