#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
string input;
vector<string> myFavGames = {"Majora's Mask", 
                             "Twilight Princess", 
                             "Baldur's Gate 3", 
                             "Minecraft", 
                             "Wind Waker"
                            };

cout << "There are so many wonderful games out in the world!\n";
cout << "Would you like to hear my favorites?\n";
getline(cin,input);
if (input == "yes" || input == "y" || input == "Yes") {
    cout << "\nThese are some of my favorites!\n";
    for (int i = 0;i < myFavGames.size(); i++) {
        cout << i + 1 << ". " << myFavGames[i] << "\n";
    }
}   //end of my favorite games

cout << "\nI would love to hear what some of your favorites are!\n";
vector<string> games;
vector<string>::iterator iter;
// auto iter = find(games.begin(), games.end(), input);

while (true) {

 cout << "What would you like to do?\n";
 cout << "Add, Edit, Remove, Show, or Quit?\n";
 getline(cin, input);

 if (input == "add" || input == "ad" || input == "ADD" || input == "Add") {
        for (int i = 0; i < 1; i++){
        cout << "\n\nWhat game would you like to add?\n";
        getline(cin, input);
        games.push_back(input); //adds input to the list
        cout << "\nGreat choice! " << input << " has been added to your favorites!\n";
        }
}  // end of input 'add'

 else if (input == "edit") {
    cout << "\nWhat game would you like to edit?\n";
    sort(games.begin(), games.end());
    for (int i = 0;i < games.size(); i++) {
        cout << i + 1 << ". " << games[i] << "\n";
    }
    cout << "Type the name of the game!\n";

    getline(cin,input);
    iter = find(games.begin(), games.end(), input);
    if (*iter == input) {
        cout << "\nWhat would you like to change " << input << " to?\n";
        getline (cin,input);
        *iter = input;
        cout << "\nYou changed the game to " << input << endl;
    } else {
        cout << "\n" << input << " was not found in your favorites.\n";
        cout << "Please try again.\n";
    }   //end of else 

    

} else if (input == "remove" || input == "delete" || input == "Remove") {
     sort(games.begin(), games.end());
     cout << "\nWhat game would you like to remove?\n";
     cout << "Type the name of the game.\n";
     for (int i = 0;i < games.size(); i++) {
        cout << i + 1 << ". " << games[i] << "\n";  //Shows the list of games.
     }
     getline(cin, input);
     iter = find(games.begin(), games.end(), input);
     if (*iter == input) {
        games.erase(iter);      //delete element form list. 
        cout << "\n" << input << " has been removed from your favorites.\n";
     } else {
        cout << "\nPlease try again. We couldn't find " << input << " in your favorites.\n";
     }  // end of else statement

    
} else if (input == "show"|| input == "Show" || input == "SHOW" || input == "sho") {
    sort(games.begin(), games.end());
    cout << "\nHere are your favorite games!\n";

    for (int i = 0;i < games.size(); i++) {
        cout << i + 1 << ". " << games[i] << "\n";
        cout << "\n";
    }

    
    //my first code doubled the numbers each time I typed 'show'
    // for (int i = 0; i < games.size(); i++) {
    //     games[i].insert(0, to_string(i + 1) + ": ");    //added ':' to numbers
    // }
    //     cout << "\n\nHere are your favorite games!\n";
    //     for(int i = 0; i < games.size(); i++) {
    //     cout << games[i] << "\n";
    // }


} else if (input == "quit" || input == "Quit" || input == "QUIT") {
    cout << "\nAre you sure you want to quit?\n";
    getline(cin,input);
    if(input == "yes" || input == "Yes" || input == "y") {
        cout << "\nAlright! Thanks for playing.\n";
        return 0;   //ends program
    }
}else {
    cout << "\nThat was not an option. Please try again!\n";

}   // end of main else 
  
} // end of while loop

    
} // end of main program