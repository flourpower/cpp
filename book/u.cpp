//implement an algorithm to determine if a string has all unique characters
#include <string>
#include <iostream>
#include <set>

using namespace std;

bool uc(string s){
	set<char> chars;
	for(string::iterator i = s.begin(); i != s.end(); i++){
		//if it's not in the set, add it
		if (chars.find(*i) == chars.end()){
			chars.insert(*i);
		}
		//if it is in the set, return false
		else{
			return false;
		}
	}
	//return true, since we found no dups
	return true;
}

int main(int argc, char** argv){
	cout << uc("abcd e fg") << endl;
}