NAME=s21_string.a

SRCS=s21_is_digit.c s21_memcpy.c s21_sprintf.c \
	s21_strcmp.c s21_strerror.c s21_strncat.c \
	s21_strpbrk.c s21_strstr.c s21_memchr.c \
	s21_memmove.c s21_strcat.c s21_strcpy.c \
	s21_strncmp.c s21_strrchr.c s21_strtok.c \
	s21_memcmp.c s21_memset.c s21_strchr.c \
	s21_strcspn.c \
	s21_strlen.c s21_strncpy.c s21_strspn.c

OBJECTS=s21_is_digit.o s21_memcpy.o s21_sprintf.o \
	s21_strcmp.o s21_strerror.o s21_strncat.o \
	s21_strpbrk.o s21_strstr.o s21_memchr.o \
	s21_memmove.o s21_strcat.o s21_strcpy.o \
	s21_strncmp.o s21_strrchr.o s21_strtok.o \
	s21_memcmp.o s21_memset.o s21_strchr.o s21_strcspn.o \
	s21_strlen.o s21_strncpy.o s21_strspn.o 

INCLUDES=./

all: $(NAME)

$(NAME): $(SRCS) s21_string.h
	@gcc -Wall -Wextra -Werror -I$(INCLUDES) -c $(SRCS)
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)

clean:
	@/bin/rm -f $(OBJECTS)

fclean: clean
	@/bin/rm -f $(NAME)

test:
	gcc test.c -lcheck $(NAME)

re: fclean all