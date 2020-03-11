//Aaron Lim Cong Kai
//Full time
//I claim all credit for this assignment
//I have not pass my program to my friends

#include <iostream>
#include <iomanip>

using namespace std;

//to get (the returning value) the weight
//table of specific length (parameter)
int getWeightTable(int);

//to get the sum of weight
//to find the letter in the sum
int getAlphabet(int, int);

//to check (true or false) if the NRIC number
//is of specific length (the two parameters)
bool checkLength(int, int);

//to get the letter
char letter(int);

int main()
{
	int wT, 
		length, 
		wt, 
		choices, 
		nric,
		nricLength,
		sum;
		
	char s, 
		 z;
		 
	bool check;
	
	//starting display
	cout << "Welcome to the NRIC "
		 << "Development system"
		 << "\n"
		 << setw(38) << setfill ('.') << "."
		 << "\n"
		 << "Enter the length of the NRIC: ";
	cin >> length;
	
	//check if weight length = length
	while (wt != length)
	{
		cout << "\n"
			 << "Enter weight table: ";
		cin >> wT;
		wt = getWeightTable(wT);
		check = checkLength(length, wt);
		if (check == false)
		{
			cout << "Weight table must have length"
				 << " = "
				 << length
				 << endl;
		}
	}
	
	//second display
	//choices == 9, end
	while(choices != 9)
	{
		cout << setw(38) << setfill('-') << "-"
			 << "\n"
			 << "We provide two services"
			 << "\n"
			 << "\n"
			 << "1. To check valid NRIC"
			 << "\n"
			 << "2. To compute NRIC check digit"
			 << "\n"
			 << "9. Quit"
			 << "\n \n"
			 << "Service No: ";
		cin >> choices;
		
		//choice 1
		if (choices == 1)
		{
			cout << setw(38) << setfill ('-') << "-"
				 << "\n"
				 << "Checking of valid NRIC"
				 << "\n"
				 << setw(22) << setfill('=') << "="
				 << "\n \n"
				 << "Enter your NRIC: ";
			cin >> s
				>> nric
				>> z;
			nricLength = getWeightTable(nric);
			if (checkLength(length, nricLength) == false)
			{
				cout << "NRIC No must be of length "
					 << length
					 << "\n"
					 << "Thank you for using the system"
					 << endl;
			}
			else
			{
				sum = getAlphabet(nric, wT);
				cout << "\n"
					 << "The computed check digit is "
					 << letter(sum)
					 << endl;
				if (z == letter(sum))
				{
					cout << "Valid check digit"
						 << "\n"
						 << "Thank you for using the system"
						 << endl;
				}
				else
				{
					cout << "Invalid check digit"
						 << "\n"
						 << "Thank you for using the system"
						 << endl;
				}
			}
		}
		//choice 2
		else if (choices == 2)
		{
			cout << setw(38) << setfill ('-') << "-"
				 << "\n"
				 << "To compute check digit"
				 << "\n"
				 << setw(22) << setfill('=') << "="
				 << "\n \n"
				 << "Enter only the number: ";
			cin >> nric;
			nricLength = getWeightTable(nric);
			if (checkLength(length, nricLength) == false)
			{
				cout << "\n"
					 << "Number must be of length "
					 << length
					 << "\n"
					 << "Thank you for using the system"
					 << endl;
			}
			else if (checkLength(length, nricLength) == true)
			{
				sum = getAlphabet(nric, wT);
				cout << "\n"
					 << "The check digit is "
					 << letter(sum)
					 << "\n"
					 << "Thank you for using the system"
					 << endl;
			}
		}
	}
	cout << setw(38) << setfill ('-') << "-"
		 << "\n"
		 << "Looking forward to serve you again"
		 << endl;
}
//to get (the returning value) the weight
//table of specific length (parameter)
int getWeightTable(int wT)
{	
	int wt = 0;
	while (wT > 0)
	{
		wT /= 10;
		++wt;
	}
	return wt;
}


//to get the sum of weight
int getAlphabet(int nric, int weight)
{
	int sum = 0;
	
	while(nric > 0)
	{
		sum += ((nric % 10) * (weight % 10));
		nric /= 10;
		weight /= 10;
	}
	
	sum = 11 - (sum % 11);
	return sum;
}

//to check (true or false) if the NRIC number
//is of specific length (the two parameters)
bool checkLength(int length, int nric)
{
	if (nric != length)
	{
		return false;
	}
	else
	{
		return true;
	}
}

//to get the letter
char letter(int sum)
{
	switch(sum)
	{
		case 1: return 'A';
			    break;
		
		case 2: return 'B';
			    break;
		
		case 3: return 'C';
			    break;
		
		case 4: return 'D';
			    break;
		
		case 5: return 'E';
			    break;
		
		case 6: return 'F';
			    break;
		
		case 7: return 'G';
			    break;
		
		case 8: return 'H';
			    break;
		
		case 9: return 'I';
			    break;
		
		case 10: return 'Z';
			    break;
		
		case 11: return 'J';
			    break;      	            
	}
}

