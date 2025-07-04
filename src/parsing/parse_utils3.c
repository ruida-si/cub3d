/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gribeiro <gribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 16:27:26 by gribeiro          #+#    #+#             */
/*   Updated: 2025/06/30 17:01:58 by gribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	channel_ext(char *file, int *i)
{
	int	num;

	num = 0;
	while (file[*i] && (file[*i] >= '0' && file[*i] <= '9'))
		num = num * 10 + (file[(*i)++] - '0');
	return (num);
}
