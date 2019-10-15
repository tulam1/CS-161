/*********************************************************************************
 * Program: expense.cpp
 * Author: Tu Lam
 * Date: 02/15/2019
 * Description: Creating a travel expense calculator to compute the total expense the user going to be spending
 * Input: Let user input their amounts and days into the program
 * Output: Calculating their expense to see where their rough estimate is equal to
 *********************************************************************************/

#include <iostream> //This include the cout, cin, and main() function
#include <string> //This include the string function to store in user input
#include <cstdlib> //This is including atoi to convert string back on int or float


using namespace std;

//All this function listed is to be declare and use inside the int main() function
int num_day();
int check_i(string input);
float check_f(string input);
float depart_time();
float arrive_time();
void airfare_money(float &expense, float &reimburse);
void conference_seminar(float &expense, float &reimburse);
void vehicle_option(float &expense, float &reimburse, int num_day, float time_depart, float time_arrive);
void choose_car(float &expense, float &reimburse, int num_day, float time_depart, float time_arrive);
void car_type(float &reimburse, int num_day);
void total_rentalcar_gas(float &expense);
void taxi_type(float &expense, float &reimburse, int num_day);
void parking_fee(float &expense, float &reimburse, int num_day);
void hotel_fee(float &expense, float &reimburse, int num_day);
void breakfast_meal(float &expense, float &reimburse, int c_day, int l_day, float time_depart, float time_arrive);
void lunch_meal(float &expense, float &reimburse, int c_day, int l_day, float time_depart, float time_arrive);
void dinner_meal(float &expense, float &reimburse, int c_day, int l_day, float time_depart, float time_arrive);
void meal_fee(float &expense, float &reimburse, int num_day, float time_depart, float time_arrive);
bool check_running();

int main() { //Main function that store all the other functions in

   float expense, reimburse, time_depart, time_arrive; //This declaration will be use for reference to change these variables
   int day; //This variable is assign to num_day() function to fetch the return value in that function
   bool again = true;

   while (again == true) {
   day = num_day();
   time_depart = depart_time();
   time_arrive = arrive_time();
   airfare_money(expense, reimburse);
   conference_seminar(expense, reimburse);
   vehicle_option(expense, reimburse, day, time_depart, time_arrive);

   cout << "\nYour total expense for this trip is: " << expense << endl;
   cout << "Your total reimbursement for this trip is: " << reimburse << endl;
   again = check_running();
   }

return 0;
}

//This function allow user to enter the number of day(s) they are travelling
int num_day() {
   
   int num_day;
   string input;
   cout << "________________________________" << endl;
   cout << "Report Travel Expense Calculator" << endl;
   cout << "--------------------------------" << endl;
   cout << "\nEnter the number of day(s) you want to travel: ";
   getline(cin,input);
   num_day = check_i(input);

   while (num_day < 1) {
      cout << "You enter an invalid response, please try again: ";
      getline(cin,input);
      num_day = check_i(input);
   }

return num_day;
}

//This function let user input time of departure
float depart_time() {

   float departure;
   string input;
   cout << "\nEnter the time depart on the first day (24-hours): ";
   getline(cin,input);
   departure = check_f(input);

   while (departure > 24 || departure < 0) {
      cout << "You enter an invalid response, please try again: ";
      getline(cin,input);
      departure = check_f(input);
   }

return departure;
}

//This function let user enter the time of arrival
float arrive_time() {

   float arrival;
   string input;
   cout << "\nEnter the time arrive on the last day (24-hours): ";
   getline(cin,input);
   arrival = check_f(input);

   while (arrival > 24 || arrival < 0) {
      cout << "You enter an invalid response, please try again: ";
      getline(cin,input);
      arrival = check_f(input);
   }

return arrival;
}

//This function let user enter the amount of airfare they travel
void airfare_money(float &expense, float &reimburse) {

   float airfare;
   string input;
   cout << "\nEnter in the total amount of airfare spend on this trip ($ form): ";
   getline(cin,input);
   airfare = check_f(input);

   while (airfare < 0) {
      cout << "You enter an invalid response, please try again: ";
      getline(cin,input);
      airfare = check_f(input);
   }

   expense = airfare;
   reimburse = airfare;
}

//This function let user enter the money they spent on conference/seminar
void conference_seminar(float &expense, float &reimburse) {

   float registration;
   string input;
   cout << "\nEnter in the total amount of conference/seminar spend on this trip ($ form): ";
   getline(cin,input);
   registration = check_f(input);

   while (registration < 0) {
      cout << "You enter an invalid response, please try again: ";
      getline(cin,input);
      registration = check_f(input);
   }
      
   expense += registration;
   reimburse += registration;
}

