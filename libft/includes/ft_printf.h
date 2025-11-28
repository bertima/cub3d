/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cowillem <cowillem@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 12:59:01 by cowillem          #+#    #+#             */
/*   Updated: 2025/11/04 12:59:01 by cowillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

size_t	ft_strlen_printf(const char *s);
int		ft_print_address(void *ptr);
int		ft_print_char(char c);
int		ft_print_hexa(int i, char c);
int		ft_print_int(int i);
int		ft_print_u_int(unsigned int i);
int		ft_print_string(char *str);
int		ft_printf(const char *s, ...);

#endif
