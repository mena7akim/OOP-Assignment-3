#include <iostream>
#include <map>
#include <cctype>
#include <fstream>
#include <set>
#include <iomanip>


using namespace std;





void copy_file_to_text(string& text, string filename)
{
	fstream File;
	File.open(filename, ios::in);
	if (!File)
	{
		cout << "Cannot open the file!" << endl;
		exit(-1);
	}

	while (!File.fail() && !File.eof())
	{
		text += File.get();
	}

	File.close();

}


void copy_text_to_file(string text, string filename)
{
	ofstream File;
	File.open(filename, ios::out);
	if (!File)
	{
		cout << "Cannot open the file!" << endl;
		exit(-1);
	}

	File << text;
	File.close();
}



void cleanFile(string filename) {
	string text;
	copy_file_to_text(text, filename);
	for (int i = 0; i < text.size(); i++) {
		if ((ispunct(text[i]) && text[i] != '-')) {
			text.erase(i, 1);
			i--;
		}
		else if (isalnum(text[i])) {
			text[i] = tolower(text[i]);
		}
		
	}
	copy_text_to_file(text, filename);
}



void search_print_file(string filename) {
	multiset<string>words;
	multiset<string>::iterator its;
	map<string, int>table;
	map<string, int >::iterator it;
	
	int sumChar = 0;
	string text;
	cleanFile(filename);
	copy_file_to_text(text, filename);
	for (int i = 0; i < text.size(); i++) {
		if (text[i] == ' ' || text[i] == '\n') {
			string word = text.substr(i-sumChar, sumChar);
			words.insert(word);
			sumChar = 0;
		}
		else {
			sumChar++;
		}
	}
	cout << endl;
	for (its = words.begin(); its != words.end(); its++) {
		int sum = words.count(*its);
		if (table.find(*its) == table.end()) {
			table.insert({ *its , sum });
		}
	}
	// print table
	cout <<setfill('-')<<setw(50) <<"-" << endl;
	cout << "|"<<setfill(' ')<<setw(15)<<"word"<<setfill(' ')<<setw(15)<<"|" << setfill(' ') << setw(8) << " frequency" << setfill(' ') << setw(9) << "|" << endl;
	cout << setfill('-') << setw(50) << "-" << endl;
	for (it = table.begin(); it != table.end(); it++) {
		cout <<"|" << setfill(' ') << setw(15) << it->first << setfill(' ') << setw(15) << "|" << setfill(' ') << setw(8) << it->second << setfill(' ') << setw(11) << "|" << endl;
	}
	cout << setfill('-') << setw(50) << "-" << endl;

}





int main() {
	string filename , text;
	cout << "please enter your file , it should On the same formula of : *.txt" << endl;
	cin >> filename;
	search_print_file(filename);
}
