void trimSpaces(char input[]) {
    // Write your code here
    int count = 0;
    int len = strlen(input);
    for(int i = 0; input[i]; i++){
        if(input[i] != ' '){
            input[count]=input[i];
            count++;
        }
    }
    input[count] = '\0';
}