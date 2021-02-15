#ifndef CHATBOT_H
#define CHATBOT_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

/* Config */
#define MAX_INPUT_SIZE 80
#define MAX_LINE_COUNT 100
#define MAX_WORD_SIZE 80

void generic_response();

void generic_quit();

void generic_welcome();

const char *make_answer(const char *token);
const char *handler();

void remember_line(const char *line);

const char *get_old_line();

bool is_remebered(const char *line);

const char *next_token();

void answer(char *input);


#endif