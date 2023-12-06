#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h> 

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef MAX_FD
#  define MAX_FD 1024
# endif

int		ft_strlen(char *str);
int		has_break_line(const char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);
char	*read_line(int fd);
char	*dup_post_n(char *buffer);
char	*dup_pre_n(char *buffer);

#endif
