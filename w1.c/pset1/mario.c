#include <cs50.h>
#include <stdio.h>

int main(void) 
{
    int height = -1;

    while (height <= 0 || height >= 9) // Evaluates if height is between 1 and 8 inclusive.
    {
        height = get_int("Height: ");
    }
    
    height--;
    
    for (int r = 0; r <= height; r++)  //Builds a left leaning tower based on first appearnce of a hash.
    {
        for (int c = 0; c <= height; c++) 
        {
            if (c >= height - r)
            {
                printf("#"); 
            } 
            else 
            {
                printf(" ");
            }
        }
        printf("\n");
    }

}
