#include <conio.h>
#include <conio.h>
#include "Combat.h"
#include "windows.h"			

void Combat::CombatChooise(Player& p, Enemy& e) {
	if(firstTry < 1)
	{ 
		e.hp = rand() % (MAX_INIT_HP_EN - MIN_INIT_HP_EN) + MIN_INIT_HP_EN;
		e.stam = rand() % (MAX_INIT_ST_EN - MIN_INIT_ST_EN) + MIN_INIT_ST_EN;
		firstTry++;
	}
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
	scanf_s(" %c", &chInput,1);
	switch (chInput)
	{
	case 'A'://Si el player ataca
		if (p.stam <= 0)
		{
			printf("\n");
			printf("Your action was invalid! Enter a character to update the fight...");
			getchar();
			getchar();
			break;
		}else
		{
			while (true)
			{
				printf("\n");
				printf("Enter the attack value (Max %d): %", p.maxSTAM);
				scanf_s("%d", &playerAttack);
				if (playerAttack <= p.maxSTAM && playerAttack > 0)
					break;
			}
			p.stam = p.stam - playerAttack;
			if (p.stam < 0)
				p.stam = 0;

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
				printf("Garbage, the enemy has defended, but receive &d damage", (int)(playerAttack * 75) / 100);
				e.stam = e.stam + ((e.maxSTAM * 25) / 100);
				if (e.stam > e.maxSTAM)
					e.stam = e.maxSTAM;
				e.hp = e.hp - ((playerAttack * 75) / 100);
				printf("\n");
				printf("Enter a character to update the fight...");
				getchar();
				getchar();

			}
			else if (Rest)//Si el enemigo descansa
			{
				printf("You've hit him while he was resting, the enemy receive &d damage", (int)playerAttack);
				e.hp = e.hp - playerAttack;
				e.stam = e.maxSTAM;
				printf("\n");
				printf("Enter a character to update the fight...");
				getchar();
				getchar();
			}
			break;
		}
	case 'D'://Si el player se defiende
		printf("\n");
		if (Defend == false && Rest == false)
		{
			e.stam = e.stam - enemyAttack;
			p.hp = p.hp - ((enemyAttack * 75) / 100);
			p.stam = p.stam + ((p.maxSTAM * 25) / 100);
			if (p.stam > p.maxSTAM)
				p.stam = p.maxSTAM;
			printf("You defend the enemy blow, but receive %d damage", (int)(enemyAttack * 75)/100);
			printf("\n");
			printf("Enter a character to update the fight...");
			getchar();
			getchar();

		}
		else if (Defend)//Si el enemigo se defiende
		{
			printf("You have both defended yourselves");
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
			printf("Both of you have taken a rest");
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
			printf("You rest when the enemy hits you, striking for %d damage", (int)enemyAttack);
			e.stam = e.stam - enemyAttack;
			p.hp = p.hp - enemyAttack;
			printf("\n");
			printf("Enter a character to update the fight...");
			getchar();
			getchar();
		}
		else if (Defend)
		{
			printf("You rest when the enemy defended, anyone receive damage");
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
			printf("You rest when the enemy rest, anyone receive damage");
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
			printf("You drink the potion when the enemy hits you, striking for %d damage", (int)enemyAttack);
			p.hp = p.hp + ((p.maxHP * 40) / 100) - enemyAttack;
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