//This function determine user if they are travelling in a car or taxi
void vehicle_option(float &expense, float &reimburse, int num_day, float time_depart, float time_arrive) {

   int option;
   string input;
   cout << "\nWhat type of transportation did you use (car - 1, taxi - 2): ";
   getline(cin,input);
   option = check_i(input);

   while (!(option == 1 || option == 2)) {
      cout << "You enter an invalid response, please try again: ";
      getline(cin,input);
      option = check_i(input);
   }

   if (option == 1) {
      choose_car(expense, reimburse, num_day, time_depart, time_arrive);
   }

   else if (option == 2) {
      taxi_type(expense, reimburse, num_day);
   }
}

//This function help to combine two functions into one function for car
void choose_car(float &expense, float &reimburse, int num_day, float time_depart, float time_arrive) {

     car_type(reimburse, num_day);
     total_rentalcar_gas(expense);
     parking_fee(expense, reimburse, num_day);
     hotel_fee(expense, reimburse, num_day);
     meal_fee(expense, reimburse, num_day, time_depart, time_arrive);   
}

//This function help the user to pick a car type they want to drive
void car_type(float &reimburse, int num_day) {
 
   int car_option, miles;
   int rental_fee[4] = {20,25,30,50};
   float gas_fee[4] = {0.24,0.27,0.32,0.45};
   string input;
   cout << "Choose a car type that you will be driving from the list below" << endl;
   cout << "1. Sedan" << endl;
   cout << "2. SUV" << endl;
   cout << "3. Van" << endl;
   cout << "4. Convertible" << endl;
   cout << "Which one will you be using (Enter 1,2,3,or 4): ";
   getline(cin,input);
   car_option = check_i(input);

   while (!(car_option == 1 || car_option == 2 || car_option == 3 || car_option == 4)) {
      cout << "You enter an invalid response, please try again: ";
      getline(cin,input);
      car_option = check_i(input);
   }

   cout << "\nEnter the total miles driven (in miles): ";
   getline(cin,input);
   miles = check_i(input);

   while (miles < 0) {
      cout << "You enter an invalid response, please try again: ";
      getline(cin,input);
      miles = check_i(input);
   }

   reimburse = reimburse + (rental_fee[car_option - 1]*num_day) + (gas_fee[car_option - 1]*miles);
}

//This function help user input their total rental on car and gas fee
void total_rentalcar_gas(float &expense) {
   
   float total_rental, total_gas;
   string input;
   cout << "\nEnter total spent on rental car ($ form): ";
   getline(cin,input);
   total_rental = check_f(input);

   while (total_rental < 0) {
      cout << "You enter an invalid response, please try again: ";
      getline(cin,input);
      total_rental = check_f(input);
   }

   cout <<"Enter total spent on gas fee ($ form): ";
   getline(cin,input);
   total_gas = check_f(input);

   while (total_gas < 0) {
      cout << "You enter an invalid response, please try again: ";
      getline(cin,input);
      total_gas = check_f(input);
   }

   expense = expense + total_rental + total_gas;
}


//This function calculate the taxi expense if user chose the taxi option
void taxi_type(float &expense, float &reimburse, int num_day) {

   float taxi_spend;
   string input;
   cout << "Enter the total amount of money spend on taxi ($ form): ";
   getline(cin,input);
   taxi_spend = check_f(input);

   while (taxi_spend < 0) {
      cout << "You enter an invalid response, please try again: ";
      getline(cin,input);
      taxi_spend = check_f(input);
   }

   expense = expense + taxi_spend;
   reimburse = reimburse + (10 * num_day);
}

//This function for entering car fee parking depend on user day on the trip
void parking_fee(float &expense, float &reimburse, int num_day) {

   float parking[num_day];
   string input;
   for (int i = 1; i <= num_day; i++) {
      cout << "Enter parking fee for day " << i << ": ";
      getline(cin,input);
      parking[i] = check_f(input);

      while (parking < 0) {
         cout << "You enter an invalid response, please try again: ";
         getline(cin,input);
         parking[i] = check_f(input);
      } 
      
      expense = expense + parking[i];
      
      if (parking[i] > 6) {
      
         reimburse = reimburse + 6;
      }     

      else {

         reimburse = reimburse + parking[i];
      }
   }

}

//This function help user calculate how much they spend for hotel depend on how may day(s)
void hotel_fee(float &expense, float &reimburse, int num_day) {

   float hotel[num_day];
   string input;
   for (int i = 1; i < num_day; i++) {
      cout << "\nEnter hotel fee for night " << i << ": ";
      getline(cin,input);
      hotel[i] = check_f(input);

      while (hotel < 0) {
         cout << "You enter an invalid response, please try again: ";
         getline(cin,input);
         hotel[i] = check_f(input);
      } 
      
      expense = expense + hotel[i];
      
      if (hotel[i] > 90) {
      
         reimburse = reimburse + 90;
      }     

      else {

         reimburse = reimburse + hotel[i];
      }
  
   }
}

