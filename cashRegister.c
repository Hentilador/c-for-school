//file headers
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


//functions


//global declarations
char key;
int intPay;
float cart,VAT,PAY,change;
//Fruits
float const bananas=20.00,apples=30.00,melons=100.00,grapes=50.00,oranges=40.00,strawberries=60.00;
//Vegetables
float const cauliflower=40.00,broccoli=70.00,carrots=50.00,beans=15.00,potatoes=40.00,celery=30.00;
//Meats
float const chicken=80.00,pork=110.00,rabbit=50.00,fish=40.00,beef=140.00,veal=130.00;
//Canned Goods
float const vienna=50,porkbeans=30,corned=45,tuna=30,meatloaf=140,sardines=25;
//Condiments
float const salt=5,pepper=10,soy=30,vinegar=30,oyster=45,patis=20;
//Beverages
float const mtndew=25,sparkle=35,cola=25,nestea=30,sprite=25,monster=110;

int main()
{
    //local declarations
    int PIN=1234,PINput,PUK=0;

    //beginning of Code
    BEGIN:
    system("cls");
    printf("Cash Register System v0.0.1");
    printf("\n\n");
    printf("Enter the 4 digit PIN: ");
    scanf("%d" ,&PINput);
    if(PUK != 3)
    {
        if(PINput != PIN)
        {
            printf("\n\nThe PIN you entered is wrong, you have %d tries left" ,3-PUK);
            PUK++;
            getch();
            goto BEGIN;
        }
    }
    else if(PUK == 3)
    {
        system("cls");
        return 0;
    }
    MENU: //TEST:MENU
    system("cls");
    printf("Cast Register System v0.0.1");
    printf("\n\n");
    if(cart != 0)
    {
        printf("Total = P %.2f\n" ,cart);
    }
    printf("1. Fruits\n2. Vegetables\n3. Meats\n4. Canned Goods\n5. Condiments\n6. Beverages\n\nPress . to reset cart\nPress ENTER when finished");
    key = getch();
    switch (key)
    {
    case '1':
        goto FRUITS;
        break;

    case '2':
        goto VEGS;
        break;

    case '3':
        goto MEATS;
        break;

    case '4':
        goto CANS;
        break;

    case '5':
        goto CONDS;
        break;

    case '6':
        goto BEVS;
        break;

    case '.':
        cart = 0;
        goto MENU;
        break;

    case 13:
        goto CASHOUT;
        break;

    default:
        goto MENU;
        break;
    }

    FRUITS://TEST:FRUITS
    system("cls");
    printf("Cast Register System v0.0.1");
    printf("\n\n");
    if(cart != 0)
    {
        printf("Total = P %.2f\n" ,cart);
    }
    printf("1. Bananas - P 20\n2. Apples - P 30\n3. Melons - P 100\n4. Grapes - P 50\n5. Oranges - P 40\n6. Strawberries - P 60\n\nPress 0 to return\nPress . to reset cart\nPress ENTER when finished");
    key = getch();
    switch(key)
    {
    case '1':
        cart += bananas;
        goto FRUITS;
        break;

    case '2':
        cart += apples;
        goto FRUITS;
        break;

    case '3':
        cart += melons;
        goto FRUITS;
        break;

    case '4':
        cart += grapes;
        goto FRUITS;
        break;

    case '5':
        cart += oranges;
        goto FRUITS;
        break;

    case '6':
        cart += strawberries;
        goto FRUITS;
        break;

    case '0':
        goto MENU;
        break;

    case '.':
        cart = 0;
        goto FRUITS;
        break;
    
    case 13:
        goto CASHOUT;
        break;

    default:
        goto FRUITS;
        break;
    }
    
    VEGS://TEST:VEGS
    system("cls");
    printf("Cast Register System v0.0.1");
    printf("\n\n");
    if(cart != 0)
    {
        printf("Total = P %.2f\n" ,cart);
    }
    printf("1. Cauliflower - P 40\n2. Broccoli - P 70\n3. Carrots - P 50\n4. Beans - P 15\n5. Potatoes - P 40\n6. Celery - P 30\n\nPress 0 to return\nPress . to reset cart\nPress ENTER when finished");
    key = getch();
    switch(key)
    {
    case '1':
        cart += cauliflower;
        goto VEGS;
        break;

    case '2':
        cart += broccoli;
        goto VEGS;
        break;

    case '3':
        cart += carrots;
        goto VEGS;
        break;

    case '4':
        cart += beans;
        goto VEGS;
        break;

    case '5':
        cart += potatoes;
        goto VEGS;
        break;

    case '6':
        cart += celery;
        goto VEGS;
        break;

    case '0':
        goto MENU;
        break;

    case '.':
        cart = 0;
        goto VEGS;
        break;

    case 13:
        goto CASHOUT;
        break;
        
    default:
        goto VEGS;
        break;
    }

    MEATS://TEST:MEATS
    system("cls");
    printf("Cast Register System v0.0.1");
    printf("\n\n");
    if(cart != 0)
    {
        printf("Total = P %.2f\n" ,cart);
    }
    printf("1. Chicken - P 80\n2. Pork - P 110\n3. Rabbit - P 50\n4. Fish - P 40\n5. Beef - P 140\n6. Veal - P 130\n\nPress 0 to return\nPress . to reset cart\nPress ENTER when finished");
    key = getch();
    switch(key)
    {
    case '1':
        cart += chicken;
        goto MEATS;
        break;

    case '2':
        cart += pork;
        goto MEATS;
        break;

    case '3':
        cart += rabbit;
        goto MEATS;
        break;

    case '4':
        cart += fish;
        goto MEATS;
        break;

    case '5':
        cart += beef;
        goto MEATS;
        break;

    case '6':
        cart += veal;
        goto MEATS;
        break;

    case '0':
        goto MENU;
        break;

    case '.':
        cart = 0;
        goto MEATS;
        break;

    case 13:
        goto CASHOUT;
        break;
        
    default:
        goto MEATS;
        break;
    }

    CANS://TEST:CANS
    system("cls");
    printf("Cast Register System v0.0.1");
    printf("\n\n");
    if(cart != 0)
    {
        printf("Total = P %.2f\n" ,cart);
    }
    printf("1. Vienna Sausage - P 50\n2. Pork and Beans - P 30\n3. Corned Beef - P 45\n4. Canned Tuna - P 30\n5. Meatloaf - P 140\n6. Sardines - P 25\n\nPress 0 to return\nPress . to reset cart\nPress ENTER when finished");
    key = getch();
    switch(key)
    {
    case '1':
        cart += vienna;
        goto CANS;
        break;

    case '2':
        cart += porkbeans;
        goto CANS;
        break;

    case '3':
        cart += corned;
        goto CANS;
        break;

    case '4':
        cart += tuna;
        goto CANS;
        break;

    case '5':
        cart += meatloaf;
        goto CANS;
        break;

    case '6':
        cart += sardines;
        goto CANS;
        break;

    case '0':
        goto MENU;
        break;

    case '.':
        cart = 0;
        goto CANS;
        break;

    case 13:
        goto CASHOUT;
        break;
        
    default:
        goto CANS;
        break;
    }

    CONDS://TEST:CONDS
    system("cls");
    printf("Cast Register System v0.0.1");
    printf("\n\n");
    if(cart != 0)
    {
        printf("Total = P %.2f\n" ,cart);
    }
    printf("1. Salt - P 5\n2. Pepper - P 10\n3. Soy Sauce - P 30\n4. Vinegar - P 30\n5. Oyster Sauce - P 45\n6. Patis - P 20\n\nPress 0 to return\nPress . to reset cart\nPress ENTER when finished");
    key = getch();
    switch(key)
    {
    case '1':
        cart += salt;
        goto CONDS;
        break;

    case '2':
        cart += pepper;
        goto CONDS;
        break;

    case '3':
        cart += soy;
        goto CONDS;
        break;

    case '4':
        cart += vinegar;
        goto CONDS;
        break;

    case '5':
        cart += oyster;
        goto CONDS;
        break;

    case '6':
        cart += patis;
        goto CONDS;
        break;

    case '0':
        goto MENU;
        break;

    case '.':
        cart = 0;
        goto CONDS;
        break;

    case 13:
        goto CASHOUT;
        break;
        
    default:
        goto CONDS;
        break;
    }

    BEVS://TEST:BEVS
    system("cls");
    printf("Cast Register System v0.0.1");
    printf("\n\n");
    if(cart != 0)
    {
        printf("Total = P %.2f\n" ,cart);
    }
    printf("1. Mountain Dew - P 25\n2. Sparkling Water - P 35\n3. Cola - P 25\n4. Nestea - P 30\n5. Sprite - P 25\n6. Monster - P 110\n\nPress 0 to return\nPress . to reset cart\nPress ENTER when finished");
    key = getch();
    switch(key)
    {
    case '1':
        cart += mtndew;
        goto BEVS;
        break;

    case '2':
        cart += sparkle;
        goto BEVS;
        break;

    case '3':
        cart += cola;
        goto BEVS;
        break;

    case '4':
        cart += nestea;
        goto BEVS;
        break;

    case '5':
        cart += sprite;
        goto BEVS;
        break;

    case '6':
        cart += monster;
        goto BEVS;
        break;

    case '0':
        goto MENU;
        break;

    case '.':
        cart = 0;
        goto BEVS;
        break;

    case 13:
        goto CASHOUT;
        break;
        
    default:
        goto BEVS;
        break;
    }

    CASHOUT:
    system("cls");
    printf("I received = ");
    scanf("%d" ,&intPay);
    PAY = (float)(intPay);
    system("cls");
    VAT = cart * .10;
    cart -= VAT;
    printf("Total = P %.2f\nVAT = P %.2f" ,cart,VAT);
    cart += VAT;
    printf("\n---------------------\n");
    printf("Sum Total = P %.2f\n" ,cart);
    printf("Paid = P %.2f" ,PAY);
    change = PAY - cart;
    printf("\n---------------------\n");
    if(PAY < cart)
    {
        system("cls");
        printf("Not enough");
        getch();
        goto CASHOUT;
    }
    if(change != 0)
    {
        printf("Change = P %.2f" ,change);
    }
    getch();
    return 0;
}