//file headers
#include <stdio.h>
#include <stdlib.h> //for system functions such as CLS
#include <conio.h> //for the getch() function
#include <time.h> //for the delay function

//functions
void initialize();
int rand();
void gameEz();
void gameAve();
void gameDiff();
void delay(unsigned nos);

//global declarations
int difficulty=0,randy=0,lucky=0,i,champion=0,instruction=0;
unsigned int scoreE=0,scoreA=0,scoreD=0; //scores for each difficulty
char key; //keypress variable
time_t t; //time

int main()
{
    //local declarations


    //beginning of Code
    Begin:
    system("cls");
    printf("Hi-Lo\n\n");
    printf("Press ENTER to Start");
    //this gets first keypress
    key = getch();
    //if the key press is ENTER it will start, and if not it will go to label Begin:
    if(key == 13)
    {
        if(instruction == 0)
        {
            system("cls");
            printf("Instructions:\n");
            printf("In Hi-Lo you will be shown a random initial number from 0 to 100 in easy, 0 to\n");
            printf("35 in average, and 0 to 10 in difficult. There will also be a random hidden number\n");
            printf("which will be compared to the initial number, you will guess if the hidden number is\n");
            printf("Higher or Lower than the initial number.\n\n");
            instruction++;
            printf("Press any key to Continue...");
            getch();
        }
        initialize();
    }
    else
    {
        goto Begin;
    }

    //game starts here
    system("cls");
    if(difficulty != 0)
    {
        if(difficulty == 1)
        {
            gameEz();
            goto Begin;
        }
        else if(difficulty == 2)
        {
            gameAve();
            goto Begin;
        }
        else if(difficulty == 3)
        {
            gameDiff();
            goto Begin;
        }
        else
        {   
            sww:
            printf("Something went wrong. Do you want to try again? Y/N");
            key = getch();
            switch(key)
            {
                case 'y':
                case 'Y':
                    goto Begin;
                    break;
                case 'n':
                case 'N':
                    goto Exit;
                    break;
                default:
                    goto sww;
                    break;
            }
        }
    }
    Exit:
    return 0;
}

void delay(unsigned nos)
{
    int mss = 1000 * nos;
    clock_t s_t = clock();
    while (clock() < s_t + mss);
} 

void initialize() //initialized the rand function and choosing the difficulty
{
    initfunct:
    system("cls");
    srand((unsigned) time(&t));
    printf("Choose a Difficulty");
    printf("\n1. Easy (0 - 100)");
    if(scoreE != 0)
    {
        printf("\n  Current score: %u" ,scoreE);
    }
    printf("\n2. Average (0 - 35)");
    if(scoreA != 0)
    {
        printf("\n  Current score: %u" ,scoreA);
    }
    printf("\n3. Difficult (0 - 10");
    if(scoreD != 0)
    {
        printf("\n  Current score: %u" ,scoreD);
    }
    
    key = getch();
    switch(key)
    {
        case '1':
            difficulty = 1;
            return;
            break;

        case '2':
            if(scoreE >= 100)
            {
                difficulty = 2;
                return;
            }
            else
            {
                system("cls");
                printf("You need to score at least 100 in Easy Difficulty");
                if(scoreE != 0)
                {
                    printf("\n\nCurrent score: %u" ,scoreE);
                }
                delay(1);
                getch();
                goto initfunct;
            }
            break;

        case '3':
            if(scoreA >= 50)
            {
                difficulty = 3;
                return;
            }
            else
            {
                system("cls");
                printf("You need to score at least 50 in Average Difficulty");
                if(scoreE != 0)
                {
                    printf("\n\nCurrent score: %u" ,scoreA);
                }
                delay(1);
                getch();
                goto initfunct;
            }
            break;

        default:
            initialize();
            break;
    }
}

