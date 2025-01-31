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
NAME			= minishell
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
SRCS_DIR			= srcs/
MAIN_FILES			= $(addprefix main/, main.c)
BUILTINS_FILES		= $(addprefix builtins/, builtin.c cd.c echo.c env.c exit_invalid.c exit.c export.c export2_utils.c pwd.c unset.c)
ENV_FILES			= $(addprefix env/, setup_env.c parse_env.c lst.c)
EXEC_FILES			= $(addprefix execution/, execute_cmd.c  execute_new_minish.c  execute_redir_cmd.c  external_exec.c  external_exec_utils.c  start_shell.c)
EXEC_HANDLER_FILES	= $(addprefix execution_handlers/, command_handler.c generate_temp_file.c handle_variable_assign.c heredoc_handler.c heredoc_handler_utils.c local_var_handler.c pipe_handler.c redirection_handler.c)
PARSING_FILES		= $(addprefix parsing/, create_ast.c new_nodes.c parse_utils.c redir_chain.c)
SIGNALS_FILES		= $(addprefix signals/, signals_utils.c signals.c)
SYNTAX_FILES		= $(addprefix syntax/, syntax.c syntax_error.c)
TOKEN_FILES			= $(addprefix tokens/, arg_lst.c expand_token.c fix_input_utils.c fix_input.c identify.c lexer.c process_tokens.c quotes.c valid.c)
UTILS_FILES			= $(addprefix utils/, cleanup.c execution_utils.c test_funcs.c free_ast.c free.c validate_utils.c)

SRC_FILES		= $(MAIN_FILES) $(BUILTINS_FILES) $(ENV_FILES) $(EXEC_FILES) $(EXEC_HANDLER_FILES) $(PARSING_FILES) $(SIGNALS_FILES) $(SYNTAX_FILES) $(TOKEN_FILES) $(UTILS_FILES)


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
	@$(MKDIR) $(OBJS_DIR)/main
	@$(MKDIR) $(OBJS_DIR)/builtins
	@$(MKDIR) $(OBJS_DIR)/env
	@$(MKDIR) $(OBJS_DIR)/execution
	@$(MKDIR) $(OBJS_DIR)/execution_handlers
	@$(MKDIR) $(OBJS_DIR)/parsing
	@$(MKDIR) $(OBJS_DIR)/signals
	@$(MKDIR) $(OBJS_DIR)/syntax
	@$(MKDIR) $(OBJS_DIR)/tokens
	@$(MKDIR) $(OBJS_DIR)/utils



$(NAME) : $(OBJS) Makefile
	@echo $(CYAN) " - Compiling $(NAME)..." $(RESET)
	@$(CC) $(CFLAGS) $(OBJS) $(LINKER) -lreadline -o $(NAME)
	@echo $(GREEN) " - "$(NAME)" Ready!" $(RESET)

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c $(INCLUDES)
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
