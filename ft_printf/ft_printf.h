/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sromanet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 19:50:12 by sromanet          #+#    #+#             */
/*   Updated: 2017/02/10 20:17:27 by sromanet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <inttypes.h>
# include <stddef.h>

typedef	struct				s_arg
{
	int						n;
	int						ii;
	char					zero;
	char					plus;
	char					minus;
	char					space;
	char					hash;
	int						width;
	int						precision;
	char					length[3];
	char					flag;
	char					notvalid;
	char					*buf;
	void					*data;
	char					**global;
}							t_arg;

int							ft_printf(const char *format, ...);
void						ft_check_flag(t_arg *arg, const char *f, int i);
int							ft_atoi_str(const char *f, int i);
void						ft_check_width(t_arg *arg, const char *f,
												int i, va_list ap);
void						ft_check_precision(t_arg *arg, const char *f,
												int i, va_list ap);
void						ft_check_type(t_arg *arg, const char *f, int i,
												char **global);
void						ft_per_minus(t_arg *arg);
void						ft_per(t_arg *arg, int i);
void						ft_data_per(t_arg *arg);
void						ft_choice_function(t_arg *arg, va_list ap,
													char **global);
void						ft_putstr(char const *s);
t_arg						*ft_arg(const char *f, int i, va_list ap, int n);
void						ft_c_minus(t_arg *arg, char s);
void						ft_c(t_arg *arg, int i, char c, char s);
void						ft_data_c(t_arg *arg);
void						ft_hash(t_arg *arg);
void						ft_data_width(t_arg *arg);
void						ft_data_d(t_arg *arg, char **global_type);
void						ft_data_o(t_arg *arg, char **global_type);
void						ft_s_precision(t_arg *arg);
char						*ft_write_null(int i);
void						ft_data_s(t_arg *arg, char **global_type);
void						ft_data_u(t_arg *arg, char **global_type);
void						ft_data_p(t_arg *arg);
void						ft_wchar_t_precision(t_arg *arg);
void						ft_ls(t_arg *arg);
void						ft_data_wchar_t(t_arg *arg);
void						ft_data_x(t_arg *arg, char **global_type);
char						*ft_itoa_base_int(unsigned int value,
												int base, t_arg *arg);
char						*ft_itoa_base_hh(unsigned char value,
												int base, t_arg *arg);
char						*ft_itoa_base_h(unsigned short int value,
												int base, t_arg *arg);
char						*ft_itoa_base_l(long int value,
												int base, t_arg *arg);
char						*ft_itoa_base_ll(unsigned long long int value,
												int base, t_arg *arg);
char						*ft_itoa_base_j(uintmax_t value,
												int base, t_arg *arg);
char						*ft_itoa_base_z(size_t v, int base, t_arg *arg);
char						*ft_itoa_base_t(ptrdiff_t value,
												int base, t_arg *arg);
char						*ft_itoa_int(int value, t_arg *arg);
char						*ft_itoa_hh(signed char value, t_arg *arg);
char						*ft_itoa_h(short int value, t_arg *arg);
char						*ft_itoa_l(long int value, t_arg *arg);
char						*ft_itoa_ll(long long int value, t_arg *arg);
char						*ft_itoa_j(intmax_t value, t_arg *arg);
char						*ft_itoa_z(size_t v, t_arg *arg, int z);
char						*ft_itoa_t(ptrdiff_t value, t_arg *arg);
char						*ft_strcpy(char *dst, const char *src);
char						*ft_first_zero(char *s, int a, int b);
size_t						ft_strlen(const char *s);
void						ft_bzero(void *s, size_t n);
char						*ft_strnew(size_t size);
char						*new_ft_strjoin(char *s1, char *s2);
char						*ft_str_spase(size_t n);
void						ft_ls_minus(t_arg *arg);
void						ft_ls_width(t_arg *arg, int i);
char						*ft_signed(char *res, t_arg *arg, int minus);
char						*ft_precision(int zero, char *res, t_arg *arg);
char						*unicode_to_utf8(wchar_t c);
int							ft_nbr_len(const char *f, int i);
int							ft_strequ(char const *s1, char const *s2);
void						ft_data_minus(t_arg *arg, char c);
void						ft_data(t_arg *arg, char c);
t_arg						*ft_create_arg(int n);
char						**ft_global_type(void);
void						ft_free_arg(t_arg *arg, int n);
int							ft_isdigit(int c);
int							ft_printf_kostyl_kostyl(char *str);
int							ft_printf_kostyl(const char *f, int i, va_list ap,
												int n);
int							ft_type(char c);
int							tk(char c, char s);
int							ft_flag(char c);
int							ft_data_flag(char c);
int							ft_all(char c);
void						ft_check_data(t_arg *arg, const char *f, int i);
void						ft_check_type(t_arg *arg, const char *f, int i,
												char **global);
int							ft_size_length(char *tmp, char *length,
												char **global);
int							ft_kk(const char *f, int i, va_list ap,
												t_arg *arg);
void						ft_return_n(va_list ap, int n);
void						ft_putstr_zero(char const *s);

#endif
