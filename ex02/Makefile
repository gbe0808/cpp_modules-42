SRCS	= main.cpp Base.cpp A.cpp B.cpp C.cpp

OBJS	= ${SRCS:.cpp=.o}

CXXFLAGS	= -Wall -Wextra -Werror

NAME	= serializer

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