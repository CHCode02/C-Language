#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#pragma warning (disable : 4996)
#define TOTAL_CASE_1 100
#define CURRENT_CASE_1 9
#define CURRENT_DEADTH 2
#define CURRENT_RECOVERY 10
#define CURRENT_UNDER_TREATMENT 88
void reportDay9();
void welcomeMenu();
void submenu();
void submenu2();
void endOfreport();
void endMenu();
double percentDeath1, percentRecovery1, percentUnderTreat1, sumOfcase1; 

void main()
{
	//Table of constants and variable
	int  currentCase1, newcaseL, newcaseI;												//Cases of getting Covid-19
	int totalCase1, totalCase2 = 0,totalNewCase,totalDaynewcase=0;
	int undertreatment;																	//Treatment case

	int totalRecovery1, totalRecovery2 = 0, newRecovery, totalNewRecovery = 0;			//Recover case
	int totalDeath1, totalDeath2 = 0, newDeath, totalnewDeath = 0;						//Death case

	//Declate Variable for maximum number
	int maxCaseDay = 0, maxRecoveryDay = 0, maxDeathDay = 0;							//Maximum Day for their catogory
	int	maxCase = 0, maxRecovery = 0, maxDeath = 0;				//Maximum number for their catogory
	double maxRecoverypercent = 0, maxDeathpercent = 0;	//Maximum percentage on the day of those catogory case.

	int decision1, decision2;															//Varaibles for making decision.
	int day;																			//Variable for which day report written.
	int different;																		//Variable for defference between yesterday newcase and nowday newcase.
	
	double percentDeath2, percentRecovery2, percentUndertreat2, sumOfcase2;				//Alphabet means percent for different status of cases.

	
	
	welcomeMenu();
	//change to double for using as percentage.
	sumOfcase1 = (double)CURRENT_RECOVERY + CURRENT_UNDER_TREATMENT + CURRENT_DEADTH;  
	percentDeath1 = (CURRENT_DEADTH / sumOfcase1) * 100;
	percentRecovery1 = (CURRENT_RECOVERY / sumOfcase1) * 100;
	percentUnderTreat1 = (CURRENT_UNDER_TREATMENT / sumOfcase1) * 100;
	submenu();

	//Change the constant to variable for looping;
	currentCase1 = CURRENT_CASE_1;														
	totalCase2 = TOTAL_CASE_1;
	totalDeath2 = CURRENT_DEADTH;
	totalRecovery2 = CURRENT_RECOVERY;

	for (day = 10; day <= 999 ; day++)
	{
		//<Manually Enter Cases Here>
		printf("Day %d\n", day);
		printf("========\n");
		printf("Key in of Today's data:\n");	//Input new data for report day

		printf("Enter of new cases (Local):");
		scanf("%d", &newcaseL);					//Read Local New Case

		printf("Enter of new cases (Import):");
		scanf("%d", &newcaseI);					//Read Import New Case

		
		totalNewCase = newcaseL + newcaseI;		//Calculate newest Case on Day 10.
		
		//Find out the difference between total new cases of report day and total new cases of yesterday  
		different = 0;
		if (totalNewCase > currentCase1)		//Report Day > Yesterday
		{
			different = totalNewCase - currentCase1;
			printf("Total new case= %d Case(s)		(Increase by %d)\n", totalNewCase, abs(different));//Show Increases
		}
			
		else if (totalNewCase <  currentCase1)	//Report Day < Yesterday
		{
			different = currentCase1 - totalNewCase;
			printf("Total new case= %d Case(s)		(Decrease by %d)\n", totalNewCase, abs(different));//Show Decreases
		}

		else if (totalNewCase == currentCase1)	//Report Day = Yesterday
		{
			printf("Total new case= 0 Case		(Same As Yesterday)\n");
		}

		printf("\n");
		printf("Enter of deaths: ");
		scanf("%d", &newDeath);					//Read New Death Case
		
		printf("Enter of recovered: ");
		scanf("%d", &newRecovery);				//Read New Recovery Case

		//Procrss Report Day Data
		totalCase1 = totalNewCase + TOTAL_CASE_1+totalDaynewcase;//Calculate total new case on Report Day.
		totalDaynewcase += totalNewCase;

		totalDeath1 = CURRENT_DEADTH + newDeath+totalnewDeath;//Calculate total new death case on Report Day.
		totalnewDeath += newDeath;

		totalRecovery1 = CURRENT_RECOVERY + newRecovery+totalNewRecovery;	//calculate toatl new recovery case on Report Day.
		totalNewRecovery += newRecovery;

		undertreatment = totalCase1 - totalDeath1 - totalRecovery1; //calculate cases that under treatment on Report Day.
		
		//find percentage of status of cases.
		sumOfcase2 = (double)undertreatment + totalRecovery1 + totalDeath1; //Get the sum of under treatment cases,total cases recovery and total death case. 
		percentDeath2 = (totalDeath1 / sumOfcase2) * 100.0;				   //Calculate percentage of Death cases until Report Day.
		percentRecovery2 = (totalRecovery1 / sumOfcase2) * 100.0;		   //Calculate percentage of Recovery cases until Report Day.
		percentUndertreat2 = (undertreatment / sumOfcase2) * 100.0;		  //Calculate percentage of Undertreatment cases until Report Day.

		
		printf("\n");
		printf("Day %d  Daily Summary Report\n", day);
		printf("-----------------------------------------------------------------------------------------\n");
		printf("|   New Cases       || Total Case || Total Death || Total Recovered || Under Treatment ||\n");
		printf("---------------------------------------------------------------------------------------||\n");
		printf("| Local%13d||		  ||             ||                 ||                 ||\n", newcaseL);
		printf("| Import%12d||		  ||             ||                 ||                 ||\n", newcaseI);
		printf("| %18d||%8d    ||%8d     ||%10d       ||%10d       ||\n", totalNewCase, totalCase1, totalDeath1, totalRecovery1, undertreatment);
		printf("----------------------------------||-------------||-----------------||-----------------||\n");
		printf("                                  ||%8.2lf%%    ||%11.2lf%%     ||%11.2lf%%     ||\n", percentDeath2, percentRecovery2, percentUndertreat2);
		printf("----------------------------------------------------------------- ------------------------\n");
		printf("\n");

		//<Here is defining the maximum cases and its percentage on which day>
		//Maximum number of total new cases per day
		if (totalNewCase > maxCase) {
			maxCase = totalNewCase;
			maxCaseDay = day;
		}
		//Maximum number of new death cases per day
		if (newDeath > maxDeath) {
			maxDeath = newDeath;
			maxDeathpercent = percentDeath2;
			maxDeathDay = day;
		}
		//Maximum number of new recovery cases per day
		if (newRecovery > maxRecovery) {
			maxRecovery = newRecovery;
			maxRecoverypercent = percentRecovery2;
			maxRecoveryDay = day;
		}
		
		do {
			printf("Option:\n");
			printf("	1.Show Daily Comparative Report and End up today Report\n");
			printf("	2.End up today Report\n");
			printf("Option:");
			scanf("%d", &decision2);

			printf("\n");
			if (decision2 == 1)
			{
				printf("			  Daily Comparative Report\n");
				printf("                    +---------------------------------------+\n");
				printf("                    |  Yesterday  |   Today   || DIFFERENCE |\n");
				printf("                    |   DAY%d      |   DAY%d   ||            |\n", day - 1, day);
				printf("+-------------------+-------------+-----------++------------+\n");
				printf("| New case          |%7d      |%7d    ||%8d    |\n", currentCase1, totalNewCase,totalNewCase- currentCase1);
				printf("+-------------------+-------------+-----------++------------+\n");
				printf("| TOTAL case        |%7d      |%7d    ||%8d    |\n", totalCase2, totalCase1,  totalCase1-totalCase2);
				printf("+-------------------+-------------+-----------++------------+\n");
				printf("| Death Rate        |%7.2lf%%     |%7.2lf%%   ||%8.2lf%%   |\n", ceil(percentDeath1), ceil( percentDeath2), percentDeath1 - percentDeath2);
				printf("+-------------------+-------------+-----------++------------+\n");
				printf("| Recovery Rate     |%7.2lf%%     |%7.2lf%%   ||%8.2lf%%   |\n",ceil(percentRecovery1), ceil(percentRecovery2),percentRecovery1-percentRecovery2);
				printf("+-------------------+-------------+-----------++------------+\n");
				

				printf("\n");
				printf("===================================================================================================\n");
				printf("---------------------------------------- END OF DAY %d REPORT -------------------------------------\n", day);
				printf("===================================================================================================\n");
				break;

			}
			
			else if (decision2 == 2)
			{


				printf("\n");
				printf("===================================================================================================\n");
				printf("---------------------------------------- END OF DAY %d REPORT -------------------------------------\n", day);
				printf("===================================================================================================\n");
				break;
			}
			else {
				printf("Invalid Option! Please Try Again.\n");
			}
		} while (decision2 > 0 && decision2 < 2);
		currentCase1 = totalNewCase;
		totalCase2 = totalCase1;
		totalDeath2 = totalDeath1;
		totalRecovery2 = totalRecovery1;
		percentDeath2 = percentDeath1;
		percentRecovery2 = percentRecovery1;
		
		do
		{
			submenu2();
			scanf("%d", &decision1);
					
			if (decision1 == 1)
			{
				
				//Output the data that input by user.

				printf("\n");

				printf("Yesterday's Totals - (Day %d):\n", day);
				printf("--------------------------------------------------------------------------------------------\n");
				printf("|              |New Cases | Total Cases | Total Deaths | Total Revovered | Under Treatment|\n");
				printf("---------------+----------+-------------+--------------+-----------------+------------------\n");
				printf("|Previous case |%6d     |%8d     |%7d       |%9d        |%9d       |\n", totalNewCase, totalCase1, totalDeath1, totalRecovery1, undertreatment);
				printf("---------------+----------+-------------+--------------+-----------------+------------------\n");
				printf("                                        |%8.2lf%%     |   %8.2lf%%     |   %8.2lf%%    |\n", percentDeath2, percentRecovery2, percentUndertreat2);
				printf("                                        +---------------------------------------------------\n");
				printf(" \n");
				printf("\n");
				endOfreport();
				
			}
			else if(decision1==2)
			{
				printf("\n");
				endOfreport(); break;
				
			}
			else if (decision1==3) {
				printf("  Maximum Comparation Report\n");
				printf("++-------------------------------------------------------++\n");
				printf("||  Maximum Case  |  Maximum Recovery  |  Maximum Death  ||\n");
				printf("++-------------------------------------------------------||\n");
				printf("||%5d (Day%d)   |%8d Day%d      |%6d Day%d     ||\n", maxCase, maxCaseDay, maxRecovery, maxRecoveryDay, maxDeath, maxDeathDay);
				printf("++-------------------------------------------------------||\n");
				printf("||                |       %.2lf          |     %.2lf     ||\n", maxRecoverypercent, maxDeathpercent);
				printf("++-------------------------------------------------------++\n");
				
				printf("\n");
				endOfreport();
				endMenu();
				system("pause");
				break;
			}
			else if(decision1==4){
				printf("\n");
				endOfreport();
				endMenu();
				system("pause");
				break;
			}
			else {
				printf("Warning!! Invalid Option! Please Try Again.");
			}
		} while (decision1 < 4 && decision1 > 1);
		
	}
	system("pause");
}

