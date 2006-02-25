/* $FreeBSD: src/gnu/usr.bin/patch/inp.h,v 1.7 2002/04/28 01:33:45 gad Exp $
 *
 * $Log: not supported by cvs2svn $
 * Revision 1.1.1.1  2005/12/24 02:43:05  laffer1
 * Imported from FreeBSD 6.0 sources
 *
 * Revision 2.0  86/09/17  15:37:25  lwall
 * Baseline for netwide release.
 *
 */

EXT LINENUM input_lines INIT(0);	/* how long is input file in lines */
EXT LINENUM last_frozen_line INIT(0);	/* how many input lines have been */
					/* irretractibly output */
void	 re_input(void);
void	 scan_input(char *_filename);
bool	 plan_a(char *_filename);
void	 plan_b(char *_filename);
bool	 rev_in_string(char *_string);
char	*ifetch(LINENUM _line, int _whichbuf);

