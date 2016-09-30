#include <iostream>
#include <iomanip>
using namespace std;
float miles, totalShippingCost, variableShippingCost;
const int fixedCost(50); //fixed cost can be changed here once, instead of changing it throughout the code if hardcoded
const char GBP(156); //to show pound sign
char currencySymbol;
int main(){
void getCurrencySymbol();
void calculateVariableCost();
void showConvertedPrice();
	cout << "Enter the distance in miles: ";
	cin >> miles;
	if (miles <= 0) //checking for miles that are not 1 or above
		cout << "ERROR: The distance must have a positive value!" << endl << endl;
	else {
		getCurrencySymbol(); //calling procedure for currency symbol (extension)
		calculateVariableCost(); //calling procedure for calculating the variable shipping cost
		switch (currencySymbol){
		case'E':
		case'e':
		case'$':
			showConvertedPrice(); break; //calling procedure for working out and showing the converted price
		default: //if no additional currency is selected the original calculation is used
			totalShippingCost = variableShippingCost + fixedCost;
			cout.setf(ios::fixed);
			cout << setprecision(2);
			cout << "The cost of shipment over " << miles << " miles is " << GBP << totalShippingCost << endl << endl;
		}
	}
system("pause");
return(0);
}

void calculateVariableCost(){
const float firstOneHundred(5.5), overOneHundred(4), overFiveHundred(2.5); //cost per mile can be changed here once, instead of changing it throughout the code if hardcoded
	if (miles <= 100)
		variableShippingCost = miles * firstOneHundred; //calculating the cost for miles 100 and below

	if ((miles > 100) && (miles <= 500))
		variableShippingCost = ((100 * firstOneHundred) + ((miles - 100) * overOneHundred)); //calculating the cost for miles between 101 and 500

	if (miles > 500)
		variableShippingCost = ((100 * firstOneHundred) + (400 * overOneHundred) + ((miles - 500) * overFiveHundred)); //calculating the cost for miles 501+
}
/* Extension */
void getCurrencySymbol(){
cout << "Indicate additional currency ('E' for euros, '$' for dollars): ";
cin >> currencySymbol;
switch (currencySymbol){
case'E':
case'e':
case'$':
	break; //if there is a currency symbol (E,e,$) do nothing
default:
	cout << "ERROR: This currency is unknown!" << endl; //otherwise display error
	}
}

void showConvertedPrice(){
	float totalCostInEuros, totalCostInDollars;
	const float euroConversion(1.4), dollarConversion(1.55); //setting conversion rate. can be changed here once, instead of changing it throughout the code if hardcoded
	switch (currencySymbol){
	case'E':
	case'e':
		totalShippingCost = variableShippingCost + fixedCost;
		totalCostInEuros = totalShippingCost * euroConversion; //calculating shipping cost in euros
		cout.setf(ios::fixed);
		cout << setprecision(2);
		cout << "The cost of shipment over " << miles << " miles is " << GBP << totalShippingCost << " (" << totalCostInEuros << " euro)"<< endl << endl; //outputting cost in pounds and euros
		break;
	case'$':
		totalShippingCost = variableShippingCost + fixedCost;
		totalCostInDollars = totalShippingCost * dollarConversion; //calculating shipping cost in dollars
		cout.setf(ios::fixed);
		cout << setprecision(2);
		cout << "The cost of shipment over " << miles << " miles is " << GBP << totalShippingCost << " ($" << totalCostInDollars << ")" << endl << endl; //outputting cost in pounds and dollars
	}
}