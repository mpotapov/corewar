#include "asm.h"

int				len_digit(char *str, int i)
{
	int len;

	len = 0;
	if (str[i] == '-')
	{
		len++;
		i++;
	}
	while (ft_isdigit(str[i++]))
		len++;
	return (len);
}

unsigned char	codage(t_tmp *tmp)
{
	unsigned char	n;
	int				i;

	i = -1;
	n = 0;
	while (++i < 3)
	{
		if (tmp->arg[i] == T_IND)
			tmp->arg[i] = 3;
		n += tmp->arg[i];
		n = n << 2;
	}
	return (n);
}

void			code(t_asm *bin)
{
	while (bin->file[bin->i])
	{
		while (ft_stn(bin->file[bin->i]) || bin->file[bin->i] == '\n')
			bin->i++;
		if (bin->file[bin->i] == COMMENT_CHAR)
			comment(bin, &bin->i);
		if (bin->file[bin->i] == '\0')
			break ;
		if (check_label(bin))
		{
			continue ;
		}
		else
			error(bin, 0, 0);
	}
	if (bin->insert != NULL)
		search_insert(bin);
}

void			go(int fd, t_asm *bin, char *old_name)
{
	char	line[4096];
	ssize_t	n;

	bin->file = ft_strnew(0);
	while ((n = read(fd, line, 4096)))
	{
		line[n] = '\0';
		bin->file = ft_new_strjoin(bin->file, line);
	}
	close(fd);
	bin->file_name = file_name(old_name, ft_strlen(old_name));
	asm_init(bin);
	name_and_comment(bin);
	code(bin);
	if (!bin->code_i && bin->lebels == NULL)
		error(bin, 0, 0);
	write_file(bin, 0);
}

int				main(int c, char **v)
{
	int		fd;
	t_asm	bin[1];

	if (c > 1)
	{
		if ((fd = open(v[c - 1], O_RDONLY)) == -1)
			ft_printf("Can't read source file %s\n", v[c - 1]);
		else
		{
			go(fd, (t_asm *)&bin, v[1]);
			ft_printf("Writing output program to %s\n", bin->file_name);
		}
	}
	else
		ft_printf("Usage: ./tmp/asm [-a] <sourcefile.s>\n    -a : "
			"Instead of creating a .cor file, "
			"outputs a stripped and annotated version of "
			"the code to the standard output\n");
	return (0);
}
