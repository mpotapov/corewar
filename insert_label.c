#include "asm.h"

t_insert	*create_insert(t_insert *first, char *label, int code_i, int arg, t_tmp *op)
{
	t_insert	*insert;
	int			i;

	insert = (t_insert *)malloc(sizeof(t_insert));
	insert->label = label;
	insert->code_i = code_i;
	insert->arg = arg;
	insert->op = create_tmp(op->n);
	insert->op->argc = op->argc;
	i = -1;
	while (++i < 3)
	{
		insert->op->arg[i] = op->arg[i];
		insert->op->val[i] = op->val[i];
	}
	insert->next = first;
	return (insert);
}

void		insert_code_2(t_asm *bin, t_insert *tmp, int tab, unsigned int val)
{
	int len;

	len = -1;
	if (bin->op[tmp->op->n].size == 2 || tmp->op->arg[tmp->arg] == T_IND)
	{
		val = (unsigned short int)val;
		bin->code[tmp->code_i++ + tab] = (unsigned char)(val >> 8);
		val = val << 24;
		bin->code[tmp->code_i + tab] = (unsigned char)(val >> 24);
	}
	else
	{
		while (++len < 4)
		{
			bin->code[tmp->code_i++ + tab] = (unsigned char)(val >> 24);
			val = val << 8;
		}
	}
}

void		insert_code_1(t_asm *bin, t_insert *tmp, int label_i)
{
	unsigned int	val;
	int				tab;
	int				n;

	val = (unsigned int)label_i - tmp->code_i;
	tab = 1;
	if (tmp->arg != 0)
		tab++;
	if (bin->op[bin->insert->op->n].cod == 1)
		tab++;
	n = -1;
	while (++n < tmp->arg)
	{
		if (tmp->op->arg[n] == T_REG)
			tab++;
		else if (tmp->op->arg[n] == T_IND || (tmp->op->arg[n] == T_DIR
								&& bin->op[tmp->op->n].size == 2))
			tab += 2;
		else if (tmp->op->arg[n] == T_DIR && bin->op[tmp->op->n].size == 4)
			tab += 4;
	}
	insert_code_2(bin, tmp, tab, val);
}

void		search_insert(t_asm *bin)
{
	t_insert	*tmp;
	int			i;

	i = 0;
	tmp = bin->insert;
	while (tmp != NULL)
	{
		if ((i = search_label(bin->lebels, tmp->label)) != -1)
		{
			insert_code_1(bin, tmp, i);
		}
		else
		{
			bin->ptr = tmp->label;
			error(bin, 0, 7);
		}
		tmp = tmp->next;
	}
}
