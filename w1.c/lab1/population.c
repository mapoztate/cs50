#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int startPop = 0;
    
    while (startPop < 9) 
    {
        startPop = get_int("Start size: ");
    }

    // TODO: Prompt for end size
    int endPop = 0;
    
    while (endPop < startPop)
    {
        endPop = get_int("End size: ");
    }

    // TODO: Calculate number of years until we reach threshold
    int counter = 0;
    
    while (startPop < endPop)
    {
        int born = startPop / 3;
        int dead = startPop / 4;
        startPop += born - dead;
        counter++;
    }


    // TODO: Print number of years
    
    printf("Years: %i\n", counter);
}
