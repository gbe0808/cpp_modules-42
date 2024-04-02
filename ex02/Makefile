SRCS	= PmergeMe.cpp main.cpp Elem.cpp

OBJS	= ${SRCS:.cpp=.o}

CXXFLAGS	= -Wall -Wextra -Werror

NAME	= PmergeMe

all:	${NAME}

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}

re:		fclean all

${NAME}:	${OBJS}
		${CXX} ${CXXFLAGS} ${OBJS} -o $@

%.o : %.cpp
			${CXX} ${CXXFLAGS} -o $@ -c $<

.PHONY: all clean fclean re