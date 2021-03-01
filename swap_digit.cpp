//
//  swap_digit.cpp
//  BOJ
//
//  Created by 지영본 on 2021/02/23.
//  acmicpc.net/problem/1039
//  문제점 : 큐에서 바꾼 수가 최대값일 때 빠져나오는 경우에서 문제가 발생한다.
//         예를 들어 입력이 (199, 2)일 경우 첫 번째와 세 번째를 바꾸면 991이 돼서 빠져나온다. 이후 main문에서 남은 한 번을 바꿔 919가 나온다.
//         하지만 199 -> 919 -> 991로 최대 값은 991이다.
#include<iostream>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<vector>
 
#define endl "\n"
#define MAX 1000000 + 1
using namespace std;
 
string Inp;
int K, M;
vector<int> Answer;
 
int Invert(string S)
{
    int Sum = 0;
    for (int i = 0; i < S.length(); i++)
    {
        Sum = Sum + (S[i] - '0');
        if (i != S.length() - 1) Sum = Sum * 10;
    }
    return Sum;
}
 
void Input()
{
    cin >> Inp >> K;
    M = Inp.length();
 
    if (M == 1 || (M == 2 && Invert(Inp) % 10 == 0))
    {
        cout << "-1" << endl;
        exit(0);
    }
}
 
void BFS(string S)
{
    queue<string> Q;
    Q.push(S);
    int Cur_K = 0;
    int Max = 0;
 
    while (Q.empty() == 0 && Cur_K < K)
    {
        int Qs = Q.size();
        set<string> Visit;
 
        for (int q = 0; q < Qs; q++)
        {
            string Cur = Q.front();
            Q.pop();
 
            for (int i = 0; i < M - 1; i++)
            {
                for (int j = i + 1; j < M; j++)
                {
                    if (i == 0 && Cur[j] == '0') continue;
 
                    swap(Cur[i], Cur[j]);
                    if (Visit.find(Cur) == Visit.end())
                    {
                        if (Cur_K == K - 1 && Max < Invert(Cur))
                        {
                            Max = Invert(Cur);
                        }
                        Q.push(Cur);
                        Visit.insert(Cur);
                    }
                    swap(Cur[i], Cur[j]);
                }
            }
        }
        Cur_K++;
    }
 
    if (Cur_K != K) cout << "-1" << endl;
    else cout << Max << endl;
 
}
 
void Solution()
{
    BFS(Inp);
}
 
void Solve()
{
    Input();
    Solution();
}
 
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    //freopen("Input.txt", "r", stdin);
    Solve();
 
    return 0;
}


출처: https://yabmoons.tistory.com/152 [얍문's Coding World..]
