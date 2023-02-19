#include <bits/stdc++.h>
#include <ctime>
#include <stdlib.h>
using namespace std;
const string WORD_LIST[] = {"dog", "cat", "human"};
const int WORD_COUNT = sizeof(WORD_LIST) /sizeof(string);
const int MAX_BAD_GUESSES = 9;
void PrintMessage(string message, bool printTop = true, bool printBottom = true)
{
    if (printTop)
    {
        cout << "+---------------------------------+" << endl;
        cout << "|";
    }
    else
    {
        cout << "|";
    }
    bool front = true;
    for (int i = message.length(); i < 33; i++)
    {
        if (front)
        {
            message = " " + message;
        }
        else
        {
            message = message + " ";
        }
        front = !front;
    }
    cout << message.c_str();

    if (printBottom)
    {
        cout << "|" << endl;
        cout << "+---------------------------------+" << endl;
    }
    else
    {
        cout << "|" << endl;
    }
}
void DrawHangman(int guessCount = 0)
{
    if (guessCount >= 1)
        PrintMessage("|", false, false);
    else
        PrintMessage("", false, false);

    if (guessCount >= 2)
        PrintMessage("|", false, false);
    else
        PrintMessage("", false, false);

    if (guessCount >= 3)
        PrintMessage("O", false, false);
    else
        PrintMessage("", false, false);

    if (guessCount == 4)
        PrintMessage("/  ", false, false);

    if (guessCount == 5)
        PrintMessage("/| ", false, false);

    if (guessCount >= 6)
        PrintMessage("/|\\", false, false);
    else
        PrintMessage("", false, false);

    if (guessCount >= 7)
        PrintMessage("|", false, false);
    else
        PrintMessage("", false, false);

    if (guessCount == 8)
        PrintMessage("/", false, false);

    if (guessCount >= 9)
        PrintMessage("/ \\", false, false);
    else
        PrintMessage("", false, false);
}
string chooseWord()
{
    int randomIndex = rand() % WORD_COUNT;
    return WORD_LIST[randomIndex];
}
void renderGame(string guessedWord, int badGuessedcount)
{
    cout << guessedWord << endl << badGuessedcount << endl;
}
char readAGuess()
{
    char ch;
    cout << "Enter your guess: ";
    cin >> ch;
    return ch;
}
string update(string guessedWord, char guess, string secretWord)
{
    for (int i = 0; i < guessedWord.length(); i++)
    {
        if(guess == secretWord[i]) guessedWord[i] = guess;
    }
    //cout << secretWord << " " << guess << " " << guessedWord << endl;
    return guessedWord;
}
void displayResult(bool lost)
{
    if(lost) cout << "Game Over!";
    else cout << "You won!";
}
bool contains(string word, char c)
{
    return (word.find_first_of(c) != string::npos);
}
int main ()
{
    srand(time(0));
    string secretWord = chooseWord();
    string guessedWord = string(secretWord.length(), '-');
    int badGuessCount = 0;
    PrintMessage("Hangman");
    do
    {
        renderGame(guessedWord, badGuessCount);
        char guess = readAGuess();
        if (contains(secretWord, guess))
          guessedWord = update(guessedWord, guess, secretWord);
        else badGuessCount++;
        DrawHangman(badGuessCount);
    } while (badGuessCount < MAX_BAD_GUESSES && guessedWord != secretWord);
    displayResult(badGuessCount == MAX_BAD_GUESSES);
    return 0;
}
