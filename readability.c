#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    // print "Text: " then get string and assign it to a string variable; new line
    string text = get_string("Text: ");
    
    // initialise letter count int variable (= 0)
    int letters = 0;
    
    // initialise word count int variable (= 0)
    int words = 0;
    
    // initialise sentence count int variable (= 0)
    int sentences = 0;
    
    // loop over string and for each character while the character does not equal '\0': if it's a-z or A-Z increment the letters count, elsif it's a space increment the word count, elsif it's a period, exclamation mark or question mark increment the sentence count
    for (int i = 0; text[i] != '\0'; i++)
    {
        if ((text[i] >= 65 && text[i] <= 90) || (text[i] >= 97 && text[i] <= 122)) // 65, 90, 97, 122 == A, Z, a, z
        {
            letters++;
        }
        else if (text[i] == 32) // 32 == space
        {
            words++;
        }
        else if (text[i] == 46 || text[i] == 33 || text[i] == 63) // 46, 33, 63 == ., !, ?
        {
            sentences++;
        }
    }
    
    // if the word count > 0, increment it by one (number of spaces is one less than number of words
    // if word count > 1, word count++
    if (words > 0)
    {
        words++;
    }
    
    // calculate average number of letters per 100 words and assign the result to float variable L
    // (float) letters / (float) words * 100
    float l = (float) letters / (float) words * 100;
    
    // calculate average number of sentences per 100 words and assign the result to float variable S
    // (float) sentences / (float) words * 100
    float s = (float) sentences / (float) words * 100;
    
    // calculate Coleman-Liau index, round it and assign the result to int variable grade
    int grade = round(0.0588 * l - 0.296 * s - 15.8);
    
    // if grade is < 1 puts "Before Grade 1\n", elsif grade is >=16 puts "Grade 16+\n", else puts "Grade %i\n", grade
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
    
}