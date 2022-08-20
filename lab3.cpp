/*
 * lab3.cpp
 *
 *  Created on: Sep 20, 2019
 *      Author: user
 */

#include <iostream>
using namespace std;


void IsoscelesTriangle(int height, int number){
	char alph = 'A';
	int bottom = 2*height-1;
	for(int i = 0; i < number; ++i)
	{
		for (int n = 0; n < height; ++n)
		{
			int j = 1;
			int count = 0;
			while(count!=2*n+1)
			{
				if(j <= (bottom/2)-n)
				{
					cout << " ";
					j++;
				}
				else
				{
					cout << alph;
					++count;
				}
			}
			cout << '\n';
			alph++;
		}
		alph = 'A';
	}

}

void ReverseIsoscelesTriangle(int height ,int number){

	char alph = 'A';
	int upper = 2*height-1;
	for(int i = 0; i < number; ++i)
	{
		for (int n = height; n > 0; --n)
		{
			int j = 0;
			int count = 0;
			while(count!=(2*n)-1)
			{
				if(j <= (upper/2)-n)
				{
					cout << " ";
					j++;
				}
				else
				{
					cout << alph;
					++count;
				}
			}
			cout << '\n';
			alph++;
		}
		alph = 'A';
	}

}

void Diamond(int halfHeight, int number){
	int fullHeight = halfHeight*2+1;

	for(int i = 0; i < number; ++i){
		int space = halfHeight;
		char text = 'A';

		for(int k = 1; k <= fullHeight ; k++){
			if(k <= halfHeight+1){
				for(int j = 1; j <= space; ++j){
					cout << " ";
				}
			}
			else{
				for(int j = 1; j <= space; ++j){
					cout << " ";
					if(space > halfHeight)
						break;
				}
			}
			cout << text;
			if(text == 'A'){
				cout << "\n";
				space--;
				text++;
				continue;
			}
//			SPACE TENGAH
			if(k <= halfHeight + 1){
				for(int a = 1; a <= 2*(k-1)-1; a++){
					cout << " ";
				}
			}
			else{
				for(int a = 1; a <= 2*(k-2*(k-halfHeight-1)-1)-1; a++){
					cout << " ";
				}
			}

			cout << text << endl;
			if(k >= fullHeight/2 + 1){
				text--;
				space++;
			}
			else{
				text++;
				space--;
			}

		}

	}

}

void Candy(int height, int number){
	for(int i = 0; i < number; ++i){
		ReverseIsoscelesTriangle(height+1, 1);
		Diamond(height, 1);
		IsoscelesTriangle(height+1, 1);
		cout << endl;
	}
}


int main(){
	int userInput;

	//userInput (MAKE CHOICE) ==============================================================================
	do{
		cout << "=============================\n"
			"Welcome to the Shape Printer!\n"
			"=============================\n";
		cout << "\n";
		cout << "1: Draw letter isosceles triangle." << endl;
		cout << "2: Draw letter reverse isosceles triangle." << endl;
		cout << "3: Draw letter diamond." << endl;
		cout << "4: Draw letter candy." << endl;
		cout << "0: Exit program" << endl;
		cout << "Input the type of shape you want to print, or exit program: " << endl;
		cin >> userInput;
		int height, number;

		switch(userInput){
		case 1:
			cout << "Please input the height of the isosceles triangle: ";
			cin >> height;
			cout << "Please input the number of the isosceles triangles: ";
			cin >> number;
			IsoscelesTriangle(height, number);
			break;
		case 2:
			cout << "Please input the height of the letter reverse isosceles triangle: ";
			cin >> height;
			cout << "Please input the number of the letter reverse isosceles triangles: ";
			cin >> number;
			ReverseIsoscelesTriangle(height, number);
			break;
		case 3:
			cout << "Please input the height/2 of the letter diamond: ";
			cin >> height;
			cout << "Please input the number of the letter diamonds: ";
			cin >> number;
			Diamond(height, number);
			break;
		case 4:
			cout << "Please input the height of the candy: ";
			cin >> height;
			cout << "Please input the number of candies: ";
			cin >> number;
			Candy(height, number);

			break;
		case 0:
			break;
		default:
			cout << "Please enter the right number (0 - 4)!\n";
		}
		cout << endl;
	}while(userInput != 0);

	return 0;
}


