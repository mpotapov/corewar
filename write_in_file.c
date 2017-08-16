#include "asm.h"

void	write_int(unsigned int i, int fd)
{
	int				n;
	unsigned char	tmp;

	n = -1;
	while (++n < 4)
	{
		tmp = (unsigned char)(i >> 24);
		write(fd, &tmp, 1);
		i = i << 8;
	}
}

void	write_big_code(t_asm *bin, t_tmp *tmp, int s)
{
	int len;

	len = -1;
	if (bin->op[tmp->n].size == 2 || tmp->arg[s] == T_IND)
	{
		tmp->val[s] = (unsigned short int)tmp->val[s];
		bin->code[bin->code_i++] = (unsigned char)(tmp->val[s] >> 8);
		tmp->val[s] = tmp->val[s] << 24;
		bin->code[bin->code_i++] = (unsigned char)(tmp->val[s] >> 24);
	}
	else
	{
		while (++len < 4)
		{
			bin->code[bin->code_i++] = (unsigned char)(tmp->val[s] >> 24);
			tmp->val[s] = tmp->val[s] << 8;
		}
	}
}

void	write_code(t_asm *bin, t_tmp *tmp)
{
	int s;

	s = -1;
	bin->code[bin->code_i++] = bin->op[tmp->n].hex;
	if (bin->op[tmp->n].cod)
		bin->code[bin->code_i++] = codage(tmp);
	while (++s < bin->op[tmp->n].argc)
	{
		if (tmp->arg[s] == T_REG)
			bin->code[bin->code_i++] = (unsigned char)tmp->val[s];
		else
			write_big_code(bin, tmp, s);
	}
	free_tmp(tmp);
}

void	write_file(t_asm *bin, int tmp)
{
	int fd;
	int i;
	int zero;

	zero = 0;
	if ((fd = open(bin->file_name, O_CREAT | O_WRONLY, 0666)) == -1)
	{
		ft_putstr("Can't create file.\n");
		exit(0);
	}
	write_int(COREWAR_EXEC_MAGIC, fd);
	write(fd, bin->head.prog_name, PROG_NAME_LENGTH + 1);
	i = -1;
	if ((tmp = 4 - (PROG_NAME_LENGTH + 1) % 4) != 4)
		while (++i < tmp)
			write(fd, &zero, 1);
	write_int(bin->code_i, fd);
	write(fd, bin->head.comment, COMMENT_LENGTH + 1);
	i = -1;
	if ((tmp = 4 - (PROG_NAME_LENGTH + 1) % 4) != 4)
		while (++i < tmp)
			write(fd, &zero, 1);
	write(fd, bin->code, bin->code_i);
	close(fd);
}
