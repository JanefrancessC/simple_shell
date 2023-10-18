#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

/* for read/write buffers */
#define READ_BUFFER_SIZE 1024
#define BUFFER_SIZE_SET 1024
#define BUFFER_FLUSH -1

/* for command chaining */
#define COMMAND_NORM	0
#define COMMAND_OR		1
#define COMMAND_AND		2
#define COMMAND_CHAIN	3

/* for convert_number() */
#define CASE_LOWER	1
#define UNSIGNED_CONV	2

/* 1 if using system getline() */
#define USE_GETLINE 0
#define USE_STRTOK 0

#define HISTORY_FILE	".simple_shell_history"
#define HIST_MAX	4096

extern char **environ;


/**
 * struct liststr - singly linked list
 * @num: the number field
 * @str: a string
 * @next: points to the next node
 */
typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_t;

/**
 *struct passinfo - contains pseudo-arguements to pass into a function,
 *		allowing uniform prototype for function pointer struct
 *@arg: a string generated from getline containing arguements
 *@argv: an array of strings generated from arg
 *@path: a string path for the current command
 *@argc: the argument count
 *@line_count: the error count
 *@err_num: the error code for exit()s
 *@linecount_flag: if on count this line of input
 *@fname: the program filename
 *@env: linked list local copy of environ
 *@environ: custom modified copy of environ from LL env
 *@history: the history node
 *@alias: the alias node
 *@env_changed: on if environ was changed
 *@status: the return status of the last exec'd command
 *@cmd_buf: address of pointer to cmd_buf, on if chaining
 *@command_type: CMD_type ||, &&, ;
 *@readfd: the fd from which to read line input
 *@histcount: the history line number count
 */
typedef struct passinfo
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *fname;
	list_t *env;
	list_t *history;
	list_t *alias;
	char **environ;
	int env_changed;
	int status;

	char **cmd_buf; /* pointer to cmd ; chain buffer, for memory mangement */
	int command_type; /* CMD_type ||, &&, ; */
	int readfd;
	int histcount;
} info_t;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}

/**
 *struct builtin - contains a builtin string and related function
 *@type: the builtin command flag
 *@func: the function
 */
typedef struct builtin
{
	char *type;
	int (*func)(info_t *);
} builtin_table;


/* toem_shloop.c */
int hsh(info_t *, char **);
int find_builtin(info_t *);
void _find_cmd_(info_t *info);
void fork_cmd(info_t *info);

/* toem_parser.c */
int isExecutableCommand(info_t *info, char *path);
char *duplicateSubstring(char *sourceString, int startIndex, int stopIndex);
char *findCommandInPath(info_t *info, char *pathString, char *command);

/* loophsh.c */
int loophsh(char **);

/* toem_errors.c */
void _putstr(char *str);
int _put_char(char c);
int _putchar_fd(char c, int fd);
int _putstr_fd(char *str, int fd);

/* toem_string.c */
int _strlen(char *);
int _strcmp(char *, char *);
char *char_finder(const char *, const char *);
char *_strcat(char *, char *);

/* toem_string1.c */
char *custom_cpy_str(char *dset, char *src);
char *custom_dup_str(const char *str);
void custom_put_str(char *str);
int _putchar(char);

/* toem_exits.c */
char *custom_strncpy(char *dest, char *src, int n);
char *custom_strcat(char *dest, char *src, int n);
char *custom_strchr(char *s, char c);

/* toem_tokenizer.c */
char **tokenize_(char *str, char *d);
/* CHIOMA, PLEASE REVIEW char **strtow2(char *, char);*/

/* toem_realloc.c */
char *memory_set(char *s, char b, unsigned int n);
void _custom_free(char **strpp);
void *custom_re_alloc(void *, unsigned int, unsigned int);

/* toem_memory.c */
int buf_free(void **ptr);

/* toem_atoi.c */
int check_interactive(info_t *info);
/*int is_delimiter(char, char *);*/
int is_delimiter(char character, char *delimiters);
int _is_alpha(int c);
int customAtoi(char *str);

/* toem_errors1.c */
int custom_atoi(char *s);
void err_msg(info_t *, char *str);
int custom_printd(int numb10, int fd);
char *custom_itoa(long int n, int b, int f);
void del_commt(char *buffer);

/* toem_builtin.c */
int _custom_exit(info_t *info);
int _custom_change_directory(info_t *info);
int _custom_help(info_t *info);

/* toem_builtin1.c */
int display_history(info_t *info);
int remove_alias(info_t *info, char *str);
int create_alias(info_t *info, char *str);
int print_single_alias(list_t *node);
int alias_builtin(info_t *info);

/*toem_getline.c */
ssize_t getInput(info_t *info);
ssize_t readBuffer(info_t *info, char *buf, size_t *i);
ssize_t bufferInput(info_t *info, char **buffer_, size_t *len);
int get_next_line(info_t *info, char **ptr, size_t *length);
void ctrl_c_handler(int);

/* toem_getinfo.c */
void init_info(info_t *info);
void fill_info(info_t *, char **argv_);
void free_info(info_t *, int _vars_);

/* toem_environ.c */
char *custom_getenv(info_t *info, const char *);
int custom_env(info_t *info);
int custom_setenv(info_t *info);
int custom_unsetenv(info_t *info);
int custom_populate_env_list(info_t *info);

/* toem_getenv.c */
char **env_list(info_t *);
int remove_env(info_t *, char *);
int add_env(info_t *, char *vars_, char *value);

/* toem_history.c */
char *read_hist_all(info_t *info);
int writeHistory(info_t *info);
int hist_file_read(info_t *info);
int add_history_list(info_t *info, char *buf, int linecount);
int sort_hist(info_t *info);

/* toem_lists.c */
list_t *add_node(list_t **, const char *, int);
list_t *add_node_end(list_t **, const char *, int);
size_t print_list_str(const list_t *_head_);
int delete_index_node(list_t **head_ptr, unsigned int index);
void free_list(list_t **);

/* toem_lists1.c */
size_t linked_list_length(const list_t *_head);
char **list_to_strings(list_t *);
size_t print_list(const list_t *_head);
list_t *starts_with_node(list_t *, char *, char);
ssize_t get_node_index(list_t *, list_t *);

/* toem_vars.c */
int isCommandChainDelimiter(info_t *info, char *buf, size_t *p);
void checkCommandChain(info_t *info, char *buf, size_t *p, size_t i, size_t len);
int replaceAliases(info_t *info);
int variables_replace(info_t *info);
int switch_string(char **str1, char *str2);

#endif /* _SHELL_H_ */
