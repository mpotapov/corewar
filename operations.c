#include "asm.h"

void	plus_operations(t_asm *bin, int *s)
{
	(*s)++;
	bin->i++;
}

void	operations(t_asm *bin, int n)
{
	int		s;
	t_tmp	*tmp;

	tmp = create_tmp(n);
	s = 0;
	while (bin->file[bin->i] != '\n' && bin->file[bin->i] != COMMENT_CHAR)
	{
		if (ft_stn(bin->file[bin->i]))
			while (ft_stn(bin->file[bin->i]))
				bin->i++;
		else if (bin->file[bin->i] == 'r')
			reg_func(bin, tmp, s);
		else if (bin->file[bin->i] == DIRECT_CHAR)
			dir_func(bin, tmp, s);
		else if ((bin->file[bin->i] == LABEL_CHAR
				|| ft_isdigit(bin->file[bin->i])))
			ind_func(bin, tmp, s);
		else if (bin->file[bin->i] == SEPARATOR_CHAR)
			plus_operations(bin, &s);
		else
			bin->file[bin->i] == '\0' ? error(bin, 0, 5) : error(bin, 0, 0);
	}
	tmp->argc == bin->op[n].argc ? 1 : error(bin, 0, 0);
	write_code(bin, tmp);
}

int		check_op(t_asm *bin)
{
	int		n;
	size_t	len;

	while (ft_stn(bin->file[bin->i]))
		bin->i++;
	n = -1;
	while (++n < OPERATIONS_NUM)
	{
		len = ft_strlen(bin->op[n].name);
		if (ft_strnequ(bin->op[n].name, bin->file + bin->i, len) &&
				(ft_stn(bin->file[bin->i + len])
				|| bin->file[bin->i + len] == DIRECT_CHAR))
		{
			bin->i += len;
			operations(bin, n);
			return (1);
		}
	}
	return (0);
}
