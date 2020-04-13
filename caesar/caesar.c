#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{   
    if (argc < 2 || argc > 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    string s = argv[1];
    for (int i = 0; i < strlen(s); i++)
    {
        if (!isdigit(s[i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    
    if (argc == 2)
    {
        int key = atoi(argv[1]);
        string str = get_string("plaintext: ");
        int result;
        printf("ciphertext: ");
        //Iterates over the user's input, checking for the case of each char.
        for (int i = 0, n = strlen(str); i < n; i++)
        {   //Will store the chars + key. 
            if (str[i] >= 'a' && str[i] <= 'z')
            {
                result = (((str[i] - 'a') + key) % 26 + 'a'); 
            }         
            else if (str[i] >= 'A' && str[i] <= 'Z')
            {
                result = (((str[i] - 'A') + key) % 26 + 'A');
            }  
            else
            {
                result = str[i];
            }
            printf("%c", result);
        }   
    }  
    printf("\n");
    return 0;
}

