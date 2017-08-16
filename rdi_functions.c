#include "asm.h"

void	reg_func(t_asm *bin, t_tmp *tmp, int s)
{
	if ((bin->op[tmp->n].argv[s] & T_REG) != T_REG)
		error(bin, tmp->n, 6);
	tmp->arg[s] = T_REG;
	if ((tmp->val[s] = (unsigned int)ft_atoi(bin->file + ++bin->i))
		> REG_NUMBER)
		error(bin, 0, 0);
	bin->i += len_digit(bin->file, bin->i);
	tmp->argc++;
}

void	dir_func2(t_asm *bin)
{
	bin->i -= 2;
	error(bin, 0, 0);
}

void	dir_func(t_asm *bin, t_tmp *tmp, int s)
{
	int i;

	if ((bin->op[tmp->n].argv[s] & T_DIR) != T_DIR)
		error(bin, tmp->n, 6);
	tmp->arg[s] = T_DIR;
	if (ft_isdigit(bin->file[++bin->i]) || bin->file[bin->i] == '-')
	{
		tmp->val[s] = (unsigned int)ft_atoi(bin->file + bin->i);
		bin->i += len_digit(bin->file, bin->i);
	}
	else if (bin->file[bin->i++] == LABEL_CHAR)
	{
		if ((i = search_label(bin->lebels, name_label(bin, 0))) != -1)
			tmp->val[s] = i - bin->code_i;
		else
		{
			bin->i -= bin->kostyl;
			bin->insert = create_insert(bin->insert,
						name_label(bin, 0), bin->code_i, s, tmp);
			tmp->val[s] = 0;
		}
	}
	else
		dir_func2(bin);
	tmp->argc++;
}

void	ind_func(t_asm *bin, t_tmp *tmp, int s)
{
	int i;

	if ((bin->op[tmp->n].argv[s] & T_IND) != T_IND)
		error(bin, tmp->n, 6);
	tmp->arg[s] = T_IND;
	if (ft_isdigit(bin->file[bin->i]))
	{
		tmp->val[s] = (unsigned int)ft_atoi(bin->file + bin->i);
		bin->i += len_digit(bin->file, bin->i);
	}
	else if (bin->file[bin->i++] == LABEL_CHAR)
	{
		if ((i = search_label(bin->lebels, name_label(bin, 0))) != -1)
			tmp->val[s] = i - bin->code_i;
		else
		{
			bin->i -= bin->kostyl;
			bin->insert = create_insert(bin->insert,
						name_label(bin, 0), bin->code_i, s, tmp);
			tmp->val[s] = 0;
		}
	}
	else
		error(bin, 0, 0);
	tmp->argc++;
}
