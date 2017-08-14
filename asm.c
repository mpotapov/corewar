#include "asm.h"
#include <stdio.h>

void	error(t_asm *bin, int r, int error)
{
    int k;
    int n;
    int a;

    n = 0;
    k = 1;
    a = bin->i;
	if (k == 1)
		printf("lol");
    if (error == 1)
        ft_printf("Syntax error in Name");
    else if(error == 2)
        ft_printf("Syntax error in Comment");
    else if(error == 3)
        ft_printf("No Name\n");
    else if(error == 4)
        ft_printf("No Comment\n");
    else if(error == 5)
        ft_printf("Syntax error - unexpected end of input (Perhaps you forgot to end with a newline ?)\n");
    else if(error == 6)
        ft_printf("Invalid parametr for instruction '%s'\n", bin->op[r].name);
    while (a > -1)
        if (bin->file[a--] == '\n')
            k++;
    while (bin->file[bin->i--] != '\n')
        n++;
    if (error != 3 && error != 4 && error != 5 && error != 6)
        printf("Syntax error at token [%d, %d]\n", k, n);
    exit(0);
}

int     len_label(t_asm *bin, int flag)
{
    int len;

    len = 0;
    while (label_chars(bin->file[bin->i]))
    {
        bin->i++;
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

char    *name_label(t_asm *bin, int flag)
{
    int len;
    char *str;
    int n;

    len = len_label(bin, flag);
    str = ft_strnew((size_t)len);
    n = -1;
    while (len != 0)
        str[++n] = bin->file[bin->i - len-- - flag];
    return (str);
}

t_label *create_label(t_label *first, char *name, int i, int code_i)
{
    t_label *tmp;

    tmp = (t_label *)malloc(sizeof(t_label));
    tmp->name = ft_strdup(name);
    tmp->i = i;
    tmp->code_i = code_i;
    tmp->next = first;
    return (tmp);
}

int search_label(t_label *l, char *name)
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

int     len_digit(char *str, int i)
{
    int len;

    len = 0;
    while (ft_isdigit(str[i++]))
        len++;
    return (len);
}

void    reg_func(t_asm *bin, t_tmp *tmp, int s)
{
    if ((bin->op[tmp->n].argv[s] & T_REG) != T_REG)
        error(bin, tmp->n, 6);
    tmp->arg[s] = T_REG;
    if ((tmp->val[s] = (unsigned int)ft_atoi(bin->file + ++bin->i)) > REG_NUMBER)
        error(bin, 0, 0);
    bin->i += len_digit(bin->file, bin->i);
    tmp->argc++;
}

void    dir_func(t_asm *bin, t_tmp *tmp, int s)
{
    int i;

    i = 0;
    if ((bin->op[tmp->n].argv[s] & T_DIR) != T_DIR)
        error(bin, tmp->n, 6);
    tmp->arg[s] = T_DIR;
    if (ft_isdigit(bin->file[++bin->i]))
    {
        tmp->val[s] = (unsigned int)ft_atoi(bin->file + bin->i);
        bin->i += len_digit(bin->file, bin->i);
    }
    else if (bin->file[bin->i++] == LABEL_CHAR)
    {
        if ((i = search_label(bin->lebels, name_label(bin, 0))) != -1)
            tmp->val[s] = i - bin->code_i;
        else
            ;
    }
    else
    {
        bin->i -= 2;
        error(bin, 0, 0);
    }
    tmp->argc++;
}

void    ind_func(t_asm *bin, t_tmp *tmp, int s)
{
    int i;

    i = 0;
    if ((bin->op[tmp->n].argv[s] & T_IND) != T_IND)
        error(bin, tmp->n, 6);
    tmp->arg[s] = T_IND;
    if (ft_isdigit(bin->file[++bin->i]))
        tmp->val[s] = (unsigned int)ft_atoi(bin->file + bin->i);
    else if (bin->file[bin->i++] == LABEL_CHAR)
    {
        if ((i = search_label(bin->lebels, name_label(bin, 0))) != -1)
            tmp->val[s] = i - bin->code_i;
        else
            ;
    }
    else
        error(bin, 0, 0);
    tmp->argc++;
}


void    write_big_code(t_asm *bin, t_tmp *tmp, int s)
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

unsigned char codage(t_tmp *tmp)
{
    unsigned char n;
    int i;

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

void    write_code(t_asm *bin, t_tmp *tmp)
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
}

void    operations(t_asm *bin, int n)
{
    int s;
    t_tmp tmp[1];

    tmp->n = n;
    tmp->argc = 0;
    s = 0;
    while (bin->file[bin->i] != '\n' && bin->file[bin->i] != COMMENT_CHAR)
    {
        if (ft_stn(bin->file[bin->i]))
            while (ft_stn(bin->file[bin->i]))
                bin->i++;
        else if (bin->file[bin->i] == 'r')
            reg_func(bin, (t_tmp *)&tmp, s);
        else if (bin->file[bin->i] == DIRECT_CHAR)
            dir_func(bin, (t_tmp *)&tmp, s);
        else if ((bin->file[bin->i] == LABEL_CHAR || ft_isdigit(bin->file[bin->i])))
            ind_func(bin, (t_tmp *)&tmp, s);
        else if (bin->file[bin->i] == SEPARATOR_CHAR)
        {
            s++;
            bin->i++;
        }
        else
            bin->file[bin->i] == '\0' ? error(bin, 0, 5) : error(bin, 0, 0);
    }
    tmp->argc == bin->op[n].argc ? 1 : error(bin, 0, 0);
    write_code(bin, (t_tmp *)&tmp);
}

int     check_op(t_asm *bin)
{
    int n;
    size_t len;
    char *s;

    s = bin->file + bin->i;
    while (ft_stn(bin->file[bin->i]))
        bin->i++;
    n = -1;
    while (++n < OPERATIONS_NUM)
    {
        len = ft_strlen(bin->op[n].name);
        if (ft_strnequ(bin->op[n].name, bin->file + bin->i, len) && (ft_stn(bin->file[bin->i + len]) || bin->file[bin->i + len] == DIRECT_CHAR))
        {
            bin->i += len;
            operations(bin, n);
            return (1);
        }
    }
    return (0);
}

int    labels(t_asm *bin)
{
    bin->lebels = create_label(bin->lebels, name_label(bin, 1), bin->i, bin->code_i);

    if (check_op(bin))
        return (1);
    else if (bin->file[bin->i] == COMMENT_CHAR)
        comment(bin, &bin->i);
    else
        error(bin, 0, 0);
    return (0);
}

int    check_label(t_asm *bin)
{
    if (check_op(bin))
        return (1);
    if (label_chars(bin->file[bin->i]))
        return (labels(bin));
    return (0);
}

void	code(t_asm *bin)
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
}

void	go(int fd, t_asm *bin, char *old_name)
{
	char line[4096];
    ssize_t n;

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



    printf("%s\n<==============>\n", bin->file);
//test how to work
    for (int i = 0; i < bin->code_i; ++i) {
        if (i % 16 == 0)
            printf("\n");
        if (i % 2 == 0 && i % 16 != 0)
            printf(" ");
        printf("%02x", bin->code[i]);
    }
}


int main(int c, char **v)
{

    int fd;
	t_asm bin[1];

	if ((fd = open(v[1], O_RDONLY)) == -1)
	{
		ft_putstr("Can't open file.\n");
	}
	else
		go(fd, (t_asm *)&bin, v[1]);
	return 0;
}