void gameEz() //TODO:
{ 
    geasy:
    randy = rand()%100+1;
    for(i = 0;i < 3;i++) //Loading Screen
    {
        system("cls");
        printf("Loading");
        if(i == 0)
        {
            printf(".");
        }
        else if(i == 1)
        {
            printf("..");
        }
        else if(i == 2)
        {
            printf("...");
        }
        else
        {
            printf("");
        }
        delay(1);
    }
    lucky = rand()%100+1;
    system("cls");
    printf("The first number is %d\n\n" ,randy);
    printf("High (+) or Low (-)");
    if(scoreE != 0)
    {
        printf("\n\nCurrent Score: %u" ,scoreE);
    }
    key = getch();
    switch(key)
    {
        case '+': //Case Plus
            if(lucky > randy)
            {
                system("cls");  
                printf("Correct! The number is %d" ,lucky);
                if(scoreE != 0)
                {
                    scoreE *= 4;
                }
                else
                {
                    scoreE++;
                }
                conteasywinadd: 
                printf("\nCurrent Score: %u" ,scoreE);
                printf("\nContinue? Y/N");
                key = getch();
                switch(key)
                {
                    case 'y':
                    case 'Y':
                        goto geasy;
                        break;
                    case 'n':
                    case 'N':
                        break;
                    default:
                        goto conteasywinadd;
                        break;
                }
                return;
            }
            else if(lucky < randy)
            {
                system("cls");
                printf("Wrong! The number is %d, you lose half of your score" ,lucky);
                scoreE /= 2;
                conteasyloseadd:
                printf("\nTry Again? Y/N");
                key = getch();
                switch(key)
                {
                    case 'y':
                    case 'Y':
                        goto geasy;
                        break;
                    case 'n':
                    case 'N':
                        break;
                    default:
                        goto conteasyloseadd;
                        break;
                }
                return;
            }
            else
            {
                system("cls");
                goto geasy;
            }
            break;

        case '-': //Case Minus
        {
            if(lucky < randy)
            {
                system("cls");  
                printf("Correct! The number is %d" ,lucky);
                if(scoreE != 0)
                {
                    scoreE *= 4;
                }
                else
                {
                    scoreE++;
                }
                conteasywinsub: 
                printf("\nCurrent Score: %u" ,scoreE);
                printf("\nContinue? Y/N");
                key = getch();
                switch(key)
                {
                    case 'y':
                    case 'Y':
                        goto geasy;
                        break;
                    case 'n':
                    case 'N':
                        break;
                    default:
                        goto conteasywinsub;
                        break;
                }
                return;
            }
            else if(lucky > randy)
            {
                system("cls");
                printf("Wrong! The number is %d, you lose half of your score" ,lucky);
                scoreE /= 2;
                conteasylosesub:
                printf("\nTry Again? Y/N");
                key = getch();
                switch(key)
                {
                    case 'y':
                    case 'Y':
                        goto geasy;
                        break;
                    case 'n':
                    case 'N':
                        break;
                    default:
                        goto conteasylosesub;
                        break;
                }
                return;
            }
            else
            {
                system("cls");
                goto geasy;
            }
        }
            break;

        default:
            goto geasy;
            break;
    }
}

void gameAve() //TODO:
{ 
    gaverage:
    randy = rand()%35+1;
    for(i = 0;i < 3;i++)
    {
        system("cls");
        printf("Loading");
        if(i == 0)
        {
            printf(".");
        }
        else if(i == 1)
        {
            printf("..");
        }
        else if(i == 2)
        {
            printf("...");
        }
        else
        {
            printf("");
        }
        delay(1);
    }
    lucky = rand()%35+1;
    system("cls");
    printf("The first number is %d\n\n" ,randy);
    printf("High (+) or Low (-)");
    if(scoreA != 0)
    {
        printf("\n\nCurrent Score: %u" ,scoreA);
    }
    key = getch();
    switch(key)
    {
        case '+': //Case Plus
            if(lucky > randy)
            {
                system("cls");  
                printf("Correct! The number is %d" ,lucky);
                if(scoreA != 0)
                {
                    scoreA *= 3;
                }
                else
                {
                    scoreA++;
                }
                contavewinadd: 
                printf("\nCurrent Score: %u" ,scoreA);
                printf("\nContinue? Y/N");
                key = getch();
                switch(key)
                {
                    case 'y':
                    case 'Y':
                        goto gaverage;
                        break;
                    case 'n':
                    case 'N':
                        break;
                    default:
                        goto contavewinadd;
                        break;
                }
                return;
            }
            else if(lucky < randy)
            {
                system("cls");
                printf("Wrong! The number is %d, you lose half of your score" ,lucky);
                scoreA /= 2;
                contaveloseadd:
                printf("\nTry Again? Y/N");
                key = getch();
                switch(key)
                {
                    case 'y':
                    case 'Y':
                        goto gaverage;
                        break;
                    case 'n':
                    case 'N':
                        break;
                    default:
                        goto contaveloseadd;
                        break;
                }
                return;
            }
            else
            {
                system("cls");
                goto gaverage;
            }
            break;

        case '-': //Case Minus
        {
            if(lucky < randy)
            {
                system("cls");  
                printf("Correct! The number is %d" ,lucky);
                if(scoreA != 0)
                {
                    scoreA *= 3;
                }
                else
                {
                    scoreA++;
                }
                contavewinsub: 
                printf("\nCurrent Score: %u" ,scoreA);
                printf("\nContinue? Y/N");
                key = getch();
                switch(key)
                {
                    case 'y':
                    case 'Y':
                        goto gaverage;
                        break;
                    case 'n':
                    case 'N':
                        break;
                    default:
                        goto contavewinsub;
                        break;
                }
                return;
            }
            else if(lucky > randy)
            {
                system("cls");
                printf("Wrong! The number is %d, you lose half of your score" ,lucky);
                scoreA /= 2;
                contavelosesub:
                printf("\nTry Again? Y/N");
                key = getch();
                switch(key)
                {
                    case 'y':
                    case 'Y':
                        goto gaverage;
                        break;
                    case 'n':
                    case 'N':
                        break;
                    default:
                        goto contavelosesub;
                        break;
                }
                return;
            }
            else
            {
                system("cls");
                goto gaverage;
            }
        }
            break;

        default:
            goto gaverage;
            break;
    }
}