//This function is for breakfast
void breakfast_meal(float &expense, float &reimburse, int c_day, int l_day, float time_depart, float time_arrive) {

   float breakfast;
   string input;
   if (c_day == 1 && time_depart > 7) {
      cout << "Your breakfast for day " << c_day << " is not allowed as an expense" << endl;
   } 

   else if (c_day == l_day && time_arrive < 8) { 
      cout << "Your breakfast for day " << c_day << " is not allowed as an expense" << endl;
   }

   else {
      cout << "Enter breakfast fee ($ form): ";
      getline(cin,input);
      breakfast = check_f(input);

      while (breakfast < 0) {
         cout << "You enter an invalid response, please try again: ";
         getline(cin,input);
         breakfast = check_f(input);
      } 

      expense = expense + breakfast;
      if (breakfast > 9) {
         reimburse = reimburse + 9;
      }

      else {
         reimburse = reimburse + breakfast;
      }
   }
}

//This function is for lunch
void lunch_meal(float &expense, float &reimburse, int c_day, int l_day, float time_depart, float time_arrive) {
   
   float lunch;
   string input;
   if (c_day == 1 && time_depart > 12) {
      cout << "Your lunch for day " << c_day << " is not allowed as an expense" << endl;
   } 

   else if (c_day == l_day && time_arrive < 13) { 
      cout << "Your lunch for day " << c_day << " is not allowed as an expense" << endl;
   }

   else {
      cout << "Enter lunch fee ($ form): ";
      getline(cin,input);
      lunch = check_f(input);

      while (lunch < 0) {
         cout << "You enter an invalid response, please try again: ";
         getline(cin,input);
         lunch = check_f(input);
      } 

      expense = expense + lunch;
      if (lunch > 12) {
         reimburse = reimburse + 12;
      }

      else {
         reimburse = reimburse + lunch;
      }
   }
}

//This function is for dinner
void dinner_meal(float &expense, float &reimburse, int c_day, int l_day, float time_depart, float time_arrive) {
   
   float dinner;
   string input;
   if (c_day == 1 && time_depart > 18) {
      cout << "Your dinner for day " << c_day << " is not allowed as an expense" << endl;
   } 

   else if (c_day == l_day && time_arrive < 19) { 
      cout << "Your dinner for day " << c_day << " is not allowed as an expense" << endl;
   }

   else {
      cout << "Enter dinner fee ($ form): ";
      getline(cin,input);
      dinner = check_f(input);

      while (dinner < 0) {
         cout << "You enter an invalid response, please try again: ";
         getline(cin,input);
         dinner = check_f(input);
      } 

      expense = expense + dinner;
      if (dinner > 16) {
         reimburse = reimburse + 16;
      }

      else {
         reimburse = reimburse + dinner;
      }
   }
}

//This function comebine couple function for meal to compile it into one function
void meal_fee(float &expense, float &reimburse, int num_day, float time_depart, float time_arrive) {

   for (int i = 1; i <= num_day; i++) {
      cout << "\nDay " << i << endl;
      breakfast_meal(expense, reimburse, i, num_day, time_depart, time_arrive);
      lunch_meal(expense, reimburse, i, num_day, time_depart, time_arrive);
      dinner_meal(expense, reimburse, i, num_day, time_depart, time_arrive);     
   }
}

//This function help to check if the user enter an invalid input of integer
int check_i(string input) {

   int good_i;
   bool input_check = false;

   while (input_check == false) {

      for (int c_i = 0; c_i < input.size(); c_i++) {
     
         if (!(input.at(c_i) >= '0' && input.at(c_i) <= '9')) {
            cout << "You enter an invalid response, please try again: ";
            getline(cin,input);
         }

         else {
            input_check = true;
         }
      }
   }
   
   good_i = atoi(input.c_str());

return good_i;
}

//This function help to check if the user enter an invalid input of float
float check_f(string input) {

   float good_f;
   bool input_check = false;

   while (input_check == false) {

      for (int c_f = 0; c_f < input.size(); c_f++) {

         if (!((input.at(c_f) >= '0' && input.at(c_f) <= '9') || input.at(c_f) == '.')) {
            cout << "You enter an invalid response, please try again: ";
            getline(cin,input);
         }

         else {
            input_check = true;
         }
      }
   }

   good_f = atof(input.c_str());

return good_f;
}

//This function let user go again if they want to calculate another report
bool check_running() {

   int again;
   string input;
   cout << "\nDo you want to calculate another expense? (0-no, 1-yes): "; 
   getline(cin,input);
   again = check_i(input);

   while (!(again == 0 || again == 1)) {
      cout << "You enter an invalid response, please try again: ";
      getline(cin,input);
      again = check_i(input);
   }

   if (again == 0) {
      return false;
   }

   else {
      return true;
   }
}
