# Colors
RESET			= "\033[0m"
BLACK    		= "\033[30m"    # Black
RED      		= "\033[31m"    # Red
GREEN    		= "\033[32m"    # Green
YELLOW   		= "\033[33m"    # Yellow
BLUE     		= "\033[34m"    # Blue
MAGENTA  		= "\033[35m"    # Magenta
CYAN     		= "\033[36m"    # Cyan
WHITE    		= "\033[37m"    # White

# Compiler
NAME			= Philosophers
CC				= cc
CFLAGS			= -Wall -Wextra -Werror #-g3 -fsanitize=address
# - g3: Include debugging information
# - fsanitize=address: Enable address sanitization for debugging

# Get the operating system name
OS				= $(shell uname)
# Suppress output from make calls
MAKE			= make -sC
# Create directories if they don't exist
MKDIR			= mkdir -p
# Remove files or directories recursively
RM				= rm -rf

# Libft Files
LIBFT_DIR		= libft
LIBFT			= $(LIBFT_DIR)/libft.a
LINKER  	    = -lft -L $(LIBFT_DIR)

# Includes Files
INCLUDES_DIR 	= includes
INCLUDES_FLAG 	= -I$(INCLUDES_DIR) \
				  -I$(LIBFT_DIR) \

INCLUDES		= $(wildcard $(INCLUDES_DIR)/*.h) \
				  $(LIBFT_DIR)/libft.h \

# Sources
SRCS_DIR		= srcs/
MAIN_FILES		= $(addprefix ,main.c health_monitor.c philo_actions.c philo_states.c philo_threads.c simulation_init.c)
UTILS_FILES		= $(addprefix utils/, parse_args.c utils.c print_status.c  validate_args.c)

SRC_FILES		= $(MAIN_FILES) $(UTILS_FILES)


SRCS			= $(addprefix $(SRCS_DIR), $(SRC_FILES))



# Objects
OBJS_DIR		= objs/
OBJ_FILES		= $(SRC_FILES:.c=.o)
OBJS			= $(addprefix $(OBJS_DIR), $(OBJ_FILES))


# Default target to build everything
all : $(LIBFT) $(OBJS_DIR) $(NAME)

$(LIBFT) :
	@echo $(CYAN) " - Making Libft..." $(RESET)
	@$(MAKE) $(LIBFT_DIR)
	@echo $(GREEN) " - Libft Ready!" $(RESET)



$(OBJS_DIR) :
	@$(MKDIR) $(OBJS_DIR)
	@$(MKDIR) $(OBJS_DIR)/utils




$(NAME) : $(OBJS) Makefile
	@echo $(CYAN) " - Compiling $(NAME)..." $(RESET)
	@$(CC) $(CFLAGS) $(OBJS) $(LINKER)  -o $(NAME)
	@echo $(GREEN) " - "$(NAME)" Ready!" $(RESET)

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c $(INCLUDES)
	@$(MKDIR) $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES_FLAG) -c $< -o $@

#Clean Targets
#Removes Objects Files
clean :
	@$(RM) $(OBJS_DIR)
	@ make -C $(LIBFT_DIR) clean > /dev/null 2>&1
	@echo $(MAGENTA) " - Files & Directory Deleted " $(RESET)

#Removes Objects files, the executable, and cleans the libraries
fclean : clean
	@$(RM) $(NAME)
	@$(MAKE) $(LIBFT_DIR) fclean
	@echo $(GREEN) " - Fully Cleaned!" $(RESET)
#Performs a full clean and rebuilds everything.
re: fclean all

#Declares targets that are not actual files, ensuring they run regardless of file status.
.PHONY: all clean fclean re
