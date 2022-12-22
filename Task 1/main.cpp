#include "MAVector.h"

int main() {
    MAVector<int> v(5);
    for(int i = 0; i < 5; i++){
        v.push_back(5 - i);
    }
    for(auto i:v){
        cout << i << ' ';
    }
    cout << '\n';
    MAVector<int> b(v);
    cout << b;
    for(int i = 0; i < 5; i++){
        cout << v[i] << ' ';
    }
    cout << '\n';
    MAVector<int> a = b;
    MAVector<int> c;
    c = a;
    sort(a.begin(), a.end());
    cout << "c " << c;
    cout << "a " << a;
    cout << "b " << b;
    cout << "v " << v;
    for(auto i:v){
        cout << i << ' ';
    }
    cout << '\n';
    sort(v.begin(), v.end());
    for(auto i:v){
        cout << i << ' ';
    }
    cout << '\n';
    reverse(v.begin(), v.end());
    cout << v;
    v.erase(v.begin() + 2, v.end());
    cout << v;
    v.erase(v.begin() + 1);
    cout << v;
    v.insert(v.begin() + 1, 4);
    cout << v;
    v.insert(v.begin(), 4);
    cout << v;
    v.pop_back();
    cout << v;
    v.clear();
    cout << v;
    v.push_back(1);
    v.push_back(2);
    cout << v;
    cout << v.empty() << '\n';
    v.clear();
    cout << v.empty() << '\n';
    v.resize();
    v.push_back(1);
    cout << v;
}
