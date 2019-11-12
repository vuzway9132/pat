/**
 * Knuth–Morris–Pratt algorithm:
 * Worst: Tw = O(n+m)
 * A string searching algorithm (or KMP algorithm) searches for occurrences 
 * of a "word" W within a main "text string" S
 */
#include <stdio.h>
#include <string.h> 
#include <stdlib.h>

typedef int Position;
#define NotFound -1

void BuildMatch(char *pattern, int *match);
Position KMP(char *string, char *pattern);	/* Tw = O(n+m) */

int main()
{
	char string[] = "This is a simple example.";
	char pattern[] = "simple";

	Position p = KMP(string, pattern);
	if (p == NotFound)
		printf("Not Found.\n");
	else
		printf("%s\n", string+p);

	return 0;  
}

void BuildMatch(char *pattern, int *match)
{
	Position i, j;
	int m = strlen(pattern);
	
	match[0] = -1;
	for (j = 1; j < m; j++) {
		i = match[j-1];
		while ((i >= 0) && (pattern[i+1] != pattern[j]))
			i = match[i];
		if (pattern[i+1] == pattern[j])
			match[j] = i+1;
		else
			match[j] = -1;
	}
}

Position KMP(char *string, char *pattern)
{
	int n = strlen(string); 	/* T = O(n) */
	int m = strlen(pattern); 	/* T = O(m) */
	Position s, p, *match;

	if (n < m)
		return NotFound;
	
	match = (Position *) malloc(sizeof(Position) * m);
	BuildMatch(pattern, match); 	/* T = O(m) */
	s = p = 0;
	while (s<n && p<m) 	/* T = O(n) */
		if (string[s] == pattern[p]) {
			s++;
			p++;
		} else if (p > 0)
			p = match[p-1]+1;
		else
			s++;
	free(match);
	return (p == m) ? (s-m) : NotFound;
}
