/*************************************************************************************************************
 * Program: word_search.cpp
 * Author: Tu Lam
 * Date: 03/02/2019
 * Description: Letting user to enter a phrase/sentence and see how many times the word in that sentence pop up
 * Input: User input in the sentence, the number of word to search, and the word to search
 * Output: Display how many times that word appear
 *************************************************************************************************************/

#include <iostream> //This is the library for cout and cin function
#include <cstring> //This library is for cin.getline and C-style string function
#include <string> //This library is for C++ string and getline function
#include <cstdlib> //This is the library for atoi and atof function to convert string to int or float
#include <ctype.h> //This library is for tolower

using namespace std;

//This is all the declaration of all the functions that's needed for the program to work
void title_page();
int number_search();
int check_i(string input);
void enter_word(int f_num, char **look_up);
int count_word(char* word, char sentences[]);

int main() {
    
    const int size = 256;
    char get_sentence[size];
    char copy_sentence[size];
    string input;
    int found;
    char guess;
    
    title_page();
    cout << "\nEnter a phrase or sentence of your desire" << endl;
    cin.getline(get_sentence,size);
    
    //This for loop is for converting uppercase to lowercase letter
    for (int i = 0; get_sentence[i] != '\0'; i++) {
        
        get_sentence[i] = tolower(get_sentence[i]);
    }
    
    int f_num = number_search();
    char **look_up = new char *[f_num];
    
    for (int k = 0; k < f_num; k++) {
        
        look_up[k] = new char[256];
    }
    
    enter_word(f_num,look_up);
    
    for(int j = 0; j < f_num; j++) {
        
        strcpy(copy_sentence, get_sentence);
        cout << "\nThe word you enter: " << look_up[j] << ": appear "<< count_word(look_up[j],copy_sentence) << " time(s) " << endl;
        
    }
    
   delete [] look_up;

return 0;
}

//This function is a void for just printing the title of the program
void title_page() {
    
    cout << "_____________________" << endl;
    cout << "Word Search Frequency" << endl;
    cout << "---------------------" << endl;
}

//This function does the "ask for a number" and return the value for later usage
int number_search() {
    
    string input;
    int total_num;
    
    cout << "\nEnter a number for how many word(s) you wanted to search: ";
    getline(cin,input);
    total_num = check_i(input);
    
    while (total_num < 1) {
        
        cout << "You enter an invalid input, please try again: ";
        getline(cin,input);
        total_num = check_i(input);
    }
    
    return total_num;
}

//This is where the word is being enter depend how many words the user chose
void enter_word(int f_num, char **look_up) {
    
  
    char guess[256];
    for (int n = 1; n <= f_num; n++) {
        
        cout << "Enter the " << n << " word you like to search: ";
        cin >> guess;
        strcpy(look_up[n-1],guess);

    }

   
}

//This function count the word how many times it appear in that sentence
int count_word(char* word, char sentences[]){
    
    int count = 0;
    char *token = strtok(sentences, " ");
    int i=0;
    
    while (token != NULL) {
       
       if(strcmp(token, word) == 0) {
            count++;
       }
        
       token = strtok(NULL, " ");
    }
    
    return count;
}

//This function is for checking if the user enter a integer or not for the how many word to search
int check_i(string input) {
    
    int good_i;
    bool check_input = false;
    
    while (check_input == false) {
        
        for (int i = 0; i < input.length(); i++) {
            
            if (!(input.at(i) >= '0' && input.at(i) <= '9')) {
                
                cout << "You enter an invalid input, please try again: ";
                getline(cin,input);
            }
            
            else {
                
                check_input = true;
            }
        }
    }
    
    good_i = atoi(input.c_str());
    
    return good_i;
}


