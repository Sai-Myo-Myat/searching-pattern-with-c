
#include "stdio.h"


int calculateSizeOfArr(char arr[]);
void searching_pattern(char expression[]);

int main() {
    char expression[100] ;

    printf("Enter word to find: ");
    scanf(" %[^\n]",&expression);
    printf("prgram start!!!!");
    searching_pattern(expression);

    printf("finished");

    return 0;
}

void searching_pattern(char expression[]) {
    printf("searching start");
    FILE *fptr;
    int sizeOfArray = calculateSizeOfArr(expression);
    char currentChar = fgetc(fptr);
    while (!feof(fptr)){

        if (currentChar == expression[0]){
            for (int i = 0; i < sizeOfArray; ++i) {
                char nextChar = fgetc(fptr);
                if (expression[i] == nextChar){
                    printf("fond it");
                }else {
                    printf("word not found");
                }
            }
        }
        fgetc(fptr);
    }
    fclose(fptr);
}

int calculateSizeOfArr(char arr[]){
    int sizeOf = 0;
    if (arr[sizeOf] != '\0'){
        sizeOf++;
    }

    return sizeOf;
}
