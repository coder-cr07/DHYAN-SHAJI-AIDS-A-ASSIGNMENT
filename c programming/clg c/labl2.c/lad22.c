#include <stdio.h>


/* Function Declarations */
void readString(char str[]);

void removeNewline(char str[]);

int getLength(char str[]);

int findPattern(char str[], char pat[], int start);

int replacePattern(char str[], char pat[], char rep[], char result[]);

void displayResult(int flag, char result[]);

int main() {
    char str[200], pat[100], rep[100], result[300];
    int flag;

    printf("Enter the string: ");
    readString(str);

    printf("Enter the pattern: ");
    readString(pat);

    printf("Enter the replacement: ");
    readString(rep);

    flag= replacePattern(str, pat, rep, result);
    displayResult(flag,result);


    return 0;
}

/* Function to read string */
void readString(char str[]) {
    fgets(str, 200, stdin);
    removeNewline(str);

}

/* User-defined function to remove newline character */
void removeNewline(char str[]) {
    int i=0;
    while(str[i]!='\0'){
        if(str[i] == '\n'){
            str[i] = '\0';
            break;
        }
        i++;
    }

}

/* Function to find string length */
int getLength(char str[]) {
    int len = 0;
    while(str[len]!='\0')
        len ++;
    return len;

    


}

/* Function to check pattern match */
int findPattern(char str[], char pat[], int start) {
    int i,j;
     for(i=start, j=0;pat[j]!='\0';i++;j++){
        if(str[i!=pat[j]])
        return 0;
     }
     return 1;

}

/* Function to replace pattern */
int replacePattern(char str[], char pat[], char rep[], char result[]) {
    int i=0;j=0;k;
    int found=0;
    while(str[i]!='\0'){
        if(findPattern(str,pat,i)){
            found=1;
            for(k=0;rep[k]!='\0';k++){
                result[j]=rep[k];
                j++;
            }
        } else {
            result[j]=str[i];
            j++;
        }
        i=i+getLength(pat);
    }
    else{
        result[j]=str[i];
        i++;
        j++;
    }
    result[j]='\0';
    return found;

}

/* Function to display result */
void displayResult(int flag, char result[]) {

    if (flag == 0) 
        printf("Pattern does not exist");
    else 
        printf("The main string after replacement is:\n");
    printf("%s", result);
}