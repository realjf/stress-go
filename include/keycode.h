// #############################################################################
// # File: keycode.h                                                           #
// # Project: include                                                          #
// # Created Date: 2024/11/27 17:35:50                                         #
// # Author: realjf                                                            #
// # -----                                                                     #
// # Last Modified: 2024/11/29 11:17:03                                        #
// # Modified By: realjf                                                       #
// # -----                                                                     #
// #                                                                           #
// #############################################################################

#ifndef __KEYCODE_H__
#define __KEYCODE_H__

#include <curses.h>

#define KEY_CODE_DOWN KEY_DOWN           /* down-arrow key */
#define KEY_CODE_UP KEY_UP               /* up-arrow key */
#define KEY_CODE_LEFT KEY_LEFT           /* left-arrow key */
#define KEY_CODE_RIGHT KEY_RIGHT         /* right-arrow key */
#define KEY_CODE_HOME KEY_HOME           /* home key */
#define KEY_CODE_BACKSPACE KEY_BACKSPACE /* backspace key */
#define KEY_CODE_F0 KEY_F0               /* Function keys.  Space for 64 */
#define KEY_CODE_F(n) KEY_F(n)           /* Value of function key n */
#define KEY_CODE_DL KEY_DL               /* delete-line key */
#define KEY_CODE_IL KEY_IL               /* insert-line key */
#define KEY_CODE_DC KEY_DC               /* delete-character key */
#define KEY_CODE_IC KEY_IC               /* insert-character key */
#define KEY_CODE_EIC KEY_EIC             /* sent by rmir or smir in insert mode */
#define KEY_CODE_CLEAR KEY_CLEAR         /* clear-screen or erase key */
#define KEY_CODE_EOS KEY_EOS             /* clear-to-end-of-screen key */
#define KEY_CODE_EOL KEY_EOL             /* clear-to-end-of-line key */
#define KEY_CODE_SF KEY_SF               /* scroll-forward key */
#define KEY_CODE_SR KEY_SR               /* scroll-backward key */
#define KEY_CODE_NPAGE KEY_NPAGE         /* next-page key */
#define KEY_CODE_PPAGE KEY_PPAGE         /* previous-page key */
#define KEY_CODE_STAB KEY_STAB           /* set-tab key */
#define KEY_CODE_CTAB KEY_CTAB           /* clear-tab key */
#define KEY_CODE_CATAB KEY_CATAB         /* clear-all-tabs key */
#define KEY_CODE_ENTER KEY_ENTER         /* enter/send key */
#define KEY_CODE_PRINT KEY_PRINT         /* print key */
#define KEY_CODE_LL KEY_LL               /* lower-left key (home down) */
#define KEY_CODE_A1 KEY_A1               /* upper left of keypad */
#define KEY_CODE_A3 KEY_A3               /* upper right of keypad */
#define KEY_CODE_B2 KEY_B2               /* center of keypad */
#define KEY_CODE_C1 KEY_C1               /* lower left of keypad */
#define KEY_CODE_C3 KEY_C3               /* lower right of keypad */
#define KEY_CODE_BTAB KEY_BTAB           /* back-tab key */
#define KEY_CODE_BEG KEY_BEG             /* begin key */
#define KEY_CODE_CANCEL KEY_CANCEL       /* cancel key */
#define KEY_CODE_CLOSE KEY_CLOSE         /* close key */
#define KEY_CODE_COMMAND KEY_COMMAND     /* command key */
#define KEY_CODE_COPY KEY_COPY           /* copy key */
#define KEY_CODE_CREATE KEY_CREATE       /* create key */
#define KEY_CODE_END KEY_END             /* end key */
#define KEY_CODE_EXIT KEY_EXIT           /* exit key */
#define KEY_CODE_FIND KEY_FIND           /* find key */
#define KEY_CODE_HELP KEY_HELP           /* help key */
#define KEY_CODE_MARK KEY_MARK           /* mark key */
#define KEY_CODE_MESSAGE KEY_MESSAGE     /* message key */
#define KEY_CODE_MOVE KEY_MOVE           /* move key */
#define KEY_CODE_NEXT KEY_NEXT           /* next key */
#define KEY_CODE_OPEN KEY_OPEN           /* open key */
#define KEY_CODE_OPTIONS KEY_OPTIONS     /* options key */
#define KEY_CODE_PREVIOUS KEY_PREVIOUS   /* previous key */
#define KEY_CODE_REDO KEY_REDO           /* redo key */
#define KEY_CODE_REFERENCE KEY_REFERENCE /* reference key */
#define KEY_CODE_REFRESH KEY_REFRESH     /* refresh key */
#define KEY_CODE_REPLACE KEY_REPLACE     /* replace key */
#define KEY_CODE_RESTART KEY_RESTART     /* restart key */
#define KEY_CODE_RESUME KEY_RESUME       /* resume key */
#define KEY_CODE_SAVE KEY_SAVE           /* save key */
#define KEY_CODE_SBEG KEY_SBEG           /* shifted begin key */
#define KEY_CODE_SCANCEL KEY_SCANCEL     /* shifted cancel key */
#define KEY_CODE_SCOMMAND KEY_SCOMMAND   /* shifted command key */
#define KEY_CODE_SCOPY KEY_SCOPY         /* shifted copy key */
#define KEY_CODE_SCREATE KEY_SCREATE     /* shifted create key */
#define KEY_CODE_SDC KEY_SDC             /* shifted delete-character key */
#define KEY_CODE_SDL KEY_SDL             /* shifted delete-line key */
#define KEY_CODE_SELECT KEY_SELECT       /* select key */
#define KEY_CODE_SEND KEY_SEND           /* shifted end key */
#define KEY_CODE_SEOL KEY_SEOL           /* shifted clear-to-end-of-line key */
#define KEY_CODE_SEXIT KEY_SEXIT         /* shifted exit key */
#define KEY_CODE_SFIND KEY_SFIND         /* shifted find key */
#define KEY_CODE_SHELP KEY_SHELP         /* shifted help key */
#define KEY_CODE_SHOME KEY_SHOME         /* shifted home key */
#define KEY_CODE_SIC KEY_SIC             /* shifted insert-character key */
#define KEY_CODE_SLEFT KEY_SLEFT         /* shifted left-arrow key */
#define KEY_CODE_SMESSAGE KEY_SMESSAGE   /* shifted message key */
#define KEY_CODE_SMOVE KEY_SMOVE         /* shifted move key */
#define KEY_CODE_SNEXT KEY_SNEXT         /* shifted next key */
#define KEY_CODE_SOPTIONS KEY_SOPTIONS   /* shifted options key */
#define KEY_CODE_SPREVIOUS KEY_SPREVIOUS /* shifted previous key */
#define KEY_CODE_SPRINT KEY_SPRINT       /* shifted print key */
#define KEY_CODE_SREDO KEY_SREDO         /* shifted redo key */
#define KEY_CODE_SREPLACE KEY_SREPLACE   /* shifted replace key */
#define KEY_CODE_SRIGHT KEY_SRIGHT       /* shifted right-arrow key */
#define KEY_CODE_SRSUME KEY_SRSUME       /* shifted resume key */
#define KEY_CODE_SSAVE KEY_SSAVE         /* shifted save key */
#define KEY_CODE_SSUSPEND KEY_SSUSPEND   /* shifted suspend key */
#define KEY_CODE_SUNDO KEY_SUNDO         /* shifted undo key */
#define KEY_CODE_SUSPEND KEY_SUSPEND     /* suspend key */
#define KEY_CODE_UNDO KEY_UNDO           /* undo key */

#endif    /* __KEYCODE_H__ */
