/*
 * Pig latin translator header.
 */
#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include <stdbool.h>

char **SplitSentenceIntoWords(const char *sentence);
bool WordHasOnlyLetters(const char *word);
void ToLowerCase(char *word);
bool IsVowel(char c);
char *GetConsonantCluster(const char *word);
char *StripString(const char *str, int num_chars);
char *StringConcat(const char *str, const char *suffix);

#endif  // TRANSLATOR_H
