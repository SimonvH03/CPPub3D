MAKEFLAGS	=	-r -R

CXX			=	c++
CXXFLAGS	=	-std=c++20 -MMD -MP
CXXFLAGS	+=	-Wall -Werror -Wextra -Wshadow

NAME		=	CPPub3d

LIBMLXDIR	=	MLX42
LIBMLX		:=	$(LIBMLXDIR)/build/libmlx42.a
LIBMLXFLAGS	=	-ldl -lglfw -pthread -lm

INCLUDE_DIRS=	MLX42/include/MLX42 \
				$(SRC_DIR) \
				$(SRC_DIR)/$(CLASSES_DIR)
INCLUDE		=	$(addprefix -I , $(INCLUDE_DIRS))

CLASSES_DIR	=	classes
CLASSES		=	Camera.cpp \
				Cell.cpp \
				Engine.cpp \
				Error.cpp \
				Game.cpp \
				GameHUD.cpp \
				Grid.cpp \
				Hud.cpp \
				MenuHUD.cpp \
				Parser.cpp \
				Player.cpp \
				Renderer.cpp \
				Scene.cpp \
				Vec2.cpp \
				Window.cpp

SRC_DIR		=	src
SRC			:=	$(SRC_DIR)/main.cpp \
				$(addprefix $(SRC_DIR)/$(CLASSES_DIR)/, $(CLASSES))

OBJ_DIR		=	obj
OBJ			:=	$(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
DEP			:=	$(OBJ:.o=.d)

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -o $@ -c $<

$(NAME): $(OBJ) $(LIBMLX)
	$(CXX) $(CXXFLAGS) $(OBJ) $(LIBMLX) $(LIBMLXFLAGS) -o $(NAME)

$(LIBMLX):
	cmake $(LIBMLXDIR) -B $(LIBMLXDIR)/build && make -C $(LIBMLXDIR)/build -j4

-include $(DEP)

clean:
	@if [ -n "$(OBJ_DIR)" ] && [ "$(OBJ_DIR)" != "/" ] && [ -d "$(OBJ_DIR)" ]; then \
		rm -rf $(OBJ_DIR); \
	else \
		echo "Error: OBJ_DIR is undefined or invalid"; \
	fi

fclean: clean
	rm -f $(NAME)

re: clean all

fre: fclean all

.PHONY: all clean fclean re fre
