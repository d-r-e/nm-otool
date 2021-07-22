#ifndef NM_H
# define NM_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>

# include <errno.h>
# include <sys/mman.h>
# include <mach-o/loader.h>

# define BINARY "nm"
# define NO_SUCH_FILE "No such file"
# define PERMISSION_DENIED "Permission denied."
# define STAT_ERROR "Stat read error"
# define FALSE 0
# define TRUE 1

/*
** libft
*/
size_t	ft_strlen(const char *s);
void	ft_putstr(const char *s);
void	ft_puts(const char *s);
void	ft_putnbr(int n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_bzero(void *s, size_t n);
char	*ft_strncpy(char *dest, const char *src, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *str1, const void *str2, size_t n);

/*
** output
*/
int	no_such_file(const char *s);
int permission_denied(const char *s);
int strerr(const char *s);

/*
** ft_nm
*/
int		is_elf(const char *memfile, struct stat *s);
int     is_mach(const char *memfile, struct stat *s);
int		analyse_elf(const char *s, const char *path);
struct mach_header_64     get_mach_header64(const char *memfile);
int     analyse_mach64(void);
typedef struct mach {
    int                     fd;
    struct mach_header_64   header;
    char                    *mem;
    struct stat             s;
} t_mach;

t_mach g_mach;

#endif
