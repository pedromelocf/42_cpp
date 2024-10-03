NAME = megaphone

CPP_SRC_PATH = ./
CPP_OBJ_PATH = cpp_object
CPP_OBJ = $(addprefix $(CPP_OBJ_PATH)/, $(notdir $(CPP_SRCS:.cpp=.o)))
CPP_SRCS = megaphone.cpp

C++98 = c++ -std=c++98
FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(CPP_OBJ)
	@ $(C++98) $(FLAGS) $(CPP_OBJ) -o $(NAME)

$(CPP_OBJ_PATH)/%.o: $(CPP_SRC_PATH)/%.cpp
	@ mkdir -p $(CPP_OBJ_PATH)
	@ $(C++98) $(FLAGS) -c $< -o $@

clean :
	@ rm -rf $(CPP_OBJ_PATH)

fclean : clean
	@ rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re