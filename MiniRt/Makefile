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

# Program names
NAME            = miniRT
BONUS_NAME      = miniRT_Bonus

# Compiler
CC              = cc
CFLAGS          = -Wall -Wextra -Werror #-g3 -fsanitize=address
# - g3: Include debugging information
# - fsanitize=address: Enable address sanitization for debugging

# Get the operating system name
OS              = $(shell uname)
# Suppress output from make calls
MAKE            = make -sC
# Create directories if they don't exist
MKDIR           = mkdir -p
# Remove files or directories recursively
RM              = rm -rf

# Libft Files
LIBFT_DIR       = libft
LIBFT           = $(LIBFT_DIR)/libft.a
LINKER          = -lft -L $(LIBFT_DIR)

# Includes Files
INCLUDES_DIR    = includes
INCLUDES_FLAG   = -I$(INCLUDES_DIR) \
                  -I$(LIBFT_DIR) \

INCLUDES        = $(wildcard $(INCLUDES_DIR)/*.h) \
                  $(LIBFT_DIR)/libft.h \

# Sources
SRCS_DIR            = srcs/
DEBUG_FILES         = $(addprefix debug/, print.c)
DRAW_FILES          = $(addprefix debug/draw_tests/, draw_circle.c draw_clock.c draw_projectile.c \
                                    draw_scene_pattern.c draw_silhouette.c draw_sphere_pattern.c \
                                    draw_sphere.c draw_sphere_uv.c draw_world_shadow.c draw_world.c \
                                    draw_sphere_nested.c draw_scene_nested.c draw_utils.c draw_planes.c \
                                    draw_cyl_infinite.c draw_cyl_truncated.c draw_cyl_capped.c draw_cone.c \
                                    draw_cone_scene.c draw_idea.c draw_simple_cone.c)
TEST_FILES          = $(addprefix debug/tests/, test_rays.c test_normal_at.c test_patterns.c test_transform.c \
                                    test_tuples.c test_phong.c test_world.c view_transform_test.c \
                                    test_ray_for_pixel.c test_shadows.c test_planes.c test_cylinders.c test_cone.c)
MAIN_FILES          = $(addprefix main/, main.c main_patterns.c main_shadows.c main_rays.c main_renders.c \
                                    main_phong.c main_transform.c main_tuples.c main_world.c \
                                    main_view.c main_plane.c main_cyl.c main_cone.c)
ENGINE_FILES        = $(addprefix make_engine/, clean_engine.c handle_hooks.c handle_mouse.c handle_bar.c key_hook.c make_engine.c)
MATRIX_FILES        = $(addprefix matrices/, determinant.c matrix_create.c matrix_invert.c matrix_utils.c )
PATTERNS_FILES      = $(addprefix patterns/, nested_patterns.c patterns.c patterns_at.c uv_patterns_at.c type_patterns.c type_uv_patterns.c uv_mapping.c)
PARSE_FILES         = $(addprefix parse/,build_list.c copy_input.c create_patterns.c load_shape.c load_unique.c objs_patterns.c parse_utils.c \
                        tokenize_lines.c valid_add_cone.c valid_add_plane.c build_scene.c entrypoint_parser.c parse_color.c \
                        parse_utils_vec.c valid_add_ambient.c valid_add_cylinder.c valid_add_sphere.c check_file.c \
                        free_parse_utils.c parse_tuple_utils.c split_lines.c valid_add_camera.c valid_add_light.c \
                        expected_identifiers.c valid_input.c is_float.c)
RAYS_FILES          = $(addprefix rays/, hits.c intersect.c ray_sphere.c \
                        intersect_pl.c intersect_cyl.c rays.c transform.c intersect_cone_caps.c intersect_cone.c)
REFLECTION_FILES    = $(addprefix reflection/, pre_compute.c normal_at.c ft_material.c ft_reflect.c ft_shading.c shade_hit.c)
SCENE_FILES         = $(addprefix scene/, world.c objects.c)
TRANSFORM_FILES     = $(addprefix transformations/, operations_matrix.c transformations.c rodrigues.c)
TUPLE_FILES         = $(addprefix tuple/, operations.c product.c \
                        tuples.c tuple_utils.c)
UTILS_FILES         = $(addprefix utils/, colours.c colours2.c free_objs.c free_utils.c free_world.c messages.c ft_utils.c)
VIEW_FILES          = $(addprefix view/, camera.c ray_for_pixel.c view_transform.c )

# Normal (mandatory) rendering
NORMAL_RENDER_FILES = render/normal_render.c

# Bonus (threaded) rendering
RENDER_THREADS_FILES = render/render_threads.c
THREADS_UTILS_FILES  = render/threads_utils.c
BONUS_RENDER_FILES   = render/bonus_render.c

SRC_FILES       =   $(MATRIX_FILES) $(PATTERNS_FILES) $(TUPLE_FILES) $(DEBUG_FILES) $(DRAW_FILES) $(TEST_FILES) \
                    $(MAIN_FILES) $(ENGINE_FILES) $(TRANSFORM_FILES) \
                    $(RAYS_FILES) $(SCENE_FILES) $(UTILS_FILES) \
                    $(REFLECTION_FILES) $(VIEW_FILES) $(PARSE_FILES) $(NORMAL_RENDER_FILES)

BONUS_SRC_FILES     = $(MATRIX_FILES) $(PATTERNS_FILES) $(TUPLE_FILES) $(DEBUG_FILES) \
                    $(DRAW_FILES) $(TEST_FILES) $(MAIN_FILES) $(ENGINE_FILES) \
                    $(TRANSFORM_FILES) $(RAYS_FILES) $(SCENE_FILES) $(UTILS_FILES) \
                    $(REFLECTION_FILES) $(VIEW_FILES) $(PARSE_FILES) \
                    $(RENDER_THREADS_FILES) $(THREADS_UTILS_FILES) \
                    $(BONUS_RENDER_FILES)

# Full paths
SRCS            = $(addprefix $(SRCS_DIR), $(SRC_FILES))
BONUS_SRCS      = $(addprefix $(SRCS_DIR), $(BONUS_SRC_FILES))

# Objects
OBJS_DIR        = objs/
OBJS_DIR_BONUS  = objs_bonus/
OBJ_FILES       = $(SRC_FILES:.c=.o)
OBJS            = $(addprefix $(OBJS_DIR), $(OBJ_FILES))
BONUS_OBJS      = $(addprefix $(OBJS_DIR_BONUS), $(BONUS_SRC_FILES:.c=.o))

# Platform-dependent compilation
ifeq ($(OS), Linux)
	MLX_DIR         = mlx_linux
	MLX             = $(MLX_DIR)/libmlx.a
	LINKER          += -lmlx -lm -lz -lXext -lX11 -L $(MLX_DIR)
	INCLUDES_FLAG   += -I$(MLX_DIR)
else
	MLX_DIR         = mlx_macos
	MLX             = $(MLX_DIR)/libmlx.a
	LINKER          += -lmlx -lm -framework OpenGl -framework Appkit -L $(MLX_DIR)
	INCLUDES_FLAG   += -I$(MLX_DIR)
endif

# Default target to build everything
all : CFLAGS += -DBONUS=0
all : $(LIBFT) $(MLX) $(OBJS_DIR) $(NAME)

$(LIBFT) :
	@echo $(CYAN)   " - ⏳ Making Libft...               ⏳" $(RESET)
	@$(MAKE) $(LIBFT_DIR)
	@echo $(GREEN)  " - ✅ Libft Ready!                "   $(RESET)

$(MLX) :
	@echo $(CYAN)   " - ⏳ Making mlx...                 ⏳" $(RESET)
	@$(MAKE) $(MLX_DIR) > /dev/null 2>&1;
	@echo $(GREEN)  " - ✅ Made mlx!                   "   $(RESET)

$(OBJS_DIR):
	@$(MKDIR) $(OBJS_DIR)
	@$(MKDIR) $(OBJS_DIR)/debug
	@$(MKDIR) $(OBJS_DIR)/debug/draw_tests
	@$(MKDIR) $(OBJS_DIR)/debug/tests
	@$(MKDIR) $(OBJS_DIR)/debug/scenes
	@$(MKDIR) $(OBJS_DIR)/main
	@$(MKDIR) $(OBJS_DIR)/make_engine
	@$(MKDIR) $(OBJS_DIR)/matrices
	@$(MKDIR) $(OBJS_DIR)/parse
	@$(MKDIR) $(OBJS_DIR)/patterns
	@$(MKDIR) $(OBJS_DIR)/rays
	@$(MKDIR) $(OBJS_DIR)/reflection
	@$(MKDIR) $(OBJS_DIR)/render
	@$(MKDIR) $(OBJS_DIR)/scene
	@$(MKDIR) $(OBJS_DIR)/transformations
	@$(MKDIR) $(OBJS_DIR)/tuple
	@$(MKDIR) $(OBJS_DIR)/utils
	@$(MKDIR) $(OBJS_DIR)/view


bonus_dirs:
	@if [ ! -d "$(OBJS_DIR_BONUS)" ]; then \
		echo $(CYAN) " - ⏳ Creating bonus directories... ⏳" $(RESET); \
		$(MKDIR) $(OBJS_DIR_BONUS); \
		$(MKDIR) $(OBJS_DIR_BONUS)/debug; \
		$(MKDIR) $(OBJS_DIR_BONUS)/debug/draw_tests; \
		$(MKDIR) $(OBJS_DIR_BONUS)/debug/tests; \
		$(MKDIR) $(OBJS_DIR_BONUS)/debug/scenes; \
		$(MKDIR) $(OBJS_DIR_BONUS)/main; \
		$(MKDIR) $(OBJS_DIR_BONUS)/make_engine; \
		$(MKDIR) $(OBJS_DIR_BONUS)/matrices; \
		$(MKDIR) $(OBJS_DIR_BONUS)/parse; \
		$(MKDIR) $(OBJS_DIR_BONUS)/patterns; \
		$(MKDIR) $(OBJS_DIR_BONUS)/rays; \
		$(MKDIR) $(OBJS_DIR_BONUS)/reflection; \
		$(MKDIR) $(OBJS_DIR_BONUS)/render; \
		$(MKDIR) $(OBJS_DIR_BONUS)/scene; \
		$(MKDIR) $(OBJS_DIR_BONUS)/transformations; \
		$(MKDIR) $(OBJS_DIR_BONUS)/tuple; \
		$(MKDIR) $(OBJS_DIR_BONUS)/utils; \
		$(MKDIR) $(OBJS_DIR_BONUS)/view; \
	else \
		echo "make: Nothing to be done for 'bonus'."; \
	fi

# bonus_dirs:
# 	@echo $(CYAN)   " - ⏳ Creating bonus directories... ⏳" $(RESET)
# 	@$(MKDIR) $(OBJS_DIR_BONUS)
# 	@$(MKDIR) $(OBJS_DIR_BONUS)/debug
# 	@$(MKDIR) $(OBJS_DIR_BONUS)/debug/draw_tests
# 	@$(MKDIR) $(OBJS_DIR_BONUS)/debug/tests
# 	@$(MKDIR) $(OBJS_DIR_BONUS)/debug/scenes
# 	@$(MKDIR) $(OBJS_DIR_BONUS)/main
# 	@$(MKDIR) $(OBJS_DIR_BONUS)/make_engine
# 	@$(MKDIR) $(OBJS_DIR_BONUS)/matrices
# 	@$(MKDIR) $(OBJS_DIR_BONUS)/parse
# 	@$(MKDIR) $(OBJS_DIR_BONUS)/patterns
# 	@$(MKDIR) $(OBJS_DIR_BONUS)/rays
# 	@$(MKDIR) $(OBJS_DIR_BONUS)/reflection
# 	@$(MKDIR) $(OBJS_DIR_BONUS)/render
# 	@$(MKDIR) $(OBJS_DIR_BONUS)/scene
# 	@$(MKDIR) $(OBJS_DIR_BONUS)/transformations
# 	@$(MKDIR) $(OBJS_DIR_BONUS)/tuple
# 	@$(MKDIR) $(OBJS_DIR_BONUS)/utils
# 	@$(MKDIR) $(OBJS_DIR_BONUS)/view

$(NAME) : $(OBJS) Makefile
	@echo $(CYAN)   " - ⏳ Compiling $(NAME)...           ⏳" $(RESET)
	@$(CC) $(CFLAGS) $(OBJS) $(LINKER) -lm -o $(NAME)
	@echo $(GREEN)  " - ✅ $(NAME) Ready!              "   $(RESET)

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c $(INCLUDES)
	@$(CC) $(CFLAGS) $(INCLUDES_FLAG) -c $< -o $@

# Bonus target
bonus : CFLAGS += -DBONUS=1
bonus : bonus_dirs $(LIBFT) $(MLX) $(BONUS_NAME)

$(BONUS_NAME) : $(BONUS_OBJS) Makefile
	@echo $(CYAN)   " - ⏳ Compiling $(BONUS_NAME)...     ⏳" $(RESET)
	@$(CC) $(CFLAGS) $(BONUS_OBJS) $(LINKER) -lm -o $(BONUS_NAME)
	@echo $(GREEN)  " - ✅ $(BONUS_NAME) Ready!        "   $(RESET)

$(OBJS_DIR_BONUS)%.o : $(SRCS_DIR)%.c $(INCLUDES)
	@$(CC) $(CFLAGS) $(INCLUDES_FLAG) -c $< -o $@

#Clean Targets
#Removes Objects Files
clean :
	@$(RM) $(OBJS_DIR) $(OBJS_DIR_BONUS)
	@ make -C $(LIBFT_DIR) clean > /dev/null 2>&1
	@echo $(MAGENTA)" - 🗑️  Files & Directory Deleted    ✅"   $(RESET)

#Removes Objects files, the executable, and cleans the libraries
fclean : clean
	@$(RM) $(NAME) $(BONUS_NAME)
	@$(MAKE) $(MLX_DIR) clean > /dev/null 2>&1;
	@$(MAKE) $(LIBFT_DIR) fclean
	@echo $(GREEN)  " - ✅ Fully Cleaned!              "   $(RESET)
#Performs a full clean and rebuilds everything.
re: fclean all

#Declares targets that are not actual files, ensuring they run regardless of file status.
.PHONY: all clean fclean re bonus bonus_dirs
