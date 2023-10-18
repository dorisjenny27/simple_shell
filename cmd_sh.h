#ifndef CMD_SH_H
#define CMD_SH_H

/* standard library function here */
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <signal.h>
#include <sys/wait.h>
#include <stddef.h>

/* usr defined fnc here */
void split_command(const char *cmd_String, char *_pathName);
int comp_str(const char *str_1, const char *str_2);
void _env_p(char **const envp);
void proc_excve(const char *my_Cmd, char **const arg_vec, char *_pathName);
char *usrd_strtok(char *sh_str, const char *dlmt);
void writeToStdout(const char *content);
int _prompt(char *_print);
char *dup_str(const char *sh_str);
void execute_cmd(const char *my_Cmd, char **const arg_vec, char *_pathName);
/*later*/
char *c_getline(char *buff, size_t *n);
void ctrl_cmp(char *buff, char *check, char *argv[]);
size_t my_str_len(const char *str);
char *my_str_cpy(char *dest, const char *src);
size_t my_strspn(const char *str, const char *accept);
char *my_strchr(const char *str, int ch);

#endif /* CMD_SH_H */
