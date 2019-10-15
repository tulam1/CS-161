/***********************************************
 * Program: games.cpp
 * Author: Tu Lam
 * Date: 1/17/2019
 * Description: A text based adventure game where your input affect your outcome of the story
 * Input: Player input in number from 1-2
 * Output: The outcome to the story the player chose
 **********************************************/

#include <iostream>  //Library to include the int main() {
#include <ctime>  //This library is including the time() for randomize
#include <cstdlib>  //This library is including the rand() & srand() variable

using namespace std;


int main() {

   srand(time(NULL));
   char again = 'Y';  //Integer for looping the game back
   int a;  //Integer value from a-g is for the player to put in input 
   int b;
   int c;
   int d;
   int e;
   int f;
   int g;


   while (again == 'y' || again == 'Y') {  //The loop for player to play again
      
      cout << "Welcome to the Knight & Princess GAME" << endl;  //The game title 
      cout << "-------------------------------------\n" << endl;

      cout << "You begin your journey as a knight on a mission to rescue the princess. Do you accept the mission?" << endl;
      cout << "(Press #1) Accept the mission | (Press #2) Decline the mission\n" << endl;
      cin >> a;  //Letting the player put in input
      cout << "The option you chose was: " << a << endl;
     
      if (a == 1) {  //The if/else if statement let the player to the path outcome depend on what they chose
      
         cout << "You accept the mission and on the path to rescuing the princess." << endl;
         cout << "As you are walking, a giant boulder is blocking your path up the hill. What would you do?" << endl;
         cout << "(Press #1) Smash the boulder with your sword | (Press #2) Walk around the boulder\n" << endl;
         cin >> b;
         cout << "Your option was: " << b << endl;  //This displaying the number the player choose next to the text
         
         if (b == 1) {

            cout << "You pick to smash the boulder. The chance of you smashing the boulder is depended on the dice from 0-10." << endl;
            cout << "If you roll an even number, you were able to smash. If not, you weren't able to smash it.\n" << endl;
            c = rand() %11;  //Assign the variable to do a randomizer
            cout << "You roll a: " << c << endl;

            if ((c%2)==1) {  //This is the remainder equation to tell if it is odd or eve number
            
               cout << "You end up with an odd number. Sorry you weren't able to smash it." << endl;
               cout << "After smashing it, the boulder begin to roll in your direction and crush you. You perish.(GAME OVER)\n" << endl;
            }

            else if ((c%2)==0) {
               
               cout << "You end up with an even number. You were able to smash the boulder." << endl;
               cout << "After smashing it, the boulder crumble and you continue ahead to the dragon's dugeon." << endl;
               cout << "You head to the dugeon and discover the princess is next to the dragon. What would you do?" << endl;
               cout << "(Press #1) Fight the dragon | (Press #2) Give up the mission\n" << endl;
               cin >> g;
               cout << "Your input was: " << g << endl;

               if (g == 1) {

                  cout << "You chose to fight the dragon and won the battle. You end up rescuing the princess." << endl;
                  cout << "You win.(THE END)\n" << endl;
               }
               
               else if (g == 2) {

                  cout << "You chose to abandoned the mission and go home. The dragon saw you leaving it dugeon." << endl;
                  cout << "It chase after and swalloe you inside it stomach. You perish.(GAME OVER)\n" << endl;
               }
            }                                                    
         }

         else if (b == 2) {
    
            cout << "You decide to walk around the boulder and head straight to the dragon's dugeon." << endl;
            cout << "As you discover the dragon's dugeon, you decide to walk in and spot the princess next to the dragon." << endl;
            cout << "(Press #1) Sneak inside to free the princess | (Press #2) Fight the dragon\n" << endl;
            cin >> d;
            cout << "Your choice was: " << d << endl;

            if (d == 1) {

               cout << "You chose to be sneaky and free the princess, but it depend on what number you land on from 0-20.\n" << endl;
               e = rand() %21;
               cout << "You roll a: " << e << endl;

               if ((e%2)==1) {
               
                  cout << "You roll an odd number. You successfully rescue the princess and live happily forvever.(THE END)\n" << endl;
               }

               else if ((e%2)==0) {
             
                  cout << "You roll an even number. You end up failing to rescue the princess and the dragon discover you." << endl;
                  cout << "The dragon then burn you to toast and you end up perish.(GAME OVER)\n" << endl;
               }
            }
            
            else if (d == 2) {
   
               cout << "You chose to fight the dragon, but the outcome depend on a dice between 0-5." << endl;
               cout << "If you roll an even, you beat the dragon. If not, you perish.\n" << endl;
               f = rand() %6;
               cout << "The outcome was: " << f << endl;

               if ((f%2)==1) {

                  cout << "You roll an odd. You didn't won the fight and the dragon end up killing you." << endl;
                  cout << "You perish.(GAME OVER)\n" << endl;
               } 

               else if ((f%2)==0) {

                  cout << "You roll an even. You defeat the dragon and rescue the princess, you win.(THE END)\n" << endl;
               }
            }         
         }
      }

      else if (a == 2) {

         cout << "You decline the mission, and the king wasn't impress with your choice." <<  endl;
         cout << "He decided to have you kill off. You perish. (GAME OVER!)" << endl;
      }

      cout << "Would you like to play again? [y/n]: ";
      cin >> again;
   }  //Ending the game loop

   cout << "Thank you for playing the GAME!" << endl;


   return 0;
}
