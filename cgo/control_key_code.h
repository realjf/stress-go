// control_key_code.h
// #############################################################################
// # File: control_key_code.h                                                  #
// # Project: include                                                          #
// # Created Date: 2024/11/30 19:33:44                                         #
// # Author: realjf                                                            #
// # -----                                                                     #
// # Last Modified: 2024/11/30 22:08:57                                        #
// # Modified By: realjf                                                       #
// # -----                                                                     #
// #                                                                           #
// #############################################################################

#ifndef __CONTROL_KEY_CODE_H__
#define __CONTROL_KEY_CODE_H__

#define CTRL_KEY_NUL 0x00 // ^@ Null
#define CTRL_KEY_SOH 0x01 // ^A Start Of Heading
#define CTRL_KEY_STX 0x02 // ^B Start Of Text
#define CTRL_KEY_ETX 0x03 // ^C End Of Text
#define CTRL_KEY_EOT 0x04 // ^D End Of Transmission
#define CTRL_KEY_ENQ 0x05 // ^E Enquiry
#define CTRL_KEY_ACK 0x06 // ^F Acknowledge
#define CTRL_KEY_BEL 0x07 // ^G Bell
#define CTRL_KEY_BS 0x08  // ^H Backspace
#define CTRL_KEY_HT 0x09  // ^I Horizontal Tab
#define CTRL_KEY_LF 0x0a  // ^J Line Feed
#define CTRL_KEY_VT 0x0b  // ^K Vertical Tab
#define CTRL_KEY_FF 0x0c  // ^L Form Feed
#define CTRL_KEY_CR 0x0d  // ^M Carriage Return
#define CTRL_KEY_SO 0x0e  // ^N Shift Out
#define CTRL_KEY_SI 0x0f  // ^O Shift In
#define CTRL_KEY_DLE 0x10 // ^P Data Link Escape
#define CTRL_KEY_DC1 0x11 // ^Q Device Control 1
#define CTRL_KEY_DC2 0x12 // ^R Device Control 2
#define CTRL_KEY_DC3 0x13 // ^S Device Control 3
#define CTRL_KEY_DC4 0x14 // ^T Device Control 4
#define CTRL_KEY_NAK 0x15 // ^U Negative Acknowledge
#define CTRL_KEY_SYN 0x16 // ^V Synchronous idle
#define CTRL_KEY_ETB 0x17 // ^W End Transmission Block
#define CTRL_KEY_CAN 0x18 // ^X Cancel
#define CTRL_KEY_EM 0x19  // ^Y End of Medium
#define CTRL_KEY_SUB 0x1a // ^Z Substitute
#define CTRL_KEY_ESC 0x1b // ^[ Escape
#define CTRL_KEY_FS 0x1c  // ^\ Form Separator
#define CTRL_KEY_GS 0x1d  // ^] Group Separator
#define CTRL_KEY_RS 0x1e  // ^^ Record Separator
#define CTRL_KEY_US 0x1f  // ^_ Unit Separator
#define CTRL_KEY_DEL 0x7f // ^? Delete

#endif /* __CONTROL_KEY_CODE_H__ */
