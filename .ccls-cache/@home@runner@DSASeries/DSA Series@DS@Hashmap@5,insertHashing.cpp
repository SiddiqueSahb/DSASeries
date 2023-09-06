#include <string>
using namespace std;

template <typename V>
class MapNode {
  //NODE WILL CONTAIN KEY , VALUE OF TYPE V AND NODE WILL HAVE POINTER TO NEXT NODE
	public:
		string key;
		V value;
		MapNode* next;

		MapNode(string key, V value) {
			this->key = key;
			this->value = value;
			next = NULL;
		}

		~MapNode() {
			delete next;
		}
};

template <typename V>
class ourmap {
  //CREATING BUCKET WHICH WILL STORE ADDRESS OF NODE OF TYPE V
	MapNode<V>** buckets;
	int count;
	int numBuckets;

	public:
	ourmap() {
		count = 0;
		numBuckets = 5;
		buckets = new MapNode<V>*[numBuckets];
    
		for (int i = 0; i < numBuckets; i++) {
			buckets[i] = NULL;
		}
	}

 //BEFORE DESTRUCTING BUCKET DESTRUCT EACH LINKLIST THEN BUCKET
	~ourmap() {
		for (int i = 0; i < numBuckets; i++) {
			delete buckets[i];
		}
		delete [] buckets;
	}

	int size() {
		return count;
	}

	V getValue(string key) {
		int bucketIndex = getBucketIndex(string key);
		MapNode<V>* head = buckets[bucketIndex];
		while (head != NULL) {
			if (head->key == key) {
				return head->value;
			}
			head = head->next;
		}
		return 0;
	}

	private:
  //
	int getBucketIndex(string key) {
		int hashCode = 0;
     
		int currentCoeff = 1;//(P^0 = 1)
    // "ABC" = [(A*P^2)%NO OF BUCKETS + (B*P^1)%NO OF BUCKETS]%NO OF BUCKETS +  (C*P^0)%NO OF BUCKETS (P IS PRIME NO)
    // 1ST LOOP DOING C*P^0   AS IT CAN GO BEYOND RANGE SO PERFORMING MODULO OPERATION
		for (int i = key.length() - 1; i >= 0; i--) {
			hashCode += key[i] * currentCoeff;
			hashCode = hashCode % numBuckets;
			currentCoeff *= 37;
			currentCoeff = currentCoeff % numBuckets;
		}
      
		return hashCode % numBuckets;//[]%NO OF BUCKETS
	}

	public:
 // BEFORE INSERTING KEY WILL GO TO HASH FUNCTION THEN IT WILL GIVE BUCKETINDEX
 //IN THAT BUCKET INDEX KEY WILL BE INSERTED
	void insert(string key, V value) {
		int bucketIndex = getBucketIndex(string key);

    //GETTING HEAD OF PARTICULAR BUCKET
		MapNode<V>* head = buckets[bucketIndex];
    //TRAVERSING FROM HEAD TILL THE END OF LIST
    //IF KEY THAT WE WANT TO INSERT IS ALREADY PRESENT IN THE LIST THEN REPLACING THAT KEY
    //WITH OLD ONE NOT CREATING NEW NODE
		while (head != NULL) {
			if (head->key == key) {
				head->value = value;
				return;
			}
			head = head->next;
		}
    // IF KEY IS NOT PRESENT ALREADY IN THE BUCKET THEN CREATING NEW NODE
    // AND INSERTING HEAD IN NEW NODE NEXT
		head = buckets[bucketIndex];
		MapNode<V>* newNode = new MapNode<V>(key, value);
		newNode->next = head;
    //bucket will contain address of newNode rather than previous Node
		buckets[bucketIndex] = newNode;
    //each time creating newNode doing count++ to get the total no of nodes
		count++;

    double loadfactor = (1.0 * count)/numBuckets;
    if(loadfactor > 0.7){
      rehash();
    }
	}


V remove(string key) {

  //FINDING BUCKEET INDEX TO GET THE BUCKET
		int bucketIndex = getBucketIndex(string key);
		MapNode<V>* head = buckets[bucketIndex];
    //PREV IS USED TO STAND JUST BEFORE THE NODE TO BE DELETED
		MapNode<V>* prev = NULL;
		while (head != NULL) {
			if (head->key == key) {
        //IF FIRST NODE OF THE BUCKET IS THE KEY THEN REPLACE BUCKET ADDRESS WITH THE ADDRESS OF NEXT NODE
				if (prev == NULL) {
					buckets[bucketIndex] = head->next;
				} else {
					prev->next = head->next;
				}
        //BEFORE DELETING ,GET THE VALUE , MAKE ITS NEXT NULL AS IT SHOULDNT POINT TO OTHER NODE
				V value = head->value;
				head->next = NULL;
				delete head;
				count--;
				return value;
			}
			prev = head;
			head = head->next;
		}
  // IF NODE TO BE DELETED IS NOT PRESENT
		return 0;
	}


  //rehas is done when the load factor is greater than 0.7
  void rehash() {
    //creatin temp array which will store address
    MapNode<V>** temp = buckets;
    //creating a bucket twice the size of previous bucket
    buckets = new MapNode<V>*[2*numBuckets];
    // bucket is initialized to NULL
    for(int i = 0;i< 2*numBuckets;i++){
      buckets[i] = NULL;
    }

    int oldbucketCount = numBuckets;
    numBuckets*=2;
    count = 0;

    //In old bucket ,going to each buckets head and traversing till the end of LL starting from the head
    //each each element starting from respective buckets head will be inserted to new Bucket
    for(int i = 0;i< oldbucketCount;i++){
      MapNode<V>* head = temp[i];
      while(head!=NULL){
        string key = head-key;
        V value = head->value;
        insert(key, value);
        head = head->next;
      }

      //deleting each pointer first from the bucket then deleting complete array 
      for(int i = 0;i<oldbucketCount;i++){
        MapNode<V>* head = temp;
        delete head;
      }
      delete [] temp;
    }
  }

};