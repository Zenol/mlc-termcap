/*
** Made by Jérémy Cochoy
*/

#ifndef MLC_KEYCODE_H_
# define MLC_KEYCODE_H_

# define IS_MIN(c)	((c) >= 'a' && (c) <= 'z')
# define IS_MAJ(c)	((c) >= 'A' && (c) <= 'Z')
# define IS_NUM(c)	((c) >= '0' && (c) <= '9')
# define IS_ALNUM(c)	(IS_NUM(c) || IS_MAJ(c) || IS_MIN(c))

#endif /* !MLC_KEYCODE_H_ */
