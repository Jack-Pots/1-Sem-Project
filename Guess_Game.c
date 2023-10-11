#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    const int min = 1;
    const int max = 100;
    int guess;
    int guesses = 0;                // Gave Value as zero, so that it does not give a random memory number.
    int answer;

    srand(time(0));

    answer = (rand() % max) + min;

    do
    {
        printf("Enter a Guess: ");
        scanf("%d", &guess);
        if(guess > answer)
        {
            printf("Too High!\n");
        }
        else if(guess < answer)
        {
            printf("Too Low!\n");
        }
        else{
            printf("Correct!\n");
        }
        
        guesses++;
    } while (guess != answer);

    printf("********************\n");
    printf("Answer:  %d\n", answer);
    printf("Guesses: %d\n", guesses);
    printf("********************");

    return 0;
}
