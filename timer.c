//file headers
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

/*information
    Pointers
*/


//global declarations
int hr=0,min=0,sec=0;

//functions
void displayTime(int time);
int updateTime(int incDec,int category, int time);
void timer();
void delay();

int main(){
    //local declarations
    int *time[]={&hr,&min,&sec};
    int category=0;
    int incDec=0;
    int start=0;
    char key;

    //beginning of Code
    begin:
    system("cls");

    printf("Instructions:\nA and D keys to switch between hours, minutes, and seconds\n");
    printf("W and S keys to increment or decrement time\nPress ENTER to start\n\n\t");

    displayTime(hr);
    printf(":");
    displayTime(min);
    printf(":");
    displayTime(sec);
    switch(category){
        case 0:
            printf("\n\t ^");
            break;
        case 1:
            printf("\n\t    ^");
            break;
        case 2:
            printf("\n\t       ^");
            break;
        default:
            break;
    }

    key = getch();
    switch(key){
        case 'w':
        case 'W':
            incDec=0;
            *time[category]=updateTime(incDec,category,*time[category]);
            break;
        case 's':
        case 'S':
            incDec=1;
            *time[category]=updateTime(incDec,category,*time[category]);
            break;
        case 'a':
        case 'A':
            if(category==0){
                category = 2;
            }
            else{
                category--;
            }
            break;
        case 'd':
        case 'D':
            if(category==2){
                category = 0;
            }
            else{
                category++;
            }
            break;
        case 13:
            timer();
            break;
        default:
            break;
    }
    goto begin;
}

void displayTime(int time){
    if(time==0){
        printf("00");
    }
    else if(time<10){
        printf("0%d" ,time);
    }
    else{
        printf("%d" ,time);
    }
}

int updateTime(int incDec,int category, int time){
    if(incDec==0){
        if(category!=0 && time>=59){
            time = 0;
        }
        else{
            time++;
        }
        return time;
    }
    else if(incDec==1){
        if(category!=0 && time<=0){
            time = 59;
        }
        else{
            if(time<=0){
                time = 0;
            }
            else{
                time--;
            }
        }
        return time;
    }
}

void timer(){
    unsigned int hrToSec,minToSec,totalTime;
    hrToSec = hr * 3600;
    minToSec = min * 60;
    totalTime = hrToSec + minToSec + sec;
    begin:
    while(totalTime!=0){
        system("cls");
        printf("Timer has started!\n\n\t");

        displayTime(hr);
        printf(":");
        displayTime(min);
        printf(":");
        displayTime(sec);

        if(sec!=0){
            sec--;
        }
        else{
            sec = 59;
            if(min!=0){
                min--;
            }
            else{
                min = 59;
                if(hr!=0){
                    hr--;
                }
            }
        }
        totalTime--;
        delay(1);
    }
    system("cls");
    printf("Timer Finished!");
    Beep(600,3000);
    printf(" Press any key to set another timer.");
    hr = 0;
    min = 0;
    sec = 0;
    getch();
}

void delay(unsigned nos){
int mss = 1000 * nos;
clock_t s_t = clock();
while (clock() < s_t + mss);
}