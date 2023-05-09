class DynamicArray {
	int *data;
	int nextIndex;
	int capacity;			// total size

	public :

//calling constructor which will initialize the value
	DynamicArray() {
		data = new int[5];
		nextIndex = 0;
		capacity = 5;
	}

	DynamicArray(DynamicArray const &d) {
		//this -> data = d.data;		// Shallow copy
		
		// Deep copy - means creating new array
		this -> data = new int[d.capacity];
		for(int i = 0; i < d.nextIndex; i++) {
			this -> data[i] = d.data[i];
		}
		this -> nextIndex = d.nextIndex;
		this -> capacity = d.capacity;
	}

	void operator=(DynamicArray const &d) {
		this -> data = new int[d.capacity];
		for(int i = 0; i < d.nextIndex; i++) {
			this -> data[i] = d.data[i];
		}
		this -> nextIndex = d.nextIndex;
		this -> capacity = d.capacity;
	}


	void add(int element) {
		//adding the element to the array and then incrementing the indexof array . if nextIndex is equal to capacity
		// then making array size double of previous and copying arrays value.
		//
		if(nextIndex == capacity) {
			int *newData = new int[2 * capacity];
			for(int i = 0; i < capacity; i++) {
				newData[i] = data[i];
			}
			//delete data array and then assign newDataArray as data.
			delete [] data;
			data = newData;
			//Double the capacity
			capacity *= 2;
		}
		data[nextIndex] = element;
		nextIndex++;
	}

//passing the index and get the value for that index.
//making func const as here we are not changing any value and not working on this variable.
	int get(int i) const {
		if(i < nextIndex) {
			return data[i];
		}
		else {
			return -1;
		}
	}

//inserting index at particular element
	void add(int i, int element) {
			if(i < nextIndex) {
				data[i] = element;
			}
			else if(i == nextIndex) {
				add(element);
			}
			else {
				return;
			}
	}

	void print() const {
		for(int i = 0; i < nextIndex; i++) {
			cout << data[i] << " ";
		}
		cout << endl;
	}












};
