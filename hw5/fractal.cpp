/***********************************************************************
 * Program: fractal.cpp
 * Author: Tu Lam
 * Date: 03/03/2019
 * Description: Printing out a design using recursive of stars and blank
 * Input: User declare how many stars and blank space
 * Output: Printing out the design
 **********************************************************************/

#include <iostream> //This library is for the cin and cout function
#include <string> // This library is for using the C++ string and using getline
#include <cstdlib> //This library is for using atoi and atof to convert the string to number

using namespace std;

//This is where all functions are declared
void design_pattern(int blank, int asterisk);
int check_i(string input_num);
bool play_again();

int main() {

   string input_num;
   int space, star;
   bool try_again = true;
 
   while (try_again == true) {
   cout << "________________________" << endl;
   cout << "Recursive Fractal Design" << endl;
   cout << "------------------------" << endl;

   cout << "\nEnter a number for the star(*) shape: ";
   getline(cin,input_num);
   star = check_i(input_num);

   while (star < 0) {

      cout << "You enter something invalid, please try again: ";
      getline(cin,input_num);
      star = check_i(input_num);
   }
   
   cout << "\nEnter a number for the blank space: ";
   getline(cin,input_num);
   space = check_i(input_num);

   while (space < 0) {

      cout << "You enter something invalid, please try again: ";
      getline(cin,input_num);
      space = check_i(input_num);
   }

   design_pattern(space,star);
   try_again = play_again();
   }
 
return 0;
}

//This is for the design to be printed out base on user input
void design_pattern(int blank, int asterisk) {

   if (asterisk == 0) {
      return;
   }
      
   design_pattern(blank, asterisk / 2);
   for (int k = 0; k < blank; k++) cout << "  ";
   for (int k = 0; k < asterisk; k++) cout << "* ";
   cout << endl;
   design_pattern((blank + asterisk / 2), asterisk / 2);
}

//This function is for checking if the user enter a good or bad number
int check_i(string input_num) {

   int good_i;
   bool check_num = false;

   while (check_num == false) {

      for (int i = 0; i < input_num.size(); i++) {

         if (!(input_num.at(i) >= '0' && input_num.at(i) <= '9')) {

            cout << "You enter something invalid, please try again: ";
            getline(cin,input_num);
         }

         else {
            
            check_num = true;
         }
      }
   }

   good_i = atoi(input_num.c_str());

return good_i;
}

//This function is for going again if the player want to go again
bool play_again() {

   int again;
   string input_num;
   
   cout <<"\nDo you want to print another design? (0-no, 1-yes): ";
   getline(cin,input_num);
   again = check_i(input_num);

   while (!(again == 0 || again == 1)) {

      cout << "You enter something invalid, please try again: ";
      getline(cin,input_num);
   }

   if (again == 0) {

      return false;
   }
   
   else {
   
      return true;
   }
}
