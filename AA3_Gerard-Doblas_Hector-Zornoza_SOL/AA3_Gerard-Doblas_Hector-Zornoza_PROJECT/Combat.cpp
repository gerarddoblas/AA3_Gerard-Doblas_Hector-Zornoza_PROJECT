#include <conio.h>
#include <conio.h>
#include "Combat.h"
#include "windows.h"
void Combat::CombatChooise(Player& p, Enemy& e) {
	std::cin >> chInput;
	enemyAttack = (e.maxSTAM * 20)/100;
	switch (chInput)
	{
	case 'A':
		printf("\n");
		printf("Enter the attack value (Max :%d): %", p.maxSTAM);
		std::cin >> playerAttack;
		p.stam = p.stam - playerAttack;
		if (playerAttack > p.maxSTAM && playerAttack < 0)//Si el Player no pone bien el numero
		{
			printf("");
		}
		else
		{
		
			if (Defend == false && Rest == false)//Si el enemigo ataca
			{
				if (playerAttack < enemyAttack)//Si el enemigo acierta
				{
					printf("");
					p.hp = p.hp - enemyAttack;
					e.stam = e.stam - enemyAttack;
					printf("\n");
					printf("Enter a character to update the fight...");
				}
				else//Si el enemigo no acierta
				{
					printf("You strike the enemy with more force! The enemy receives %d damage", playerAttack);
					e.hp = e.hp - playerAttack;
					e.stam = e.stam - enemyAttack;
					printf("\n");
					printf("Enter a character to update the fight...");
				}
			}
			else if (Defend)//Si el enemigo se defiende
			{
				printf("");
				e.stam = e.stam + ((e.maxSTAM * 25)/100);
				e.hp = e.hp - ((playerAttack * 75) / 100);
				printf("\n");
				printf("Enter a character to update the fight...");

			}
			else
			{

			}
			


		}

		break;
	case 'D':
		break;
	case 'R':
		break;
	case 'P':
		break;
	default:
		break;
	}
}