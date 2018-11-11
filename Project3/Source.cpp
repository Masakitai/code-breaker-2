//code breaker part 2 by Christian Mangione
//inclusions
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <cctype>
#include <vector>
//namespace
using namespace std;
//start program
int main()
{
	// Display Title of program to user
	cout << "\t\t\tWelcome to the Code Breaker System!\n\n";
	// Ask the recruit to login using thier name
	cout << "What is your handle, spy?\n";
	// Hold the recruit's name in a var, and address them by it throughout the simulation.
	string username = " ";
	//input name
	cin >> username;
	// Display an overview of what Keywords II is to the recruit 
	cout << "\n\nThe Soviet Union wants to bomb Virginia!\n\n";
	cout << "Decipher 3 codes to disable the nukes, " << username << ".\n";
	// Display an directions to the recruit on how to use Keywords
	cout << "To break the codes, attempt a single letter at a time until the full passphrase is revealed.\n";
	cout << "You will be informed, if you guess correctly and admonished, if you do not.\n";
	cout << "The world hangs in the balance. You are our only hope, " << username << ".\n\n";
	cout << "Go forth, " << username << ", and prosper!\n\n";
	// Create a collection of 10 words you had wrote down manually
	//vector coolection 
	vector<string> passphrase;
	//each word
	passphrase.push_back("TURMOIL");
	passphrase.push_back("COUNTDOWN");
	passphrase.push_back("SATCHEL");
	passphrase.push_back("TRENCHCOAT");
	passphrase.push_back("INTIMIDATE");
	passphrase.push_back("SIDEKICK");
	passphrase.push_back("CODENAME");
	passphrase.push_back("POISON");
	passphrase.push_back("UNDERCOVER");
	passphrase.push_back("TANGERINE");
	// Create an int var to count the number of simulations being run starting at 1
	int simulations = 1;
	//play loop
	string playAgain = "yes";
	while (playAgain == "yes")
	{
		// Display the simulation # is staring to the recruit. 
		cout << "Starting simulation " << simulations << "!\n\n";
		// Pick new 3 random words from your collection as the secret code word the recruit has to guess. 
		//random seed
		srand(static_cast<unsigned int>(time(0)));
		//shuffle
		random_shuffle(passphrase.begin(), passphrase.end());
		//words to guess
		// need 3
		int wordCount = 0;
		while (wordCount < 3)
		{
			const string thisWord = passphrase[wordCount];
			// While recruit hasnft made too many incorrect guesses and hasnft guessed the secret word
			//guess var
			int guess = 0;
			int maxGuess = 8;
			//random words
			string WORDS(thisWord.size(), '-');
			string lettersUsed = "";
			//word loop
			while ((guess < maxGuess) && (WORDS != thisWord))
			{
				//     Tell recruit how many incorrect guesses he or she has left
				cout << username << ", you only have " << (maxGuess - guess) << " chances to get the word right before the enemy finds you! Get to work!\n\n";
				//     Show recruit the letters he or she has guessed
				cout << "Here is a list of letters which have already been used:\n" << lettersUsed << "\n";
				//     Show player how much of the secret word he or she has guessed
				cout << "\nAt this point, the code is:\n" << WORDS << "\n\n";
				//     Get recruit's next guess
				char choice;
				cout << "\n\nEnter the Code:";
				cin >> choice;
				//allows any case to apply to code
				choice = toupper(choice);
				//     While recruit has entered a letter that he or she has already guessed
				while (lettersUsed.find(choice) != string::npos)
				{
					cout << "\nYou have already attempted to use " << choice << ".";
					//          Get recruit fs guess
					cout << "\n\nEnter the Code:";
					cin >> choice;
					//allows any case to apply to code
					choice = toupper(choice);
				}
				//     Add the new guess to the group of used letters
				lettersUsed += choice;
				//     If the guess is in the secret word
				if (thisWord.find(choice) != string::npos)
				{
					//          Tell the recruit the guess is correct
					cout << "You have assumed correctly." << choice << " is in the code.\n";
					//          Update the word guessed so far with the new letter
					for (int v = 0; v < thisWord.length(); ++v)
					{
						if (thisWord[v] == choice)
						{
							WORDS[v] = choice;
						}
					}
				}
				else
				{
					//     Otherwise
					//          Tell the recruit the guess is incorrect
					cout << "\nYour choice of " << choice << " is an utter failure.\n";
					//          Increment the number of incorrect guesses the recruit has made
					++guess;
				}

			}
			// If the recruit has made too many incorrect guesses
			if (guess == maxGuess)
			{
				//     Tell the recruit that he or she has failed the Keywords II course.
				cout << "\nYou have failed to save Virginia. Santa will be displeased.\n";
				cout << "We have petitioned to remove the name " << username << " from his 'Good' list. \n\n";
			}
			else
			{
				// Otherwise
				//     Congratulate the recruit on guessing the secret words
				cout << "\nWell done, spy.";
			}
			//count words and return to top
			++wordCount;
			if (wordCount != 3)
			{
				int left = (3 - wordCount);
				cout << "\nThere are " << left << " codes remaining, probie.\n";
			}
			else
			{
				//exit simulation
				cout << "\nAll codes have been shown. The test is over.\n";
			}

		}
		// Ask the recruit if they would like to run the simulation again
		cout << "Would you like to play a game?\n";
		cout << "How about Thermonuclear Warfare?\n yes/no\n";
		// If the recruit wants to run the simulation again
		cin >> playAgain;
		//     Increment the number of simiulations ran counter
		++simulations;
		//     Move program execution back up to // Display the simulation # is staring to the recruit. 
	}
	// Otherwise 
	//     Display End of Simulations to the recruit
	cout << "Goodbye, " << username << ". It has been our esteemed privilege.";
	//     Pause the Simulation with press any key to continue
	system("pause");
	return 0;
}

