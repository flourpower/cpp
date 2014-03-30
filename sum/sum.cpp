//Given a vector of integers and a sum integer, return whether two integers that sum to the target if possible, and -1 otherwise
/*Approach: with K the target, insert K - i into the map for every i in the vector, then every new insertion
we check whether the number is already in the set, and if it is, we are done because we've found a sum*/
#include <iostream>
#include <vector>
#include <set>

using namespace std;

bool check(vector<int> &v, int k){
	set<int> s;
	for(vector<int>::iterator i = v.begin(); i != v.end(); i++){
		//if the int is in the set, return true
		if (s.find(*i) != s.end()){
			return true;
		}
		//else, insert K - int into the set
		else{
			s.insert( k - (*i));
		}
	}
	return false;
}

int main(int argc, char* argv){
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(9);
	v.push_back(7);
	cout << check(v,5) << endl;
}