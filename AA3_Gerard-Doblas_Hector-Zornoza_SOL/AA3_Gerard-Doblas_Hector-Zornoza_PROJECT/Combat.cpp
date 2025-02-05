#include <conio.h>
#include <conio.h>
#include "Combat.h"
#include "windows.h"																						//Los printf
void Combat::CombatChooise(Player& p, Enemy& e) {
	enemyAttack = (e.maxSTAM * 20)/100;
	if (e.hp < ((e.maxHP * 30) / 100) && e.stam < ((e.maxSTAM * 30) / 100))
	{
		Defend = true;
	}
	else if (e.hp > ((e.maxHP * 30) / 100) && e.stam > ((e.maxSTAM * 30) / 100))
	{
		Defend = false;
	}
	if (e.stam < ((e.maxSTAM * 20) / 100) && Defend == false)
	{
		Rest = true;
	}
	else if (e.stam > ((e.maxSTAM * 20) / 100))
	{
		Rest = false;
	}
	scanf_s("%c", &chInput);
	switch (chInput)
	{
	case 'A'://Si el player ataca
		while (true)
		{
			printf("\n");
			printf("Enter the attack value (Max %d): %", p.maxSTAM);
			scanf_s("%d", &playerAttack);
			if (playerAttack <= p.maxSTAM && playerAttack > 0)
				break;
		}
		p.stam = p.stam - playerAttack;
		
			if (Defend == false && Rest == false)//Si el enemigo ataca
			{
				if (playerAttack < enemyAttack)//Si el enemigo acierta
				{
					printf("");
					p.hp = p.hp - enemyAttack;
					e.stam = e.stam - enemyAttack;
					printf("\n");
					printf("Enter a character to update the fight...");
					getchar();
					getchar();
				}
				else//Si el enemigo no acierta
				{
					printf("You strike the enemy with more force! The enemy receives %d damage", playerAttack);
					e.hp = e.hp - playerAttack;
					e.stam = e.stam - enemyAttack;
					printf("\n");
					printf("Enter a character to update the fight...");
					getchar();
					getchar();
				}
			}
			else if (Defend)//Si el enemigo se defiende
			{
				printf("");
				e.stam = e.stam + ((e.maxSTAM * 25)/100);
				if (e.stam > e.maxSTAM)
					e.stam = e.maxSTAM;
				e.hp = e.hp - ((playerAttack * 75) / 100);
				printf("\n");
				printf("Enter a character to update the fight...");
				getchar();
				getchar();

			}
			else if(Rest)//Si el enemigo descansa
			{
				printf("");
				e.hp = e.hp - playerAttack;
				e.stam = e.maxSTAM;
				printf("\n");
				printf("Enter a character to update the fight...");
				getchar();
				getchar();
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
			if (p.stam > p.maxSTAM)
				p.stam = p.maxSTAM;
			printf("\n");
			printf("Enter a character to update the fight...");
			getchar();
			getchar();

		}
		else if (Defend)//Si el enemigo se defiende
		{
			printf("");
			e.stam = e.stam + ((e.maxSTAM * 25) / 100);
			if (e.stam > e.maxSTAM)
				e.stam = e.maxSTAM;
			p.stam = p.stam + ((p.maxSTAM * 25) / 100);
			if (p.stam > p.maxSTAM)
				p.stam = p.maxSTAM;
			printf("\n");
			printf("Enter a character to update the fight...");
			getchar();
			getchar();
		}
		else if (Rest)//Si el enemigo descansa
		{
			printf("");
			e.stam = e.maxSTAM;
			p.stam = p.stam + ((p.maxSTAM * 25) / 100);
			if (p.stam > p.maxSTAM)
				p.stam = p.maxSTAM;
			printf("\n");
			printf("Enter a character to update the fight...");
			getchar();
			getchar();
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
			getchar();
			getchar();
		}
		else if (Defend)
		{
			printf("");
			e.stam = e.stam + ((e.maxSTAM * 25) / 100);
			if (e.stam > e.maxSTAM)
				e.stam = e.maxSTAM;
			printf("\n");
			printf("Enter a character to update the fight...");
			getchar();
			getchar();

		}
		else if (Rest)
		{
			printf("");
			e.stam = e.maxSTAM;
			printf("\n");
			printf("Enter a character to update the fight...");
			getchar();
			getchar();
		}
		break;
	case 'P'://Si el player se toma una poción
		printf("\n");
		if (p.potions != 0)
		{
			printf("");
			p.hp = p.hp + ((p.hp * 40) / 100);
			if (p.hp > p.maxHP)
				p.hp = p.maxHP;
			p.potions--;
			printf("\n");
			printf("Enter a character to update the fight...");
			getchar();
			getchar();
		}
		else
		{
			printf("");
			printf("\n");
			printf("Enter a character to update the fight...");
			getchar();
			getchar();
		}
		break;
	default:
		break;
	}
}