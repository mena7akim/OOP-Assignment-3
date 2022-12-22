#ifndef TASK_1_MAVECTOR_H
#define TASK_1_MAVECTOR_H
#pragma once

#include <iostream>
using namespace std;


template <class T>
class MAVector
{
private:
    int size, capacity;
	T* data;

public:
    using iterator = T*;
    using const_iterator = T const*;
	MAVector(int cap = 2) {
		this->capacity = cap;
		this->size = 0;
		this->data = new T[capacity];
	}

	MAVector(T* arr, int n) {
		this->capacity = 2;
		this->data = new T[capacity];

		while (capacity < n) {
			this->data = new T[capacity * 2];
			capacity *= 2;
		}
		for (int i = 0; i < n; i++) {
			data[i] = arr[i];
		}
		this->size = n;
	}


	MAVector(const MAVector& other) {
		this->size = other.size;
		this->capacity = other.capacity;
		data = new T[other.size];
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
            throw out_of_range("index out of range");
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
            if(iterator(ptr) == it) continue;
            temp[newSize++] = *ptr;
        }
        size = newSize;
        delete [] data;
        data = temp;
        ptr = nullptr;
        temp = nullptr;
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
            if(ptr >= it1 && iterator(ptr) <= it2) continue;
            temp[newSize++] = *ptr;
        }
        size = newSize;
        delete [] data;
        data = temp;
        ptr = nullptr;
        temp = nullptr;
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
            if(iterator(ptr) == it) {
                temp[newSize++] = value;
            }
            temp[newSize++] = *ptr;
        }
        size = newSize;
        delete [] data;
        data = temp;
        ptr = nullptr;
        temp = nullptr;
    }

    iterator begin() { return iterator(&data[0]);}
    iterator end() { return iterator(&data[size]);}

	int push_back(T temp) {
		if (size < capacity) {
			data[size++] = temp;
		}
		else {
			cout << "Resizing to..." << capacity * 2 << endl;
			T* newData = new T[capacity * 2];
			capacity *= 2;

			for (int i = 0; i < size; i++) {
                newData[i] = data[i];
			}
			delete[] data;
			data = newData;
            newData = nullptr;
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
		data = new T[capacity];
	}


	// Comparison operations

	bool operator==(const MAVector<T>& other) {
		if (size == other.size) {
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
				}
				else if (data[i] > other.data[i]) {
					return false;
				}
				if ((i == size - 1) && (data[i] == other.data[i])) {
					return false;
				}
			}
		}
		else if(other.size > size) {
			for (int i = 0; i < size; i++) {
				if (data[i] < other.data[i]) {
					return true;
				}
				else if (data[i] > other.data[i]) {
					return false;
				}
				if ((i == size - 1) && (data[i] == other.data[i])) {
					return true;
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

	void resize() {
        T* temp = new T[capacity * 2];
        for(int i = 0; i < size; i++){
            temp[i] = data[i];
        }
        delete [] data;
        data = temp;
        temp = nullptr;
    }

	bool empty() {
		if (size == 0) {
			return true;
		}
		else {
			return false;
		}
	}

    friend ostream& operator << (ostream& out, MAVector<T> &v) {
        for(int i = 0; i < v.Size(); i++){
            out << v[i] << ' ';
        }
        out << '\n';
        return out;
    }
	
};



#endif
