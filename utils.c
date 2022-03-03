#include "main.h"

int		arr_size(const char **str)
{
	int ret;

	ret = 0;
	while (str[ret])
		ret += 1;
	return (ret);
}

void	print_equip(t_equip *equip)
{
	char *type[] = {"Weapon", "Helmet", "Shield", "Gauntlet", "Chestpiece", "Boots"};
	char *rank[] = {"Common", "Uncommon", "Rare", "Epic", "Legendary"};

	printf("%s ", type[equip->type]);
	printf("(+%i)\n", equip->levels);
	for (int i = 0; i < equip->stars; i += 1)
		printf("*");
	printf("\n");
	if (equip->rank == COMMON)
		printf(GRY "%s\n\n" RESET, rank[equip->rank]);
	else if (equip->rank == UNCOMMON)
		printf(GRN "%s\n\n" RESET, rank[equip->rank]);
	else if (equip->rank == RARE)
		printf(BLU "%s\n\n" RESET, rank[equip->rank]);
	else if (equip->rank == EPIC)
		printf(MAG "%s\n\n" RESET, rank[equip->rank]);
	else if (equip->rank == LEGENDARY)
		printf(YEL "%s\n\n" RESET, rank[equip->rank]);

	int width = 13;
	for (int i = 0; i < 4; i += 1)
	{
		if (equip->substat[i] == HP_PERC)
			printf("%-*s %i%%\n", width, "HP", equip->substat_value[i]);
		else if (equip->substat[i] == HP_FLAT)
			printf("%-*s %i\n", width, "HP", equip->substat_value[i]);
		else if (equip->substat[i] == ATK_PERC)
			printf("%-*s %i%%\n", width, "Attack", equip->substat_value[i]);
		else if (equip->substat[i] == ATK_FLAT)
			printf("%-*s %i\n", width, "Attack", equip->substat_value[i]);
		else if (equip->substat[i] == DEF_PERC)
			printf("%-*s %i%%\n", width, "Defense", equip->substat_value[i]);
		else if (equip->substat[i] == DEF_FLAT)
			printf("%-*s %i\n", width, "Defense", equip->substat_value[i]);
		else if (equip->substat[i] == SPEED)
			printf("%-*s %i\n", width, "Speed", equip->substat_value[i]);
		else if (equip->substat[i] == CRIT_RATE)
			printf("%-*s %i%%\n", width, "Crit Rate", equip->substat_value[i]);
		else if (equip->substat[i] == CRIT_DMG)
			printf("%-*s %i%%\n", width, "Crit Damage", equip->substat_value[i]);
		else if (equip->substat[i] == ACCURACY)
			printf("%-*s %i\n", width, "Accuracy", equip->substat_value[i]);
		else if (equip->substat[i] == RESISTANCE)
			printf("%-*s %i\n", width, "Resistance", equip->substat_value[i]);
	}
}

//* Perc = percentage up to one decimal place
bool	probability(float perc)
{
	int	num;
	int	rand;

	num = (int) (perc * 10);
	rand = rand_num(1, 1000);
	if (rand <= num)
		return (true);
	return (false);
}

int		rand_num(int lower, int upper)
{
	int	ret;
	struct timeval	time;

	usleep(1);
	gettimeofday(&time, NULL);
	srand(time.tv_usec);
	ret = (rand() % (upper - lower + 1)) + lower;
	return (ret);
}
