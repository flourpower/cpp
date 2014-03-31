#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

void tokenize(const string& str,
                      vector<string>& tokens,
                      const string& delimiters = " \t"){
    string::size_type lastPos = str.find_first_not_of(delimiters, 0);
    string::size_type pos     = str.find_first_of(delimiters, lastPos);
    while (string::npos != pos || string::npos != lastPos)
    {
        tokens.push_back(str.substr(lastPos, pos - lastPos));
        lastPos = str.find_first_not_of(delimiters, pos);
        pos = str.find_first_of(delimiters, lastPos);
    }
}

int main(int argc, char* argv[]){
	int count, i, piece;
	set<int> datas;
	vector<string> tokens; 
	string line;
	getline(cin, line);
	count = atoi(line.c_str());
	vector< set<int> > centers(count);
	//cout << "Number of data centers is: " << count << endl;
	for(i = 0; i < count; i++){
		//for every line
		getline(cin, line);
		//cout << line << endl;
		tokenize(line, tokens, " \t");
		for (vector<string>::iterator j = tokens.begin(); j != tokens.end(); j++){
			//for every piece of data in this line
			piece = atoi((*j).c_str());
			//if it's not in the big set, add it
			if (datas.find(piece) == datas.end()){
				datas.insert(piece);
			}
			else{
			//else, do nothing
			}
			//put it in the set associate with this center
			centers.at(i).insert(piece);
		}
		tokens.clear();
	}
	//FOR TESTING
	//now print out the set of all data
	//cout << "Here is the set of all the data points held:";
	for (set<int>::iterator k = datas.begin(); k != datas.end(); k++){
		//cout << " " << *k;
	}
	//cout << endl;
	//now loop through the centers, printing their key, and then their data
	for (i = 0; i < centers.size(); i++){
		//cout << "Center " << i+1 << ":";
		for(set<int>::iterator j = centers.at(i).begin(); j != centers.at(i).end(); j++){
			//cout << " " << *j;
		}
		//cout << endl;
	}
	//END FOR TESTING
	//for each data center
	int k;
	for (i = 0; i < centers.size(); i++){
		//cout << "Center " << i+1 << ":";
		//for each piece that's in datas that isn't in this data center
		for(set<int>::iterator j = datas.begin(); j != datas.end(); j++){
			//if the piece of data is not in this center
			if (centers.at(i).find(*j) == centers.at(i).end()){
				//find it in another center
				for (k = 0; k < centers.size(); k++){
					if(centers.at(k).find(*j) != centers.at(k).end()){
						cout << *j << " " << k+1 << " " << i+1 << endl;
						break;
					}
				}
			}
		}
	}
	cout << "done" << endl;
		
}



/*
So we'd like to construct a set of all of the available pieces of data.
Then, for each data center, construct a set of all of the pieces it has
	Then for each source data center, and each piece it is missing, find a center with this piece, and issue a copy command
*/