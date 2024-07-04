#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>

// #include <ostream>
// #include <istream>
 using namespace std;

 string input;
 vector<string> games;
 vector<string>::iterator iter;

 void Load(vector<string>& vector) {
    string line;
    ifstream readFile("save.txt");
    if(readFile.is_open()) {
        while(getline(readFile, line)) {
            vector.push_back(line);
        }
    }
    else {
        cout << "Cannot read from that file.\n";
    }
 }  //end of load 
 

 void Display(vector<string>& vector) {
    for(int i = 0; i < vector.size(); i++) {
        cout << i + 1 << ": " << vector[i] <<"\n\n";
    }

 }  //end of Display Function

 void AddGame(vector<string>& vector) {
    for (int i = 0; i < 1; i++) {
        getline(cin, input);
        vector.push_back(input); //adds input to the list
        cout << input << " has been added to your favorites!\n\n";
    }
    
 }  //end of Add Game Function/Ref

 void Remove(vector<string>& vector) {
    getline(cin, input);
    iter = find(vector.begin(), vector.end(), input);
    if (*iter == input) {
        vector.erase(iter);      //delete element form list. 
        cout << "\n" << input << " has been removed from your favorites.\n";
    
    }
 }  // end of Remove Function

 void Edit(vector<string>& vector) {
    getline(cin,input);
    iter = find(vector.begin(), vector.end(), input);
    if (*iter == input) {
        cout << "\nWhat would you like to change " << input << " to?\n";
        getline (cin,input);
        *iter = input;
        cout << "\nYou changed the game to " << input << endl;
    } 
    
    else {
        cout << "\n" << input << " was not found in your favorites.\n";
        cout << "Please try again.\n";
    }   //end of else 
 }  //end of Edit function

 void Save (const vector<string> & vector) {
    ofstream writeFile("save.txt");
    if(writeFile.is_open()) {
        for( int i = 0; i < vector.size(); i ++) {
            writeFile << vector[i] << "\n";
        }
    }
    writeFile.close();
}

void Wipe (const vector<string>& vector) {
      ofstream writeFile("save.txt");
           games.clear();
           writeFile.open("save.txt");
           if (writeFile.is_open()) {
            writeFile << "";
     }
           writeFile.close();
           
}   //end of wipe function

 