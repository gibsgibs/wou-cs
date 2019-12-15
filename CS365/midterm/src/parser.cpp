#include "parser.hpp"

#include <stdlib.h> // EXIT_FAILURE
#include <stdio.h>  // printf()
#include <string.h> // strlen()
#include <ctype.h>  // isspace(),
#include <string.h> // strtok_r()
#include <stdbool.h>

bool Parser::Empty(char *str)
{
  while (*str)
  {
    if (!isspace(*str++))
      return false;
  }
  return true;
}

char *Parser::LeftTrim(char *s)
{
  while (isspace((int)*s))
    ++s;
  return s;
}

char *Parser::RightTrim(char *str)
{
  if (*str == 0)
    return str;
  else
  {
    char *back = str + strlen(str) - 1;

    while (isspace(*back))
      back--;

    *(back + 1) = 0;

    return str;
  }
}

char *Parser::Trim(char *str)
{
  if (str != nullptr)
    return (LeftTrim(RightTrim(str)));
  else
    return nullptr;
}

void Parser::GetArgument(char *str, const char *delim, char *argv[])
{

  char *token;
  int i = 0;

  token = strtok(str, delim);

  while (token != nullptr)
  {
    argv[i] = token;
    token = strtok(NULL, delim);
    i++;
  }
  argv[i] = nullptr;
}

void Parser::PrintArgument(char *argv[])
{
  int i = 0;
  char *s;

  while ((s = argv[i]))
  {
    printf("  argv[%d] = %s\n", i, s);
    i++;
  }
}

void Parser::PrintArguments(char *argvs[MAX_COMMANDS][MAX_ARGV])
{
  int i = 0;
  while (argvs[i][0])
  {
    printf("Command %d\n", i);
    PrintArgument(argvs[i]);
    i++;
  }
}

void Parser::ParseCommands(char *str, const char *delim, char *cmds[])
{

  char *token;
  int i = 0;

  token = strtok(str, delim);

  while (token != NULL)
  {
    if (Empty(token))
    {
      fprintf(stderr, "Parser error: EMPTY command!\n");
      exit(EXIT_FAILURE);
    }

    cmds[i] = Trim(token);
    token = strtok(nullptr, delim);
    i++;
  }
  cmds[i] = nullptr;
}

int Parser::Parse(char *str, char *argvs[MAX_COMMANDS][MAX_ARGV])
{

  char *cmds[MAX_COMMANDS];

  ParseCommands(str, "|", cmds);

  int i = 0;

  while (cmds[i])
  {
    GetArgument(cmds[i], " ", argvs[i]);
    i++;
  }

  argvs[i][0] = nullptr;
  return i;
}