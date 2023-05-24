#define SHELL_H
#ifndef SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

int main(void);
int main(int ac, char **av);

/*command chaining*/
#define CMD_CHAIN 3
#define CMD_AND		2
#define CMD_OR		1
#define CMD_NORM 0

/*SYSTEM GETLINE()*/
#define CONVERT_LOWERCASE 1
#define CONVERT_UNSIGNED 2

/* environ.c prototypes */
char * _getenv(info_t *info, const char *name);
int _mysetenv(info_t *info);
int _mysetenv(info_t *info);
int populate_env_list(info_t *info);
int _myenv(info_t *info);

/* bultin.c prototype */
int _myexit(info_t *info);
int _mycd(info_t *info);
int _myhelp(info_t *info)

/* getinfo.c prototypes */
void free_info(info_t *info, int all);
void clear_info(info_t *info);
void set_info(info_t *info, char **av);

/* builtin1.c prototypes */
int _myhistory(info_t *info);
int unset_alias(info_t *info, char *str);
int set_alias(info_t *info, char *str);
int print_alias(list_t *node);
int _myalias(info *info);

/* _atoic.c prototypes */
int interactive(info_t *info);
int _atoc(char *s);
int is_delim(char c, char *delim);
int _isalpha(int c);

/* history.c prototypes */
char *get_history_file(info_t *info);
int write_history(info_t *info);
int read_history(info_t *info);
int build_history_list(info_t *info, char *buf, int linecount);

/* lists.c prototypes */
list_t *add_node(list_t **head, const char *str, int num);
int renumber_history(info_t *info);
list_t *add_node_end(list_t **head, const char *str, int num);
size_t print_list_str(const list_t *h);
int delete_node_at_index(list_t **head, unsigned int index);
void free_list(list_t **head_ptr);

/* main.c prototypes */
int main(int ac, char **av);
populate_env_list(info);
read_history(info);
hsh(info av);

/* memory.c prototypes */
int bfree(void **ptr)

/* errors.c protoypes*/
void _eputs(char *str);
int _eputchar(char c);
int _putsfd(char *str, int fd);
int _putfd(char c, int fd);

/* error1.c prototypes */

/* string.c prototypes */

/* getenv.c prototypes */

/* parser.c prototypes */

/* getLne.c prototypes */



#endif
