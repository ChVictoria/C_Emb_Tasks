#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 1

int inputStr(unsigned char * buffer, unsigned int initial_size) {
    unsigned int size_n = initial_size;

    if (buffer != NULL){
        int nextChar = EOF;
        unsigned int i = 0;
        while (( nextChar = getchar() ) != '\n' && nextChar != EOF)
        {
            buffer[i++]=(char)nextChar;

            if(i == size_n)
            {
                size_n ++;
                buffer = realloc(buffer, size_n*sizeof(unsigned char));
            }
        }

        buffer[i] = '\0';
        return size_n-1;
    }
    printf("Can't allocate memory!\n");
    return -1;
}

void reverseString(unsigned char * buffer, int size){
    for(int i=0; i<size/2; i++){
        unsigned char t = buffer[i];
        buffer[i] = buffer[size-1-i];
        buffer[size-1-i] = t;
    }
}
void printString(unsigned char * buffer, int size){
    for(int i=0; i<size; i++){
        printf("%c", buffer[i]);
    }
}
int main(){
    unsigned char * userStr = NULL;
    userStr = (unsigned char*)malloc(MAX_SIZE*sizeof(unsigned char));

    printf("Input a string:");
    int size = inputStr(userStr, MAX_SIZE);

    reverseString(userStr, size);
    printf("Reversed string:");
    printString(userStr, size);

    free(userStr);
    userStr  = NULL;
    return 0;
}

