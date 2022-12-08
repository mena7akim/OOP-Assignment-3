#ifndef TASK_1_MAVECTOR_H
#define TASK_1_MAVECTOR_H
#pragma once

#include "iterator.h"
#include <iostream>
using namespace std;


template <class T>
class MAVector
{
private:
	int size, capacity;
	T* data;
public:

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



	// modifying operations


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

	
};



#endif
