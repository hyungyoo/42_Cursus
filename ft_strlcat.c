/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keulee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 14:04:42 by keulee            #+#    #+#             */
/*   Updated: 2019/12/16 17:29:35 by keulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
//
// Description
// The strlcpy() and strlcat() functions copy and concatenate strings
// with the same input parameters and output result as snprintf(3).
// They are designed to be safer, more consistent, and less error prone
// replacements for the easily misused functions strncpy(3) and strncat(3).
//
// strlcat() appends string src to the end of dst.
// It will append at most dstsize - strlen(dst) - 1 characters.
// It will then NUL-terminate, unless dstsize is 0 or the original
// dst string was longer than dstsize 
// (in practice this should not happen as it means that either dstsize
// is incorrect or that dst is not a proper string).
//
// If the src and dst strings overlap, the behavior is undefined.
//
// Return
// The strlcpy() and strlcat() functions return the total length of the string
// they tried to create.
// For strlcat() that means the initial length of dst plus the length of src. 
// If the return value is >= dstsize, the output string has been truncated.
// It is the caller's responsibility to handle this.
//
#include "libft.h"

size_t	ft_strlcat(char *restrict dest, const char *restrict src,
size_t size)
{
	unsigned int	i;
	unsigned int	dest_len;
	unsigned int	src_len;

	i = 0;
	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	if (size < dest_len)
		return (src_len + size);
	while (src[i] != '\0' && (dest_len + i) < size - 1)
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest_len + src_len);
}
