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

    //! Initialize by specific capacity No content is added, size = 0 Assign a default size value
    MAVector(int cap = 2) {
		this->capacity = cap;
		this->size = 0;
		this->data = new T[capacity];
	}

    //! Initialize by n items from array
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

    //! Initialize with a copy
	MAVector(const MAVector& other) {
		this->size = other.size;
		this->capacity = other.capacity;
		data = new T[other.size];
		for (int i = 0; i < other.size; i++) {
			data[i] = other.data[i];
		}
		
	}

    //! Copy assignment
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

    //! Move assignment
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

    //! Delete allocated memory
	~MAVector() {
		delete[] data;
	}

    //! Access item by reference, Throw an exception if out of range
    T& operator[](int index) {
		if (index <= size - 1) {
			return data[index];
		}
		else {
            throw out_of_range("index out of range");
		}
	}

    //! Remove item at iterator, Throw exception if invalid iter
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

    //! Remove items between iterator 1 <= iterator 2 otherwise do nothing, Throw exception if any iterator outside range
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

    //! Insert item at iterator, Throw exception if invalid
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
    //! Return an iterator to the beginning of the array
    iterator begin() { return iterator(&data[0]);}

    //! Return an iterator to the end of the array
    iterator end() { return iterator(&data[size]);}

    //! Access item by reference, Throw an exception if out of range
    int push_back(T temp) {
		if (size < capacity) {
			data[size++] = temp;
		}
		else {
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

    //! Remove and return last element in vec
	T pop_back() {    
		this->size -= 1;
		return data[size - 1];
	}

    //! Delete all vector content
	void clear() {
		this->size = 0;
		delete[] data;
		data = new T[capacity];
	}

    //! Return true if two vectors are equal
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

    //! Compares item by item, Return true if first different item in this is < in other
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


    //! Return current size of vec
	int Size() const {
		return size;
	}

    //! Return size of current allocated array
	int Capacity() const {
		return capacity;
	}

    //! Relocate to bigger space
	void resize() {
        T* temp = new T[capacity * 2];
        for(int i = 0; i < size; i++){
            temp[i] = data[i];
        }
        delete [] data;
        data = temp;
        temp = nullptr;
    }

    //! Return true if size is 0
    bool empty() {
		if (size == 0) {
			return true;
		}
		else {
			return false;
		}
	}
    //! Print the content of the array
    friend ostream& operator << (ostream& out, MAVector<T> &v) {
        for(int i = 0; i < v.Size(); i++){
            out << v[i] << ' ';
        }
        out << '\n';
        return out;
    }
	
};



#endif
