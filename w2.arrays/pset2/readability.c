//Definitely not the best implementation, and style50 made this look ugly, but it's whatever.

#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void)
{
    string text = get_string("Text: ");
    string output = "";

    double letter = 0; // amt of letters in inputted text
    double word = 0; // amt of words in inputted text
    double sentence = 0; //amt of sentences in putted text


    double L = 0; //avg amt of letters per 100 words
    double S = 0; //avg amt of sentences per 100 words


    for (int i = 0; i < strlen(text); i++) 
    {

        if (text[i] >= 65 && text[i] <= 122) //Evaluating if current character is between the ASCII ranges of letters, indicating a letter.
        {
            letter++;
        }
        
        else if (text[i] == 32 && (text[i - 1] != 33 && text[i - 1] != 46 
                                   && text[i - 1] != 63)) //Evaluating if current character has a space, which indicates a new word.
        {
            word++;
        }        
        
        else if (text[i] == 33 || text[i] == 63 
                 || text[i] == 46) //Evaluating if current character is an end of a sentence by looking for the three end of punctuation marks.
        {
            sentence++;
            word++;
        }
    }

    L = (letter / word) * 100;
    S = (sentence / word) * 100;

    double index = round(0.0588 * L - 0.296 * S - 15.8); // Uses Coleman-Liau index to determine grade level.

    if (index < 1) //Applying output.
    {
        output = "Before Grade 1";
    }
    else if (index > 16)
    {
        output = "Grade 16+";
    }


    /*Here are the outputs you should use when developing the program.
    printf("\n%f letter(s)", letter);
    printf("\n%f word(s)", word);
    printf("\n%f sentence(s)", sentence);*/

    if (index <= 16 && index > 1)
    {
        printf("Grade %i\n", (int) index); // Prints grade level of inputted text.

    }
    else
    {
        printf("%s\n", output); //Otherwise, gives standard output.
    }
}
