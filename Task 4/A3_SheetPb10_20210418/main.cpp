#include <bits/stdc++.h>
using namespace std;

class monthError{
    string msg;
public:
    monthError(string msg) : msg(msg){

    }
    string what(){
        return msg;
    }
};

class month{
public:
    month(int m, int d){
        if(m > 12 || m < 1){
            throw monthError("illegal month number\n");
        }
    }
};



class dayError{
    string msg;
public:
    dayError(string msg) : msg(msg){

    }
    string what(){
        return msg;
    }
};

class day{
public:
    day(){

    }
    day(int d, int m){
        if(m != 2 && d > 31 || d < 1){
            throw dayError("illegal day number\n");
        }
        if(m == 2 && d > 29 || d < 1){
            throw dayError("illegal day number\n");
        }
    }
};





int main(){
    int D, M;
    cin >> D >> M;
    try{
        month(M, D);
    }
    catch (monthError& e){
        cout << e.what();
        return 0;
    }
    try{
        day(D, M);
        cout << D << '/' << M << '\n';
    }
    catch (dayError& e){
        cout << e.what();
        return 0;
    }

}