#include <conio.h>
#include <conio.h>
#include "Combat.h"
#include "windows.h"
void Combat::CombatChooise(Player& p, Enemy& e) {
	std::cin >> chInput;
	enemyAttack = (e.maxSTAM * 20)/100;
	if (e.hp < ((e.maxHP * 30) / 100) && e.stam < ((e.maxSTAM * 30) / 100))
	{
		Defend = true;
	}
	else
	{
		Defend = false;
	}
	if (e.stam < ((e.maxSTAM * 20) / 100))
	{
		Rest = true;
	}
	else
	{
		Rest = false;
	}

	switch (chInput)
	{
	case 'A'://Si el player ataca
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
			else if(Rest)//Si el enemigo descansa
			{
				printf("");
				e.hp = e.hp - playerAttack;
				e.stam = e.maxSTAM;
				printf("\n");
				printf("Enter a character to update the fight...");
			}
		}

		break;
	case 'D'://Si el player se defiende
		printf("\n");
		if (Defend == false && Rest == false)
		{
			printf("");
			e.stam = e.stam - enemyAttack;
			p.hp = p.hp - ((enemyAttack * 75) / 100);
			p.stam = p.stam + ((p.maxSTAM * 25) / 100);
			printf("\n");
			printf("Enter a character to update the fight...");
		}
		else if (Defend)//Si el enemigo se defiende
		{
			printf("");
			e.stam = e.stam + ((e.maxSTAM * 25) / 100);
			p.stam = p.stam + ((p.maxSTAM * 25) / 100);
			printf("\n");
			printf("Enter a character to update the fight...");
		}
		else if (Rest)//Si el enemigo descansa
		{
			printf("");
			e.stam = e.maxSTAM;
			p.stam = p.stam + ((p.maxSTAM * 25) / 100);
			printf("\n");
			printf("Enter a character to update the fight...");
		}
		break;
	case 'R'://Si el player descansa
		printf("\n");
		p.stam = p.maxSTAM;
		if (Defend == false && Rest == false)
		{
			printf("");
			e.stam = e.stam - enemyAttack;
			p.hp = p.hp - enemyAttack;
			printf("\n");
			printf("Enter a character to update the fight...");
		}
		else if (Defend)
		{
			printf("");
			e.stam = e.stam + ((e.maxSTAM * 25) / 100);
			printf("\n");
			printf("Enter a character to update the fight...");

		}
		else if (Rest)
		{
			printf("");
			e.stam = e.maxSTAM;
			printf("\n");
			printf("Enter a character to update the fight...");
		}
		break;
	case 'P'://Si el player se toma una poción
		printf("\n");
		if (p.potions != 0)
		{
			printf("");
			p.hp = ((p.hp * 40) / 100);
			p.potions--;
			printf("\n");
			printf("Enter a character to update the fight...");
		}
		else
		{
			printf("");
			printf("\n");
			printf("Enter a character to update the fight...");
		}
		break;
	default:
		break;
	}
}