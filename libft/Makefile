# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smakni <smakni@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/10 10:28:08 by smakni            #+#    #+#              #
#    Updated: 2018/05/31 16:22:00 by smakni           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

CC		=	gcc

CFLAGS	+=	-Wall -Wextra -Werror

SRCS	=	ft_putchar.c ft_putstr.c ft_putnbr.c ft_strlen.c ft_strdup.c     \
			ft_strcmp.c ft_strncmp.c ft_strcpy.c ft_strncpy.c ft_strcat.c    \
			ft_strncat.c ft_memalloc.c ft_memset.c ft_bzero.c ft_memcpy.c    \
			ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_strchr.c    \
			ft_strrchr.c ft_isdigit.c ft_isascii.c ft_isalpha.c ft_isalnum.c \
			ft_strstr.c ft_strnstr.c ft_toupper.c ft_tolower.c ft_isprint.c  \
			ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c     \
			ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c  \
			ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_putendl.c \
			ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c    \
			ft_itoa.c ft_power.c ft_lstnew.c ft_lstdelone.c	ft_lstdel.c 	 \
			ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_lstmove_last.c 			 \
			ft_llast.c ft_strtoupper.c ft_atoi.c ft_strlcat.c			 	 \
			ft_strtolower.c ft_sqrt.c ft_factorial.c ft_print_bits.c		 \
			ft_strsub_free.c ft_strjoin_free.c

OBJS	=	$(SRCS:.c=.o)

HEAD	=	libft.h

LM		=	ar rc

RM		=	rm -f

all	:	 $(NAME)

$(NAME): $(OBJS)
		 $(LM) $(NAME) $(OBJS)

clean:
		 $(RM) $(OBJS)
			
fclean:  clean
		 $(RM) $(NAME)

re:		 fclean all
