/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabadan <drabadan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 12:40:30 by drabadan          #+#    #+#             */
/*   Updated: 2024/06/07 13:28:12 by drabadan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"
#include "stdio.h"

typedef struct	s_vector
{
	double	x;
	double	y;

}	t_vector; 

void change_2(t_vector *zhopa)
{
	 zhopa->x = 6.0;
	 zhopa->y = 12.0;	
}

void change_x_y(t_vector *zhopa)
	change_2(zhopa);

int	main(void)
{
	t_vector	ptr_v;

	ptr_v.x = 1.0;
	ptr_v.y = 2.0;
	change_x_y(&ptr_v);
	printf ("x = %.2f\ny = %.2f\n", ptr_v.x, ptr_v.y);
	return (0);
}
