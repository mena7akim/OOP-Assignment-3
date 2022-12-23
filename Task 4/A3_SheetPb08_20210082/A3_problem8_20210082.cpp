#include <iostream>
using namespace std;

template<class T>
class Stack
{
private:
	int size;
	T* data;

public:
	Stack() {
		this->size = 0;
	}

	Stack(Stack& other) {
		size = other.size;
		delete[] data;
		data = new T[other.size];
		for (int i = 0; i < other.size; i++) {
			data[i] = other.data[i];
		}
	}

	Stack& operator=(const Stack& other) {
		if (this != &other) {
			size = other.size;
			delete[] data;
			data = new T[other.size];
			for (int i = 0; i < other.size; i++) {
				data[i] = other.data[i];
			}
		}
		return *this;
	}


	void push_back(const T& num) {
		T* newdata = new T[size + 1];
		for (int i = 0; i < size; i++) {
			newdata[i] = data[i];
		}
		delete[] data;
		data = newdata;
		newdata = nullptr;
		data[size++] = num;
	}


	void pop_back() {
		size--;
	}

	T top() {
		return data[size - 1];
	}


	int Size() {
		return size;
	}


	bool empty() {
		if (size == 0) {
			return true;
		}
		else
			return false;
	}


	~Stack() {
		delete[] data;
	}

};

template <class T>
class manageStack {
private:
	int size2;
	string type;
	Stack<T> s;
public:
	class StackOverflowException
	{
	private:
		string message;
	public:
		StackOverflowException(string msg) {
			this->message = msg;
		}
		string print() {
			return message;
		}

	};

	class StackEmptyException
	{
	private:
		string message;
	public:
		StackEmptyException(string msg) {
			this->message = msg;
		}
		string print() {
			return message;
		}

	};

	manageStack(int sz , string t) {
		this->size2 = sz;
		this->type = t;
	}

	void menu() {
		while (true) {
			int choice;
			cout << "\nHello user ^_^ " << endl << endl;
			cout << "1- push on stack" << endl;
			cout << "2- pop the last element from stack" << endl;
			cout << "3- check top in stack" << endl;
			cout << "4- check if the stack is empty" << endl;
			cout << "5- exit" << endl;
			cout << "\n enter your choice :";
			cin >> choice;
			if (choice == 1) {
				try {
					if (s.Size() == size2) {
						throw StackOverflowException("stack overflow , please pop element and try again");
					}
					else {
						T num;
						cout << "\n enter the element that you want to push it: ";
						cin >> num;
						s.push_back(num);
					}
				}
				catch (StackOverflowException& so) {
					cout << so.print() << endl;
				}
			}
			else if (choice == 2) {
				try {
					if (s.empty()) {
						throw StackEmptyException("stack is already empty , please push elements and try again");
					}
					else {
						s.pop_back();
					}
				}
				catch (StackEmptyException& se) {
					cout << se.print() << endl;
				}
			}
			else if (choice == 3) {
				try {
					if (s.empty()) {
						throw StackEmptyException("stack is already empty , please push elements and try again");
					}
					else {
						cout << s.top();
					}
				}
				catch (StackEmptyException& se) {
					cout << se.print() << endl;
				}
			}
			else if (choice == 4) {
				if (s.empty()) {
					cout << "it is empty" << endl;
				}
				else {
					cout << "not empty" << endl;
				}
			}
			else if (choice == 5) {
				break;
			}
			else {
				cout << "you already enter invalid choice , please try again" << endl;
			}
		}
	}
};

int main() {
	int n;
	string type;
	cout << "please enter the size you want : ";
	cin >> n;
	cout << "\nplease enter the type you want : ";
	cin >> type;

	if (type == "int") {
		manageStack<int> m(n, type);
		m.menu();
	}
	else if (type == "float") {
		manageStack<float> m(n, type);
		m.menu();
	}
	else if (type == "string") {
		manageStack<string> m(n, type);
		m.menu();
	}
	else if (type == "char") {
		manageStack<char> m(n, type);
		m.menu();
	}
	else {
		cout << "invalid type , please try again" << endl;
	}
	
}
