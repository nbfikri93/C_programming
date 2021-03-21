/*1) Swap variable using pointer*/
/*2) Print array elements using pointer and find the length of string*/
/*3) Copy a string to another string and concatenate two string*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100 // Maximum array size

int main() {

    //1) Swap variable using pointer
    swapVariable();
    
    //2) Print array elements using pointer
    printArrayByPointer();
    
    //3) Copy a string to another string
    copyString();
    
    return 0;
}

void swapVariable()
{
    char a = 'B';
    char b = 'N';
    
    //Passing the addresses of a and b
    swap(&a, &b);
    
    //Printing the swapped values of a and b
    printf("\n1) Swap variable using pointer :");
    printf("\nFirst number  : %c", a);
    printf("\nSecond number : %c", b);
}

//Swap function to swap 2 variable
void swap(char *x, char *y) {
    char temp;
    //Copy the value of a to some temp variable
    temp = *x;
    
    //Copy the value of b to a
    *x = *y;
    
    //Copy the value of a stored in temp to b
    *y = temp;
}

void printArrayByPointer()
{
    char arr[MAX_SIZE] = "GitHub";
    char * ptr;
    int count = 0;
    
    ptr = arr; // initialize pointer to arr[0]
 
    printf("\n\n2) Print array elements using pointer :");
 
    printf("\nArray elements are : ");
    
    while (*ptr != '\0')
    {
        // Print value pointed by the pointer
        printf("%c ", *ptr);
        // Move pointer to next array element
        ptr++;
        count++;
    }
    
    printf("\nLength of string is : %d", count);
}

void copyString()
{
    char text1[MAX_SIZE], text2[MAX_SIZE], text3[MAX_SIZE], text4[MAX_SIZE] ;
    char * str1 = text1;
    char * str2 = text2;
    char * str3 = text3;
    char * str4 = text4;
    char * str5 = text1;
    char * str6 = text3;

    printf("\n\n3) Copy a string to another string :");

    // 1st method. Normal way of copying text1 to text 2 character by character
    // Inputting string from user
    printf("\nEnter any string: ");
    gets(text1);

    do
    {
        *(str2) = *(str1);
        str1++;
        str2++;        
    }while(*str2 != '\0');

    printf("\nFirst string = %s", text1);
    printf("\nSecond string = %s", text2);    

    // 2nd method. Simpler way to copy
    // Inputting string from user
    printf("\n\nEnter another string: ");
    gets(text3);
    
    while(*(str4++) = *(str3++));
 
    printf("\nFirst string = %s", text3);
    printf("\nSecond string = %s", text4);
 
    // String concatenation
    // Moving till the end of str2
    while(*(++str5));
 
    // Concatenate str2 to str4
    while(*(str5++) = *(str6++));
 
    printf("\n\nConcatenated string: %s", text1);
}
