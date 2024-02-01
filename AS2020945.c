/*Title: Food Ordering System
Description: Print the bill  */

#include <stdio.h>
#include <stdlib.h>
#include<time.h>
//Initializing Main Array
float price[8] = {290.0,110.0, 75.0, 150.0, 240.0, 350.0, 40.0,190.0 };

//global variable
int intNumberOfAdult;
int intNumberOfChildern;

/*------------------------------------------------------------------------------------------------------------------
[Begin of Function Declaration]
--------------------------------------------------------------------------------------------------------------------*/

// print menu
void printMeals();

//read the amount to be paid for adults and return
float orderForAdult();

//read the amount to be paid for children and return
float orderForChildren();

//read the total amount for both and return
float calculateBillAmount();

//read the discount and total after discount and return
float CalculateDiscount(float fltBillAmount);

//read the amount of receive and return
float ReceiveMoneyfunc();

//read the balance and return
float CalculateBalance(float fltReceivedMoney, float fltTotalBill);

//PrintBill
void PrintBill(float fltBillAmount,float fltTotalBill, float fltReceivedMoney, float fltBalance);

//createFile for store bill
void createFile(float fltBillAmount,float fltTotalBill,float fltReceivedMoney,float fltBalance);


/*------------------------------------------------------------------------------------------------------------------
[End of Function Declaration]
--------------------------------------------------------------------------------------------------------------------*/


/*------------------------------------------------------------------------------------------
[BEGIN] Function:  main
--------------------------------------------------------------------------------------------*/

int main()
{
    time_t tm; //local time zone
    time(&tm);

    float fltBillAmount = 0.0;
    float fltTotalBill;
    float fltReceivedMoney = 0.0;
    float fltBalance = 0.0;

    printMeals();

    printf("please enter number of adults  :");
    scanf("%d",&intNumberOfAdult);

    printf("please enter number of children:");
    scanf("%d",&intNumberOfChildern);



    fltBillAmount = calculateBillAmount();
    printf("\nCost for Items Selected : %.2f",fltBillAmount);
    fltTotalBill=CalculateDiscount(fltBillAmount);

    fltReceivedMoney = ReceiveMoneyfunc();
    fltBalance = CalculateBalance(fltReceivedMoney, fltTotalBill);
    PrintBill( fltBillAmount, fltTotalBill,fltReceivedMoney, fltBalance);

    printf("\nCurrent Date/Time : %s",ctime(&tm));

    // To hold the output screen for some time until the user pass any key
    getch();

    return 0;
}
/*-----------------------------------------------------------------------------------------
[END] Function:  main
-------------------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------------------
[BEGIN] Function:  "printMeals"
--------------------------------------------------------------------------------------------
Precondition:  : None
Post Condition : Display the menu in console
Description    :
--------------------------------------------------------------------------------------------*/

void printMeals()
{

    printf(" \t\t************WELCOME TO DUTCHMANS STREET RESTURANT ************\n\n\n");
    printf(" \t\t\t MENUE \20\n\n\n");
    printf(" \t\t\t MEALS\t\t\t\tPRICE\n");
    printf(" \t\t\t 1- Soup with shrimps \t\tRs290.00\n");
    printf(" \t\t\t 2- Spaghetti \t\t\tRs110.00\n");
    printf(" \t\t\t 3- Rolls \t\t\tRs 75.00\n");
    printf(" \t\t\t 4- Noodles \t\t\tRs150.00\n");
    printf(" \t\t\t 5- Pasta \t\t\tRs240.00\n");
    printf(" \t\t\t 6- Macaroni \t\t\tRs350.00\n");
    printf(" \t\t\t 7- Buns \t\t\tRs 40.00\n");
    printf(" \t\t\t 8- Sop buntut \t\t\tRs190.00\n");
    printf("\n");
}
/*------------------------------------------------------------------------------------------
[END] Function : "printMeals"
--------------------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------------------
[BEGIN] Function:  "orderForAdult"
--------------------------------------------------------------------------------------------
Precondition:  : read menuOption,amount,response,total,total with tax,tax
Post Condition : return the total for all adults
Description    :
--------------------------------------------------------------------------------------------*/

