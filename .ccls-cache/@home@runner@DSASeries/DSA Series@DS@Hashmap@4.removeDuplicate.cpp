/*

APPROACH

unordered map takes O(1) times

1.There is an array containing duplicate element
2.Suppose an array a[] = {1,2,3,3,2,1,4,3,6,5,5};
3.Create a hashmap to mark an element as seen so later it can be avoided if again appear.
 and add it in output vector
4.If an element is already seen then skip the part.


 */








#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> removeDuplicates(int* a, int size) {
  //create output vector to store elements
	vector<int> output;
  //create hashmap seen to mark element
	unordered_map<int, bool> seen;
  //Traverse each element in an array , check  count of key
  //count is used to check the presence of key
  //if count is greater than 0 it means key is appeared again and no need to add it in output vector
  //make hashmap seen[key] as true and add it to output vector if key appear for the 1st time.
	for (int i = 0; i < size; i++) {
		if (seen.count(a[i]) > 0) {
			continue;
		}
		seen[a[i]] = true;
		output.push_back(a[i]);
	}
	return output;
}

int main() {
	int a[] = {1,2,3,3,2,1,4,3,6,5,5};
	vector<int> output = removeDuplicates(a, 11);
	for (int i = 0; i < output.size(); i++) {
		cout << output[i] << endl;
	}
}
