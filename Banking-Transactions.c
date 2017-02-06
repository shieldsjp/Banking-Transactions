/*--------------------------------------------------------------------------------------------------------------
Program file: 		Banking Transactions
Objective:			This program allows users to make some simple banking transactions. 
					User input is required and will prompt the user to enter their current balance (cannot be less than zero), the number of deposits and withdrawals (0-5) and will display
					a closing balance and bank record. The closing balance will be the current balance with the deposits minus the withdrawals. Depending on how much the closing balance reflects,
					a specific message will be displayed for the user.
-----------------------------------------------------------------------------------------------------------------*/
#include <stdio.h>
void main (void)
{
	
/*Variable Declarations and accumulators*/
/*-------------------------------------*/

	int x, numberofdeposits, numberofwithdrawals;
	float balance, currentbalance;
	float deposits[5], withdrawals[5];
	float totaldeposits = 0, totalwithdrawals = 0;
	char c;
	
/*Output display*/
/*--------------*/

	printf ("Welcome to the Computer Banking System\n\n");

	do
	{
	printf ("\nEnter your current balance in dollars and cents: ");
	scanf ("%f", &currentbalance);
	while ( (c = getchar() != '\n') && c != EOF);
	
/*Current balance entered by user must be at least zero*/
/*-----------------------------------------------------*/

	if (currentbalance <= -.001)
	printf ("*** Beginning balance must be at least zero, please re-enter.\n\n");
 	}while (currentbalance <= -.001);
 	
	do
	{
	printf ("\nEnter the number of deposits (0 - 5): ");
	scanf ("%i", &numberofdeposits);
	while ( (c = getchar() != '\n') && c != EOF);
	
	
/*Number of deposits entered by user must at least 1 and no more than 5*/
/*---------------------------------------------------------------------*/

	if (numberofdeposits <= 0 || numberofdeposits > 5)
	printf ("*** Invalid number of deposits, please re-enter\n\n");
} while (numberofdeposits <= 0 || numberofdeposits > 5);
	
	do
	{
	printf ("\nEnter the number of withdrawals (0 - 5): ");
	scanf ("%i", &numberofwithdrawals);
	while ( (c = getchar() != '\n') && c != EOF);
	
/*Number of withdrawals entered by user must at least 1 and no more than 5*/
/*------------------------------------------------------------------------*/

	if (numberofwithdrawals <= 0 || numberofwithdrawals > 5)
	printf ("*** Invalid number of deposits, please re-enter\n\n");
} while (numberofwithdrawals <= 0 || numberofwithdrawals > 5);

printf ("\n");

/*Array created for the specific number of deposits*/
/*-------------------------------------------------*/

		for (x = 0; x < numberofdeposits; x++) {
do
{
 printf ("Enter the amount of deposit #%i: ", x + 1);
 scanf ("%f", &deposits[x]);
 while ( (c = getchar() != '\n') && c != EOF);
 
/*Deposit amount must be greater than zero*/
/*----------------------------------------*/

  if (deposits[x] <= 0)
printf ("*** Deposit amount must be greater than zero. Please re-enter\n");
}while (deposits[x] <= 0); 

/*Running tally of deposit amounts*/
/*--------------------------------*/

 totaldeposits = totaldeposits + deposits[x];
}
 
 printf ("\n");
 
/*Array created for the specific number of withdrawals*/
/*----------------------------------------------------*/

 	for (x = 0; x < numberofwithdrawals; x++) 
	 	{
 		do
 		{
 printf ("Enter the amount of withdrawl #%i: ", x + 1);
 scanf ("%f", &withdrawals[x]);
 while ( (c = getchar() != '\n') && c != EOF); 
 
/*Withdrawal amount cannot exceed the current balance*/
/*---------------------------------------------------*/

 if (withdrawals[x] > currentbalance)
printf ("***Withdrawal amount exceeds current balance.***\n");
else

/*Prompting user that withdrawal amount be greater than zero*/
/*---------------------------------------------------------*/

if (withdrawals[x] <= 0)
printf ("*** Withdrawal amout must be greater than zero. Please re-enter! ***\n");
}
while (withdrawals[x] > currentbalance || withdrawals[x] <= 0);

/*Running tally of withdrawal amounts*/
/*----------------------------------*/

totalwithdrawals = totalwithdrawals + withdrawals[x];

/*Current balance which is total deposits added to current balance minus the total withdrawals*/
/*--------------------------------------------------------------------------------------------*/

balance = currentbalance - totalwithdrawals + totaldeposits;
if (balance == 0)
{

printf ("\n *** Balance is now zero. No more withdrawals can be made at this time. ***\n");
numberofwithdrawals = x;
}
}
printf ("\n*** The closing balance is $%.2f *** \n", balance);

/*if and if else statements below that display a message to the user based on total amount of ending balance*/
/*---------------------------------------------------------------------------------------------------------*/

if (balance >= 50000.00)
printf ("*** It is time to invest some money!*** \n\n");
else if (balance >= 15000.00 && balance <= 49999.99)
printf ("*** Maybe you should consider a CD.*** \n\n");
else if (balance >= 1000.00 && balance <= 14999.99)
printf ("*** Keep up the good work!*** \n\n");
else
printf ("*** Your balance is getting low!*** \n\n");

/*Bank Record will display to the user stating current balance along with total deposits and withdrawal amounts*/
/*------------------------------------------------------------------------------------------------------------*/

printf (" *** Bank Record ***\n");
printf ("\nStarting Balance: $ %.2f\n\n", currentbalance);
for (x = 0; x < numberofdeposits; x++)
{
printf ("Deposit #%i: %.2f\n", x + 1, deposits[x]);
}
for (x = 0; x < numberofwithdrawals; x++)
{
printf ("\nWithdrawal #%i: %.2f", x + 1, withdrawals[x]);
}
printf ("\n\nEnding Balance:$ %.2f\n", balance);
{

/*The following statement is used to pause the output*/
/*---------------------------------------------------*/
	
getchar();
}
}/* end main */
