#ifndef SHELL_H
#define SHELL_H
#define DELIM " \n\a\t"


#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>

/* Path Structure */
/**
 * struct path - path node struct
 * @dir: string containing directory
 * @next: pointer to next node.
 */
typedef struct path
{
	char *dir;
	struct path *next;
} path_t;

extern char **environ;

path_t *main_path;
path_t *env;

char *_strcpy(char *dest, char *src);
int _strlen(char *s);
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);
char *_itoa(int num);


char *read_line(void);
char **tokenize(char *buffer, char *delim);
int execute(char **args, char *program, int n);
void prompt(char *program);
void prompter(void);
void signal_handler (int sig);

int word_count(char *s);

char *_getenv(char *name);
path_t *make_path(void);
char *check_path(path_t *head, char *command);
char *path_concat(char *s1, char *s2);
path_t *_environ(void);

void free_path(path_t *head);

int check_builtin(char **args, char *line);
void hsh_exit(char **args, char *line);
void print_env(void);
int cd(char **command);
int check_command(char **args, char *program, int n);


void __error(char **args, char *program, int code, int n);
char clear_screen(void);
void signal_handler (int sig);
char *read_line(void);


int exit_builtin(char **args, char *line);
int env_builtin(char **args, char *line);
int setenv_builtin(char **args, char *line);
int unsetenv_builtin(char **args, char *line);
int cd_builtin(char **args, char *line);





#endif /* SHELL_H */
