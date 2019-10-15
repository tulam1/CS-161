/****************************************************************************************************
 * Program: diffusion.cpp
 * Author: Tu Lam
 * Date: 03/12/2019
 * Description: Printing out a heat diffusion table for a plate or wire depend on which one user want
 * Input: User input all the datas for the calculation the heat diffusion
 * Output: Printing out the heat diffusion data depend on which data the user chose
 ***************************************************************************************************/

#include <iostream> //This library is for the cout and cin statement
#include <string> //This is for C++ string input from user
#include <ctype.h> //This library is for the toupper and tolower function
#include <cstdlib> //This library help with the conversion of atoi and atof
#include <cmath> //This library help with the abs() and pow() math function

using namespace std;

//This is where all the functions underneath the int main function get declares
void title_page();
bool wire_or_plate(string &material);
float thermal();
float density();
float heat_capacity();
int wire_length();
int plate_length();
int section();
int interval();
float simulation();
int initial_temp();
int left_temp();
int right_temp();
int up_temp();
int bottom_temp();
void printing_wire(float k1, float p1, float c1, int l1, int x1, int t1, float sm1);
void wire_stable(float k1, float p1, float c1, int l1, int x1, int t1, int delta_x, float delta_t);
void printing_plate(float k2, float p2, float c2, int l2, int x2, int t2, float sm2);
void plate_stable(float k2, float p2, float c2, int l2, int x2, int t2, int delta_x2, float delta_t2);
int check_i(string user_input);
float check_f(string user_input);
bool play_again();

int main() {

	string material;
	float k1 = 0, k2 = 0, p1 = 0, p2 = 0, c1 = 0, c2 = 0, sm1 = 0, sm2 = 0; 
   int l1 = 0, l2 = 0, x1 = 0, x2 = 0, t1 = 0, t2 = 0;
	bool go_again = true;

   while (go_again == true) {
	title_page();
	wire_or_plate(material);

	if (material == "wire") {
		k1 = thermal();
		p1 = density();
		c1 = heat_capacity();
		l1 = wire_length();
		x1 = section();
		t1 = interval();
		sm1 = simulation();
		printing_wire(k1,p1,c1,l1,x1,t1,sm1);
	}

   else if (material == "plate") {
		k2 = thermal();
		p2 = density();
		c2 = heat_capacity();
		l2 = plate_length();
		x2 = section();
		t2 = interval();
		sm2 = simulation();
		printing_plate(k2,p2,c2,l2,x2,t2,sm2);
	}

	go_again = play_again();
	}

return 0;
}

/********************************************
 * Function: void title_page();
 * Input: No input
 * Output: Printing the title of the program
 *******************************************/
void title_page() {

	cout << "____________________" << endl;
	cout << "Heat Diffusion Array" << endl;
   cout << "--------------------" << endl;

}

/*************************************************************
 * Function: bool wire_or_plate();
 * Input: User enter the word "wire" or "plate"
 * Output: Give the true and false statement base on user input
 *************************************************************/
bool wire_or_plate(string &material) {

	string option;
	bool enter_again = true;

	do {
		cout << "\nEnter which material do you want to test? Enter the word [wire] or [plate]: ";
		getline(cin,option);

		for (int i = 0; i < option.length(); i++) {
			option[i] = tolower(option[i]);
      }

		if (option == "wire") {
			enter_again = true;
		}

		else if (option == "plate") {
			enter_again = true;
		}

		else {
			cout << "You enter an invalid response, please try again!" << endl;
			enter_again = false;
		}
   } while (enter_again == false);

	material = option;
}

/*******************************************************
 * Function: float thermal();
 * Input: User input the number for thermal conductivity
 * Output: Return the number for later use in the equation
 ******************************************************/
float thermal() {

	string user_input;
	float conduct = 0;

	cout << "\nEnter the amount of thermal conductivity you desire [k-value]: ";
	getline(cin,user_input);
	conduct = check_f(user_input);

	while (conduct <= 0) {
		cout << "You enter an invalid response, please try again: ";
		getline(cin,user_input);
		conduct = check_f(user_input);
	}

return conduct;
}

/*******************************************************
 * Function: float density();
 * Input: User input the number for matertial density
 * Output: Return the number for later use in the equation
 ******************************************************/
