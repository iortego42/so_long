NAME= solong

CC  = gcc
AR = ar
ARFLAGS = -rc
RM = rm -rf 
OBJDIR = build
SRCDIR = src
INCDIR = include 


LDFLAGS = -L $(LFTPATH) -l$(LFTNAME)
# CFLAGS = -Wall -Wextra -Werror  -I $(INCDIR) -fsanitize=address
CFLAGS = -Wall -Wextra -Werror  -I $(INCDIR)
LFTPATH = libft
LFTNAME = ft
LFT = $(LFTPATH)/lib$(LFTNAME).a
CFLAGS += -I $(LFTPATH)/include

LDFLAGS += -L $(MLXPATH) -l$(MLXNAME)
MLXPATH = minilib
MLXNAME = mlx
MLX = $(MLXPATH)/lib$(MLXNAME).a
CFLAGS += -I $(MLXPATH) -framework OpenGL -framework AppKit


SRCS =	\
		so_long.c


OBJS := $(addprefix $(OBJDIR)/,$(SRCS:%.c=%.o))

all: $(NAME)

sanitize: CFLAGS += -fsanitize=address -g3 
sanitize: $(OBJS) $(LFTNAME)sanitize $(MLX)
	@echo "[$(NAME)]->>\033[34m [◊] SANITIZE MODE ON [◊]\033[0m"
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LDFLAGS) $(CFLAGS)

debug: CFLAGS += -g3
debug: $(OBJS) $(LFTNAME)debug $(MLX)
	@echo "[$(NAME)]->>\033[33m [∆] DEBUG MODE ON [∆]\033[0m"
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LDFLAGS)  

$(NAME): $(OBJS) $(LFT) $(MLX) 
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(LDFLAGS) 

$(LFTNAME)debug:
	make -C $(LFTPATH) debug

$(LFTNAME)sanitize:
	make -C $(LFTPATH) sanitize

$(LFT): 
	make -C $(LFTPATH)	

$(MLX):
	make -C $(MLXPATH)

$(OBJDIR): 
	mkdir $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	make fclean -C $(LFTPATH)
	make clean -C $(MLXPATH)
	$(RM) $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

red: fclean debug

res: fclean sanitize

.PHONY: sanitize debug res red re clean fclean all
