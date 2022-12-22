#include <bits/stdc++.h>
using namespace std;

int n;

void solve1(int i, string s = ""){
    if(i == n){
        cout << s << '\n';
        return;
    }
    solve1(i + 1, s + "RED ");
    solve1(i + 1, s + "GREEN ");
}

void solve2(int i, string s = ""){
    if(i == n){
        cout << s << '\n';
        return;
    }
    solve2(i + 1, s + "RED ");
    solve2(i + 1, s + "GREEN ");
    solve2(i + 1, s + "YELLOW ");
}


int main(){
    int testCases;
    cin >> testCases;
    while(testCases--){
        cin >> n;
        solve1(0);
        cout << "-----------------------------\n";
        solve2(0);
    }
}