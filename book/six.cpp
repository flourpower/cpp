//print the last six lines of an input file
//take the input file as a command line param

#include <iostream>
#include <fstream>
#include <deque>

using namespace std;

int main(int argc, char* argv[]){
	fstream f (argv[1]);
	if (f.is_open()){
		deque<string> lines(6,"");
		string line;
		while(! f.eof()){
			getline(f,line);
			lines.push_back(line);
			lines.pop_front();
		}
		for(deque<string>::iterator p=lines.begin(); p != lines.end(); p++){
			cout << *p << endl;
		}
		f.close();
		return 1;
	}
	else {
		cout << "couldn't open the file";
		return -1;
	}
	return 0;
}