float density() {

	string user_input;
	float m_density = 0;
	
	cout << "\nEnter the amount of material density you desire [rho-value]: ";
	getline(cin,user_input);
	m_density = check_f(user_input);

	while (m_density <= 0) {
		cout << "You enter an invalid response, please try again: ";
		getline(cin,user_input);
		m_density = check_f(user_input);
	}

return m_density;
}

/*******************************************************
 * Function: float heat_capacity();
 * Input: User input the number for the heat capacity
 * Output: Return the number for later use in the equation
 ******************************************************/
float heat_capacity() {

	string user_input;
	float capacity = 0;

	cout << "\nEnter the specific amount for heat capacity that you desire [c-value]: ";
	getline(cin,user_input);
	capacity = check_f(user_input);

	while (capacity <= 0) {
		cout << "You enter an invalid response, please try again: ";
		getline(cin,user_input);
		capacity = check_f(user_input);
	}

return capacity;
}

/*******************************************************
 * Function: int wire_length();
 * Input: User input the length of the wire
 * Output: Return the number for later use in the equation
 ******************************************************/
int wire_length() {

	string user_input;
	int w_length = 0;

	cout << "\nEnter the length of the wire you desire [l-value]: ";
	getline(cin,user_input);
	w_length = check_i(user_input);

	while (w_length <= 0) {
		cout << "You enter an invalid response, please try again: ";
		getline(cin,user_input);
		w_length = check_i(user_input);
	}

return w_length;
}

/*******************************************************
 * Function: int plate_length();
 * Input: User input the length/width of the plate
 * Output: Return the number for later use in the equation
 ******************************************************/
int plate_length() {

	string user_input;
	int p_length = 0;

	cout << "\nEnter the length and width of the plate you desire [l-value]: ";
	getline(cin,user_input);
	p_length = check_i(user_input);

	while (p_length <= 0) {
		cout << "You enter an invalid response, please try again: ";
		getline(cin,user_input);
		p_length = check_i(user_input);
	}

return p_length;
}

/*************************************************************
 * Function: int section();
 * Input: User input the number of section they want to divide
 * Output: Return the number for later use in the equation
 ************************************************************/
int section() {

	string user_input;
	int l_section = 0;

	cout << "\nEnter the amount of section you want to divide [x-value]: ";
	getline(cin,user_input);
	l_section = check_i(user_input);

	while (l_section <= 0) {
		cout << "You enter an invalid response, please try again: ";
		getline(cin,user_input);
		l_section = check_i(user_input);
	}

return l_section;
}

/*************************************************************
 * Function: int interval();
 * Input: User input the number of time interval
 * Output: Return the number for later use in the equation
 ************************************************************/
int interval() {

	string user_input;
	int time = 0;

	cout << "\nEnter the time interval of your choice [t-value]: ";
	getline(cin,user_input);
	time = check_i(user_input);

	while (time <= 0) {
		cout << "You enter an invalid response, please try again: ";
		getline(cin,user_input);
		time = check_i(user_input);
	}

return time;
}

/*************************************************************
 * Function: float simulation();
 * Input: User input the number of time of simulation 
 * Output: Return the number for later use in the equation
 ************************************************************/
float simulation() {

	string user_input;
	float sim = 0;

	cout << "\nEnter the time of simulation of your choice [sm-value]: ";
	getline(cin,user_input);
	sim = check_f(user_input);

	while (sim <= 0) {
		cout << "You enter an invalid response, please try again: ";
		getline(cin,user_input);
		sim = check_f(user_input);
	}

return sim;
}

/*************************************************************
 * Function: int initial_temp();
 * Input: User input the number for the initial temp.
 * Output: Return the number for later use in the equation
 ************************************************************/
int initial_temp() {

	string user_input;
	int i_temp = 0;

	cout << "\nEnter the initial temperature: ";
	getline(cin,user_input);
	i_temp = check_i(user_input);

	while (i_temp != 0) {
		cout << "You enter an invalid response, please try again: ";
		getline(cin,user_input);
		i_temp = check_i(user_input);
	}

return i_temp;
}

/*************************************************************
 * Function: int left_temp();
 * Input: User input the number for the left temp.
 * Output: Return the number for later use in the equation
 ************************************************************/
