//reverse the words in an input string

#include <iostream>
#include <vector>

using namespace std;

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

void rev(string str){
	//reverse the words in this string
	int j;
	vector<string> words;
	tokenize(str, words, " \t");
	for(vector<string>::iterator i = words.begin(); i != words.end(); i++){
		for(j = (i->size()) - 1; j >= 0; j--){
			cout << (*i)[j];
		}
		cout << " ";
	}
}

int main(int argc, char** argv){
	rev("my name is fred");
	cout << endl;
}
















