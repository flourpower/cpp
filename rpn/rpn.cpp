//implementing an RPN calculator in C++

#include <iostream>
#include <stack>
#include <sstream>
#include <string>
#include <vector>
#include <ctype.h>
#include <stdlib.h>
using namespace std;

int number(string str);

int number(string str){
	int isNumber = 1;
	for (string::iterator i = str.begin(); i != str.end(); ++i){
		isNumber *= isdigit(*i);
	}
	return isNumber;
}

//now we want a function that operates on a reference to a stack
void add_number (string str, stack <int> &s){
	s.push(atoi(str.c_str()));
}

void do_op (string str, stack <int> &s){
	int a, b;
	if(str == "+"){
		a = s.top();
		s.pop();
		b = s.top();
		s.pop();
		s.push(a+b);
		cout << "Result: " << s.top() << endl;
	}
	if(str == "-"){
		a = s.top();
		s.pop();
		b = s.top();
		s.pop();
		s.push(a-b);
		cout << "Result: " << s.top() << endl;
	}
	if(str == "*"){
		a = s.top();
		s.pop();
		b = s.top();
		s.pop();
		s.push(a*b);
		cout << "Result: " << s.top() << endl;
	}
	if(str == "/"){
		a = s.top();
		s.pop();
		b = s.top();
		s.pop();
		s.push(a/b);
		cout << "Result: " << s.top() << endl;
	}
}

void evaluate(vector<string> &tokens, stack <int> &s){
	for (vector<string>::iterator p=tokens.begin(); p!=tokens.end(); ++p){
		if (number(*p)){
			add_number(*p, s);
		}
		else if ( (*p) == "+" || (*p) == "-" || (*p) == "*" || (*p) == "/" ){
			if (s.size() < 2){
				cout << "not enough numbers on the stack, clearing stack." << endl;
				const size_t stack_size = s.size();
				int i;
				for (i = 0; i < stack_size; i++){
					s.pop();
				}
			}
			else{
				do_op(*p,s);
			}
		}
		else{
			cout << "neither a number nor an operator" << endl;	
		}	
	}
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
	stack <int> stk;
	vector <string> tokens; 
	string line;
	while (true){
		getline(cin,line);
		//cout << "the line is: " << line << endl;
		tokenize(line, tokens, " \t");
		evaluate(tokens, stk);
		tokens.erase(tokens.begin(),tokens.end());
	}
}

