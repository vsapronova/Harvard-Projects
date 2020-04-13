#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int shift(char c);
int main(int argc, string argv[])
{   
    if (argc != 2)
    {
        printf("Usage: ./caesar keyword\n");
        return 1;
    }
    string s = argv[1];
    for (int i = 0; i < strlen(s); i++)
    {
        if (!isalpha(s[i]))
        {
            printf("Usage: ./caesar keyword\n");
            return 1;
        }
    }

        int key = (int) argv[1];
        int key_value;
        string str = get_string("plaintext: ");
        int result;
        printf("ciphertext: ");
        //Iterates over the user's input, checking for the case of each char.
        for (int i = 0, j = 0, n = strlen(str); i < n; i++, j++)
        {   
            if (j >= strlen(argv[1]))
            {
                j = 0;
            }
            
            char key_c = argv[1][j];
            key_value = shift(key_c);

            if (str[i] >= 'a' && str[i] <= 'z')
            {
                result = (((str[i] - 'a') + key_value) % 26 + 'a'); 
            }         
            else if (str[i] >= 'A' && str[i] <= 'Z')
            {
                result = (((str[i] - 'A') + key_value) % 26 + 'A');
            }  
            else
            {
                result = str[i];
                j = (j - 1);
            }
            printf("%c", result);
        }
        printf("\n");
        return 0;
}  
    


int shift(char c)
{
    int keyword_num;
    int num_c = (int) c;
    if (c >= 'A' && c <= 'Z')
    {
        keyword_num = num_c - 'A';
    }
    else
    {
        keyword_num = num_c - 'a';
    }
    return keyword_num;
}

