#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<vector<int>> v;
vector<bool> solo;
vector<int> temp;
void dfs(int idx){
    if(v[idx].empty()){
        for(int i=0;i<temp.size();i++){
            cout<<char(temp[i]+'A')<<" ";
        }
        cout<<char(idx+'A')<<"\n";
        return;
    }
    else{
        temp.push_back(idx);
        for(int i=0;i<v[idx].size();i++){
            dfs(v[idx][i]);
        }
        temp.pop_back();
        return;
    }
}

int main(){
    int n;
    string str;
    getline(cin, str);
    
    for(char c='A';c<='z';c+=1) {
        v.push_back(vector<int>());
        solo.push_back(true);
    }
    
    cin>>n;
    
    
    for(int i=0;i<n;i++){
        char pre_skill, post_skill;
        cin>>pre_skill>>post_skill;
        v[pre_skill-'A'].push_back(post_skill-'A');
        solo[post_skill-'A']=false;
    }
    for(int i=0;i<solo.size();i++){
        if(solo[i]==true && !v[i].empty()){
            dfs(i);
        }
    }
    
    return 0;
}
