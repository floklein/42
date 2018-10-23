/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 18:04:46 by nthibaud          #+#    #+#             */
/*   Updated: 2016/02/18 18:05:45 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	add(int op1, int op2)
{
	int	result;

	result = (op1) + (op2);
	return (result);
}

int	sub(int op1, int op2)
{
	int	result;

	result = (op1) - (op2);
	return (result);
}

int	mul(int op1, int op2)
{
	int	result;

	result = (op1) * (op2);
	return (result);
}

int	div(int op1, int op2)
{
	int	result;

	result = (op1) / (op2);
	return (result);
}

int	mod(int op1, int op2)
{
	int	result;

	result = (op1) % (op2);
	return (result);
}
