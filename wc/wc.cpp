// take the name of a file and an integer n and print out the n most common words in that file
// I'm assuming that the file can fit in memory
#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include <stdlib.h>
#include <vector>
#include <list>

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

void words_into_map(map <string,int>, vector<string> words){
	cout << "inserting all of the words from the last line into a map" << endl;
	//now we need to actually do this inserting instead of just saying we're doing it
}

int main(int argc, char* argv[]){
	fstream f (argv[1]);
	int n = atoi(argv[2]);
	map<string,int> m;
	string line;
	vector<string> words;
	if (f.is_open()){
		cout << "opening the file " << argv[1] << " and finding the " << n << " most common words" << endl;
		while (! f.eof()){
			getline(f,line);
			tokenize(line, words, " \t");
			words_into_map(m, words);
		}
		return 0;
	}
	else{
		cout << "Your file failed to open" << endl;
		return -1;
	}
}