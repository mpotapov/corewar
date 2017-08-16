#include "asm.h"

char	*name_label(t_asm *bin, int flag)
{
	int		len;
	char	*str;
	int		n;

	len = len_label(bin, flag);
	str = ft_strnew((size_t)len);
	n = -1;
	while (len != 0)
		str[++n] = bin->file[bin->i - len-- - flag];
	return (str);
}

t_label	*create_label(t_label *first, char *name, int i, int code_i)
{
	t_label *tmp;

	tmp = (t_label *)malloc(sizeof(t_label));
	tmp->name = name;
	tmp->i = i;
	tmp->code_i = code_i;
	tmp->next = first;
	return (tmp);
}

int		search_label(t_label *l, char *name)
{
	while (l != NULL)
	{
		if (ft_strequ(l->name, name))
		{
			ft_strdel(&name);
			return (l->code_i);
		}
		l = l->next;
	}
	ft_strdel(&name);
	return (-1);
}

int		labels(t_asm *bin)
{
	bin->lebels = create_label(bin->lebels,
						name_label(bin, 1), bin->i, bin->code_i);
	if (check_op(bin))
		return (1);
	else if (bin->file[bin->i] == COMMENT_CHAR)
	{
		comment(bin, &bin->i);
		if (bin->file[bin->i] == '\0' && bin->file[bin->i - 1] != '\n')
			error(bin, 0, 0);
		return (1);
	}
	else if (bin->file[bin->i] == '\n')
		return (1);
	else
		error(bin, 0, 0);
	return (0);
}

int		check_label(t_asm *bin)
{
	if (check_op(bin))
		return (1);
	if (label_chars(bin->file[bin->i]))
		return (labels(bin));
	return (0);
}
