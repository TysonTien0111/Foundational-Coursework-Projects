/*
 * Program to translate English to Pig Latin.
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "translator_tools.h"

char *StringConcatAndFree(char *str, const char *suffix)
{
	char *new_str = StringConcat(str, suffix);
	free(str);
	return new_str;
}

bool Translate(char *str)
{
	char **words = SplitSentenceIntoWords(str);
	for (unsigned int i = 0; words[i] != NULL; i++) {
		if (!WordHasOnlyLetters(words[i]))
			return false;

		ToLowerCase(words[i]);

		if (!IsVowel(words[i][0])) {
			char *cluster = GetConsonantCluster(words[i]);
			words[i] = StripString(words[i], strlen(cluster));
			words[i] = StringConcatAndFree(words[i], cluster);
			free(cluster);
			words[i] = StringConcatAndFree(words[i], "ay");
		} else {
			words[i] = StringConcat(words[i], "ay");
		}

		printf("%s ", words[i]);
		free(words[i]);
	}

	printf("\n");
	free(words);

	return true;
}

int main(int argc, char *argv[])
{
	if(argc != 2) {
		printf("Usage: %s \"English string to translate\"\n", argv[0]);
		return 1;
	}

	if(!Translate(argv[1])) {
		printf("\nTranslation failed.\n");
		return 1;
	}

	return 0;
}
