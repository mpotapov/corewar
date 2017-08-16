#include "asm.h"

void	commands_date2(t_asm *bin, int *i)
{
	while (ft_stn(bin->file[*i]) && bin->file[*i] != '\n')
		(*i)++;
}

void	commands_date(t_asm *bin, int *i, int max_len, char *str)
{
	int n;

	commands_date2(bin, i);
	n = -1;
	if (bin->file[*i] == '"')
	{
		while (bin->file[++(*i)] != '"' && ++n < max_len)
			str[n] = bin->file[*i];
		str[++n] = '\0';
		if (bin->file[*i] == '"')
		{
			while (bin->file[*i])
			{
				if (bin->file[(*i)++] == '\n')
					return ;
				if (ft_stn(bin->file[*i]) || bin->file[*i] == '\n')
					continue ;
				else if (bin->file[*i] == COMMENT_CHAR)
					comment(bin, i);
				else
					break ;
			}
		}
	}
	bin->name == 1 ? error(bin, 0, 2) : error(bin, 0, 1);
}

void	commands(t_asm *bin, int *i)
{
	if (ft_strnequ(bin->file + *i, NAME_CMD_STRING,
			ft_strlen(NAME_CMD_STRING)) && !bin->name)
	{
		*i += ft_strlen(NAME_CMD_STRING);
		bin->name = 1;
		commands_date(bin, i, PROG_NAME_LENGTH, (char *)&bin->head.prog_name);
	}
	else if (ft_strnequ(bin->file + *i, COMMENT_CMD_STRING,
				ft_strlen(COMMENT_CMD_STRING)) && !bin->comm)
	{
		*i += ft_strlen(COMMENT_CMD_STRING);
		bin->comm = 1;
		commands_date(bin, i, COMMENT_LENGTH, (char *)&bin->head.comment);
	}
	else
		bin->name == 1 ? error(bin, 0, 2) : error(bin, 0, 1);
}

void	name_and_comment(t_asm *bin)
{
	int i;

	i = 0;
	while (bin->file[i])
	{
		if (bin->name && bin->comm)
			break ;
		if (ft_stn(bin->file[i]) || bin->file[i] == '\n')
			i++;
		else if (bin->file[i] == NAME_CMD_STRING[0])
			commands(bin, &i);
		else if (bin->file[i] == COMMENT_CHAR)
			comment(bin, &i);
		else
			bin->name == 1 ? error(bin, 0, 4) : error(bin, 0, 3);
	}
	while (ft_stn(bin->file[i]) || bin->file[i] == '\n'
		|| bin->file[i] == COMMENT_CHAR)
	{
		if (bin->file[i] == COMMENT_CHAR)
			comment(bin, &i);
		i++;
	}
	bin->i = i;
}
