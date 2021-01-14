#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int run1pay, run2pay, runtype1final, runtype2final, cargo, runtype1weight, runtype2weight, runtype1finalpay, runtype2finalpay, moonmoney, moontruck, moonmoneyfinal, moonplacer, methmoney, methtruck, methmoneyfinal, methplacer, methtax, methdifference, moontax, moondifference, bonusmoney, runtype1tax, runtype2tax, runtype1diff, runtype2diff, diffamount, placeholdervar, selectvar, upgradetier;

char uselessvar, mode2, legallity, license, category, vehicle;

string mode1, uselessvar1, legallity1, license1, category1, vehicle1, upgradetier1;

string *selectpoint;

bool legal, wpl;

string groundvehicles[9] = {"Enter 1 for Quadbike", "Enter 2 for Hatchback", "Enter 3 for Hatchback (Sport)", "Enter 4 for Offroad", "Enter 5 for Offroad (Covered)", "Enter 6 for MB 4WD (Jeep)", "Enter 7 for SUV", "Enter 8 for Van (Transport)", "Enter 9 for Van (Cargo)"};

int groundspace[5][9] = {
  {20, 40, 40, 80, 100, 80, 100, 80, 200},
  {21, 42, 42, 84, 105, 84, 105, 84, 210},
  {22, 44, 44, 88, 110, 88, 110, 88, 220},
  {23, 46, 46, 92, 115, 92, 115, 92, 230},
  {24, 48, 48, 96, 120, 96, 120, 96, 240}};

string airvehicles[6] = {"Enter 1 for M900/MH-9", "Enter 2 for Orca", "Enter 3 for Hellcat", "Enter 4 for Mohawk/Huron (Unarmed)", "Enter 5 for Taru", "Enter 6 for Taru Transport"};

int airvehiclespace[5][9] = {
  {80, 160, 80, 300, 140, 300},
  {84, 168, 84, 315, 147, 315},
  {88, 176, 88, 330, 154, 330},
  {92, 184, 92, 345, 161, 345},
  {96, 192, 96, 360, 168, 360}};

string trucks[9] = {"Enter 1 for Flatbed Truck", "Enter 2 for Box Truck", "Enter 3 for Zamak Transport", "Enter 4 for Zamak Transport (Covered)", "Enter 5 for Tempest Transport", "Enter 6 for Tempest Transport (Covered)", "Enter 7 for Tempest Device", "Enter 8 for HEMMT Transport", "Enter 9 for HEMMT Box"};

int truckspace[5][9] = {
  {200, 300, 400, 600, 600, 800, 600, 800, 1000},
  {210, 315, 420, 630, 630, 840, 625, 840, 1050},
  {220, 330, 440, 660, 660, 880, 660, 880, 1100},
  {230, 345, 460, 690, 690, 920, 690, 920, 1150},
  {240, 360, 480, 720, 720, 960, 720, 960, 1200}};

string fuel[4] = {"Enter 1 for Fuel Truck", "Enter 2 for Zamak Fuel", "Enter 3 for Tempest Fuel", "Enter 4 for HEMMT Fuel"};

int fuelspace[5][9] = {
  {300, 600, 800, 1000},
  {315, 630, 830, 1050},
  {330, 660, 860, 1100},
  {345, 690, 890, 1150},
  {360, 720, 920, 1200}};

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

void vehicleselect(int array1[5][9], int x, int y)
{
  cargo = array1[y][x];
}

void selection()
{
  int n;
  cout << "1 for Ground Vehicles" << endl;
  cout << "2 for Cargo Trucks" << endl;
  cout << "3 for Fuel Trucks" << endl;
  cout << "4 for Air Vehicles" << endl;
  cout << "Please select a vehicle category: ";
  cin >> category1;
  if(category1.length() != 1)
  {
    cout << "Please enter a valid answer" << endl;
    selection();
  }
  else
  {
    category = category1[0];
    switch(category)
    {
      case '1':
        selectpoint = groundvehicles;
        n = 9;
        placeholdervar = 1;
        break;
      case '2':
        selectpoint = trucks;
        n = 9;
        placeholdervar = 2;
        break;
      case '3':
        selectpoint = fuel;
        n = 4;
        placeholdervar = 3;
        break;
      case '4':
        selectpoint = airvehicles;
        n = 6;
        placeholdervar = 4;
        break;
      default:
        cout << "Please enter a valid answer" << endl;
    }
    for(int i = 0; i < n; i++)
    {
      cout << selectpoint[i] << endl;
    }
    cout << "Select a vehicle: ";
    cin >> vehicle1;
    if(vehicle1.length() != 1)
    {
      cout << "Please enter a vaild answer";
      selection();
    }
    else
    {
      vehicle = vehicle1[0];
      vehicle = --vehicle;
    }
    cout << "Please enter what tier of cargo upgrades you have." << endl << "0 for no upgrades" << endl << "1 for tier 1 upgrades" << endl << "2 for tier 2 upgrades" << endl << "3 for tier 3 upgrades" << endl << "4 for tier 4 upgrades" << endl;
    cin >> upgradetier1;
    if(upgradetier1.length() != 1)
    {
      cout << "Please enter a valid answer" << endl;
      selection();
    }
    else
    {
      upgradetier = upgradetier1[0];
    }
    switch(placeholdervar)
    {
      case 1:
        vehicleselect(groundspace, vehicle, upgradetier);
        break;
      case 2:
        vehicleselect(truckspace, vehicle, upgradetier);
        break;
      case 3:
        vehicleselect(fuelspace, vehicle, upgradetier);
        break;
      case 4:
        vehicleselect(airvehiclespace, vehicle, upgradetier);
        break;
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
  selection();
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
  selection();
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
  selection();
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
  selection();
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
