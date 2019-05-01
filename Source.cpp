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
    char colon2;



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
class riders       // creates a class for riders
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
char colon2;




void riderInfo()       // obtaining riders info
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



int main()
{

   int driversCount = 0;         // keeps track of drivers 
   int ridersCount = 0;           // keeps track of riders 
   bool running = true;             // used to run the program as needed

   drivers driver[driversCount+1];
   riders rider[ridersCount+1];

   while (running)
   {
   int ans;

   cout << " Please Enter 1 if you are a Driver or 2 if you are a Rider : " << endl;
   cin >> ans;

   string driverFile="driverFile0";      // creating a name for the driver files
   string txt="txt";                    
   string dot=".";     
   int position = driverFile.length();
   driverFile = driverFile.insert(position,dot);
   driverFile = driverFile+txt; 
   cout << driverFile <<endl;

   int i = 1;              //used to create different files names for drivers 
   while(true)
   {

    string result;                       // next 4 lines used to convert i from int to string 
    stringstream ss; 
    ss << i;
    result = ss.str();
    driverFile = driverFile.replace(10,1,result);  


     ifstream infile(driverFile);          // reading files with " driverFile(i).text"
      if (!infile)                          // if no files are found, break out of the while loop 
    {
      break;      
    }

      while (infile.good())                  // while more lines exist in the file 
     {

          infile >> driver[driversCount].name >> driver[driversCount].phoneNum >> driver[driversCount].city >> driver[driversCount].month
           >> driver[driversCount].day >> driver[driversCount].hour
           >> driver[driversCount].min ;      // used to read files one line at a time 
      }

     infile.close();         
     {
     cout <<  driver[driversCount].name << " " << driver[driversCount].phoneNum << " " << driver[driversCount].city
          << " " << driver[driversCount].month << " "  << driver[driversCount].day << driver[driversCount].hour
           << " " << driver[driversCount].min << "\n";         
     }
     i++;             // go to the next driver file 
     driversCount++;    // create a new driver 
     
   }
   if (ans == 1)  
   {

     driver[driversCount].driverInfo(); // if a driver is being added, take their info from the class


     ofstream myfile (driverFile);          // create a file for the new driver 

     {

         myfile << driver[driversCount].name << " \n";     // first line in the text file 
         myfile << driver[driversCount].phoneNum << " \n"; // second line in the text file
         myfile << driver[driversCount].city << " \n";     // third line in the text file
         myfile << driver[driversCount].day << " \n";      // fourth line in the text file
         myfile << driver[driversCount].month << " \n";    // fifth line in the text file
         myfile << driver[driversCount].hour << " \n";     // sixth line in the text file
         myfile << driver[driversCount].min << " \n";      // seventh line in the text file 
       }
       myfile.close();                                     // close the file 
   }
    else if (ans == 2)
    {

      rider[ridersCount].riderInfo();                 
      for(int i = 0; i <= driversCount; i++)    // start looping through drivers 
         {

            if (rider[ridersCount].city == driver[i].city && rider[ridersCount].month == driver[i].month
            && rider[ridersCount].day == driver[i].day      )   // if match is found
               {
                       cout << " Congrats, we found a match " <<endl;  	// turn flag on
                       cout << " Your Driver profile : " <<endl;
                       cout << " **********************" <<endl;
                       cout << " name : ";
                       cout <<  driver[i].name <<endl;
                       cout << " phone number : " << driver[i].phoneNum <<endl;
                       cout << " Driver leaving at  : " << driver[i].hour << ":"<<driver[i].min<<endl;

                       cout << " **********************" <<endl;
               }
               else
             cout << " No other/drivers available at this time, please try again later"<<endl;
          }
    }

   cout << " Do you want to run the program again ? "<<endl;
   cout << " Enter 'yes' for Yes or 'no' for  No " << endl;
   
   enum  trueFalse { no , yes };
   string input;
   cin >> input;
   if (input == "yes"){
     running = yes;
   }
   else{
     running = no;
   }

}
}
