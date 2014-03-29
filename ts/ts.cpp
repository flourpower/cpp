/*
Solves the following problem

You are to write a program that takes a list of strings containing
integers and words and returns a sorted version of the list.
 
The goal is to sort this list in such a way that all words are in
alphabetical order and all integers are in numerical order.
Furthermore, if the nth element in the list is an integer it must
remain an integer, and if it is a word it must remain a word.

take input from stdin and produce output to stdout

approach:
read in the list of words and integers into a vector
create a bit vector telling you which thing is an integer and which thing is a word
sort the words vector
sort the integers vector, read back from both of them into the bit vector and print
*/
#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <deque>

using namespace std;

int number(string str){ //this doesn't properly identify negative numbers
	int isNumber = 1;
	for (string::iterator i = str.begin(); i != str.end(); ++i){
		isNumber *= isdigit(*i);
	}
	return isNumber;
}

void tokenize(const string& str,
                      vector<string>& tokens,
                      const string& delimiters = " \t")
{
    // Skip delimiters at beginning.
    string::size_type lastPos = str.find_first_not_of(delimiters, 0);
    // Find first "non-delimiter".
    string::size_type pos     = str.find_first_of(delimiters, lastPos);

    while (string::npos != pos || string::npos != lastPos)
    {
        // Found a token, add it to the vector.
        tokens.push_back(str.substr(lastPos, pos - lastPos));
        // Skip delimiters.  Note the "not_of"
        lastPos = str.find_first_not_of(delimiters, pos);
        // Find next "non-delimiter"
        pos = str.find_first_of(delimiters, lastPos);
    }
}

int main(int argc, char* argv[]){
	vector<int> bits;
	string str;
	vector<string> tokens;
	deque<string> strings;
	deque<int> ints;
	getline(cin, str);
	tokenize(str, tokens, " \t");
	for(vector<string>::iterator a = tokens.begin(); a != tokens.end(); a++){
		if (number(*a)){
			//put it in number vector
			ints.push_back(atoi((*a).c_str()));
			//update bit vector
			bits.push_back(1);
		}
		else{
			//put it in word vector
			strings.push_back(*a);
			//update the bit vector
			bits.push_back(0);
		}
	}
	sort(ints.begin(),ints.end());
	sort(strings.begin(), strings.end());
	int i;
	for(i = 0; i < bits.size(); i++){
		if (bits.at(i) == 1){
			//output a number
			cout << ints.front() << " ";
			ints.pop_front();
		}
		else{
			//output a string
			cout << strings.front() << " ";
			strings.pop_front();
		}
	}
}
