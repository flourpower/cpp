//remove all of the duplicate characters in a string without using any additional buffer
#include <iostream>
#include <string>

using namespace std;

void ud(string & s){
	//so we go left to right over string, every letter we encounter, we traverse the rest of the string, deleting all occurences of this letter
	int i, j;
	for(i = 0; i < s.size(); i++){
		for(j = i+1; j < s.size(); j++){
			if (s[j] == s[i])
				s.erase(j,1);
		}
	}
}

int main(int argc, char* argv){
	string s ("my name is bob and I love fishing");
	cout << s << endl;
	ud(s);
	cout << s << endl; 
}