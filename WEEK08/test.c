/*/////////////////////////////////////////////////////////////////////////
						  Workshop - #7 (P2)
Full Name  : Chaerin Yoo
Student ID#: 102998234
Email      : cyoo10@myseneca.ca
Section    : NFF

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MAXIMUM_PATH 70
#define MINIMUM_PATH 10

#define MAX_NUM_LIVES 10
#define MIN_NUM_LIVES 1

struct PlayerInfo
{
	int num_lives;
	char character_symbol;
	int num_treasure;
	int positions[MAXIMUM_PATH];
};

struct GameInfo
{
	int max_num_move;
	int path_length;
	int bombs[MAXIMUM_PATH];
	int treasure[MAXIMUM_PATH];
};

int main(void)
{
	struct PlayerInfo player;
	struct GameInfo game;

	int i, j;

	printf("================================\n");
	printf("         Treasure Hunt!\n");
	printf("================================\n");
	printf("\n");

	printf("PLAYER Configuration\n");
	printf("--------------------\n");

	printf("Enter a single character to represent the player: ");
	scanf(" %c", &player.character_symbol);
	do
	{
		printf("Set the number of lives: ");
		scanf("%d", &player.num_lives);
		if (player.num_lives < MIN_NUM_LIVES || player.num_lives >MAX_NUM_LIVES)
		{
			printf("     Must be between %d and %d!\n", MIN_NUM_LIVES, MAX_NUM_LIVES);
		}
	} while (player.num_lives < MIN_NUM_LIVES || player.num_lives >MAX_NUM_LIVES);
	printf("Player configuration set-up is complete\n");
	printf("\n");

	player.num_treasure = 0;

	for (i = 0; i < MAXIMUM_PATH; i++)
	{
		player.positions[i] = 0;
	}

	printf("GAME Configuration\n");
	printf("------------------\n");
	do
	{
		printf("Set the path length (a multiple of 5 between 10-70): ");
		scanf("%d", &game.path_length);
		if (game.path_length < MINIMUM_PATH || game.path_length>MAXIMUM_PATH || game.path_length % 5 != 0)
		{
			printf("     Must be a multiple of 5 and between 10-70!!!\n");
		}
	} while (game.path_length < MINIMUM_PATH || game.path_length>MAXIMUM_PATH || game.path_length % 5 != 0);



	do
	{
		printf("Set the limit for number of moves allowed: ");
		scanf("%d", &game.max_num_move);
		if (game.max_num_move < player.num_lives || game.max_num_move > .75 * game.path_length)
		{
			printf("    Value must be between %d and %d\n", player.num_lives, (int)(.75 * game.path_length));
		}
	} while (game.max_num_move < player.num_lives || game.max_num_move > .75 * game.path_length);
	printf("\n");

	printf("BOMB Placement\n");
	printf("--------------\n");
	printf("Enter the bomb positions in sets of 5 where a value\n");
	printf("of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
	printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game.path_length);

	for (i = 0; i < game.path_length; i += 5)
	{
		printf("   Positions [%2d-%2d]: ", i + 1, i + 5);
		for (j = i; j < i + 5; j++)
		{
			scanf("%d", &game.bombs[j]);
		}
	}
	printf("BOMB placement set\n");
	printf("\n");

	printf("TREASURE Placement\n");
	printf("------------------\n");
	printf("Enter the treasure placements in sets of 5 where a value\n");
	printf("of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");
	printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game.path_length);
	for (i = 0; i < game.path_length; i += 5)
	{
		printf("   Positions [%2d-%2d]: ", i + 1, i + 5);
		for (j = i; j < i + 5; j++)
		{
			scanf("%d", &game.treasure[j]);
		}
	}
	printf("TREASURE placement set\n");
	printf("\n");

	printf("GAME configuration set-up is complete...\n");
	printf("\n");

	printf("------------------------------------\n");
	printf("TREASURE HUNT Configuration Settings\n");
	printf("------------------------------------\n");
	printf("Player:\n");
	printf("   Symbol     : %c\n", player.character_symbol);
	printf("   Lives      : %d\n", player.num_lives);
	printf("   Treasure   : [ready for gameplay]\n");
	printf("   History    : [ready for gameplay]\n");
	printf("\n");

	printf("Game:\n");
	printf("   Path Length: %d\n", game.path_length);
	printf("   Bombs      : ");
	for (i = 0; i < game.path_length; i++)
	{
		printf("%d", game.bombs[i]);
	}
	printf("\n");
	printf("   Treasure   : ");
	for (i = 0; i < game.path_length; i++)
	{
		printf("%d", game.treasure[i]);
	}
	printf("\n\n");
	printf("====================================\n");
	printf("~ Get ready to play TREASURE HUNT! ~\n");
	printf("====================================\n");

	char board[MAXIMUM_PATH];
	for (i = 0; i < game.path_length; i++)
	{
		board[i] = '-';
	}

	int nextMove = -1;
	while (player.num_lives > 0 && game.max_num_move > 0)
	{
		if (nextMove != -1)
		{
			printf("\n  ");
			for (i = 0; i < nextMove; i++)
			{
				if (i != nextMove - 1)
				{
					printf(" ");
				}
				else
				{
					printf("%c", player.character_symbol);
				}
			}
		}

		printf("\n  ");
		for (i = 0; i < game.path_length; i++)
		{
			printf("%c", board[i]);
		}

		printf("\n  ");

		for (i = 0; i < game.path_length; i++)
		{
			if ((i + 1) % 10 != 0)
			{
				printf("|");
			}
			else
			{
				printf("%d", (i + 1) / 10);
			}
		}

		printf("\n  ");

		for (i = 0; i < game.path_length; i++)
		{
			printf("%d", (i + 1) % 10);
		}
		printf("\n");
		printf("+---------------------------------------------------+\n");
		printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n", player.num_lives, player.num_treasure, game.max_num_move);
		printf("+---------------------------------------------------+\n");
		printf("Next Move [1-%d]: ", game.path_length);
		scanf("%d", &nextMove);

		while (nextMove < 1 || nextMove > game.path_length)
		{
			printf("  Out of Range!!!\n");
			printf("Next Move [1-%d]: ", game.path_length);
			scanf("%d", &nextMove);
		}
		printf("\n");

		if (player.positions[nextMove - 1] == 1)
		{
			printf("===============> Dope! You've been here before!\n");
		}
		else
		{
			player.positions[nextMove - 1] = 1;
			game.max_num_move -= 1;
			if (game.bombs[nextMove - 1] == 1 && game.treasure[nextMove - 1] == 1)
			{
				player.num_lives -= 1;
				player.num_treasure += 1;
				printf("===============> [&] !!! BOOOOOM !!! [&]\n");
				printf("===============> [&] $$$ Life Insurance Payout!!! [&]\n");
				board[nextMove - 1] = '&';
			}
			else if (game.bombs[nextMove - 1] == 1)
			{
				player.num_lives -= 1;
				printf("===============> [!] !!! BOOOOOM !!! [!]\n");
				board[nextMove - 1] = '!';
			}
			else if (game.treasure[nextMove - 1] == 1)
			{
				player.num_treasure += 1;
				printf("===============> [$] $$$ Found Treasure! $$$ [$]\n");
				board[nextMove - 1] = '$';
			}
			else
			{
				printf("===============> [.] ...Nothing found here... [.]\n");
				board[nextMove - 1] = '.';
			}
		}
	}

	printf("\nNo more LIVES remaining!\n");
	printf("\n  ");

	for (i = 0; i < game.path_length; i++)
	{
		if (i != nextMove - 1)
		{
			printf(" ");
		}
		else
		{
			printf("%c", player.character_symbol);
		}
	}

	printf("\n  ");

	for (i = 0; i < game.path_length; i++)
	{
		printf("%c", board[i]);
	}

	printf("\n  ");

	for (i = 0; i < game.path_length; i++)
	{
		if ((i + 1) % 10 != 0)
		{
			printf("|");
		}
		else
		{
			printf("%d", (i + 1) / 10);
		}
	}
	printf("\n  ");

	for (i = 0; i < game.path_length; i++)
	{
		printf("%d", (i + 1) % 10);
	}

	printf("\n");
	printf("+---------------------------------------------------+\n");
	printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n", player.num_lives, player.num_treasure, game.max_num_move);
	printf("+---------------------------------------------------+\n");
	printf("\n##################\n");
	printf("#   Game over!   #\n");
	printf("##################\n\n");
	printf("You should play again and try to beat your score!\n");


	return 0;

}

