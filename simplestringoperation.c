/*1) Check if character in the string is repeated twice consecutively*/
/*2) Check the frequency of the character in the string*/

#include <stdio.h>

int main() {

    char str[100] ="engineering";
    int i,j = 1;
    int cnt;
    int frequency[100];
    int size;
    
    size = strlen(str);
    
    for(i=0; i<size; i++)
    {
        //Initially initialize frequency variable to -1
        frequency[i] = -1;
    }
    
    for(i = 0; i<size; i++)
    {
        cnt = 1;
        
        // Check if character is repeated twice consecutively 
        if(str[i] == str[i+1])
        {
            printf("\n%c is repeated twice consecutively\n",str[i]);
        }
        
        // Check the frequency of the character in the string    
        for(j = i+1; j<size; j++)
        {
            if (str[i] == str[j])
            {
                cnt++;
                
                //skip counting next element & avoid printing the duplicate
                frequency[j] = 0;
            }
        }
        
        if(frequency[i] != 0)
        {
            frequency[i] = cnt;
        }         
    }
    
    for(i = 0; i<size; i++)
    {
        if(frequency[i] != 0)
        {
            printf("\n%c occurs %d times\n", str[i], frequency[i]);            
        }    
    }
    
    return 0;
}
