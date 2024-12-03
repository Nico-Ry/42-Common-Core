/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nryser <nryser@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 20:17:35 by nryser            #+#    #+#             */
/*   Updated: 2024/11/29 20:18:17 by nryser           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		word_count(const char *str, char c);
char	*fill_word(const char *str, int start, int end);
void	*ft_free(char **strs, int count);
void	ft_initiate_vars(size_t *i, int *j, int *s_word);

char	**ft_split(const char *s, char c)
{
	char	**res;
	size_t	i;
	int		j;
	int		s_word;

	ft_initiate_vars(&i, &j, &s_word);
	res = ft_calloc((word_count(s, c) + 1), sizeof(char *));
	if (!res)
		return (NULL);
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && s_word < 0)
			s_word = i;
		else if ((s[i] == c || i == ft_strlen(s)) && s_word >= 0)
		{
			res[j] = fill_word(s, s_word, i);
			if (!(res[j]))
				return (ft_free(res, j));
			s_word = -1;
			j++;
		}
		i++;
	}
	return (res);
}

void	ft_initiate_vars(size_t *i, int *j, int *s_word)
{
	*i = 0;
	*j = 0;
	*s_word = -1;
}

void	*ft_free(char **strs, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (NULL);
}

char	*fill_word(const char *str, int start, int end)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((end - start + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (start < end)
	{
		word[i] = str[start];
		i++;
		start++;
	}
	word[i] = 0;
	return (word);
}

int	word_count(const char *str, char c)
{
	int	count;
	int	x;

	count = 0;
	x = 0;
	while (*str)
	{
		if (*str != c && x == 0)
		{
			x = 1;
			count++;
		}
		else if (*str == c)
		x = 0;
		str++;
	}
	return (count);
}

/*The subject tells us that ft_split() must return an array of strings
 (=> an array of arrays, since strings are arrays of characters
 terminated by a NUL character).
We can also phrase that as an array of words, we take the string s
and we split it to get an array containing each words of it. Each word
is separated by one or more c, that's our word delimiter.
It's also said that our words array must be NUL-terminated.
 That means we have to allocate one more element in our array,
 that we can set to 0. By doing this we
 have an easy way to loop over our words array, the same as
  for a string: while(words[i] != 0).
The subject is not that hard to understand, the more complex
thing is to your code do all that.*/
