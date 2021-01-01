#include <iostream>
#include <cmath>
#include <string>
using namespace std;

float run1pay, run2pay, runtype1final, runtype2final, cargo, runtype1weight, runtype2weight, runtype1finalpay, runtype2finalpay, moonmoney, moontruck;
char uselessvar, mode2;
string mode1;

int main();

void moonshine()
{
  cout << "Enter moonshines current price: ";
  cin >> moonmoney;
  cout << "Enter amount of space including character and vehicle: ";
  cin >> cargo;
  moontruck = cargo / 3;
  cout << moontruck;
  cout << "Enter Y to restart the program, press any other button to close the program: ";
  cin >> uselessvar;
  switch(uselessvar)
  {
    case 'Y':
      main();
      break;
    case 'y':
      main();
      break;
    default:
      cout << "ok";
  }
}

void comparison()
{
  cout << "Enter Run type 1's unrefined weight: ";
  cin >> runtype1weight;
  cout << "Enter Run type 2's unrefined weight: ";
  cin >> runtype2weight;
  cout << "Enter amount of space including character and vehicle: ";
  cin >> cargo;
  cout << "Enter Run 1's pay per item: ";
  cin >> run1pay;
  cout << "Enter Run 2's pay per item: ";
  cin >> run2pay;
  runtype1final = cargo / runtype1weight;
  runtype2final = cargo / runtype2weight;
  runtype1finalpay = runtype1final * run1pay;
  runtype2finalpay = runtype2final * run2pay;
  cout << "Run 1 will make: $" << runtype1finalpay << endl << "Run 2 will make: $" << runtype2finalpay << endl;
  cout << "Enter Y to restart the program, press any other button to close the program: ";
  cin >> uselessvar;
  switch(uselessvar)
  {
    case 'Y':
      main();
      break;
    case 'y':
      main();
      break;
    default:
      cout << "ok";
  }
}

void calc()
{
  cout << "Enter run unrefined weight: ";
  cin >> runtype1weight;
  cout << "Enter run pay per item: ";
  cin >> run1pay;
  cout << "Enter amount of space including character and vehicle: ";
  cin >> cargo;
  runtype1final = cargo / runtype1weight;
  runtype1finalpay = runtype1final * run1pay;
  cout << "This run will make: $" << runtype1finalpay << endl;
  cout << "Enter Y to restart the program, press any other button to close the program: ";
  cin >> uselessvar;
  switch(uselessvar)
  {
    case 'Y':
      main();
      break;
    case 'y':
      main();
      break;
    default:
      cout << "ok";
  }
}

int main()
{
  mode1 = "1";
  mode2 = '1';
  cout << "Comparison, Calculator or Moonshine? 1 for Comparison, 2 for Calculator, 3 for moonshine: ";
  cin >> mode1;
  if(mode1.length() != 1)
  {
    cout << "Please enter a valid answer" << endl;
    main();
  }
  else
  {
    mode2 = mode1[0];
    switch(mode2)
    {
    case '1':
      comparison();
      break;
    case '2':
      calc();
      break;
    case '3':
      moonshine();
      break;
    default:
      cout << "Please enter a valid answer" << endl;
      main();
    }
  }
}
