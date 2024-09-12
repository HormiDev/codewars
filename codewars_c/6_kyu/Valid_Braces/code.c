#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct key
{
	char        content;
	struct key	*next;
}	t_key;

t_key *ft_last_key(t_key *key_list)
{
	t_key *key;

	key = key_list;
	while (key->next)
		key = key->next;
	return (key);
}

t_key *ft_delete_last_key(t_key *key_list)
{
	t_key *key;
	t_key *last_key;

	key = key_list;
	if (key->next == 0)
	{
		free(key);
		return (0);
	}
	while (key->next->next)
		key = key->next;
	last_key = key->next;
	free(last_key);
	key->next = 0;
	return (key_list);
}

t_key *ft_delete_key_list(t_key *key_list)
{
	t_key *key;
	t_key *next_key;

	key = key_list;
	while (key)
	{
		next_key = key->next;
		free(key);
		key = next_key;
	}
	return (0);
}

void ft_print_key_list(t_key *key_list)
{
	t_key *key;

	key = key_list;
	while (key)
	{
		printf("%c", key->content);
		key = key->next;
	}
	printf("\n");
}

t_key *ft_open_new_key(char key_char, t_key *key_list)
{
  t_key	*new;
  new = malloc(sizeof(t_key));
	if (new == 0)
		return (0);
  new->content = key_char;
	new->next = 0;
	if (key_list == 0)
		return (new);
	ft_last_key(key_list)->next = new;
	return (key_list);
}

bool valid_braces (const char *braces)
{
	int	i = 0;
	t_key	*keylist = 0;
	
	if (braces == 0)
		return false;
	while (braces[i])
	{
		if (braces[i] == '(' || braces[i] == '[' || braces[i] == '{')
		{
			keylist = ft_open_new_key(braces[i], keylist);
			if (keylist == 0)
			{
				keylist = ft_delete_key_list(keylist);
				return (false);
			}
		}
		else if (braces[i] == ')' || braces[i] == ']' || braces[i] == '}')
		{
			if (keylist == 0)
				return (false);
			if ((braces[i] == ')' && ft_last_key(keylist)->content == '(')
				|| (braces[i] == ']' && ft_last_key(keylist)->content == '[')
				|| (braces[i] == '}' && ft_last_key(keylist)->content == '{'))
				keylist = ft_delete_last_key(keylist);
			else
			{
				keylist = ft_delete_key_list(keylist);
				return (false);
			}
		}
		i++;
	}
	if (keylist != 0)
	{
		ft_delete_key_list(keylist);
		return (false);
	}
	return (true);
}

#include <stdio.h>
int main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (valid_braces(argv[1]))
			printf("%s is true\n", argv[1]);
		else
			printf("%s is false\n", argv[1]);
	}
	else
		printf("Se requiere un argumento\n");
	return (0);
}
