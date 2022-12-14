#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

ifstream infile;

bool openFile() {
	infile.open("C:/Users/Aya Ashraf/Downloads/Telegram Desktop/dictionary.txt", ios::in);
	if (!infile) {
		return false;
	}
	else {
		return true;
	}
}


bool searchWord(string word) {
	if (openFile()) {
		string line;
		while (infile>>line)
		{
			if (line == word) {
				infile.close();
				return true;
			}

		}
		infile.close();
		return false;
	}
}


bool checkWord(string word, string result) {
	string str;
	if (word == "") {
		result += str;
		cout << result << endl;
		return true;
	}
	else {
		for (int i = 1; i <= word.size(); i++) {
			str = word.substr(0, i);
			if (searchWord(str)) {
				string remaining = word.substr(i);
				checkWord(remaining, result + str + " ");
			}
		}
	}
}


bool separateWord(string word) {
	if (checkWord(word , "")) {
		return true;
	}
	else
		return false;
		
}




int main() {
	separateWord("iwillmeetyoutomorrow");
}
