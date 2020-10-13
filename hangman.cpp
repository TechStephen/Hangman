#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <cstdlib>

using namespace std;

class Hangman {
    public:
        string words[28] = {"perfect", "welcome", "healthy", "crooked","unusual", "leading", "graphic", "purging", "similar", "iranian", "damaged", "Pacific", "gutless", "thrifty", "corrupt", "mediate", "orbital", "hostile", "artless", "pungent", "defiant", "logical", "sitting", "selfish", "weekday", "bipolar", "changed", "colored"};
        string word;
        int numofguesses = 0;
        int maxnumofguesses = 5;
        int count = 0;
        vector <char> blanks;
        char pickedWord[7];
        bool guessed = false;
        bool done = false;
        bool going;
        bool bln, bln2, bln3, bln4, bln5, bln6 = false;

        Hangman() {
            blanks.push_back('_'); blanks.push_back('_'); blanks.push_back('_'); blanks.push_back('_');
            blanks.push_back('_'); blanks.push_back('_'); blanks.push_back('_');
            
            srand(time(NULL));
            int rndNum = (rand() % 28) + 1; 
            word = words[rndNum];

            for(int i=0;i<7;i++) {
                pickedWord[i] = word.at(i);
            }
        }

        void miss(int failedguesses) {
            switch(failedguesses) {
                case 0:
                    cout << "\n" << "O" << "\n";
                    printAllBlanks(); 
                    numofguesses = numofguesses + 1;
                    maxnumofguesses = maxnumofguesses - 1;
                    break;
                case 1:
                    cout << "\n" << "O-" << "\n";
                    printAllBlanks();
                    numofguesses = numofguesses + 1;
                    maxnumofguesses = maxnumofguesses - 1;
                    break;
                case 2:
                    cout << "\n" << "O->" << "\n";
                    printAllBlanks();
                    numofguesses = numofguesses + 1;
                    maxnumofguesses = maxnumofguesses - 1;
                    break;
                case 3:
                    cout << "\n" << "O->-" << "\n";
                    printAllBlanks();
                    numofguesses = numofguesses + 1;
                    maxnumofguesses = maxnumofguesses - 1;
                    break;
                case 4:
                    cout << "O->-<" << "\n";
                    cout << "You Lose! Out of Guesses!" << "\n" << "Word was: " << word << "!";
                    numofguesses = numofguesses + 1;
                    maxnumofguesses = maxnumofguesses - 1;
                    guessed = true;
                    break;   
            }
        }

        int getMaxGuess() {
            return maxnumofguesses;
        }

        int getNumGuesses() {
            return numofguesses;
        }

        bool getGuessed() {
            return guessed;
        }

        void printPhrase(char letter) {
           done = false;
           string test = "";
           string s;
           while(done == false) {
               for(int i = 0; i < 7; i++) {
                   if(letter == pickedWord[i]) {
                       blanks.insert(blanks.begin()+(i), letter);
                       blanks.erase(blanks.begin()+(i+1));

                       for(int i=0;i<blanks.size();i++) {
                        s += blanks.at(i);
                     }
                        string ans = test + s;

                        if(isEqual(ans,word)==true) {printAllBlanks(); guessed = true;}

                        done = true;     
                   }
               }
           }
            if(guessed == false) {
                printAllBlanks();
            }
            else {

            }
        }
        
        void printAllBlanks() {
            for(int i=0;i<blanks.size();i++) {
                cout << blanks.at(i);
            }
        }

        string getWord() {
            return word;
        }

        void logic(char letter) {
            if(letter==word.at(0) || letter==word.at(1) || letter==word.at(2) || letter==word.at(3) || letter==word.at(4) || letter==word.at(5) || letter==word.at(6)) {
                printPhrase(letter);
                going = true;
            }
            else 
            {
                miss(count);
                count++;
            }
        }

        bool isEqual(string s, string str) {
            char tmp[7];
            char tmp2[7];
            bool equal = false;
            for(int i=0;i<7;i++) {
                tmp[i] = s.at(i);
            }
            for(int i=0;i<7;i++) {
                tmp2[i] = str.at(i);
            }
            if(tmp[0] == tmp2[0] && tmp[1] == tmp2[1] && tmp[2] == tmp2[2] && tmp[3] == tmp2[3] && tmp[4] == tmp2[4] && tmp[5] == tmp2[5] && tmp[6] == tmp2[6]) {
                equal = true;
            }
            else {
                
            }
            return equal;
        }

        void setFalse() {
            guessed = false;
        }

};



int main() 
{
    int cntr = 0;
    char ans;
    bool playAgain = true;

    while(playAgain == true && cntr == 0) {
        Hangman hangman;
        string w = hangman.getWord();
        cout << "---------HangMan!--------";
        cout << "\n" << "Guess the word using letters!" << "\n" << "Hint: is an Adjectives" << "\n" << "_ _ _ _ _ _ _";
    while(hangman.getGuessed() == false) {
        cout << "\n" << "You have " << hangman.getMaxGuess() << " wrong guesses left: " << endl;
        cin >> ans;
        cntr = cntr + 1;

        hangman.logic(ans);
    }

    if(hangman.getMaxGuess() == 0) {
        cout << "";
    }
    else {
        cout << "\n" << "You Win! You Guessed the Word!";
    }
        string resp;
        cout << "\n" << "Would you like to play again?(y/n): ";
        cin.ignore();
        getline(cin, resp);
        if(resp == "y") {
            hangman.setFalse();
            cntr = 0;
        }
        else {
            cout << "\n" << "Thanks for playing!";
            playAgain = false;
        }

    }
    
    return 0;
}