int left_temp() {

	string user_input;
	int l_temp = 0;

	cout << "\nEnter the left side temperature: ";
	getline(cin,user_input);
	l_temp = check_i(user_input);

	while (!(l_temp == 0 || l_temp == 100)) {
		cout << "You enter an invalid response, please try again: ";
		getline(cin,user_input);
		l_temp = check_i(user_input);
	}

return l_temp;
}

/*************************************************************
 * Function: int right_temp();
 * Input: User input the number for the right temp.
 * Output: Return the number for later use in the equation
 ************************************************************/
int right_temp() {

	string user_input;
	int r_temp = 0;

	cout << "\nEnter the right side temperature: ";
	getline(cin,user_input);
	r_temp = check_i(user_input);

	while (!(r_temp == 100)) {
		cout << "You enter an invalid response, please try again: ";
		getline(cin,user_input);
		r_temp = check_i(user_input);
	}

return r_temp;
}

/*************************************************************
 * Function: int up_temp();
 * Input: User input the number for the upper temp.
 * Output: Return the number for later use in the equation
 ************************************************************/
int up_temp() {

	string user_input;
	int u_temp = 0;

	cout << "\nEnter the top side temperature: ";
	getline(cin,user_input);
	u_temp = check_i(user_input);

	while (!(u_temp == 100)) {
		cout << "You enter an invalid response, please try again: ";
		getline(cin,user_input);
		u_temp = check_i(user_input);
	}

return u_temp;
}

/*************************************************************
 * Function: int bottom_temp();
 * Input: User input the number for the bottom temp.
 * Output: Return the number for later use in the equation
 ************************************************************/
int bottom_temp() {

	string user_input;
	int b_temp = 0;

	cout << "\nEnter the bottom side temperature: ";
	getline(cin,user_input);
	b_temp = check_i(user_input);

	while (!(b_temp == 100)) {
		cout << "You enter an invalid response, please try again: ";
		getline(cin,user_input);
		b_temp = check_i(user_input);
	}

return b_temp;
}

/*************************************************************
 * Function: void printing_wire();
 * Input: No input
 * Output: Printing out the table based on the information
 ************************************************************/
void printing_wire(float k1, float p1, float c1, int l1, int x1, int t1, float sm1) {

	int delta_x = l1 / x1;
	float delta_t = sm1 / t1; 
	int r_temp = 0, l_temp = 0, i_temp = 0;
	float wr[t1][x1];
	
	i_temp = initial_temp();
	l_temp = left_temp();
	r_temp = right_temp();
	wire_stable(k1,p1,c1,l1,x1,t1,delta_x,delta_t);
   
	for (int i = 0; i <= t1; i++) {
		for (int j = 0; j < x1; j++) {
			if (j == 0) {
				wr[i][j] = l_temp;
			}
			
			else if (j == x1 - 1) {
				wr[i][j] = r_temp;
			}

			else {
				wr[i][j] = i_temp;
			}
		}
	}

	for (int i = 1; i < t1; i++) {
		for (int j = 1; j < x1 - 1; j++) {
			wr[i+1][j] = ((delta_t * (k1 * ((wr[i][j+1] - (2*wr[i][j]) + wr[i][j - 1]) / (delta_x * delta_x)))) / (c1 * p1)) + wr[i][j];
		}
	}

	for (int i = 0; i <= t1; i++) {
		for (int j = 0; j < x1; j++) {
			cout << wr[i][j] << " ";
		}
		cout << endl;
	}
}

/***************************************************************************
 * Function: void wire_stable();
 * Input: No input
 * Output: Determining if the data input from previous information is stable
 **************************************************************************/
void wire_stable(float k1, float p1, float c1, int l1, int x1, int t1, int delta_x, float delta_t) {

	float stable_sum = 0;

	stable_sum = abs((k1 * delta_t) / (((delta_x * delta_x) * c1 * p1)));

	if (stable_sum <= 0.5) {
		cout << "\nYour input is stable, the board is printing now..." << endl;
	}

	else if (stable_sum > 0.5) {
		cout << "\nYour board is unstable, you are now exiting the program..." << endl;
		exit(0);
	}
}

/***************************************************************************
 * Function: void printing_plate();
 * Input: No input
 * Output: Printing out the table for the heat diffusion based on the info
 **************************************************************************/