float orderForAdult()
{
    int menuOption,i,amount;
    char chrResponse = 'y';
    float fltTotalAllPerson =0.0;
    float totalAllPersonWithTAX;
    float fltTax = 5.0;


    // check number of adults
    if(intNumberOfAdult >0)
    {
        printf("***\tadults:\n");
    }
    else
    {
        printf("\n");
    }

    //Begin of for loop
    for(i=0; i<intNumberOfAdult; i++)
    {
        chrResponse = 'y';

        printf("adult %d please enter your orders\n",i+1);

        //Start of while loop
        //Continue process until chrResponse variable = "Y" or "y"
        while(chrResponse == 'y' || chrResponse == 'Y')
        {
            printf("please enter your option:");
            scanf("%d",&menuOption);

            if(menuOption<1 || menuOption>8)
            {
                printf("\nSorry we don`t have this order \n again! \n");
                continue;
            }

            printf("please enter your amount of order:");
            scanf("%d",&amount);

            fltTotalAllPerson = fltTotalAllPerson + (amount * price[menuOption - 1] );
            totalAllPersonWithTAX=fltTotalAllPerson + ((fltTotalAllPerson * fltTax) / 100);

            printf("\nWould you like to enter more orders(y/n):");
            scanf(" %c",&chrResponse);
        }
        //end of while loop
        printf("\n");
    }
//end of for loop
    return totalAllPersonWithTAX;
}
/*------------------------------------------------------------------------------------------
[END] Function : "orderForAdult"
--------------------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------------------
[BEGIN] Function: "orderForChildren"
--------------------------------------------------------------------------------------------
Precondition:  : read menuOption,amount,response,total
Post Condition : return the total for all Children
Description    :
--------------------------------------------------------------------------------------------*/

float orderForChildren()
{
    int menuOption,i,amount;
    char chrResponse = 'y';
    float fltTotalAllChildren = 0.0;

    // check number of children
    if(intNumberOfChildern >0)
    {
        printf("***\tChildren:\n");
    }

    else
    {
        printf("\n");
    }
    //Begin of for loop
    for(i=0; i<intNumberOfChildern; i++)
    {
        chrResponse = 'y';

        printf("child %d please enter your orders\n",i+1);

        //Start of while loop
        //Continue process until chrResponse variable = "Y" or "y"
        while(chrResponse == 'y' || chrResponse == 'Y')
        {
            printf("Please enter your option:");
            scanf("%d",&menuOption);

            if(menuOption<1 || menuOption>8)
            {
                printf("\nSorry we don`t have this order \n again! \n ");
                continue;
            }
            printf("Please enter your amount of order:");
            scanf("%d",&amount);


            fltTotalAllChildren = fltTotalAllChildren + amount * price[menuOption - 1];


            printf("\nWould you like to enter more orders(y/n):");
            scanf(" %c",&chrResponse);


        }
        //End of while loop
        printf("\n");

    }
    //End of for loop
    return fltTotalAllChildren;
}
/*------------------------------------------------------------------------------------------
[END] Function : "orderForChildren"
--------------------------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------------------
[BEGIN] Function:  "calculateBillAmount"
--------------------------------------------------------------------------------------------
Precondition:  : read billAmount,TotalForAdults,TotalForChildren
Post Condition : return the BillAmount
Description    : calculate the bill amount of adults and children
--------------------------------------------------------------------------------------------*/


float calculateBillAmount()
{
    float fltBillAmount = 0.0;
    float TotalForAdults = 0.0;
    float TotalForChildren = 0.0;

    TotalForAdults = orderForAdult();
    TotalForChildren = orderForChildren();
    fltBillAmount = TotalForAdults+TotalForChildren;


    return fltBillAmount;
}
/*------------------------------------------------------------------------------------------
[END] Function : "calculateBillAmount"
--------------------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------------------
[BEGIN] Function:  "CalculateDiscount"
--------------------------------------------------------------------------------------------
Precondition:  : read
Post Condition : return the fltTotalBill
Description    :
--------------------------------------------------------------------------------------------*/

