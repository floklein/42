#
#

NOM=libmlx.a
SRC= mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_xpm.c mlx_int_str_to_wordtab.c
OBJ1=$(SRC:.c=.o)
OBJ=$(OBJ1:.m=.o)
CFLAGS+=-O2

RED=\033[1;31m
GRE=\033[1;32m
LCY=\033[1;36m
LYE=\033[1;33m
NC=\033[0m

.SILENT: $(OBJ) $(OBJ1) all $(NOM) clean

all: $(NOM)

$(NOM):	$(OBJ)
	@ar -r $(NOM) $(OBJ) 2>/dev/null
	@ranlib $(NOM)
	@echo "${GRE}(✓) MiniLibX${NC}"

clean:
	@rm -f $(NOM) $(OBJ) *~
	@rm -f mlx_app

re: clean all
