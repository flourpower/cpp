// take the name of a file and an integer n and print out the n most common words in that file
// I'm assuming that the file can fit in memory
#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include <stdlib.h>
#include <vector>
#include <list>
#include <utility>
#include <algorithm>

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

void insert(map <string,int> & m, string str){
	if (m.find(str) != m.end()){
		m[str]++;
	}
	else{
		m[str] = 1;
	}
}

void words_into_map(map <string,int> & m, vector<string> & words){
	for(vector<string>::iterator w = words.begin(); w != words.end(); w++){
		insert(m, *w);
	}
}

bool cmp (pair <string, int> a,pair <string, int> b) { return (a.second > b.second); }

int main(int argc, char* argv[]){
	fstream f (argv[1]);
	int n = atoi(argv[2]);
	map<string,int> m;
	string line;
	vector<string> words;
	if (f.is_open()){
		while (! f.eof()){
			getline(f,line);
			tokenize(line, words, " \t");
			words_into_map(m, words);
			words.clear();
		}
		vector< pair <string,int> > pairs;
		for(map<string,int>::iterator i = m.begin(); i != m.end(); i++){
			pairs.push_back(*i);
		}
		std::sort (pairs.begin(), pairs.end(), cmp);
		int i;
		for (i = 0; (i < n) && (i < pairs.size()); i++){
			cout << pairs.at(i).first << ": " << pairs.at(i).second << endl;
		}
		sort(pairs.begin(), pairs.end());
		return 0;
	}
	else{
		cout << "Your file failed to open" << endl;
		return -1;
	}
}