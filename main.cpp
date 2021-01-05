#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int run1pay, run2pay, runtype1final, runtype2final, cargo, runtype1weight, runtype2weight, runtype1finalpay, runtype2finalpay, moonmoney, moontruck, moonmoneyfinal, moonplacer, methmoney, methtruck, methmoneyfinal, methplacer, methtax, methdifference, moontax, moondifference, bonusmoney, runtype1tax, runtype2tax, runtype1diff, runtype2diff, diffamount;
char uselessvar, mode2, legallity, license;
string mode1, uselessvar1, legallity1, license1;
bool legal, wpl;

int main();

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

void runtax()
{
  cout << "Enter 1 if this run is legal, enter 2 if this run is illegal: ";
  cin >> legallity1;
  if(legallity1.length() != 1)
  {
    cout << "Please enter a valid answer" << endl;
    runtax();
  }
  else
  {
    legallity = legallity1[0];
    switch(legallity)
    {
      case '1':
        legal = true;
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
            case '1':
              bonusmoney = 15 / 10;
              wpl = true;
              break;
            case '2':
              bonusmoney = 0;
              wpl = false;
              break;
            default:
              cout << "Please enter a valid answer" << endl;
              runtax();
            }
          }
        break;
      case '2':
        bonusmoney = 0;
        legal = false;
        break;
      default:
        cout << "Please enter a valid answer" << endl;
        runtax();
      
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
  cout << "Enter amount of space including character and vehicle: ";
  cin >> cargo;
  cout << "Enter Run type 1's unrefined weight: ";
  cin >> runtype1weight;
  cout << "Enter Run 1's pay per item: ";
  cin >> run1pay;
  runtype1final = cargo / runtype1weight;
  runtype1finalpay = runtype1final * run1pay;
  runtax();
  if(legal == true)
  {
    if(wpl == true)
    {
      runtype1tax = runtype1finalpay *  15 / 10;
      runtype1diff = runtype1tax - runtype1finalpay;
      cout << "Run 1 will make $" << runtype1tax << " with workers protection." << endl;
      cout << "That is a bonus amount of $" << runtype1diff << endl;
    }
    else
    {
      runtype1tax = runtype1finalpay;
      cout << "Run 1 will make $" << runtype1tax << endl;
    }
  }
  else
  {
    runtype1tax = runtype1finalpay * 8.5 / 10;
    runtype1diff = runtype1finalpay - runtype1tax;
    cout << "Run 1 will make $" << runtype1tax << " after cartel tax and $" << runtype1finalpay << " before tax" << endl << "That is a difference of $" << runtype1diff << endl;
  }
  cout << "Enter Run type 2's unrefined weight: ";
  cin >> runtype2weight;
  cout << "Enter Run 2's pay per item: ";
  cin >> run2pay;
  runtype2final = cargo / runtype2weight;
  runtype2finalpay = runtype2final * run2pay;
  runtax();
  if(legal == true)
  {
    if(wpl == true)
    {
      runtype2tax = runtype2finalpay * 15 / 10;
      runtype2diff = runtype2tax - runtype2finalpay;
      cout << "Run 2 will make $" << runtype2tax << " with workers protection." << endl;
      cout << "That is a bonys amount of $" << runtype2diff << endl;
    }
    else
    {
      runtype2tax = runtype2finalpay;
      cout << "Run 2 will make $" << runtype2tax << endl;
    }
  }
  else
  {
    runtype2tax = runtype2finalpay * 8.5 / 10;
    runtype2diff = runtype2finalpay - runtype2tax;
    cout << "Run 2 will make $" << runtype2tax << " after cartel tax and $" << runtype2finalpay << " before tax" << endl << "That is a difference of $" << runtype2diff << endl;
  }
  if(runtype1tax > runtype2tax)
  {
    diffamount = runtype1tax - runtype2tax;
    cout << "Run 1 will make more money, with a $" << diffamount << " difference between the two runs" << endl;
  }
  else if(runtype1tax == runtype2tax)
  {
    cout << "Both of these runs will make the exact same amount." << endl;
  }
  else
  {
    diffamount = runtype2tax - runtype1tax;
    cout << "Run 2 will make more money, with a $" << diffamount << " difference between the two runs" << endl;
  }
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
  runtax();
  if(legal == true)
  {
    if(wpl == true)
    {
      runtype1tax = runtype1finalpay *  15 / 10;
      runtype1diff = runtype1tax - runtype1finalpay;
      cout << "Run 1 will make $" << runtype1tax << " with workers protection." << endl;
      cout << "That is a bonus amount of $" << runtype1diff << endl;
    }
    else
    {
      cout << "Run 1 will make $" << runtype1finalpay << endl;
    }
  }
  else
  {
    runtype1tax = runtype1finalpay * 8.5 / 10;
    runtype1diff = runtype1finalpay - runtype1tax;
    cout << "Run 1 will make $" << runtype1tax << " after cartel tax and $" << runtype1finalpay << " before tax" << endl << "That is a difference of $" << runtype1diff << endl;
  }
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
