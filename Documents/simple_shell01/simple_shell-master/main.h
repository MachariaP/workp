#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <errno.h>

extern char **environ;

char *_get_env(const char *name);
int _putchar(char c);
int _strlen(const char *str);
void _print(const char *str);
void _print_error(const char *str);
char *_strcpy(char *dest, const char *src);
int _strcmp(const char *s1, const char *s2);
char *_strcat(char *dest, const char *src);
char *_strncpy(char *dest, const char *src, int n);
char **parse_input(char *input, int len);
int setup_arguments(char **args, char *input, char *delim);
void check_for_executable(char **args, char *str, char *path, int index);
char *get_path_from_environ(const char *path, const char *s);
char *find_executable(char *path, char *input);
int count_token(char *input);
char *custom_strdup(const char *str);
void catch_ctrlc(int);
void free_args(char **args);
void free_args_by_index(char **args, int count);
void __exit(char **args, char *tmp, char **tokens);
int execute(char *input, int length, char **tokens);
int execute_pipe_mode(int fd, char *);
void show_errors(int status, char *name, char *cmd, int mode);
int execute_normal_mode(char *);
int format_pipe(char *, char **);
int count_whitespace(char *str);
void error_1_output(char *name, char *cmd, char *text);
char *_strtok(char *src, char *delim);
unsigned int is_delim(char c, char *delim);

#endif /* MAIN_H */
