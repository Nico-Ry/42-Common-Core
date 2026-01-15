#####################
#      SETUP        #
#####################

# Name of the final executable
NAME = bureaucrat

# Compiler to use
CC = c++
RM = rm -f

# Compiler flags:
# -Wall   : enable most warnings
# -Wextra : enable extra warnings
# -Werror : treat warnings as errors
# -std=c++98 : enforce C++98 standard (required by subject)
CFLAGS = -Wall -Wextra -Werror -std=c++98

#####################
#      COLORS       #
#####################

NOC = \033[0m
YELLOW = \033[1;33m
GREEN = \033[1;32m
RED = \033[1;31m

#####################
#      FILES        #
#####################

# Source files
SRCS	= main.cpp \
		  Bureaucrat.cpp \
		  AForm.cpp \
		  ShrubberyCreationForm.cpp \
		  RobotomyRequestForm.cpp \
		  PresidentialPardonForm.cpp \
		  Intern.cpp

#####################
#      RULES        #
#####################

# Compile .cpp files into .o files
%.o: %.cpp
	@${CC} ${CFLAGS} -c $< -o $@

# Object files generated from source files
OBJS	= $(SRCS:.cpp=.o)

all: ${NAME}

# Link object files into the final executable
${NAME}: ${OBJS}
	@${CC} ${CFLAGS} ${OBJS} -o ${NAME}
	@echo "$(GREEN)Exercise compiled ✓$(NOC)"

# Remove object files
clean:
	@${RM} ${OBJS}
	@echo "$(RED)Objects deleted ✓$(NOC)"

# Remove object files and the executable
fclean:
	@${RM} ${OBJS}
	@${RM} ${NAME}
	@echo "$(RED)Executable deleted ✓$(NOC)"

# Rebuild everything from scratch
re: fclean all

.PHONY: all clean fclean re
