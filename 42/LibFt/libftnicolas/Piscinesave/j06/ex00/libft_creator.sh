#!/bin/sh
gcc -c ft_*
ar rc libft.a *.o
rm *.o
