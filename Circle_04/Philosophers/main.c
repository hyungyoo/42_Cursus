/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 15:42:05 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/08/18 16:51:06 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(void)
{
        struct timeval	now;
		long	now_int;
        
		gettimeofday(&now, NULL);
		now_int = (now.tv_sec * 1000) + (now.tv_usec / 1000);
		printf("%ld\n", now_int);
		
		gettimeofday(&now, NULL);
		now_int = (now.tv_sec * 1000) + (now.tv_usec / 1000);
		printf("%ld\n", now_int);
		
		gettimeofday(&now, NULL);
		now_int = (now.tv_sec * 1000) + (now.tv_usec / 1000);
		printf("%ld\n", now_int);
		
		gettimeofday(&now, NULL);
		now_int = (now.tv_sec * 1000) + (now.tv_usec / 1000);
		printf("%ld\n", now_int);
		
		return 0;
}