void reportDay9() 
{	

	//Output of Day 9th Data
	printf("Yesterday's Totals - (Day 9):\n");
	printf("--------------------------------------------------------------------------------------------\n");
	printf("|    New Cases | Total Cases | Total Deaths | Total Recovered | Under Treatment|\n");
	printf("---------------+-----------+-------------+--------------+-----------------+------------------\n");
	printf("|Previous case |%6d     |%8d     |%7d       |%9d        |%9d       |\n", CURRENT_CASE_1, TOTAL_CASE_1, CURRENT_DEADTH, CURRENT_RECOVERY, CURRENT_UNDER_TREATMENT);
	printf("----------------+----------+-------------+--------------+-----------------+------------------\n");
	printf("                                         |%9.2lf%%    |%10.2lf%%      |%10.2lf%%     |\n", percentDeath1, percentRecovery1, percentUnderTreat1);
	printf("--------------------------------------------------------------------------------------------\n");
	printf("\n");
}

void welcomeMenu() {
	int workerCode;
	
	printf("..............................Covid-19 CASES Tracking System................................\n");
	printf("		Coded by:Lee Chen Hong\n");
	do {
		printf("(Remainder:Please make sure your worker code is correct before enter)\n");
		printf("Please Enter Worker Code(Example:WKC001):WKC");
		scanf("%d", &workerCode);

	
		if (workerCode <= 0) {
			printf("Please check your worker on id card before enter it.\n");
		}
		else {
			printf("HI!!Worker%d ,Welcome To System Tracking System of COVID-19!!\n", workerCode);
		}

	} while (workerCode == 0 || workerCode<0);
	
}
void submenu()
{
	int decision3,desicion4;
	do
	{
		printf("Menu:\n");
		printf("Option 1:	Show the yesterday's report.\n");
		printf("Option 2:	key in next day data.\n");
		printf("Option 3:	Exit\n");
		printf("\n");
		printf("Enter Your option HERE:");
		scanf("%d", &decision3);

		switch (decision3)
		{
		case 1:reportDay9();
			printf("Option:\n");
			printf("	1.Continue\n");
			printf("	2.Back\n");
			printf("Enter your Option:");
			scanf("%d", &desicion4);
			if (desicion4 == 1) {
				break;
			}
			else if (desicion4 == 2) {
				submenu();
			}
			else {
				printf("Error!! Invaild Option, Please Try Again.");
			}
		case 2:break;
		case 3:endMenu();system("pause");
		default:printf("Error!! Invaild Option!! Please Enter Valid Option.\n");
		}
	} while (decision3 <= 1 || decision3 > 3);
}

void submenu2(){
	printf("Option:\n");
	printf("DO YOU WANTED TO CONTINUE NEXT DAY??\n");
	printf("	1.YES, and WITH yesterday's total report.\n");
	printf("	2.YES, but WITHOUT yesterday's total report.\n");
	printf("	3.NO, and WITH Maximum Compative Report\n");
	printf("	4.NO, but WITHOUT Maximum Compative Report\n");
	printf("Your option:");
}
void endOfreport() {
	printf("***************************************************************************************************\n");
	printf("------------------------------------ END OF REPORT-------------------------------------------------\n");
	printf("***************************************************************************************************\n");
}
void endMenu() {
	printf("Thank You For Using Chen Hong's Covid-19 Tracking System!!");
	printf("All the data will be saved in DataBase\n");
	printf("If found Any Bugs or Improvement Requested,Please contacts Lee Chen Hong(011-xxxxxxxx).\n");
}

