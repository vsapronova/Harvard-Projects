// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dictionary.h"

// Represents number of elements in a trie node
#define N 27

// Represents a node in a trie
typedef struct node
{
    bool is_word;;
    struct node *children[N];
}
node;

node *root;
int word_count = 0;

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    word_count = 0;
    root = malloc(sizeof(node));
    if (root == NULL)
    {
        return false;
    }

    for (int i = 0; i < N; i++)
    {
        root->children[i] = NULL;
    }
    // Open dictionary
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        fprintf(stderr, "Cound not open %s.\n", dictionary);
        return false;
    }

    node *trav = root;
    char word[LENGTH + 1];


    // Insert words into trie
    while (fscanf(file, "%s", word) != EOF)
    {
        for (int c = 0; c < strlen(word); c++)
        {
            char ch = word[c];

            int index;
            if (isalpha(ch))
            {
                index = tolower(ch)  - 'a';
            }
            else
            {
                index = 26;
            }
            if (trav->children[index] == NULL)
            {
                node *new_node;
                new_node = malloc(sizeof(node));
                for (int i = 0; i < N; i++)
                {
                    new_node->children[i] = NULL;
                }

                if (new_node == NULL)
                {
                    return false;
                }

                trav->children[index] = new_node;
            }
            trav = trav->children[index];
        }
        trav->is_word = true;
        // Reset trav
        trav = root;
        word_count++;
    }
    // Close dictionary
    fclose(file);

    // Indicate success
    return true;

}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return word_count;
}

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    node *trav = root;
    int len = strlen(word);

    for (int i = 0; i < len; i++)
    {
        char letter = tolower(word[i]);
        int index;

        if (letter == '\'')
        {
            index = 26;
        }
        else
        {
            index = letter - 'a';
        }

        if (trav->children[index] == NULL)
        {
            return false;
        }

        else
        {
            trav = trav->children[index];

        }
    }
    if (trav->is_word == true)
    {
        return true;
    }


    return false;

}

void killer(node *trav)
{
    for (int k = 0; k < N; k++)
    {
        if (trav->children[k] != NULL)
        {
            killer(trav->children[k]);
        }
    }
    free(trav);
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    killer(root);

    return true;
}
