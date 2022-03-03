#ifndef MAIN_H
# define MAIN_H

# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <time.h>
# include <unistd.h>

# define BLK "\e[0;30m"
# define RED "\e[0;31m"
# define GRN "\e[0;32m"
# define YEL "\e[0;33m"
# define BLU "\e[0;34m"
# define MAG "\e[0;35m"
# define CYN "\e[0;36m"
# define WHT "\e[0;37m"
# define GRY "\e[0;90m"
# define RESET "\e[0m"

enum type {WEAPON, HELMET, SHIELD, GAUNTLET, CHESTPIECE, BOOTS};
enum rank {COMMON, UNCOMMON, RARE, EPIC, LEGENDARY};
enum substat {HP_PERC, HP_FLAT, ATK_PERC, ATK_FLAT, DEF_PERC, DEF_FLAT,
			  SPEED, CRIT_RATE, CRIT_DMG, ACCURACY, RESISTANCE};

typedef	struct s_equip
{
	short	type;
	short	rank;
	short	stars;
	short	levels;

	const char	*mainstat;
	short	substat[4];
	short	substat_value[4];
	short	substat_roll[4];
}	t_equip;

//* ---------- new_equip.c ----------
t_equip	*new_equip(void);

//* ---------- utils.c ----------
int		arr_size(const char **str);
void	print_equip(t_equip *equip);
bool	probability(float perc);
int		rand_num(int lower, int upper);

#endif