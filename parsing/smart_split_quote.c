#include "../../minishell.h"

#include <stdbool.h>
#include <string.h>

char*	ignore_quotes(char* str) {
	int len = strlen(str);
	char* result = malloc(len + 1);
	if (result == NULL) {
		return NULL;
	}

	int i = 0;
	int j = 0;
	bool single_quote_found = false;
	bool double_quote_found = false;

	while (str[i] != '\0') {
		if (str[i] == '\'') {
			if (double_quote_found) {
				result[j++] = str[i];
			} else {
				single_quote_found = !single_quote_found;
			}
		} else if (str[i] == '\"') {
			if (single_quote_found) {
				result[j++] = str[i];
			} else {
				double_quote_found = !double_quote_found;
			}
		} else {
			result[j++] = str[i];
		}
		i++;
	}

	result[j] = '\0';
	return result;
}


void	other_smart_split(t_toks **tok)
{
	t_toks	*tk;

	tk = *tok;
	while (tk)
	{
		sub_sub(tk->rdl, &tk);
		tk = tk->next;
	}
}
