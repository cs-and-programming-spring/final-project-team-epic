// Example program
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

class drivers           // Creating class for driveres
{
    public:
    string name;
    string phoneNum;
    string city;
    string otherCities;
    int hour;
    int min;
    int day;
    int month;
    char colon;


    void driverInfo()         // called to obtain drivers info
    {

      cout << " What is your name "<< endl;
  cin>>name;
     cout << " What is your Phone Number "<< endl;
  cin>>phoneNum;
     cout << " What city you are traveling to "<< endl;
  cin>>city;
     cout << " What DAY you are traveling "<< endl;
  cin >> month >> colon >> day;
      cout << " What TIME you are traveling, please use 24 hour  system "<< endl;
  cin >> hour >> colon >> min ;

    }
};
class riders
{
public:
string name;
string phoneNum;
string city;
string otherCities;
int hour;
int min;
int day;
int month;
char colon;



void riderInfo()
{

  cout << " What is your name "<< endl;
cin>>name;
 cout << " What is your Phone Number "<< endl;
cin>>phoneNum;
 cout << " What city you are traveling to "<< endl;
cin>>city;
 cout << " What DAY you are traveling "<< endl;
cin >> month >> colon >> day;
  cout << " What TIME you are traveling, please use 24 hour  system "<< endl;
cin >> hour >> colon >> min ;

}

};



void readingDriversfiles()
{

  vector<drivers> newDriver;
  drivers oldDriver;

  while(true)
  {
  ifstream infile("driver.txt");
    	if (!infile)
  	{
  		cout << "Error opening the file. \n";
      break;
  	}

    	while (infile.good())
  	 {

        	infile >> oldDriver.name >> oldDriver.phoneNum >> oldDriver.city;
  		newDriver.push_back(oldDriver);
  	}

     infile.close();
     for (int i =0; i<2; i++)  //just changed here
     {
  	 cout <<  newDriver[i].name << " " << newDriver[i].phoneNum << " " << newDriver[i].city << "\n";
     }

     //return 0;
    }
  }




int main()
{

   int driversCount = 0;
   int ridersCount = 0;
   bool running = true;

   drivers driver[driversCount+1];
   riders rider[ridersCount+1];

   while (running)
   {
   int ans;



   cout << " Please Enter 1 if you are a Driver or 2 if you are a Rider : " << endl;
   cin >> ans;
   if (ans == 1)
   {
     string driverFile="driverFile0";
     string txt="txt";
     string dot=".";

     driverFile = driverFile+dot;
     driverFile = driverFile+txt;

    int i = 1;
    while(true)
    {

      cout << i <<endl;
      string result;
      stringstream ss;
      ss << i;
      result = ss.str();
      cout <<result <<endl;


      driverFile = driverFile.replace(10,1,result);
      cout << driverFile <<endl;


       ifstream infile(driverFile);
        if (!infile)
      {
        cout << "Error opening the file. \n";
        break;
      }

        while (infile.good())
       {

            infile >> driver[driversCount].name >> driver[driversCount].phoneNum >> driver[driversCount].city >> driver[driversCount].month
            >> driver[driversCount].colon >> driver[driversCount].day >> driver[driversCount].hour
            >>driver[driversCount].colon >> driver[driversCount].min ;
        }

       infile.close();
       {
       cout <<  driver[driversCount].name << " " << driver[driversCount].phoneNum << " " << driver[driversCount].city
            << " " << driver[driversCount].month << " " <<  driver[driversCount].colon << " " << driver[driversCount].day << driver[driversCount].hour
            <<" " << driver[driversCount].colon << " " << driver[driversCount].min << "\n";
       }
       i++;
       cout << driversCount << " DriversCount "<<endl;

       driversCount++;
       cout << driversCount << " DriversCount "<<endl;

    }


     driver[driversCount].driverInfo();





     ofstream myfile (driverFile);

     {

         myfile << driver[driversCount].name << " \n";
         myfile << driver[driversCount].phoneNum << " \n";
         myfile << driver[driversCount].city << " \n";
         myfile << driver[driversCount].day << " \n";
         myfile << driver[driversCount].month << " \n";
         myfile << driver[driversCount].hour << " \n";
         myfile << driver[driversCount].min << " \n";
       }
       myfile.close();



   }
    else if (ans == 2)
    {

      rider[ridersCount].riderInfo();
      for(int i = 0; i <= driversCount; i++)    // start to loop through the array
         {
          //drivers drive= ;
          cout  << driver[0].city <<endl;
          cout  << driver[1].city <<endl;



            if (rider[0].city == driver[i].city  )   // if match is found
               {
                       cout << " Congrats, we found a match " <<endl;  	// turn flag on
                       cout << " Your Driver profile : " <<endl;
                       cout << " **********************" <<endl;
                       cout << " name : ";
                       cout <<  driver[i].name <<endl;
                       cout << " phone number : " << driver[i].phoneNum <<endl;
                       cout << " **********************" <<endl;
                       //break ;    // break out of for loop
               }
               else
             cout << " No drivers available at this time, please try again later"<<endl;


          }

    }

   cout << " Do you want to run the program again ? "<<endl;
   cout << " Enter 1 for Yes and 2 for  No " << endl;
   cin >> running ;

}
}
