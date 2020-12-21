//
//  telescope.cpp
//  baekjoon
//
//  Created by 지영본 on 2020/07/25.
//  Copyright © 2020 지영본. All rights reserved.
//  acmicpc.net/problem/1013

#include <iostream>

using namespace std;
string str;
bool answer;
void automata(int curr, int start){
    if(start==str.length())
    {
        if(curr==1 || curr==7 || curr==9)
            answer= true;
        else
            answer= false;
    }
    else if(str[start]=='0')
    {
        if(curr==1) automata(2, start+1);
        else if(curr==2) automata(4, start+1);
        else if(curr==3) automata(5, start+1);
        else if(curr==4) answer=false;
        else if(curr==5) automata(6, start+1);
        else if(curr==6) automata(6, start+1);
        else if(curr==7) automata(8, start+1);
        else if(curr==8) automata(4, start+1);
        else if(curr==9) automata(10, start+1);
        else if(curr==10) automata(6, start+1);
    }
    else if(str[start]=='1')
    {
        if(curr==1) automata(3, start+1);
        else if(curr==2) automata(1, start+1);
        else if(curr==3) automata(4, start+1);
        else if(curr==4) answer = false;
        else if(curr==5) automata(4, start+1);
        else if(curr==6) automata(7, start+1);
        else if(curr==7) automata(9, start+1);
        else if(curr==8) automata(1, start+1);
        else if(curr==9) automata(9, start+1);
        else if(curr==10) automata(1, start+1);
    }
}

int main(){
    int T;
    cin>>T;
    int ans[T];
    for(int i=0;i<T;i++)
    {
        answer=true;
        cin>>str;
        
        automata(1, 0);
        if(answer==true) ans[i]=1;
        else
            ans[i]=0;
    }
    for(int i=0;i<T;i++)
    {
        if(ans[i]==0)
            cout<<"NO\n";
        else
            cout<<"YES\n";
    }
    
    return 0;
}