void gameDiff() //TODO:
{ 
    gdifficult:
    if(scoreD >= 10)
    {
        for(int i = 0; i < 100; i++)
        {
            system("cls");
            printf("YOU ARE THE CHAMPION OF HI-LO!!!\n\n\nYou get this free timer from 100 to 0. Enjoy!\n\n");
            printf("%d" ,100-i);
            delay(1);
        }
        return; 
    }


    randy = rand()%10+1;
    for(i = 0;i < 3;i++)
    {
        system("cls");
        printf("Loading");
        if(i == 0)
        {
            printf(".");
        }
        else if(i == 1)
        {
            printf("..");
        }
        else if(i == 2)
        {
            printf("...");
        }
        else
        {
            printf("");
        }
        delay(1);
    }
    lucky = rand()%10+1;
    system("cls");
    printf("The first number is %d\n\n" ,randy);
    printf("High (+) or Low (-)");
    if(scoreD != 0)
    {
        printf("\n\nCurrent Score: %u" ,scoreD);
    }
    key = getch();
    switch(key)
    {
        case '+': //Case Plus
            if(lucky > randy)
            {
                system("cls");  
                printf("Correct! The number is %d" ,lucky);
                if(scoreD != 0)
                {
                    scoreD *= 2;
                }
                else
                {
                    scoreD++;
                }
                contdiffwinadd: 
                printf("\nCurrent Score: %u" ,scoreD);
                printf("\nContinue? Y/N");
                key = getch();
                switch(key)
                {
                    case 'y':
                    case 'Y':
                        goto gdifficult;
                        break;
                    case 'n':
                    case 'N':
                        break;
                    default:
                        goto contdiffwinadd;
                        break;
                }
                return;
            }
            else if(lucky < randy)
            {
                system("cls");
                printf("Wrong! The number is %d, you lose half of your score" ,lucky);
                scoreD /= 2;
                contdiffloseadd:
                printf("\nTry Again? Y/N");
                key = getch();
                switch(key)
                {
                    case 'y':
                    case 'Y':
                        goto gdifficult;
                        break;
                    case 'n':
                    case 'N':
                        break;
                    default:
                        goto contdiffloseadd;
                        break;
                }
                return;
            }
            else
            {
                system("cls");
                goto gdifficult;
            }
            break;

        case '-': //Case Minus
        {
            if(lucky < randy)
            {
                system("cls");  
                printf("Correct! The number is %d" ,lucky);
                if(scoreD != 0)
                {
                    scoreD *= 2;
                }
                else
                {
                    scoreD++;
                }
                contdiffwinsub: 
                printf("\nCurrent Score: %u" ,scoreD);
                printf("\nContinue? Y/N");
                key = getch();
                switch(key)
                {
                    case 'y':
                    case 'Y':
                        goto gdifficult;
                        break;
                    case 'n':
                    case 'N':
                        break;
                    default:
                        goto contdiffwinsub;
                        break;
                }
                return;
            }
            else if(lucky > randy)
            {
                system("cls");
                printf("Wrong! The number is %d, you lose half of your score" ,lucky);
                scoreD /= 2;
                contdifflosesub:
                printf("\nTry Again? Y/N");
                key = getch();
                switch(key)
                {
                    case 'y':
                    case 'Y':
                        goto gdifficult;
                        break;
                    case 'n':
                    case 'N':
                        break;
                    default:
                        goto contdifflosesub;
                        break;
                }
                return;
            }
            else
            {
                system("cls");
                goto gdifficult;
            }
        }
            break;

        default:
            goto gdifficult;
            break;
    }
}