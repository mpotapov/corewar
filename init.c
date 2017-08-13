#include "asm.h"

void	op_init(t_asm *bin)
{
	*bin = (t_asm){{
						{"live",	1, {T_DIR},													0, 1, 4},
						{"ld",		2, {T_DIR | T_IND, T_REG},									1, 2, 4},
						{"st",		2, {T_REG, T_IND | T_REG},									1, 3, 0},
						{"add",		3, {T_REG, T_REG, T_REG},									1, 4, 0},
						{"sub",		3, {T_REG, T_REG, T_REG},									1, 5, 0},
						{"and",		3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG},	1, 6, 4},
						{"or",		3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG},	1, 7, 4},
						{"xor",		3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG},	1, 8, 4},
						{"zjmp",	1, {T_DIR},													0, 9, 2},
						{"ldi",		3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG},			1, 10, 2},
						{"sti",		3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG},			1, 11, 2},
						{"fork",	1, {T_DIR},													0, 12, 2},
						{"lld",		2, {T_DIR | T_IND, T_REG},									1, 13, 4},
						{"lldi",	3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG},			1, 14, 2},
						{"lfork",	1, {T_DIR},													0, 15, 2},
						{"aff",		1, {T_REG},													1, 16, 0},
						{0, 0, 0, 0, 0, 0}
					}, bin->file, bin->i, bin->code, bin->code_i, .name = bin->name,
			.comm = bin->comm, .file_name = bin->file_name, .head = bin->head};
}

void	asm_init(t_asm *bin)
{
	op_init(bin);
	bin->name = 0;
	bin->comm = 0;
	bin->buff_size = BUFF_SIZE;
	bin->code = (unsigned char *)malloc(sizeof(unsigned char) * bin->buff_size);
	bin->code_i = 0;
	bin->lebels = NULL;
	bin->head.magic = COREWAR_EXEC_MAGIC;
//	bin->code_size = sizeof(bin->head.magic) + PROG_NAME_LENGTH + 1 + 4 - ((PROG_NAME_LENGTH + 1) % 4) + 4
//					 + COMMENT_LENGTH + 1 + 4 - ((COMMENT_LENGTH + 1) % 4);
//	bin->code = (unsigned char *)ft_strnew(bin->code_size);
//	write_magic(bin, COREWAR_EXEC_MAGIC);


}
