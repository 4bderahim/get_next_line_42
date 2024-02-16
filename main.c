#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct strc{
	char *word;
	struct strc *next;
} sp_list;

sp_list *new(char *content)
{
	sp_list *ne;

	ne = (sp_list *) malloc(sizeof(sp_list));
	if (!ne)
		return (NULL);
	ne->word = content;
	ne->next = NULL;
	return ne;
}

char *get_word(char *s, char *pre_word, char c)
{
	char *word;
	int i;
	int j;
	j = 0;
	i = 0;   
	if (pre_word)
		{
			free(pre_word);
		}
	while (s[i] != '\0' && s[i] != c)
		i++;
	word = (char *) malloc(i+1);
	if (!word)
		return NULL;
	word[i] = 0;
	while (j < i)
	{
		word[j] = s[j];
		j++;
	}
	return (word);
}
void addb(sp_list **lst, sp_list *new)
{
	sp_list *tmp;
	tmp = *lst;
	if (!tmp)
		{
			*lst = new;
			return ;
		}
	while (tmp->next !=NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = new;
}
sp_list *sp(char *s, char c)
{
	sp_list *splited;
	char *tmp_word;
	int i ;

	i = 0;
	splited = NULL;
	tmp_word = NULL;
	while (*s != 0)
	{
		
		if (*s == c || i == 0)
		{
			if (*(s+1) != c)
			{
				s += i;
				tmp_word = get_word(s, tmp_word, c);
				sp_list *neww;
				neww = new(tmp_word);
				tmp_word = NULL;
				addb(&splited, neww);
				i = 1;
			}
		}
		s++;
	}
	return splited;
}
int main()
{
	sp_list *p;
	p = sp("he llo wor       ld Non e !", ' ');
	printf("%zu", sizeof("ddd"));
	while (p != NULL)
	{
		printf("[%s]\n", p->word);
		p = p->next;
	}
}