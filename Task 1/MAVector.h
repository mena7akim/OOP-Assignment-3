#ifndef TASK_1_MAVECTOR_H
#define TASK_1_MAVECTOR_H
#pragma once

#include <iostream>
using namespace std;

//template <typename T>
//class iterator
//{
//public:
//    using valueType = typename T::valueType;
//    using pointer = T*;
//    using reference = T&;
//
//    iterator(pointer ptr) : p(ptr) {}
//    reference operator*() const {
//        return *p;
//    }
//    pointer operator->() {
//        return p;
//    }
//    iterator& operator++() {
//        p++;
//        return *this;
//    }
//    iterator operator++(int) {
//        iterator tmp = *this;
//        ++(*this);
//        return tmp;
//    }
//    friend bool operator== (const iterator& a, const iterator& b) {
//        return a.p == b.p;
//    };
//    friend bool operator!= (const iterator& a, const iterator& b) {
//        return a.p != b.p;
//    };
//
//private:
//    pointer p;
//};



template <class T>
class MAVector
{
private:
	int size, capacity;
	T* data;

public:
//    template <typename T>
    class iterator
    {
    public:
        using valueType = typename T::valueType;
        using pointer = T*;
        using reference = T&;

        iterator(pointer ptr) : p(ptr) {}
        reference operator*() const {
            return *p;
        }
        pointer operator->() {
            return p;
        }
        iterator& operator++() {
            p++;
            return *this;
        }
        iterator operator++(int) {
            iterator tmp = *this;
            ++(*this);
            return tmp;
        }
        friend bool operator== (const iterator& a, const iterator& b) {
            return a.p == b.p;
        };
        friend bool operator!= (const iterator& a, const iterator& b) {
            return a.p != b.p;
        };

    private:
        pointer p;
    };

	// constuctors and Big 4

	MAVector(int cap = 2) {
		this->capacity = cap;
		this->size = 0;
		this->data = new T[capacity];
	}

	MAVector(T* arr, int n) {
		this->capacity = 2;
		this->data = new T[capacity];

		while (capacity < n) {
			cout << "Resizing to ..." << capacity * 2 << endl;
			this->data = new T[capacity * 2];
			capacity *= 2;
		}
		for (int i = 0; i < n; i++) {
			data[i] = arr[i];
		}
		this->size = n;
	}


	MAVector(const MAVector& other) {
		delete[] data;
		this->size = other.size;
		this->capacity = other.capacity;
		data = new T [other.size];
		for (int i = 0; i < other.size; i++) {
			data[i] = other.data[i];
		}
		
	}


	MAVector& operator=(const MAVector& other) {
		if (this != &other) {
			delete[] data;
			this->size = other.size;
			this->capacity = other.capacity;
			data = new T[other.size];
			for (int i = 0; i < other.size; i++) {
				data[i] = other.data[i];
			}
		}
		return *this;
	}


	MAVector& operator=(const MAVector&& other) {
		if (this != &other) {
			delete[] data;
			this->size = other.size;
			this->capacity = other.capacity;
			data = new T[other.size];
			for (int i = 0; i < other.size; i++) {
				data[i] = other.data[i];
			}
			other.size = 0;
			other.capacity = 0;
			other.data = nullptr;
		}
		return *this;
	}


	~MAVector() {
		delete[] data;
	}



	//Access operations

	T& operator[](int index) {
		if (index <= size - 1) {
			return data[index];
		}
		else {
			// we need here throw an exception if out of range 
			cout << "index out of range" << endl;
			exit(-1);
		}
	}

    void erase(iterator it){
        T* ptr = data;
        for(; ptr <= data + size; ptr++){
            if(ptr == it) break;
        }
        if(ptr == data + size){
            throw invalid_argument("invalid iterator");
        }
        T* temp = new T[capacity];
        ptr = data;
        int newSize = 0;
        for(; ptr < data + size; ptr++){
            if(ptr == it) continue;
            temp[newSize++] = *ptr;
        }
        size = newSize;
        delete [] data;
        data = temp;
    }

