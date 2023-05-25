#ifndef SHELL_H
#define SHELL_H


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
char *_getenv(info_t *info, const char *name);
int _mysetenv(info_t *info);
int _mysetenv(info_t *info);
int populate_env_list(info_t *info);
int _myenv(info_t *info);

/* bultin.c prototype */
int _myexit(info_t *info);
int _mycd(info_t *info);
int _myhelp(info_t *info);

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
int bfree(void **ptr);

/* errors.c protoypes*/
void _eputs(char *str);
int _eputchar(char c);
int _putsfd(char *str, int fd);
int _putfd(char c, int fd);

/* error1.c prototypes */
int _erratoi(char *s);
void print_error(info_t *info, char *estr);
int print_d(int input, int fd);
char *convert_number(long int num, int base, int flags);
void remove_comments(char *buf);

/* string.c prototypes */
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *starts_with(constant char *haystack, constr char *needle);
char *_stract(char *dest, char *src);

/* getenv.c prototypes */
char **get_environ(info_t *info);
int _unsetenv(info_t *info, char *var);
int _setenv(info_t *info, char *var, char *value);

/* parser.c prototypes */
int is_chmd(info_t *info, char *path);
char *dup_chars(char *pathstr, int start, int stop);
char *find_path(info_t *info, char *pathstr, char *chmd);

/* getLne.c prototypes */
ssize_t input_buf(info_t *info, char **buf, size_t *len);
ssize_t get_input(info_t *info);
ssize_t read_buf(info *info, char *buf, size_t *i);
int _getline(info_t *info, char **ptr, size_t *length);
void sigintHandler(__atribute__((unused))int sig_num);



#endif
