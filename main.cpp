#include <iostream>
#include <string> 
#include <cstdlib> 
#include <fstream>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
using namespace std;
void rules();
int main()
{
    string playerName;
    string id;
    int balance;
    int bettingAmount;
    int guess;
    int dice; 
    char choice;
    srand(time(0));
    sleep(0.5);
    cout << "\n\t\t========WELCOME TO CASINO WORLD=======\n\n";
    
    sleep(1);
    cout << "\n\nWhat's your Name : ";
    getline(cin, playerName);
    cout << "\n\n Enter your id : ";
    getline(cin,id);

    ofstream user("users.txt");
    user<<"Name :"<<playerName<<endl;
    user<<"Id: "<<id<<endl;
    sleep(0.5);
    cout << "\n\nEnter the starting balance to play game : $";
    cin >> balance;
    do
    {
        system("clear");
        rules();
        cout << "\n\nYour current balance is $ " << balance << "\n";

        do
        {
            cout << "Hey, " << playerName<<", enter amount to bet : $";
            cin >> bettingAmount;
            if(bettingAmount > balance)
                cout << "Betting balance can't be more than current balance!\n"
                       <<"\nRe-enter balance\n ";
        }while(bettingAmount > balance);

        do
        {
            cout << "Guess any betting number between 1 & 10 :";
            cin >> guess;
            if(guess <= 0 || guess > 10)
                cout << "\nNumber should be between 1 to 10\n"
                    <<"Re-enter number:\n ";
        }while(guess <= 0 || guess > 10);
        dice = rand()%10 + 1;
        sleep(1);
        cout<<"wait !"<<endl;
        for(int i=0;i<3;i++){
            cout<<(3-i)<<endl;
            sleep(1);
        }
        cout<<endl;
        system("clear");
        cout<<endl;
        cout<<"Now!!!";
        cout<<endl;
        cout<<"waiting for results";
        sleep(2);
        system("clear");
        cout<<"\n";
        sleep(1);
        if(dice == guess)
        {
            cout << "\n\nYou are in luck!! You have won Rs." << bettingAmount * 10;
            balance = balance + bettingAmount * 10;
        }
        else
        {
            cout << "Oops, better luck next time !! \n You lost $ "<< bettingAmount <<"\n";
            balance = balance - bettingAmount;
        }
        cout << "\nThe winning number was : " << dice <<"\n";
        cout << "\n"<<playerName<<", You have balance of $ " << balance << "\n";
        if(balance == 0)
        {
            cout << "You have no money to play ";
            break;
        }
        cout << "\n\n-->Do you want to play again (y/n)? ";
        cin >> choice;
    }while(choice =='Y'|| choice=='y');
    cout << "\n\n\n";

    cout << "\n\nThanks for playing the game. Your balance is $ " << balance << "\n\n";
    user<<balance<<endl;
    user.close();
    return 0;
}
void rules()
{
    system("clear");
    cout << "\t\t======CASINO NUMBER GUESSING RULES!======\n";
    cout << "\t1. Choose a number between 1 to 10\n";
    cout << "\t2. Winner gets 10 times of the money bet\n";
    cout << "\t3. Wrong bet, and you lose the amount you bet\n\n";
}