#include <stdio.h>
#include "myBank.h"
//matAcount is matrix of the account .numbers and number is count how mach account we have
double matAcount [50][3]={0};
int number=0;
//firs func is O : to open new acount and put in sum amount
void O(double x)
{
    int i;
    if(number < 50 && x>0)// if number is < 50 this mean that our bank is full
    {
        for(i=0 ;i<50 ; i++){
            if( matAcount[i][2] == 0)
            {
                matAcount[i][0]=901+i;//acount number
                matAcount[i][1] +=x;//add the amount
                matAcount[i][2] = 1;//1=acount is open
                number++;
                printf("you new account number is : %0.0lf\n", matAcount[i][0]);
                i=51;//to go out from the for
            }
        }
    }
    else if(x<0) printf("Cannot deposit a negative amount\n");
    else if(number > 50) printf("the bank is full!!!");

}

// func B - to see the balance in the account
void B(int numAcount)
{
    if(numAcount <951  && numAcount>900)
    {
        //print the balance
        if(matAcount[numAcount-901][2]==1) printf("The balance of the account is : %0.2lf\n" , matAcount[numAcount-901][1]);
        else printf("This account is closed \n");
        //the account is closed
    }
    else{
        printf("No sach acount in the bank!\n");
    }
}

// func D to add money to the account
void D(int numAcount , double addMoney)
{
    if(numAcount <951  && numAcount>900 && matAcount[numAcount-901][2]==1)// if its ligull account number and the account isnt close:
    {
        if(addMoney>0)//money we whant to add is positive
        {
            matAcount[numAcount-901][1]+=addMoney;//add to the matrix
            printf("The new balance of the acoount number '%d' ,is : %0.2lf \n",numAcount , matAcount[numAcount-901][1]);
        }
        else printf("Cannot add Money!!");
    }
}

//func W to withdraw money from the account
void W(int numAcount , double outMoney)
{
    if(numAcount <951  && numAcount>900 && matAcount[numAcount-901][2]==1 && matAcount[numAcount-901][1]-outMoney >=0 )
    {
        //withdraw from the matrix
        matAcount[numAcount-901][1]-=outMoney;
        printf("The new balance is: '%d' ,is : %0.2lf \n",numAcount , matAcount[numAcount-901][1]);
        //print massege
    }
    else
    {
        //print the appropriate message:
        if(numAcount >950  && numAcount<900) printf("Not ligall num acount!!\n");
        else if(matAcount[numAcount-901][2]!=1) printf("this acount is not open!\n");
        else  printf("Cannot withdraw more than the balance\n");

    }
}

//func C = to close account number
void C(int numAcount)
{
    if(numAcount>900 && numAcount <951 && matAcount[numAcount-901][2]==1)//the account is open
    {
        matAcount[numAcount-901][1]=0;
        matAcount[numAcount-901][2]=0;
        number--;
        printf("you account is closed!\nthank you for been in this bank\nhave a nice day! :) \n");
    }
    else printf("This account is already closed\n");//account is close
}

//func I- to add interest
void I(double interest)
{
    if( interest <=100 && interest >-100)//interest is between 100 to -99
    {
        int temp;
        temp=0;
        while(temp<50)
        {
            if(matAcount[temp][2]==1)
            {
                double in = (matAcount[temp][1]/100)*interest;
                matAcount[temp][1]+=in;
            }
            temp++;
        }
        printf("The interest rate increase was successful to %d acount how open.\n",number);
    }
}

// func P - to print the accounts how open
void P()
{
    int temp;
    temp=0;
    while(temp<50)
    {
        if(matAcount[temp][2]==1)
        {
           printf("this bank acount number %0.0lf is open.\nThe balance is %0.2lf\n",matAcount[temp][0],matAcount[temp][1]);
        }
        temp++;
    }

}

// func E to close all the accounts and finish
void E()
{
    int temp;
    temp=0;
    while(temp<50)
    {
        if(matAcount[temp][2]==1)
        {
            matAcount[temp][1]=0;
            matAcount[temp][2]=0;
            number--;
        }
        temp++;
    }
    printf("all the acounts is closed!\nBye bye! :)\n");
}
