/******************************************************
 * Program: macros.cpp
 * Author: Tu Lam
 * Date: 1/12/2019
 * Description: Processing macros to produce the signed and unsigned 
                values and calculate it with the pow() and sizeof() function
 * Input: Min and Max values of macros
 * Output: Number that are min and max to signed and unsigned
 *****************************************************/

#include <iostream> 
#include <climits> //library of preprocessor macros include in the library
#include <cmath> //library of math for the pow() function

using namespace std;

int main() {

   cout << "Preprocessing Macros" << endl;

   cout << "Short Max: " << SHRT_MAX << endl;

   cout << "Short Min: " << SHRT_MIN << endl;

   cout << "Unsigned Short Max: " << USHRT_MAX << endl;

   cout << "Int Max: " << INT_MAX << endl;

   cout << "Int Min: " << INT_MIN << endl;

   cout << "Unsigned Int Max: " << UINT_MAX << endl;

   cout << "Long Max: " << LONG_MAX << endl;

   cout << "Long Min: " << LONG_MIN << endl;

   cout << "Unsigned Long Max: " << ULONG_MAX << endl;



   cout << "\nFunctions & Calculations (sizeof & pow)" << endl;

   //Short typecast
   //Typecast short was not written due to it limit how much number can present in the signed function
   cout << "Signed Short Max: " << pow(2,sizeof(short)*8-1)-1 << endl;

   cout << "Signed Short Min: " << -pow(2,sizeof(short)*8-1) << endl;

   cout << "Unsigned Short Max: " << (unsigned short) (pow(2,sizeof(short)*8)-1) << endl;

   //Int typecast
   //Typecast int and long need to be type beyond here due to getting a scientific number and want to limit how much it show up
   cout << "Signed Int Max: " <<  (int) pow(2,sizeof(int)*8)-1 << endl;

   cout << "Signed Int Min: " << (int) -pow(2,sizeof(int)*8) << endl;
 
   cout << "Unsigned Int Max: " << (unsigned int) pow(2,sizeof(int)*8)-1 << endl;

   //Long typecast
   cout << "Signed Long Max: " << (long) pow(2,sizeof(long)*8)-1 << endl;

   cout << "Signed Long Min: " << (long) -pow(2,sizeof(long)*8) << endl;

   cout << "Unsigned Long Max: " << (unsigned long) pow(2,sizeof(long)*8)-1 << endl;


   return 0;
}
