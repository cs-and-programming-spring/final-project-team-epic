// Example program
#include <iostream>
#include <string>
#include <fstream>
#include <vector>



using namespace std;

class cars
{
    string make;
    string model;
    string year;

};
class drivers
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


    void driverInfo()
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
  int count = 1;
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
   char colon;

   drivers driver[driversCount+1];
   riders rider[ridersCount+1];

   while (running)
   {
   int ans;



   cout << " Please Enter 1 if you are a Driver or 2 if you are a Rider : " << endl;
   cin >> ans;
   if (ans == 1)
   {



     driver[driversCount].driverInfo();
   string line;




     ofstream myfile ("DriverList.txt");
     for(int i = 0; i <= driversCount; i++)
     {
        ifstream file ("DriverList.txt");
       {
         while ( getline (file,line) )
         {
           cout << line << '\n';
         }
       }
         myfile << line << " \n";
         myfile << driver[i].name << " \n";
         myfile << driver[i].phoneNum << " \n";
         myfile << driver[i].city << " \n";
         myfile << driver[i].day << " \n";
         myfile << driver[i].month << " \n";
         myfile << driver[i].hour << " \n";
         myfile << driver[i].min << " \n";
       }
       myfile.close();
     //cout << driver[driversCount].city;
    // driversCount++;

   }
    else if (ans == 2)
    {

      rider[ridersCount].riderInfo();
      for(int i = 0; i <= driversCount; i++)    // start to loop through the array
         {
          //drivers drive= ;
          //riders ride=;

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

             cout << " Would you like to check list of cities "<<endl;
             cout << rider[0].name <<endl;
          }

    }

   cout << " Do you want to run the program again ? "<<endl;
   cout << " Enter 1 for Yes and 2 for  No " << endl;
   cin >> running ;

}
}