float CalculateDiscount(float fltBillAmount)
{

    float fltDiscount =0.0;
    float fltTotalBill;
    if(fltBillAmount < 40)
    {
        fltDiscount=((fltBillAmount * 0.5)/100);
    }
    else if(fltBillAmount>= 40 && fltBillAmount<100)
    {
        fltDiscount=((fltBillAmount * 1)/100);
    }
    else if(fltBillAmount>= 100 && fltBillAmount<300)
    {
        fltDiscount=((fltBillAmount * 1.5)/100);
    }
    else if(fltBillAmount>= 300 && fltBillAmount<1000)
    {
        fltDiscount=((fltBillAmount * 2.0)/100);
    }
    else
    {
        fltDiscount= ((fltBillAmount * 5.0)/100);
    }

    fltTotalBill = fltBillAmount-fltDiscount;
    return fltTotalBill;

}
/*------------------------------------------------------------------------------------------
[END] Function : "CalculateDiscount"
--------------------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------------------
[BEGIN] Function:  "ReceiveMoneyfunc"
--------------------------------------------------------------------------------------------
Precondition:  : None
Post Condition : return the ReceivedMoney
Description    :
--------------------------------------------------------------------------------------------*/

float ReceiveMoneyfunc()
{
    float fltReceivedMoney = 0.0;
    printf("\nPlease Enter the Amount You Pay : ");
    scanf("%f",&fltReceivedMoney);
    return fltReceivedMoney;
}
/*------------------------------------------------------------------------------------------
[END] Function : "ReceiveMoneyfunc"
--------------------------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------------------
[BEGIN] Function:  "CalculateBalance"
--------------------------------------------------------------------------------------------
Precondition   : read amount of ReceivedMoney, fltBillAmount
Post Condition : return the Balance
Description    :
--------------------------------------------------------------------------------------------*/

float CalculateBalance(float fltReceivedMoney, float fltTotalBill)
{
    float fltBalance = 0.0;
    fltBalance = fltReceivedMoney - fltTotalBill;
    return fltBalance;
}
/*------------------------------------------------------------------------------------------
[END] Function : "CalculateBalance"
--------------------------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------------------
[BEGIN] Function:  "PrintBill"
--------------------------------------------------------------------------------------------
Precondition:  :
Post Condition : None
Description    : Display the Bill in console
--------------------------------------------------------------------------------------------*/

void PrintBill(float fltBillAmount,float fltTotalBill, float fltReceivedMoney, float fltBalance)
{
    printf("\n-------------------------------------------------------------------------------------------\n");
    printf("***************************************FINAL BILL******************************************\n\n");
    printf("\tTotal Amount                 : Rs.%5s%.2f"," ",fltBillAmount);
    printf("\n\tTotal bill after discount    : Rs.%5s%.2f"," ",fltTotalBill);
    printf("\n\tReceived Money               : Rs.%5s%.2f"," ",fltReceivedMoney);
    printf("\n\tBalance                      : Rs.%5s%.2f"," ",fltBalance);
    printf("\n-------------------------------------------------------------------------------------------\n");
    printf("\n*******************************Thank You Come Again!!**************************************\n");
    printf("\n-------------------------------------------------------------------------------------------");
    createFile(fltBillAmount,fltTotalBill,fltReceivedMoney,fltBalance);

}
/*------------------------------------------------------------------------------------------
[END] Function : "PrintBill"
--------------------------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------------------
[BEGIN] Function:  "createFile"
--------------------------------------------------------------------------------------------
Precondition:  : None
Post Condition : Store the Bill
Description    : print bill for customer
--------------------------------------------------------------------------------------------*/

void createFile(float fltBillAmount,float fltTotalBill,float fltReceivedMoney,float fltBalance)
{
    FILE *filePointer; //handle and keep track on the file being accessed
    filePointer=fopen("file1.txt","a");

    fprintf(filePointer,"**************FINAL BILL***************\n");
    fprintf(filePointer,"Total Amount : Rs. %0.2f\n",fltBillAmount);
    fprintf(filePointer,"Total bill after discount    : Rs. %0.2f\n",fltTotalBill);
    fprintf(filePointer,"Received Money : Rs. %0.2f\n",fltReceivedMoney);
    fprintf(filePointer,"Balance : Rs. %0.2f\n",fltBalance);
    fprintf(filePointer,"************Thank You Come Again!!*************");
    fclose(filePointer);
}
/*------------------------------------------------------------------------------------------
[END] Function : "createFile"
--------------------------------------------------------------------------------------------*/
