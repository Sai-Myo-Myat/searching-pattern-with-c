
#include "cstdio"
#include "stdio.h"


int calculateSizeOfArr(char arr[]);
bool searching_pattern(char expression[]);

int main() {
    char expression[100] ;

    printf("Enter word to find: ");
    scanf(" %[^\n]",&expression);
    puts(expression);
    printf("program start!!!!'\n");
    bool result = searching_pattern(expression);
        if (result == true) {
            printf("We found it!");
        }else   {
            printf("We can't found!");
        }

    return 0;
}

bool searching_pattern(char expression[]) {
    printf("searching start\n");
    FILE *fptr;

    fptr = fopen("text.txt", "r");
    bool isIt = false;
    int currentChar = fgetc(fptr);

    int sizeOfArray = calculateSizeOfArr(expression);

    int expressionFirstChar = expression[0];

    if (fptr != NULL){
        while (!feof(fptr)){
            if (currentChar == expressionFirstChar){
                for (int i = 1; i < sizeOfArray; ++i) {

                    currentChar = fgetc(fptr);
                    int expressionNextChar = expression[i];
                    if (expressionNextChar == currentChar){
                        isIt = true;
                    } else {
                        isIt = false;
                        break;
                    }
                }
            }
            currentChar = getc(fptr);
        }
    }else {
        printf("file not found!");
    }

    fclose(fptr);

    return  isIt;

}

int calculateSizeOfArr(char arr[]){
    int sizeOf = 0;
    while (arr[sizeOf] != '\0'){
        sizeOf++;
    }

    return sizeOf;
}
