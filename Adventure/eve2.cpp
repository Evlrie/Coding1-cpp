
//One thing I was having difficulty with was on the cinn >> answerYN
// if I typed 'y' or 'n' everything came out fine
// if I typed 'yes' or 'no' then it would spill everything in the loops at once and skip cin inputs.

#include <windows.h>    
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

int main () {
    int numInput = 0;
    
    int turn = 1;   //This starts my turn integer. 
    int health = 25;    //Player Stats
    int turns = 0;
    int block = 0;
    int attack = 1;
    int money = 10;
   
    int patronHealth = 10; //Patron stats
    int patronTurns = 0;
    int patronBlock = 0;
    int patronAttack = 1;
    int patronMoney = 20;

    int barHealth = 35;   //Bartender stats
    int bartenderTurns = 0;
    int bartenderBlock = 0;
    int barAttack = 1;
    int barMoney = 30;
    
    int potioncost = 30;  // this is for the store
   
    

    srand(time(NULL));  // seeds the random number generator
    cout << "\n\nYou have walked into a small tavern. You have " << money << " gold coins.\n";
    cout << "The bartender strikes up conversation with you.\n\n";
    Sleep (2000);
    cout << "\"Welcome to The Leaky Tap Tavern!\n";         
    cout << "You must be the adventurer I've heard so much about...\"\n\n";
    Sleep(2000);
    cout << "\"Alas, my memory deceives me. What is your name?\"\n\n";
  
    string userName = "";
    cin >> userName;
    Sleep(1000);
    cout << "\n\n\"Ah yes, " << userName << "! I'll make sure to remember.\n\n";

    char initial = 'b';
    char answerYN = 'y';
    Sleep(1000);
    cout << "\"Would you like to hear more about a job I have for you, " << userName << "?\"\n";
    cout << "Press 'y' or 'n' for yes/no questions.\n\n";   //IF ANSWER IS ANYTHING ELSE THE GAME SKIPS SOME CIN INPUTS AND KEEPS PLAYING. Tried a string with or statements... did not work for me.
    cin >> answerYN;


    
    if(answerYN == 'y') {   //Answering 'y' will result in my more developed fight loop with patrons of tavern.
        Sleep (1000);                 
        cout << "\n\n\"See those two unruly patrons over there?\n";
        cout << "Please escort them out, and I'll give you money!\"\n\n\n";
        Sleep (2000);
        cout << "You look over to where the bartender points, and see the patrons in question.\n";
        cout << "You make your way over to the patrons.\n";
        cout << "They tell you to get lost, and fighting ensues.\n\n";
        Sleep(4000);



    while (answerYN == 'y') {   // starts patron fight routine

        while (health > 0 || patronHealth > 0) {
            Sleep(1000);
            if(turn <= 4) {
                // cout << "Turn #" << turn << "\n";
            int playerDamage = rand () % 6 + 1;
            int patronDamage = rand () % 4 + 1;
            int playerDefend = rand () % 3 + 1;
            int patronDefend = rand () % 3 + 1;
            if (patronDamage > playerDefend) {      //If you failed to defend against attack.
                cout << "\n";
                
                cout << "The patron wacked you with their tankard!\n";
                health -= patronDamage;
                cout << "Your health: " << health << "\n\n";
                

            } else      //If you succeed in dodging attack
            cout << "\nYou successfully dodged the patron's attack!\n";


        if (playerDamage > patronDefend) {     //If enemy fails to defend against your attack.
            
            cout << "You slung a nasty punch to the patron.\n";
            patronHealth -= playerDamage;
            cout << "Patron's health: " << patronHealth << "\n\n";
            
        } else  //If you failed to hit enemy
            cout << "The Patron dodged your sloppy punch.\n\n";

    

        if (health <= 0) {      //If your health reaches 0 or less you get knocked out, ends game
            patronMoney += money;
            money = 0;
            cout << "The patron has knocked you out and taken you money!\n";
            cout << "Better luck next time.\n";
            cout << "Your wallet: " << money << "\n"; 
            cout << "Your health: " << health << "\n";
            return 0;

        } else if (patronHealth <= 0) {     //If patron health reaches 0 or less
            money += patronMoney;
            Sleep(3000);
            cout << "\nYou managed to grab the patron and chuck them out the tavern doors.\n";
            cout << "Congratulations! You now have " << money << " gold coins!\n";
            cout << "Your health: " << health << "\n\n";
            // cout << "Patron's health: " << patronHealth << "\n";


            int patronDialogue = rand () % 2 + 1;  // used to randomly pick different dialogue options.
            string Dialogue1 =  "You look up and see his buddy getting ready for vengence.\n";
            string Dialogue2 = "Someone taps you on the shoulder. You look over and see a fist hurling towards you.\n";
            string Dialogue3 = "A patron barges through the front doors and decides to fight.\n";

            if (patronDialogue == 1)  {     // different descriptions for enemies to give the loop variety if you continue it, based on a random dice.
                cout << Dialogue1;
            } else if (patronDialogue == 2) {       
                cout << Dialogue2;
            } else {
                cout << Dialogue3;
            }
            

            patronHealth = rand () % 20 + 1;    //After winning first fight enemies in the loop will have differnt health than first.
            patronMoney = rand () % 10 + 1;     //Random money enemies drop
            turn = 0;                              
            
        }turn = turn + 1; 
            if (turn > 4) {  //When turn reaches more than 4 you get this option.
                Sleep(3000);
                cout << "You both get tired of fighting and decide to leave and go to another tavern together.\n";
                cout << "Thanks for playing!\n";
                return 0;
            } 
            }   //end of turn loop


            Sleep(2000);
            cout << "Would you like to continue fighting the patrons?\n";
            cout << "Type 'y' or 'n'\n\n";
            cin >> answerYN;


            if (answerYN == 'n') {   //No response to the question do you want to continue.
                Sleep(1000);
                cout << "\n\nYou manage to ditch the tavern and patrons.\n\n";
                cout << "Press 1 to go to store. Your money: " << money << "\n"; //temporary
                cout << "Press 2 to end the game.\n\n";
                cin >> numInput;
                

            if (numInput == 1) {    //If you chose to go to the shop.
                 Sleep(1000);
                cout << "\n\n\n\n\"Hello there, welcome to my shop! How can I help you?\"\n\n";
                cout << "Your money: " << money << "\n\n";
                cout << "Press '1' or '2'\n";
                cout << "1. Health potion: 30 gold coins\n";
                cout << "2. Return to Patron Battle.\n\n";
                cin >> numInput;


            if (numInput == 1) {    //If you don't have enough money to buy health potion.
            Sleep(1000);
                if (money < potioncost) {
                cout << "\n\n\"Sorry. You don't have enought to buy the potion\"\n\n";
                cout << "Would you like to return to the battle?\n";
                cout << "Type 'y' or 'n'\n\n";
                cin >> answerYN;
                if (answerYN=='n') {
                    cout << "\nYou decide to go home. Thanks for playing.\n\n";
                    return 0;
                }
            } else if (money >= potioncost) {        //If you can buy the potion
                cout << "\n\n\"Thanks for your business! Hope you feel better!\"\n\n"; 
                money -= potioncost;
                cout << "Your money: " << money << "\n";
                 Sleep(1000);
            cout << "You used the health potion you bought, and are feeling a lot better!\n";
            cout << "Would you like to return to the battle?\n";
            cout << "Type 'y' or 'n'\n";
            health = 25;        //Restores health back to full hp.
            cout << "Your health: " << health << "\n\n";
            cin >> answerYN;       
            if (answerYN != 'y') {      //anything that doesn't = y will end game.
                cout << "\nYou decided to call it a day. Thanks for playing!\n";
                return 0;
            }
            }
            
            
        } //end of NumInput 1
        
        } else if (numInput == 2) {     //If you don't want to return to fighting after going to store
            cout << "\n\n\nYou return home. Thanks for playing!\n";
            return 0;
        }   //end of NumInput 2
            
        
        }   //end of answer 'n' to do you want to continue question
        
        }   //end of health

        }   //end of answerYN = 'y'


    } else if (answerYN == 'n') {            //Answering 'n' will lead to a fight with the bartender, but not as complicated as 'y' loop.
        answerYN = 'y';                        //Flipped it to 'y' so we can keep fighting in the while loop.  
        Sleep (1000);
        cout << "\n\nYou have offended the bartender with your bluntness. Prepare for a barfight!\n\n";
        Sleep (1000);

        
        while (answerYN == 'y') {       //Pretty much the same layout moving foward as patron battle. Just no store, or option to continue fighting after winning. 
        while (health > 0 || barHealth > 0) {   //health greater than 0 keeps playing   
            if(turn <= 4) {
                // cout << "Turn #" << turn << "\n";
            int playerDamage = rand () % 6 + 1;
            int barDamage = rand () % 6 + 1;
            int playerDefend = rand () % 4 + 1;
            int barDefend = rand () % 4 + 1;
            if (barDamage > playerDefend) {
                cout << "\n";
                cout << "The bartender threw a mean punch.\n";
                health -= barDamage;
                cout << "Your health: " << health << "\n\n";
                
            } else 
            cout << "You successfully dodged the bartender's attack!\n";
        
        if (playerDamage > barDefend) {
            cout << "You painfully kicked the bartender.\n";
            barHealth -= playerDamage;
            cout << "Bartender's health: " << barHealth << "\n\n";
            

        } else 
            cout << "The bartender dodged your sloppy punch.\n\n";
            
        if (health <= 0) {  //Gets knocked out if health reaches 0
            barMoney += money; 
            money = 0;
            cout << "\nThe bartender has knocked you out and taken your money!\n";
            cout << "Game over.\n";
            cout << "Your wallet: " << money << "\n";
            cout << "Your health: " << health << "\n";
            return 0;

        } else if (barHealth <= 0) {
            money += barMoney;
            cout << "You managed to knock the patron out!\n";
            cout << "Congratulations! You now have " << money << " gold coins!\n";
            cout << "Your health: " << health << "\n";
            cout << "Thanks for playing!";
            return 0;
           

          
        }turn = turn + 1; 
            if (turn > 4) {         //If turns reaches 4
                cout << "\"This is pointless.\"\n";
                cout << "You both get tired of fighting and decide to share an ale.\n";
                cout << "Thanks for playing!\n";
                return 0;
            } 
            }   
            Sleep (2000);
            cout << "Would you like to continue fighting the bartender?\n\n";
            cin >> answerYN;
            cout << "\n";
            if (answerYN == 'n') {      //If you answer no to continuing your fight.
                cout << "\n\n You apologize for offending the bartender, and leave the tavern.\n";
                cout << "Thanks for playing\n";
                return 0;
           }

        
        }   //end of health loop.

    }       //end of YN while loop
    }       //end of first YN question 
  

    

   

} //end of main