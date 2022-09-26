#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>

using namespace std;
 
int main()
{	
	string fname, lname, staff_id;
	char citizenship_status, employment_classification;
	double normal_pay, overtime_pay, gross_pay, superannuation_deduction, tax_deduction, net_pay, hrs_worked;
	
	// declaring tax percentage constants
	const double CITIZEN_LESS_THRESHOLD_TAX_PERCENT = 0.0;
	const double CITIZEN_GREATER_THRESHOLD_TAX_PERCENT = 0.10;
	const double NONCITIZEN_LESS_THRESHOLD_TAX_PERCENT = 0.08;
	const double NONCITIZEN_GREATER_THRESHOLD_TAX_PERCENT = 0.12;
	
	// declaring gross pay threshold constants
	const double CITIZEN_THRESHOLD_PAY = 30000;
	const double NONCITIZEN_THRESHOLD_PAY = 50000;
	
	// declaring rates constants
	const double SENIOR_RATE = 30;
	const double INTER_JUNIOR_RATE = 20;
	const double PART_TIME_RATE = 11;
	const double OVERTIME_RATE = 1.5;
	const double SUPERANNUATION_RATE = 0.1;
	
	// declaring normal hours and weeks constants
	const int NORMAL_HOURS = 40;
	const int WEEKS_IN_YEAR = 52;
	
	cout<<"\n\t Employee Tax Calculator";
	cout<<"\n\t -----------------------";
	
	cout<<"\n\t\t Enter your First Name: ";
	cin>>fname;
	
	cout<<"\n\t\t Enter your Last Name: ";
	cin>>lname;
	
	cout<<"\n\t\t Enter your Staff ID: ";
	cin>>staff_id;
	
	cout<<"\n\t Enter your Hours Worked: ";
	cin>>hrs_worked;
	
	// check if input matches data type
	if(cin.fail())
	{
		cout<<"\n\t Error! Hours worked requires a numeric input.";
		cout<<"\n\n";
		return 0;
	}
	
	cout<<"\n\t Enter your Employment Classification"; 
	cout<<"\n\t('S' for Senior Staff, 'J' for Intermediate/Junior Staff, 'P' for Part time Staff): ";
	cin>>employment_classification;
	
	// check if user entered anything outside of the possible employment_classification values
	if(employment_classification != 'S' && employment_classification != 'J' && employment_classification != 'P')
	{
		cout<<"\n\t Error! Employment Classification can only be one of these values: 'S', 'J', 'P'";
		cout<<"\n\n";
		return 0;
	}
 	
	cout<<"\n\t Enter your Citizenship Status"; 
	cout<<"\n\t('F' for Fijian Citizenship, 'N' for Non-Fijian Citizenship): ";
	cin>>citizenship_status;
	
	// check if user entered anything outside of the possible citizenship_status values
	if(citizenship_status != 'F' && citizenship_status != 'N')
	{
		cout<<"\n\t Error! Employment Classification can only be one of these values: 'F', 'N'";
		cout<<"\n\n";
		return 0;
	}
	
	/*
		Following formulas were used to calculate the necessary values:
		
		normal_pay = WEEKS_IN_YEAR * NORMAL_HOURS * NORMAL_RATE ---> (NORMAL_RATE is one of these three constants:
		SENIOR_RATE, INTER_JUNIOR_RATE, PART_TIME_RATE. Depends on employment_classification)
		
		overtime_pay = WEEKS_IN_YEAR * (hrs_worked - NORMAL_HOURS) * OVERTIME_RATE
		
		gross_pay = normal_pay + overtime_pay
		
		superannuation_deduction = gross_pay * SUPERANNUATION_RATE
		
		tax_deduction = gross_pay * TAX_PERCENT ---> (TAX_PERCENT is one of these four constants: 
		CITIZEN_LESS_THRESHOLD_TAX_PERCENT, CITIZEN_GREATER_THRESHOLD_TAX_PERCENT, NONCITIZEN_LESS_THRESHOLD_TAX_PERCENT,
		NONCITIZEN_GREATER_THRESHOLD_TAX_PERCENT. Depends on citizenship_status and gross_pay amount)
		
		net_pay = gross_pay - (superannuation_deduction + tax_deduction)
		
		Calculate pays and deductions
	*/
	if(employment_classification == 'S')
	{
		if(hrs_worked > NORMAL_HOURS)
		{
			normal_pay = WEEKS_IN_YEAR * NORMAL_HOURS * SENIOR_RATE;
			overtime_pay = WEEKS_IN_YEAR * (hrs_worked - NORMAL_HOURS) * OVERTIME_RATE;
		}
		else
		{
			normal_pay = WEEKS_IN_YEAR * hrs_worked * SENIOR_RATE;
			overtime_pay = 0;
		}
		
		gross_pay = normal_pay + overtime_pay;
		
		superannuation_deduction = gross_pay * SUPERANNUATION_RATE;
		
		if(citizenship_status == 'F' && gross_pay <= CITIZEN_THRESHOLD_PAY)
		{
			tax_deduction = gross_pay * CITIZEN_LESS_THRESHOLD_TAX_PERCENT;	
		}
		else if (citizenship_status == 'F' && gross_pay > CITIZEN_THRESHOLD_PAY)
		{
			tax_deduction = gross_pay * CITIZEN_GREATER_THRESHOLD_TAX_PERCENT;	
		}
		else if(citizenship_status == 'N' && gross_pay <= NONCITIZEN_THRESHOLD_PAY)
		{
			tax_deduction = gross_pay * NONCITIZEN_LESS_THRESHOLD_TAX_PERCENT;		
		}
		else
		{
			tax_deduction = gross_pay * NONCITIZEN_GREATER_THRESHOLD_TAX_PERCENT;
		}
		
		net_pay = gross_pay - (superannuation_deduction + tax_deduction);
		
	}
	else if(employment_classification == 'J')
	{
		if(hrs_worked > NORMAL_HOURS)
		{
			normal_pay = WEEKS_IN_YEAR * NORMAL_HOURS * INTER_JUNIOR_RATE;
			overtime_pay = WEEKS_IN_YEAR * (hrs_worked - NORMAL_HOURS) * OVERTIME_RATE;
		}
		else
		{
			normal_pay = WEEKS_IN_YEAR * hrs_worked * INTER_JUNIOR_RATE;
			overtime_pay = 0;
		}
		
		gross_pay = normal_pay + overtime_pay;
		
		superannuation_deduction = gross_pay * SUPERANNUATION_RATE;
		
		if(citizenship_status == 'F' && gross_pay <= CITIZEN_THRESHOLD_PAY)
		{
			tax_deduction = gross_pay * CITIZEN_LESS_THRESHOLD_TAX_PERCENT;	
		}
		else if (citizenship_status == 'F' && gross_pay > CITIZEN_THRESHOLD_PAY)
		{
			tax_deduction = gross_pay * CITIZEN_GREATER_THRESHOLD_TAX_PERCENT;	
		}
		else if(citizenship_status == 'N' && gross_pay <= NONCITIZEN_THRESHOLD_PAY)
		{
			tax_deduction = gross_pay * NONCITIZEN_LESS_THRESHOLD_TAX_PERCENT;		
		}
		else
		{
			tax_deduction = gross_pay * NONCITIZEN_GREATER_THRESHOLD_TAX_PERCENT;
		}
		
		net_pay = gross_pay - (superannuation_deduction + tax_deduction);
	}
	else // can use else branch since we've validated for only three possible values
	{
		if(hrs_worked > NORMAL_HOURS)
		{
			normal_pay = WEEKS_IN_YEAR * NORMAL_HOURS * PART_TIME_RATE;
			overtime_pay = WEEKS_IN_YEAR * (hrs_worked - NORMAL_HOURS) * OVERTIME_RATE;
		}
		else
		{
			normal_pay = WEEKS_IN_YEAR * hrs_worked * PART_TIME_RATE;
			overtime_pay = 0;
		}
		
		gross_pay = normal_pay + overtime_pay;
		
		superannuation_deduction = gross_pay * SUPERANNUATION_RATE;
		
		if(citizenship_status == 'F' && gross_pay <= CITIZEN_THRESHOLD_PAY)
		{
			tax_deduction = gross_pay * CITIZEN_LESS_THRESHOLD_TAX_PERCENT;	
		}
		else if (citizenship_status == 'F' && gross_pay > CITIZEN_THRESHOLD_PAY)
		{
			tax_deduction = gross_pay * CITIZEN_GREATER_THRESHOLD_TAX_PERCENT;	
		}
		else if(citizenship_status == 'N' && gross_pay <= NONCITIZEN_THRESHOLD_PAY)
		{
			tax_deduction = gross_pay * NONCITIZEN_LESS_THRESHOLD_TAX_PERCENT;		
		}
		else
		{
			tax_deduction = gross_pay * NONCITIZEN_GREATER_THRESHOLD_TAX_PERCENT;
		}
		
		net_pay = gross_pay - (superannuation_deduction + tax_deduction);
	}
	
	// display details and calcuated values to user
	cout<<"\n\t USP Staff Details";
 	cout<<"\n\t -----------------";
	cout<<"\n\t Employee Name: ";
	cout<<fname + " " + lname;
	
	cout<<"\n\t Staff ID: ";
	cout<<staff_id;
	
	cout<<"\n\t Employment Status: ";
	cout<<employment_classification;
	
	cout<<"\n\t Citizenship Statuts: ";
	cout<<citizenship_status;
	
	cout<<"\n\t Normal Pay: $";
	cout<<normal_pay;
	
	cout<<"\n\t Overtime Pay: $";
	cout<<overtime_pay;
	
	cout<<"\n\t Gross Pay: $";
	cout<<gross_pay;
	
	cout<<"\n\t Superannuation Deduction: $";
	cout<<superannuation_deduction;
	
	cout<<"\n\t Tax Deduction: $";
	cout<<tax_deduction;
	
	cout<<"\n\t Net Pay: $";
	cout<<net_pay;
	
	
	cout<<"\n\n";
	return 0;
	system("PAUSE");
}