void printing_plate(float k2, float p2, float c2, int l2, int x2, int t2, float sm2) {

	int delta_x2 = l2 / x2;
	float delta_t2 = sm2 / t2;
	int l_temp = 0, r_temp = 0, u_temp = 0, b_temp = 0, i_temp = 0;
	float pt[x2][x2][t2];

	i_temp = initial_temp();
	l_temp = left_temp();
	r_temp = right_temp();
	u_temp = up_temp();
	b_temp = bottom_temp();
	plate_stable(k2,p2,c2,l2,x2,t2,delta_x2,delta_t2);

	for (int i = 0; i <= t2; i++) {
		for (int j = 0; j < x2; j++) {
			for (int k = 0; k < x2; k++) {
					pt[k][j][i] = i_temp;
					pt[k][0][i] = u_temp;
					pt[k][x2-1][i] = b_temp;
					pt[0][j][i] = l_temp;
					pt[x2-1][j][i] = r_temp;
			}
		}
	}

   for (int i = 1; i < t2; i++) {
		for (int j = 1; j < x2 - 1; j++) {
			for (int k = 1; k < x2 - 1; k++) {
				pt[j][k][i+1] = ((delta_t2 * (k2 * (((pt[j+1][k][i]-(2*pt[j][k][i])+pt[j-1][k][i])/(delta_x2*delta_x2))+((pt[j][k+1][i] - (2*pt[j][k][i]) + pt[j][k-1][i]) / (delta_x2*delta_x2))))) / (c2 * p2)) + pt[j][k][i];
			}
		}
	}

	for (int i = 0; i <= t2; i++) {
		for (int j = 0; j < x2; j++) {
			for (int k = 0; k < x2; k++) {
				cout << pt[k][j][i] << " ";
			}
		cout << endl;
		}
	}
}

/***************************************************************************
 * Function: void plate_stable();
 * Input: No input
 * Output: Determining if the data input from previous information is stable
 **************************************************************************/
void plate_stable(float k2, float p2, float c2, int l2, int x2, int t2, int delta_x2, float delta_t2) {

	float stable_sum = 0;

	stable_sum = ((delta_x2 * delta_x2 * p2 * c2) / (4 * k2));

	if (delta_t2 <= stable_sum) {
		cout << "\nYour input is stable, the board is printing now..." << endl;
	}

	else if (delta_t2 > stable_sum) {
		cout << "\nYour board is unstable, you are now exiting the program..." << endl;
		exit(0);
	}
}

/***************************************************************************
 * Function: int check_i();
 * Input: String user_input
 * Output: Check to see the user input the info is an ingeter
 **************************************************************************/
int check_i(string user_input) {

	int good_i = 0;
	bool check_in = false;

	while (check_in == false) {
		for (int i = 0; i < user_input.length(); i++) {
			if (!(user_input.at(i) >= '0' && user_input.at(i) <= '9')) {
				cout << "You enter an invalid response, please try again: ";
				getline(cin,user_input);
			}

			else {
				check_in = true;
			}
		}
	}

	good_i = atoi(user_input.c_str());

return good_i;
}

/***************************************************************************
 * Function: float check_f();
 * Input: String user_input
 * Output: Check to see the user input the info is an float
 **************************************************************************/
float check_f(string user_input) {

	float good_f = 0;
	bool check_fl = false;
 
	while (check_fl == false) {
		for (int i = 0; i < user_input.length(); i++) {
			if (!((user_input.at(i) >= '0' && user_input.at(i) <= '9') || user_input.at(i) == '.')) {
				cout << "You enter an invalid response, please try again: ";
				getline(cin,user_input);
			}

			else {
				check_fl = true;
			}
		}
	}

	good_f = atof(user_input.c_str());

return good_f;
}

/********************************************************************************
 * Function: bool play_again();
 * Input: String user_input
 * Output: Asking the user to play again or not based on true and false statement
 *******************************************************************************/
bool play_again() {

	int option;
	string user_input;

 	cout << "\nDo you want to try another method? (0-no, 1-yes): ";
	getline(cin,user_input);
	option = check_i(user_input);

	while (!(option == 0 || option == 1)) {
		cout << "You enter an invalid response, please try again: ";
		getline(cin,user_input);
		option = check_i(user_input);
	}

	if (option == 0) {
		return false;
	}

	else {
		return true;
	}
}
