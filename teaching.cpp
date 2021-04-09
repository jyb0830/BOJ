//
//  teaching.cpp
//  BOJ
//
//  Created by 지영본 on 2021/03/21.
//  acmicpc.net/problem/1062

#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> v;
vector<char> alpha, learning;


int n,k, answer=0;

void back_tracking(int idx, int num){
    //cout<<"idx : "<<idx<<"   num : "<<num<<"\n";
    if(num==k){
        int temp=0;
        for(int i=0;i<n;i++){
            bool check=true;
            for(int j=0;j<v[i].size();j++){
                check=false;
                for(int x=0;x<k;x++){
                    if(v[i][j]==learning[x]) check=true;
                }
                if(check==false) break;
            }
            if(check) temp++;
        }
        answer=max(answer, temp);
        return;
    }
    
    else{
        for(int i=idx;i<alpha.size();i++){
            bool check=false;
            for(int j=0;j<learning.size();j++){
                if(alpha[i]==learning[j]) {
                    check=true;
                    break;
                }
            }
            if(!check){
                learning.push_back(alpha[i]);
                back_tracking(i, num+1);
                learning.pop_back();
            }
        }
    }
}

int main(){
    cin>>n>>k;
    
    for(int i=0;i<n;i++){
        string str;
        cin>>str;
        str = str.substr(4);
        str.resize(str.length()-4);
        v.push_back(str);
    }
    alpha.push_back('a');
    alpha.push_back('c');
    alpha.push_back('i');
    alpha.push_back('n');
    alpha.push_back('t');
    
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].size();j++){
            bool check=false;
            for(int k=0;k<alpha.size();k++){
                if(v[i][j]==alpha[k]) check=true;
            }
            if(!check) alpha.push_back(v[i][j]);
        }
    }
    learning.push_back('a');
    learning.push_back('c');
    learning.push_back('i');
    learning.push_back('n');
    learning.push_back('t');
    
    if(k<5){
        cout<<0<<"\n";
        return 0;
    }
    
    if(k>alpha.size()){
        cout<<n<<"\n";
        return 0;
    }
    
    back_tracking(0, 5);
    
    cout<<answer<<"\n";
    
    return 0;
}
