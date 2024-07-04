#include "functions.h"
using namespace std;


int main() {
    string input;
    vector<string> games;
    // vector<string>::iterator iter;
    //Moved to functions.h to get iter to work
    cout << "There are many Games out in the world.\n";
    cout << "Please tell me some of your favorite games!\n\n";
    

    while(true) {
          cout << "What would you like to do?\n";
          cout << "Type your answer.\n";
          cout << "Load, Add, Edit, Remove, Show, or Quit?\n";
          getline(cin, input);


        if (input == "load" || input == "Load" || input == "LOAD") {
            Load(games);
            cout << "\nYour save has been opened\n";

        }  // end of load
       
       else if (input == "add" || input == "ad" || input == "ADD" || input == "Add") {
        cout << "\nWhat game would you like to add?\n";
        AddGame(games);
       }    // end of add


       else if (input == "edit" || input == "Edit" || input == "EDIT") {
        cout << "\nWhat game would you like to edit?\n";
        sort(games.begin(), games.end());
        Display(games);
        cout << "Type the NAME of the game.\n";
        Edit(games);
       }    // end of Edit


       else if (input == "remove" || input == "REMOVE" || input == "Remove") {
        sort(games.begin(), games.end());
        cout << "\nWhat game would you like to remove?\n";
        Display(games);     //Shows Display function
        cout << "\nPlease type the NAME of the game.\n";
        Remove(games);      //Shows the remove function
       }    //end of Remove


       else if (input == "show"|| input == "Show" || input == "SHOW" || input == "sho") {
        sort(games.begin(), games.end());
        cout << "\nHere are your favorite games!\n";
        Display(games);
       }    //end of show



       else if (input == "quit" || input == "Quit" || input == "QUIT") {
        cout << "\nAre you sure you want to quit?\n";
        getline(cin,input);

        if (input == "Yes" || input == "yes" || input == "YES") {
        cout << "\nWould you like to SAVE or WIPE your list before QUITTING?\n"; 
        
        getline(cin, input);
        if (input == "SAVE" || input == "save") {
            Save(games);
            cout << "\nYour favorite games have been saved!\n";
            cout << "Thanks for playing!\n";
            return 0;   //ends game

        }   
        
        else if (input == "Wipe" || input == "WIPE" || input == "wipe") {
            Wipe(games);
            cout << "\nYou have wiped your game file.\n";
            cout << "Thanks for playing.\n";
            return 0;   ///ends game

            }    
         } // end of yes answer
       }    //end of quit

       else {
        cout << "\nThat was not an option. Please try again.\n\n";
       }    //end of main while loop











    }   //end of while loop
}