    void erase(iterator it1, iterator it2){
        bool validIt1 = 0, validIt2 = 0;
        T* ptr = data;
        for(; ptr < data + size; ptr++){
            if(ptr == it1 && !validIt2) validIt1 = 1;
            if(ptr == it2 && validIt1)  validIt2 = 1;
        }
        if(!validIt1 || !validIt2){
            throw invalid_argument("invalid iterator");
        }
        T* temp = new T[capacity];
        ptr = data;
        int newSize = 0;
        for(; ptr < data + size; ptr++){
            if(ptr >= it1 || ptr <= it2) continue;
            temp[newSize++] = *ptr;
        }
        size = newSize;
        delete [] data;
        data = temp;
    }
	// modifying operations

    void insert(iterator it, T value){
        T* ptr = data;
        for(; ptr <= data + size; ptr++){
            if(ptr == it) break;
        }
        if(ptr == data + size){
            throw invalid_argument("invalid iterator");
        }
        T* temp = new T[capacity];
        ptr = data;
        int newSize = 0;
        for(; ptr < data + size; ptr++){
            temp[newSize++] = *ptr;
            if(ptr == it) ptr--;
        }
        size = newSize;
        delete [] data;
        data = temp;
    }

    iterator begin() { return iterator(data);}
    iterator end() { return iterator(data + size);}

	int push_back(T temp) {
		if (size < capacity) {
			data[size++] = temp;
		}
		else {
			cout << "Resizing to..." << capacity * 2 << endl;
			T* newdata = new T[capacity * 2];
			capacity *= 2;

			for (int i = 0; i < size; i++) {
				newdata[i] = data[i];
			}
			delete[] data;
			data = newdata;
			newdata = nullptr;
			data[size++] = temp;
		}
		return size;
	}


	T pop_back() {    
		this->size -= 1;
		return data[size - 1];
	}


	void clear() {
		this->size = 0;
		delete[] data;
		data = new T[capacity];               // i am not sure about this line ..... if you can get better , write it here
	}



	// Comparison operations

	bool operator==(const MAVector<T>& other) {
		if (size == other.size) {                  // i am not sure if i should check the capacity or not
			int sum = 0;
			for (int i = 0; i < size; i++) {
				if (data[i] == other.data[i]) {
					sum++;
				}
			}
			if (sum == other.size) {
				return true;
			}
			else {
				cout << "these ara not equal" << endl;
				return false;
			}
		}
		else {
			cout << "these size ara not equal" << endl;
			return false;
		}
	}


	bool operator< (const MAVector<T>&other) {
		if (other.size <= size) {
			for (int i = 0; i < other.size; i++) {
				if (data[i] < other.data[i]) {
					return true;
					break;
				}
				else if (data[i] > other.data[i]) {
					return false;
					break;
				}
				if ((i == size - 1) && (data[i] == other.data[i])) {
					return false;
					break;
				}
			}
		}
		else if(other.size > size) {
			for (int i = 0; i < size; i++) {
				if (data[i] < other.data[i]) {
					return true;
					break;
				}
				else if (data[i] > other.data[i]) {
					return false;
					break;
				}
				if ((i == size - 1) && (data[i] == other.data[i])) {
					return true;
					break;
				}
			}
		}
		return false;
	}



	// Capacity operations

	int Size() const {
		return size;
	}

	int Capacity() const {
		return capacity;
	}

	

	bool empty() {
		if (size == 0) {
			return true;
		}
		else {
			cout << "it is not empty" << endl;
			return false;
		}
	}

    friend ostream& operator << (ostream& out, MAVector<T> v) {
        for(int i = 0; i < v.Size(); i++){
            out << v[i] << ' ';
        }
        out << '\n';
        return out;
    }
	
};



#endif
