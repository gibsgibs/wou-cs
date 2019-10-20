/**
  * @brief Assignment 9
  * @author Gabriel Brehm
  */

#include <iostream>
#include <fstream>
using namespace std;

struct Stats
{
        string firstName;
        string lastName;
        double completions = 0;
        double attempts = 0;
        double yards = 0;
        double touchdowns = 0;
        double interceptions = 0;
        double gameStat[10][5];
};
/**
 * @brief printMenu - prints out the menu, and stores the choice as an int
 * @return - choice - the choice picked from the menu
 */
int printMenu()
{
    cout << "1: Print Player"
         << "\n2: Print Player Stats"
         << "\n3: Print Passer Raiting"
         << "\n4: Exit"
         << "\nEnter an option: ";
    int choice = 0;
    cin >> choice;
    cout << "\n";
    return choice;
}
/**
 * @brief getData - finds the file, checks if it exists, opens it,
 *                  and assigns the player names to variables,
 *                  and assigns the rest of the info to the array gameStat
 * @param player - the stats data type created with a stuct
 */
void getData(Stats player[])
{
    ifstream assign9;

    if(assign9.fail())
    {
        cout << "Fail";
    }
    assign9.open("QBInfo.txt");
    int trash;
    assign9 >> trash;
    for(int i = 1; i < 4; i++)
    {
        assign9 >> player[i].firstName
                >> player[i].lastName;
        for(int j = 0; j < 10; j++)
        {
            for(int k = 0; k < 5; k++)
            {
                assign9 >> player[i].gameStat[j][k];
            }
        }
    }
}
/**
 * @brief printData - prints all the info from the file in a formatted way
 * @param player - array of the player's stats
 * @param playerChoice - the player to print
 */
void printData(Stats player[], int playerChoice)
{
    cout << player[playerChoice].firstName
         << " "
         << player[playerChoice].lastName
         << "\n\n";

    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            cout << player[playerChoice].gameStat[i][j]
                 << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}
/**
 * @brief getTotalCompletions - adds up the completions from each game
 * @param player - array of the player's stats
 * @param playerChoice - the player to print
 * @return the total completions
 */
double getTotalCompletions(Stats player[], int playerChoice)
{
    for(int i = 0; i < 10; i++)
        player[playerChoice].completions += player[playerChoice].gameStat[i][0];
    return player[playerChoice].completions;
}
/**
 * @brief getTotalAttempts - adds up the attempts from each game
 * @param player - array of the player's stats
 * @param playerChoice - the player to print
 * @return the total attempts
 */
double getTotalAttempts(Stats player[], int playerChoice)
{
    for(int i = 0; i < 10; i++)
        player[playerChoice].attempts += player[playerChoice].gameStat[i][1];
    return player[playerChoice].attempts;
}
/**
 * @brief getTotalYards - adds up the yards from each game
 * @param player - array of the player's stats
 * @param playerChoice - the player to print
 * @return the total yards
 */
double getTotalYards(Stats player[], int playerChoice)
{
    for(int i = 0; i < 10; i++)
        player[playerChoice].yards += player[playerChoice].gameStat[i][2];
    return player[playerChoice].yards;
}
/**
 * @brief getTotalTouchdowns - adds up the touchdowns from each game
 * @param player - array of the player's stats
 * @param playerChoice - the player to print
 * @return the total touchdowns
 */
double getTotalTouchdowns(Stats player[], int playerChoice)
{
    for(int i = 0; i < 10; i++)
        player[playerChoice].touchdowns += player[playerChoice].gameStat[i][3];
    return player[playerChoice].touchdowns;
}
/**
 * @brief getTotalInterceptions - adds up the interceptions from each game
 * @param player - array of the player's stats
 * @param playerChoice - the player to print
 * @return the total touchdowns
 */
double getTotalInterceptions(Stats player[], int playerChoice)
{
    for(int i = 0; i < 10; i++)
        player[playerChoice].interceptions += player[playerChoice].gameStat[i][4];
    return player[playerChoice].interceptions;
}
/**
 * @brief calcPasserRating - calculates the passer rating based on the completions,
 *                           attempts, yards, interceptions, and touchdowns, useing
 *                           the given formula
 * @param player - array of the player's stats
 * @param playerChoice - the player to print
 * @return the passer rating
 */
double calcPasserRating(Stats player[], int playerChoice)
{
    cout << player[playerChoice].firstName
         << " "
         << player[playerChoice].lastName
         << "\n";
    double passerRating, a = 0, b = 0, c = 0, d = 0;
    a = (((player[playerChoice].completions / player[playerChoice].attempts) - 0.3) * 5);
    if(a < 0)
        a = 0;
    else if(a > 2.375)
        a = 2.375;
    b = (((player[playerChoice].yards / player[playerChoice].attempts) - 3) * 0.25);
    if(b < 0)
        b = 0;
    else if(b > 2.375)
        b = 2.375;
    c = ((player[playerChoice].touchdowns / player[playerChoice].attempts) * 20);
    if(c < 0)
        c = 0;
    else if(c > 2.375)
        c = 2.375;
    d = (2.375 - ((player[playerChoice].interceptions / player[playerChoice].attempts) * 25));
    if(d < 0)
        d = 0;
    else if(d > 2.375)
        d = 2.375;
    passerRating = (a + b + c + d) / 0.06;
    return passerRating;
}
int main()
{
    Stats player[4];
    getData(player);
    int choice = 0, playerChoice = 0;
    while(choice < 4)
    {
        choice = printMenu();
        if(choice == 1)
        {
            cout << "Enter player number (1-Manning, 2-Brady, 3-Brees): ";
            cin >> playerChoice;
            cout << "\n";
            printData(player, playerChoice);
        }
        if(choice == 2)
        {
            cout << "Enter player number (1-Manning, 2-Brady, 3-Brees): ";
            cin >> playerChoice;
            cout << "\n"
                 << player[playerChoice].firstName
                 << " "
                 << player[playerChoice].lastName
                 << "\n"
                 << "Total completions: " << getTotalCompletions(player, playerChoice) << "\n"
                 << "Total attempts: " << getTotalAttempts(player, playerChoice) << "\n"
                 << "Total yards: " << getTotalYards(player, playerChoice) << "\n"
                 << "Total touchdowns: " << getTotalTouchdowns(player, playerChoice) << "\n"
                 << "Total interceptions: " << getTotalInterceptions(player, playerChoice) << "\n\n";
        }
        if(choice == 3)
        {
            cout << "Enter player number (1-Manning, 2-Brady, 3-Brees): ";
            cin >> playerChoice;
            cout << "\n";
            getTotalCompletions(player, playerChoice);
            getTotalAttempts(player, playerChoice);
            getTotalYards(player, playerChoice);
            getTotalTouchdowns(player, playerChoice);
            getTotalInterceptions(player, playerChoice);
            cout << "\n"
                 << "Passer rating: "
                 << calcPasserRating(player, playerChoice)
                 << "\n\n";
        }
    }
    return 0;
}
