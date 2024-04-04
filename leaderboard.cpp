#include<iostream>
#include<filesystem>
#include<SFML/Graphics.hpp>

int score = 0;
int cnt;
char EnterName[40] = "Unknown";
int indexNumber = strlen(EnterName);
typedef struct PlayerInfo
{
	char GameName[40];
	int GameScore;
}P;

P SortingArray[11];

void ShowHighScores()
{
	FILE* filepointer = fopen("HighScores.txt", "rb");
	fread(SortingArray, sizeof(P), 10, filepointer);
	fclose(filepointer);
}

void UpdateHighScores()
{
	FILE* filepointer = fopen("HighScores.txt", "rb");

	fread(SortingArray, sizeof(P), 10, filepointer);
	fclose(filepointer);

	new score;

	SortingArray[10].GameScore = score;

	strcpy(SortingArray[10].GameName, EnterName);
	for (int i = 10;i > 0;i--) {
		int k = 0;
		for (int j = 0;j <= i;j++) {
			if (SortingArray[j].GameScore < SortingArray[k].GameScore)
			{
				k = j;
			}
		}
		int t = SortingArray[i].GameScore;
		SortingArray[i].GameScore = SortingArray[k].GameScore;
		SortingArray[k].GameScore = t;
		char Name1[40], Name2[40];

		strcpy(Name1, SortingArray[i].GameName);
		strcpy(Name2, SortingArray[k].GameName);
		strcpy(SortingArray[k].GameName, Name1);
		strcpy(SortingArray[i].GameName, Name2);
	}
	filepointer = fopen("HighScores.txt", "wb");
	fwrite(SortingArray, sizeof(P), 10, filepointer);
	fclose(filepointer);
}
void printscores(sf::RenderWindow& window)
{
	sf::Text text;
	sf::Font font;
	for (auto i = 0;i < 10;i++)
		window.draw(SortingArray[i].GameName, SortingArray[i].GameScore);
		
}