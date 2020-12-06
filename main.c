#include <stdio.h>
#include "myBank.h"

int main()
{
    //setting variables:
    double m;
    printf("hello and Welcome to our bank\n");//open masseg
    int els = 0 , numa;
    char c='j';
    //starting
    while(c != 'E')
    {
        //menu:
        printf("Please choose a transaction type:\nO-Open Account\nB-Balance Inquiry\nD-Deposit\nW-Withdrawal\nC-Close Account\nI-Interest\nP-Print\nE-Exit\n");
        scanf("%c",&c);
        while(c == '\n' && (c = getchar()) == '\n'); //empty the buffer if c == \n
        els=0;
        if(c == 'O')
        {
            printf("Please enter amount for deposit\n");
            double j = m;
            scanf("%lf",&m);
            if(j != m){
                O(m);
                m = 0;
            } 
            else printf("Failed to read the amount\n"); c=getchar();
            els=1;
        }
        if(c == 'B')
        {
            printf("Please enter account number to see your balance\n");
            scanf("%d",&numa);
            if(numa>900 && numa <951) B(numa);
            else printf("Failed to read the account numer\n") ;c=getchar();//if numa is char or number illigul
            els=1;
        }
        if(c=='D')
        {
            printf("Please enter account number:\n");
            numa=0;
            scanf("%d",&numa);
            if( numa < 951 && numa > 900){
                printf("Add money to your acount\n");
                scanf("%lf",&m);
                D(numa , m);
            }
            else printf("Failed to read the account number\n");c=getchar();//not legal account number
           
            els=1;
        }
        if (c == 'W')
        {
            printf("Please enter account number:\n");
            scanf("%d",&numa);
            if(numa>900 && numa < 951){//if numa is char of legal number
                printf("Please enter the amount to withdraw:\n");
                scanf("%lf",&m);
                if(m > 0) W(numa , m);
                else printf("Invalid withdraw\n"); c=getchar();//if m is illegal amount
            }else printf("Invalid account number\n");c= getchar();//if numa is illegal
            els=1;

        }
        if(c == 'C')
        {
            printf("Please enter the account number\n");
            scanf("%d",&numa);
            if(numa>900 && numa < 951) C(numa);//if numa is legal
            else printf("Failed to read the account number\n"); c= getchar();
            els=1;

        }
        if (c == 'I')
        {
            els=1;
            numa=0;
            int j=numa;
            printf("Please enter the interest rate : \n");
            scanf("%d",&numa);
            if(numa <=100 && numa >-100){
                if(j!=numa)I(numa);
                else printf("Invalid transaction type\n");c=getchar();
            }
            else{//I cnot been more then 100% or less the -99% 
                 printf("Failed to read the interest rate\n");c=getchar();
            }
        }

        if(c == 'P')//print the accounts
        {
            P();
            els=1;

        }
        if(c == 'E')// close the accounts and exit
        {
            E();
            els=1;

        }
        if(els == 0) printf("Invalid transaction type\n");//char not legal
        

    }
    return 1;
}

