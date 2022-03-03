#include "main.h"

static int	rand_perc(int stars, int substat)
{
	int num;

	num = 0;
	if (substat == HP_PERC || substat == ATK_PERC || substat == DEF_PERC
	    || substat == CRIT_RATE || substat == CRIT_DMG)
		num = rand_num(stars, stars + 2);
	return (num);
}

static int	rand_flat(int stars, int substat)
{
	int num;

	num = 0;
	if (substat == HP_FLAT || substat == ATK_FLAT || substat == DEF_FLAT)
		num = rand_num(100 * stars - 50, 100 * stars);
	else if (substat == SPEED)
	{
		if (stars <= 3)
			num = stars;
		else
			num = rand_num(stars - 1, stars);
	}
	else if (substat == ACCURACY || substat == RESISTANCE)
		num = rand_num(2 * stars, 3 * stars);
	return (num);
}

static void init_substat_value(t_equip *new)
{
	for (int i = 0; i < 4; i += 1)
	{
		if (new->substat[i] == HP_PERC)
			new->substat_value[i] = rand_perc(new->stars, HP_PERC);
		else if (new->substat[i] == HP_FLAT)
			new->substat_value[i] = rand_flat(new->stars, HP_FLAT);
		else if (new->substat[i] == ATK_PERC)
			new->substat_value[i] = rand_perc(new->stars, ATK_PERC);
		else if (new->substat[i] == ATK_FLAT)
			new->substat_value[i] = rand_flat(new->stars, ATK_FLAT);
		else if (new->substat[i] == DEF_PERC)
			new->substat_value[i] = rand_perc(new->stars, DEF_PERC);
		else if (new->substat[i] == DEF_FLAT)
			new->substat_value[i] = rand_flat(new->stars, DEF_FLAT);
		else if (new->substat[i] == SPEED)
			new->substat_value[i] = rand_flat(new->stars, SPEED);
		else if (new->substat[i] == CRIT_RATE)
			new->substat_value[i] = rand_perc(new->stars, CRIT_RATE);
		else if (new->substat[i] == CRIT_DMG)
			new->substat_value[i] = rand_perc(new->stars, CRIT_DMG);
		else if (new->substat[i] == ACCURACY)
			new->substat_value[i] = rand_flat(new->stars, ACCURACY);
		else if (new->substat[i] == RESISTANCE)
			new->substat_value[i] = rand_flat(new->stars, RESISTANCE);
	}
}

t_equip	*new_equip(void)
{
	t_equip	*new;

	new = calloc(1, sizeof(t_equip));
	new->type = rand_num(WEAPON, BOOTS);
	new->rank = rand_num(COMMON, LEGENDARY);
	new->stars = rand_num(1, 6);
	new->levels = 1;

	int reroll = 1;
	while (reroll)
	{
		reroll = 0;
		for (int i = 0; i < 4; i += 1)
			new->substat[i] = rand_num(HP_PERC, RESISTANCE);
		for (int i = 0; i < 4; i += 1)
			for (int j = i + 1; j < 4; j += 1)
				if (new->substat[i] == new->substat[j])
					reroll = 1;
	}
	init_substat_value(new);
	return (new);
}
