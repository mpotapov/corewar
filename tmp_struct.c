#include "asm.h"

t_tmp	*create_tmp(int n)
{
	t_tmp	*tmp;
	int		i;

	if ((tmp = (t_tmp *)malloc(sizeof(t_tmp))) == NULL)
		return (NULL);
	tmp->n = n;
	tmp->argc = 0;
	tmp->arg = (unsigned char *)malloc(sizeof(unsigned char) * 3);
	tmp->val = (unsigned int *)malloc(sizeof(unsigned int) * 3);
	i = -1;
	while (++i < 3)
	{
		tmp->arg[i] = 0;
		tmp->val[i] = 0;
	}
	return (tmp);
}

void	free_tmp(t_tmp *tmp)
{
	if (tmp)
	{
		if (tmp->val)
			free(tmp->val);
		if (tmp->arg)
			free(tmp->arg);
		free(tmp);
	}
}

int		len_label(t_asm *bin, int flag)
{
	int len;

	len = 0;
	bin->kostyl = 0;
	while (label_chars(bin->file[bin->i]))
	{
		bin->i++;
		bin->kostyl++;
		len++;
	}
	if (flag == 1 && bin->file[bin->i] == LABEL_CHAR)
		bin->i++;
	else if (flag == 0)
		return (len);
	else
		error(bin, 0, 0);
	return (len);
}
