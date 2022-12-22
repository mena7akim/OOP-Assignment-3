#include <bits/stdc++.h>
using namespace std;


template<typename T>
class mySet{
    set<T> st;
public:
    mySet(){

    }
    void add(T item){
        st.insert(item);
    }
    void remove(T item){
        st.erase(item);
    }
    int size() const{
        return st.size();
    }
    bool count(T item) const{
        return st.count(item);
    }
    T* dynamicallyAllocate(){
        T* ptr = new T[st.size()];
        int j = 0;
        for(auto item: st){
            ptr[j++] = item;
        }
        return ptr;
    }
    bool operator==(const mySet &other) const{
        return (other.st == this->st);
    }
    bool operator!=(const mySet &other) const{
        return (other.st != this->st);
    }
};




int main(){
    mySet<int> st1;
    st1.add(10);
    st1.add(20);
    mySet<int> st2;
    st2.add(10);
    st2.add(20);
    st2.add(30);
    mySet<int> st3;
    st3.add(10);
    st3.add(20);
    cout << (st1 == st2) << '\n';
    cout << (st1 != st2) << '\n';
    cout << (st1 == st3) << '\n';
}
