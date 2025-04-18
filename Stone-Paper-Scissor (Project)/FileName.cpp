#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

struct strWinResult
{
	int Player1Wins = 0, ComputerWins = 0, Draws = 0;
};

int ReadPositiveNumber(string Message)
{
	int Number = 0;
	do
	{
		cout << Message << endl;
		cin >> Number;
	} while (Number < 1);
	
	return Number;
}

int ReadChoice()
{

	int Choice;
	do
	{
		cin >> Choice;
	} while (Choice > 0 && Choice > 4);

	return Choice;
}

int RandomNumberGenerator(int From, int To)
{
	int RandomNumber = rand() % (To - From + 1) + From;
	return RandomNumber;
}

string RoundWinner( int UserChoice, int ComputerChoice , strWinResult &WinResult)
{
	string Result = "";
	

	if (UserChoice == ComputerChoice)
	{
		WinResult.Draws++;
		Result = "[No Winner]";
		return Result;
	}
	else if (UserChoice == 1 && ComputerChoice == 2)
	{
		WinResult.ComputerWins++;
		Result = "[Computer]";
		return Result;
	}
	else if (UserChoice == 2 && ComputerChoice == 1)
	{
		WinResult.Player1Wins++;
		Result = "[Player1]";
		return Result;
	}
	else if (UserChoice == 3 && ComputerChoice == 1)
	{
		WinResult.ComputerWins++;
		Result = "[Computer]";
		return Result;
	}
	else if (UserChoice == 1 && ComputerChoice == 3)
	{
		WinResult.Player1Wins++;
		Result = "[Player1]";
		return Result;
	}
	else if (UserChoice == 2 && ComputerChoice == 3)
	{
		WinResult.ComputerWins++;
		Result = "[Computer]";
		return Result;
	}
	else if (UserChoice == 3 && ComputerChoice == 2)
	{
		WinResult.Player1Wins++;
		Result = "[Player1]";
		return Result;
	}



}

string NumberToTitle(int Number)
{
	string Title = "";
	if (Number == 1)
		Title = "Stone";
	else if (Number == 2)
		Title = "Paper";
	else if (Number == 3)
		Title = "Scissor";

	return Title;
}

void ColorsAndSounds(string Result)
{
	if (Result == "[No Winner]")
		system("color 67");

	else if (Result == "[Player1]")
		system("color 27");

	else
	{
		system("color 47");
		cout << "\a";
	}
}

void RoundResults(int UserChoice, int ComputerChoice, int RoundNumber, strWinResult &WinResult)
{
	cout << "\n";
	cout << "----------Round [" << RoundNumber << "]----------\n";
	cout << "Player1 Choice: " << NumberToTitle(UserChoice) << endl ;
	cout << "Computer Choice: " << NumberToTitle(ComputerChoice) << endl;
	string Result = RoundWinner(UserChoice, ComputerChoice,WinResult);
	cout << "Round Winner: " << Result;
	ColorsAndSounds(Result);
	cout << endl;
	cout << "----------------------------\n";
}

string FinalWinner(strWinResult WinResult)
{
	string Winner = "";

	if (WinResult.ComputerWins > WinResult.Player1Wins)
		Winner = "Computer";
	else if (WinResult.ComputerWins < WinResult.Player1Wins)
		Winner = "Player1";
	else
		Winner = "No Winner";

	return Winner;
}

void GameResults( int Rounds, strWinResult WinResult)
{

	cout << endl;
	cout << "\t\t----------------------------\n";
	cout << "\t\t+++ G a m e O v e r ++\n";
	cout << "\t\t----------------------------\n";
	cout << "\t\t--------[Game Results]-------\n";
	cout << "Game Rounds         : " << Rounds << endl;
	cout << "Player1 won times   : " << WinResult.Player1Wins << endl;
	cout << "Computer won times  : " << WinResult.ComputerWins << endl;
	cout << "Draw times          : " << WinResult.Draws << endl;
	cout << "Final Winner        : " << FinalWinner(WinResult) << endl;

}

void GameRounds(int Rounds, strWinResult WinResult)
{
	int UserChoice = 0, ComputerChoice =0;


	for (int i = 1; i <= Rounds; i++)
	{
		cout << "\nRound [" << i << "] begins:\n";
		cout << "\nYour Choice: [1]:Stone, [2]:Paper, [3]:Scissors ?";
		UserChoice = ReadChoice();
		ComputerChoice = RandomNumberGenerator(1, 3);
		RoundResults(UserChoice, ComputerChoice, i,WinResult);
		
	}

	GameResults(Rounds, WinResult);
}

char WillContinue()
{
	char Continue;
	cout << "\n\n\t\t\tDo you want to play again? Y/N? ";
	cin >> Continue;
	return Continue;
}

void StartGame()
{

	strWinResult WinResult;

	char Continue;
	do
	{
		system("cls");
		system("color 07");
		int Rounds = ReadPositiveNumber("How many rounds from 1 to 10 : ");
		GameRounds(Rounds, WinResult);
	    Continue = WillContinue();
	} while (Continue == 'y' || Continue == 'Y');


}

int main()
{
	srand((unsigned)time(NULL));

	StartGame();

	return 0;
}


//
