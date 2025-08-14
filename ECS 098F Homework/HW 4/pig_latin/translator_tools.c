/*
 * Tools for the Pig Latin translator.
 * For details on translation rules, see ASSIGNMENT.md
 */
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "translator_tools.h"

// Splits an input sentence into a null-terminated array of words.
// For example "the fox jumps" would become ["the", "fox", "jumps", NULL].
char **SplitSentenceIntoWords(const char *sentence)
{
	char **words = malloc(sizeof(char*) * strlen(sentence));
	unsigned int words_index = 0;

	// Remove any leading spaces
	while (*sentence == ' ')
		sentence++;

	// Because the input may be a string literal, and strtok will modify the
	// input: the sentence must be copied into managed memory.
	char *sentence_copy = strdup(sentence);
	char *token = strtok(sentence_copy, " ");
	while(token != NULL) {
		words[words_index] = token;
		words_index++;
		token = strtok(NULL, " ");
	}

	words[words_index] = NULL;
	words = realloc(words, sizeof(char*) * (words_index + 1));

	return words;
}

// Returns true if the input string contains only letters.
bool WordHasOnlyLetters(const char *word)
{
	while (*word != '\0') {
		if (!isalpha(*word))
			return false;
		word++;
	}
	return true;
}

// Converts 'word' to a lower case word. For example "sIlLy" will become
// "silly". This function expects the input string to only contain letters.
// This function modifies the input.
void ToLowerCase(char *word)
{
	while (*word != '\0') {
		*word = tolower(*word);
		word++;
	}
}

// Returns true if the provided lower case char is a vowel, false otherwise.
bool IsVowel(char c)
{
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

// Returns a string containing the leading consonants of 'word'.
// For example an input of "string"  will return "str".
// This function expects the string to contain only lowercase letters.
char *GetConsonantCluster(const char *word)
{
	unsigned int size = strlen(word);

	if(size == 0)
		return NULL;
  
	char *cluster = malloc(size + 1);
	unsigned int index = 0;
	while (word[index] != '\0' && !IsVowel(word[index])) {
		cluster[index] = word[index];
		index++;
	}
	cluster[index] = '\0';
	cluster = realloc(cluster, index + 1);

	return cluster;
}

// Returns a new string that has num_chars stripped from the start of a string.
// StripString("foobarbaz", 3) == "barbaz"
char *StripString(const char *str, int num_chars)
{
	unsigned int length = strlen(str);
	char *result = malloc(length - num_chars + 1);
	strcpy(result, str + num_chars);

	return result;
}

// Creates a new string that appends a suffix to the provided string.
char *StringConcat(const char *str, const char *suffix)
{
	char *new_str = malloc(strlen(str) + strlen(suffix) + 1);
	strcpy(new_str, str);
	strcat(new_str, suffix);

	return new_str;
}
