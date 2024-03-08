#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <random>
#include <conio.h>
#include <stdio.h>
#include <thread>
#include <chrono>
#include <Windows.h>
using namespace std::chrono_literals;

void drawline(int n, char symbol)
{
    for (int i = 0; i < n; i++)
        std::cout << symbol;
    std::cout << "\n";
}
void printrules() 
{
    std::cout << "Welcome to our game ! Here is rules" << std::endl;
    std::cout << "\t1. Choose any number between 1 to 10\n";
    std::cout << "\t2. If you win you will get 10 times of money you bet\n";
    std::cout << "\t3. If you bet on wrong number you will lose your betting amount\n\n";
}
void print_rolling(std::string &roll , int n)
{
    for (int i = 0; i < n; i++) {
        system("CLS");
        std::cout << roll << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(5s));
        system("CLS");
    }
}
int main()
{
    //local values
    std::string name;
    std::string rolling;
    int dice = 0;
    char choice;
    int deposit = 0;
    int amount = 0;
    int guess = 0;
    int bettingAmount = 0;

    drawline(100, '=');

    std::cout << "\t\t\t\Hello! Welcome to our casino game!\t\t\t\t" << std::endl;
    std::cout << "Do you wanna play? " << std::endl;
    std::cout << "Choose (y/n) : ";

    std::cin >> choice;
    

    printrules();
    std::cout << "Please write your name : ";
    std::cin >> name;
    std::cout << std::endl;
    std::cout << "\nEnter Deposit amount to play game : $";
    std::cin >> amount;

    switch (choice)
    {
        case 'y':
            std::cout << "You choosed play game! Let`s go" << std::endl;
        case 'n':
            break;
    }
    std::srand(static_cast<unsigned>(std::time(NULL)));

    std::cout << "Guess your number to bet between 1 to 10 :";
    
    while (guess <= 0 || guess > 10) { //fail with true in while statement
        std::cin >> guess;
        if (guess < 0 || guess > 10) {
            std::cout << "Please check the number!! should be between 1 to 10\n"
                << "\nRe-enter data\n ";
        }
    }
   
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(1, 10); // distribution in range [1, 10]

    dice = dist6(rng);

    do
    {
        std::cout << name << ", enter money to bet : $";
        std::cin >> bettingAmount;
        if (bettingAmount > amount)
            std::cout << "Your betting amount is more than your current balance\n"
            << "\nRe-enter data\n ";
    } while (bettingAmount > amount);
    //rolling code
    rolling = "Rolling............";
   // const auto start = std::chrono::high_resolution_clock::now();
    std::this_thread::sleep_for(std::chrono::seconds(5s));
    print_rolling(rolling , dice);
    std::this_thread::sleep_for(std::chrono::seconds(5s));
    //const auto end = std::chrono::high_resolution_clock::now();
    //const std::chrono::duration<double, std::milli> elapsed = end - start;
    

    if (dice == guess)
    {
        amount = amount + bettingAmount * 10;
        std::cout << "Your won , your amount : " << amount << std::endl;
    }
    else
    {
        amount = amount - bettingAmount;
        std::cout << "Your lose , your amount : " << amount << std::endl;
    }

    std::cout << "Do you wanna play again? " << std::endl;


    do
    {
        std::cout << "Choose (y/n) : ";
        std::cin >> choice;
        system("CLS");
        if (choice == 'y')
        {
            return main();
        }
        else if(choice == 'n')
        {
            std::cout << "Goodbye! See you soon" << std::endl;
            exit(0);
        }
        else
        {
            std::cout << "Try again!" << std::endl;
        }
             
    } while (true);
}

