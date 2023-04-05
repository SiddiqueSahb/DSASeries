
bool isPermutation(char input1[], char input2[]) {
    // Write your code here

    int count1[26] = {0};


    for(int i=0;input1[i]!='\0';i++){
        char ch = input1[i];
        int index = ch - 'a';
        count1[index]++;
    }

     for(int i=0;input2[i]!='\0';i++){
        char ch = input2[i];
        int index = ch - 'a';
        count1[index]--;
    }

    for(int i = 0;i<26;i++){
        if(count1[i] != 0){
            return false;
        }
    }
    return true;
}