/**********************************************************
 * Program: 21_card.cpp
 * Author: Tu Lam
 * Description: Making a game of BlackJack and making the player trying to beat the dealer
 * Input: The amount of money from player, bet, how many players, and drawing card or not
 * Output: Seeing if the player won the game from the dealer
 *********************************************************/

#include <iostream> //This library is for the int main() function and the return function
#include <string> //This is to include in string to store data
#include <ctime> //This library is to create the time() for randomizing
#include <cstdlib> //This is for the variable rand() & srand()

using namespace std;

void dealer_turn() { //This is the function for the dealer

int c, dealer[21];
int total_dealer = 0;

   cout << "\nNow it's time for the dealer to go" << endl;
   cout << "The dealer drew a: ";
     
   do {
       
      int dealer_draw = rand()% 11+1;
      cout << dealer_draw << " ";
        
      for (c = 0; c < 1; c++) {
          
         dealer[c] = dealer_draw;
         total_dealer = total_dealer + dealer[c];
      } 
    } while(total_dealer <= 17);
         cout << "\nThe total amount the dealer drew was: " << total_dealer << endl;
}

int main() {


srand(time(NULL));
float money1, money2, money3, money4; //This is float, int are for getting card drawn, adding up total for player and banker
float bet1, bet2, bet3, bet4;
int num_player;
int get_card = 0, get_card2 = 0, get_card3 = 0, get_card4 = 0;
int draw_card1, draw_card2, draw_card3, draw_card4;
int total_card1 = 0, total_card2 = 0, total_card3 = 0, total_card4 = 0;
int total_dealer = 0;
float total_money1 = 0, total_money2 = 0, total_money3 = 0, total_money4 = 0;
int b, player_1[21], player_2[21], player_3[21], player_4[21]; //Array for card add up
bool again=true; //bool statement make it true and flase for incorrect input
bool bet_money1 = false, bet_money2 = false, bet_money3 = false, bet_money4 = false;
bool try_again = true; //Looping the game to play again

while (try_again) {

int draw_card1, draw_card2, draw_card3, draw_card4; //Repeated int to make the srand() doesn't continue where it left off
int total_card1 = 0, total_card2 = 0, total_card3 = 0, total_card4 = 0;

   cout << "______________________________________" << endl;
   cout << "Welcome to the game of BlackJack or 21" << endl;
   cout << "--------------------------------------\n" << endl;

   cout << "Enter the amount of player will be playing (1-4): ";
   cin >> num_player;

   while (num_player < 1 || num_player > 4) { //This is for the error fo the number of players if enter incorretly

      cout << "\nThe number of player you enter is not in the range, please try again" << endl;
      cout << "Enter the amount of player will be playing (1-4): ";
      cin >> num_player;
   }

   for (int a = 1; a <= num_player; a++) { //This is for the exact number of player to print

      if (a == 1) {

         cout << "\nPlayer 1 - Enter the amount of money to start you off: "; //Here is where player start an initial money and bet
         cin >> money1;
         cout << "This is your initial amount: " << money1 << endl;

         cout << "\nPlayer 1 - Enter the amount you desire to bet the dealer: ";
         cin >> bet1;
         cout << "This is the amount you bet: " << bet1 << endl;

         while (bet_money1 == false) { //This is for error when entering bet

            if (bet1 > money1 || bet1 <= 0) {

               cout << "\nThe amount you enter is invalid, please try again" << endl;
               cout << "Player 1 - Enter the amount you desire to bet the dealer: ";
               cin >> bet1;
               cout << "This is the amount you bet: " << bet1 << endl;
            }

            else {

               bet_money1 = true;
            }
         }

         cout << "\nType in 1 to start drawing card: "; //This draw card method is help to select randomizing card
         cin >> draw_card1;

         if (draw_card1 == 1) {

            while (draw_card1 == 1) {

               get_card = rand() %11+1;
               cout << "\nYou draw a: " << get_card << endl;

               for (b = 0; b < 1; b++) {

                  player_1[b] = get_card;
                  total_card1 = total_card1 + player_1[b];
               }

            cout << "Your total is: " << total_card1 << endl;
            cout << "Do you want to draw another card? (1-yes, 0-no): ";
            cin >> draw_card1;
            }
         }

         else if (draw_card1 !=1) {

            exit(0);
         }

         cout << "Your overall score is: " << total_card1 << endl;
      }

      else if (a == 2) {
       
         cout << "\nPlayer 2 - Enter the amount of money to start you off: ";
         cin >> money2;
         cout << "This is your initial amount: " << money2 << endl;

         cout << "\nPlayer 2 - Enter the amount you desire to bet the dealer: ";
         cin >> bet2;
         cout << "This is the amount you bet: " << bet2 << endl;

         while (bet_money2 == false) {

            if (bet2 > money2 || bet2 <= 0) {

               cout << "\nThe amount you enter is invalid, please try again" << endl;
               cout << "Player 2 - Enter the amount you desire to bet the dealer: ";
               cin >> bet2;
               cout << "This is the amount you bet: " << bet2 << endl;
            }

            else {

               bet_money2 = true;
            }
         }
      
         cout << "\nType in 1 to start drawing card: ";
         cin >> draw_card2;

         if (draw_card2 == 1) {

            while (draw_card2 == 1) {

               get_card2 = rand() %11+1;
               cout << "\nYou draw a: " << get_card2 << endl;

               for (b = 0; b < 1; b++) {

                  player_2[b] = get_card2;
                  total_card2 = total_card2 + player_2[b];
               }

            cout << "Your total is: " << total_card2 << endl;
            cout << "Do you want to draw another card? (1-yes, 0-no): ";
            cin >> draw_card2;
            }
         }
     
         else if (draw_card2 !=1) {

            exit(0);
         }

         cout << "Your overall score is: " << total_card2 << endl;
      }

      else if (a == 3) {

         cout << "\nPlayer 3 - Enter the amount of money to start you off: ";
         cin >> money3;
         cout << "This is your initial amount: " << money3 << endl;

         cout << "\nPlayer 3 - Enter the amount you desire to bet the dealer: ";
         cin >> bet3;
         cout << "This is the amount you bet: " << bet3 << endl;

         while (bet_money3 == false) {

            if (bet3 > money3 || bet3 <= 0) {

               cout << "\nThe amount you enter is invalid, please try again" << endl;
               cout << "Player 3 - Enter the amount you desire to bet the dealer: ";
               cin >> bet3;
               cout << "This is the amount you bet: " << bet3 << endl;
            }

            else {

               bet_money3 = true;
            }
         }

         cout << "\nType in 1 to start drawing card: ";
         cin >> draw_card3;

         if (draw_card3 == 1) {

            while (draw_card3 == 1) {

               get_card3 = rand() %11+1;
               cout << "\nYou draw a: " << get_card3 << endl;

               for (b = 0; b < 1; b++) {

                  player_3[b] = get_card3;
                  total_card3 = total_card3 + player_3[b];
               }

            cout << "Your total is: " << total_card3 << endl;
            cout << "Do you want to draw another card? (1-yes, 0-no): ";
            cin >> draw_card3;
            }
         }
     
         else if (draw_card3 !=1) {

            exit(0);
         }

         cout << "Your overall score is: " << total_card3 << endl;
      }

      else if (a == 4) {

         cout << "\nPlayer 4 - Enter the amount of money to start you off: ";
         cin >> money4;
         cout << "This is your initial amount: " << money4 << endl;

         cout << "\nPlayer 4 - Enter the amount you desire to bet the dealer: ";
         cin >> bet4;
         cout << "This is the amount you bet: " << bet4 << endl;

         while (bet_money4 == false) {

            if (bet4 > money4 || bet4 <= 0) {

               cout << "\nThe amount you enter is invalid, please try again" << endl;
               cout << "Player 4 - Enter the amount you desire to bet the dealer: ";
               cin >> bet4;
               cout << "This is the amount you bet: " << bet4 << endl;
            }

            else {

               bet_money4 = true;
            }
         }

         cout << "\nType in 1 to start drawing card: ";
         cin >> draw_card4;

         if (draw_card4 == 1) {

            while (draw_card4 == 1) {

               get_card4 = rand() %11+1;
               cout << "\nYou draw a: " << get_card4 << endl;

               for (b = 0; b < 1; b++) {

                  player_4[b] = get_card4;
                  total_card4 = total_card4 + player_4[b];
               }

            cout << "Your total is: " << total_card4 << endl;
            cout << "Do you want to draw another card? (1-yes, 0-no): ";
            cin >> draw_card4;
            }
         }
     
         else if (draw_card4 !=1) {

            exit(0);
         }

         cout << "Your overall score is: " << total_card4 << endl;
      }      
   }

    dealer_turn() ; //This is a reuse function from the top for the dealer

    if ((total_card1 == 21) || (total_card2 == 21) || (total_card3 == 21) || (total_card4 == 21)) { //Bunch of if/else statement for comparing card

       cout << "You Win" << endl;
       total_money1 = money1 + bet1;
       total_money2 = money2 + bet2;
       total_money3 = money3 + bet3;
       total_money4 = money4 + bet4;
       cout << "\nPlayer 1 - money total is: " << total_money1 << endl;
       cout << "\nPlayer 2 - money total is: " << total_money2 << endl;
       cout << "\nPlayer 3 - money total is: " << total_money3 << endl;
       cout << "\nPlayer 4 - money total is: " << total_money4 << endl;
    }

    else if ((total_card1 < 21) || (total_card2 < 21) || (total_card3 < 21) || (total_card4 < 21) && (total_dealer > 21)) {

       cout << "\nYou Win" << endl;
       total_money1 = money1 + bet1;
       total_money2 = money2 + bet2;
       total_money3 = money3 + bet3;
       total_money4 = money4 + bet4;
       cout << "\nPlayer 1 - money total is: " << total_money1 << endl;
       cout << "\nPlayer 2 - money total is: " << total_money2 << endl;
       cout << "\nPlayer 3 - money total is: " << total_money3 << endl;
       cout << "\nPlayer 4 - money total is: " << total_money4 << endl;
    }  
    
    else if ((total_card1 == total_dealer) || (total_card2 == total_dealer) || (total_card3 == total_dealer) || (total_card4 == total_dealer)) {

       cout << "\nIt's a tie" << endl;
       total_money1 = money1;
       total_money2 = money2;
       total_money3 = money3;
       total_money4 = money4;
       cout << "\nPlayer 1 - money total is: " << total_money1 << endl;
       cout << "\nPlayer 2 - money total is: " << total_money2 << endl;
       cout << "\nPlayer 3 - money total is: " << total_money3 << endl;
       cout << "\nPlayer 4 - money total is: " << total_money4 << endl;
    }

    else if ((total_card1 < 21) || (total_card2 < 21) || (total_card3 < 21) || (total_card4 < 21) && (total_dealer == 21) || (total_dealer > total_card1)||(total_dealer > total_card2) || (total_dealer > total_card3) || (total_dealer > total_card4)) {
 
    
       cout << "\nSorry, the dealer win" << endl;
       total_money1 = money1 - bet1;
       total_money2 = money2 - bet2;
       total_money3 = money3 - bet3;
       total_money4 = money4 - bet4;
       cout << "\nPlayer 1 - money total is: " << total_money1 << endl;
       cout << "\nPlayer 2 - money total is: " << total_money2 << endl;
       cout << "\nPlayer 3 - money total is: " << total_money3 << endl;
       cout << "\nPlayer 4 - money total is: " << total_money4 << endl;
    } 

    else {

       cout << "\nSorry, the dealer win" << endl;
       total_money1 = money1 - bet1;
       total_money2 = money2 - bet2;
       total_money3 = money3 - bet3;
       total_money4 = money4 - bet4;
       cout << "\nPlayer 1 - money total is: " << total_money1 << endl;
       cout << "\nPlayer 2 - money total is: " << total_money2 << endl;
       cout << "\nPlayer 3 - money total is: " << total_money3 << endl;
       cout << "\nPlayer 4 - money total is: " << total_money4 << endl;
    }

     cout << "\nDo you want to play the game again? (1-yes,0-no): ";
     cin >> try_again;

     if (try_again == '1') {
        cout << endl;
     }

     else if (try_again == '0') {

        try_again = false;
     }
}
  cout << "Thanks for playing BlackJack" << endl;

return 0;
}

