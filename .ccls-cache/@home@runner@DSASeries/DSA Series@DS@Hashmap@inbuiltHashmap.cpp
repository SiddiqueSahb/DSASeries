#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
	unordered_map<string, int> ourmap;
	
	// insert
	pair<string, int> p("abc", 1);
	ourmap.insert(p);
	ourmap["def"] = 2;

	// find or access
	cout << ourmap["abc"] << endl;
	cout << ourmap.at("abc") << endl;
	
	//cout << ourmap.at("ghi") << endl;
	cout << "size : " << ourmap.size() << endl;
  // find ghi - using sqaure bracket , if ghi is not present then then it will add it and give its key value
	cout << ourmap["ghi"] << endl; 
	cout << "size : " << ourmap.size() << endl;

	// check Presense
	if (ourmap.count("ghi") > 0) {
		cout << "ghi is present" << endl;
	}

	// erase
	ourmap.erase("ghi");
	cout << "size : " << ourmap.size() << endl;

  //In hashmap how many times key appears in hashmap
  //it is either 0 or 1
	if (ourmap.count("ghi") > 0) {
		cout << "ghi is present" << endl;
	}

}
