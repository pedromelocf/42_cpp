NAME = fixedpointer1

CPP_SRC_PATH = ./src/
CPP_OBJ_PATH = ./src/cpp_object

CPP_INCLUDES = $(wildcard ./src/*.hpp)

CPP_OBJ = $(addprefix $(CPP_OBJ_PATH)/, $(notdir $(CPP_SRCS:.cpp=.o)))
CPP_SRCS = $(wildcard ./src/*.cpp)

C++98 = c++ -std=c++98
FLAGS = -Wall -Werror -Wextra -Wunreachable-code -Ofast
VALGRIND = valgrind

all: $(NAME)

$(NAME): $(CPP_OBJ)
	@ $(C++98) $(FLAGS) $(CPP_OBJ) -o $(NAME)

$(CPP_OBJ_PATH)/%.o: $(CPP_SRC_PATH)/%.cpp
	@ mkdir -p $(CPP_OBJ_PATH)
	@ $(C++98) $(FLAGS) -c $< -o $@

$(CPP_OBJ_PATH): $(CPP_INCLUDES)

clean :
	@ rm -rf $(CPP_OBJ_PATH)

fclean : clean
	@ rm -f $(NAME)

re : fclean all

val : all
	@ $(VALGRIND) ./$(NAME)

.PHONY: all clean fclean re val