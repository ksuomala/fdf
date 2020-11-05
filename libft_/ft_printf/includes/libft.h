/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuomala <ksuomala@student.hive.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 12:07:29 by ksuomala          #+#    #+#             */
/*   Updated: 2020/10/31 18:03:51 by ksuomala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H
# define BUFF_SIZE	10000
# define FD_SIZE	10

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include "ft_printf.h"

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_lstfree(t_list **ptr);

int					get_next_line(const int fd, char **line);
int					ft_sqrt(int nb);
void				ft_free2d(char **arr);

void				*ft_memset(void *s, int c, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memdup(void *src, size_t size);
void				ft_memdel(void **ap);

void				ft_putstr(const char *str);
void				ft_putnbr(int nb);
long long			ft_atoi(const char *str);
char				*ft_strdup(const char *str);
char				*ft_itoa(int n);
size_t				ft_strlen(const char *str);
void				ft_putchar(char c);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strncpy(char *dest, const char *src, size_t n);
void				ft_bzero(void *s, size_t n);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strncat(char *dest, const char *src, size_t n);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
void				ft_putcstr(char *str);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *haystack, const char *needle, \
size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_tolower(int c);
int					ft_toupper(int c);
void				ft_putendl(char const *s);
void				*ft_memalloc(size_t size);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char(*f)(unsigned int, char));
char				*ft_strsub(char const *s, unsigned intstart, size_t len);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strtrim(char const *s);
char				*ft_strjoin(char const *s1, char const*s2);
char				**ft_strsplit(char const *s, char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putendl_fd(char const *s, int fd);

char				*ft_strndup(const char *str, size_t n);
void				ft_n(int n);
void				ft_putnstr(const char *str, size_t n);
void				ft_putnchar(char c, size_t n);
char				*ft_itoa_base(long long nb, long base);
char				*ft_u_itoa_base(unsigned long long nb, int base);
char				*ft_itoa_float(long double nb, int presicion);
char				*ft_dtoa(long double dec, int presicion, int roundup);
char				*ft_toupper_str(char *s);
char				*ft_strfjoin(char *s1, char *s2);
void				ft_swap_ptr(void **dest, void **src);
void				*ft_replace_ptr(void *new, void *old);
int					ft_count_digits_s(char *s);
long double			ft_mod_double(long double x, long double y);

#endif
