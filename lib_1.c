#include "asm.h"

char	*ft_new_strjoin(char *s1, char const *s2)
{
	char *fresh;
	char *ptr;
	char *tmp;

	tmp = NULL;
	fresh = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (fresh)
	{
		tmp = fresh;
		if (s1)
		{
			ptr = s1;
			while (*s1)
				*(fresh++) = *(s1++);
			ft_strdel(&ptr);
			s1 = NULL;
		}
		if (s2)
			while (*s2)
				*(fresh++) = *(s2++);
		*fresh = '\0';
	}
	return (tmp);
}

char	*file_name(char *name, size_t len)
{
	char	*tmp;
	int	 i;

	tmp = ft_strnew(len + 3);
	i = -1;
	while (++i < len - 1)
		tmp[i] = name[i];
	tmp[i] = 'c';
	tmp[++i] = 'o';
	tmp[++i] = 'r';
	return (tmp);
}

void	comment(t_asm *bin, int *i)
{
	while (bin->file[*i] != '\n')
		(*i)++;
	(*i)++;
}

int	 ft_stn(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

int	 label_chars(char c)
{
	if (ft_strchr(LABEL_CHARS, c) != NULL)
		return (1);
	return (0);
}
