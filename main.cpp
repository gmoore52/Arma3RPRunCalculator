#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int run1pay, run2pay, runtype1final, runtype2final, cargo, runtype1weight, runtype2weight, runtype1finalpay, runtype2finalpay, moonmoney, moontruck, moonmoneyfinal, moonplacer, methmoney, methtruck, methmoneyfinal, methplacer, methtax, methdifference, moontax, moondifference;
char uselessvar, mode2, legallity, license;
string mode1, uselessvar1, legallity1, license1;
bool legal, wpl;

int main();

void runtax()
{
  cout << "Enter 1 if this run is legal, enter 2 if this run is illegal: ";
  cin >> legallity1;
  if(legallity1.length() != 1)
  {
    cout << "ok";
  }
  else
  {
    legallity = legallity1[0];
  }
  switch(legallity)
  {
    case '1':
      cout << "Do you have a workers protection license? 1 for yes, 2 for no: ";
      cin >> license1;
      if(license1.length() != 1)
      {
        cout << "Please enter a valid answer" << endl;
        runtax();
      }
      else
      {
        license = license1[0];
        switch(license)
        {
          
        }
      }
      break;
    case '2':

      break;
      
  }
  if(legallity == '1')
  {
    legal = true;
  }
  else if(legallity == '2')
  {
    legal = false;
  }
  else
  {
    cout << "Please enter a valid answer" << endl;
    runtax();
  }
  if(legal == true)
  {
    cout << "Do you have a workers protection license? 1 for yes, 2 for no: ";
    cin >> license1;
    if(license1.length() != 1)
    {
    cout << "Please enter a valid answer" << endl;
    runtax();
    }
    else
    {
    license = license1[0];
    }
    if(license == '1')
    {
      wpl = true;
    }
    else
    {
      wpl = false;
    }
  }
}

void restart()
{
  cout << "Enter Y to restart the program, enter any other key to close the program: ";
  cin >> uselessvar1;
  if(uselessvar1.length() != 1)
  {
    cout << "ok";
  }
  else
  {
    uselessvar = uselessvar1[0];
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
}

void meth()
{
  cout << "Enter meths current price: ";
  cin >> methmoney;
  cout << "Enter amount of space including character and vehicle: ";
  cin >> cargo;
  methplacer = cargo / 3;
  methtruck = methplacer / 2;
  methmoneyfinal = methmoney * methtruck;
  methtax = methmoneyfinal * 8.5 / 10;
  methdifference = methmoneyfinal - methtax;
  cout << "you will need " << methtruck << " of each required resource to make " << methtruck << " meth" << endl << "This run will make $" << methtax << " after cartel tax, and $" << methmoneyfinal << " before tax." << endl << "That is a difference of $" << methdifference << endl;
  restart();
}

void moonshine()
{
  cout << "Enter moonshines current price: ";
  cin >> moonmoney;
  cout << "Enter amount of space including character and vehicle: ";
  cin >> cargo;
  moonplacer = cargo / 3;
  moontruck = moonplacer / 2;
  moonmoneyfinal = moonmoney * moontruck;
  moontax = moonmoneyfinal * 8.5 / 10;
  moondifference = moonmoneyfinal - moontax;
  cout << "You will need " << moontruck << " of each required resource to make " << moontruck << " moonshine." << endl << "This run will make $" << moontax << " after cartel tax, and $" << moonmoneyfinal << " before tax." << endl << "That is a difference of $" << moondifference << endl;
  restart();
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
  restart();
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
  restart();
}

int main()
{
  mode1 = "1";
  mode2 = '1';
  cout << "Comparison, Calculator, Moonshine, or Meth? 1 for Comparison, 2 for Calculator, 3 for moonshine, 4 for Meth: ";
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
    case '4':
      meth();
      break;
    default:
      cout << "Please enter a valid answer" << endl;
      main();
    }
  }
}
