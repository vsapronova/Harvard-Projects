#include <cs50.h>
#include <stdio.h>

int get_height(void);
void built(int height);
void print_repeat(string str, int count);

int main(void)
{
    int height = get_height();
    built(height);
}

int get_height(void)
{
    int height = 0;
    while (height < 1 || height > 8)
    {
        height = get_int("Height: ");
    } 
    printf("%i\n", height);
    return height;
}

void built(int height)
{
    for (int i = 1; i < height + 1; i++)
    {
        print_repeat(" ", height - i);
        print_repeat("#", i);
        printf("  ");
        print_repeat("#", i);
        print_repeat(" ", height - i);
        printf("\n");
    }  
}

void print_repeat(string str, int count)
{
    for (int j = 0; j < count; j++)
    {
        printf("%s", str);
    }
}
