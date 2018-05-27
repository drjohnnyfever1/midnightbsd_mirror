/* $MidnightBSD$ */
/* $FreeBSD: stable/10/sys/dev/sound/pci/allegro_code.h 230401 2012-01-20 22:37:10Z pfg $ */
/*-
 * Copyright (C) 1996-2008, 4Front Technologies
 * Copyright (C) 1997-1999 ESS Technology, Inc
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 */

/*---------------------------------------------------------------------------
 * This source code, its compiled object code, and its associated data sets
 * are copyright (C) 1997-1999 ESS Technology, Inc. This source code and its
 * associated data sets are trade secrets of ESS Technology, Inc.
 *---------------------------------------------------------------------------
 * DESCRIPTION: DSP binaries
 *---------------------------------------------------------------------------
 * AUTHOR:  Henry Tang / Hong Kim / Alger Yeung/Don Kim
 *---------------------------------------------------------------------------
 * For practical purposes we only include what is necessary for current
 *  Maestro3 driver. Files used in this header include:
 *    kernel.dat
 *    400m_src.dat
 *    mini_src_lpf from srcmgr.h
 *---------------------------------------------------------------------------
 */
#ifndef _DEV_SOUND_PCI_ALLEGRO_CODE_H
#define _DEV_SOUND_PCI_ALLEGRO_CODE_H

/*
 * Kernel
 */

uint16_t gaw_kernel_vect_code[] = {
    0x7980, 0x0030, 0x7980, 0x03B4, 0x7980, 0x03B4, 0x7980, 0x00FB, 0x7980,
    0x00DD, 0x7980, 0x03B4, 0x7980, 0x0332, 0x7980, 0x0287, 0x7980, 0x03B4,
    0x7980, 0x03B4, 0x7980, 0x03B4, 0x7980, 0x03B4, 0x7980, 0x031A, 0x7980,
    0x03B4, 0x7980, 0x022F, 0x7980, 0x03B4, 0x7980, 0x03B4, 0x7980, 0x03B4,
    0x7980, 0x03B4, 0x7980, 0x03B4, 0x7980, 0x0063, 0x7980, 0x006B, 0x7980,
    0x03B4, 0x7980, 0x03B4, 0xBF80, 0x2C7C, 0x8806, 0x8804, 0xBE40, 0xBC20,
    0xAE09, 0x1000, 0xAE0A, 0x0001, 0x6938, 0xEB08, 0x0053, 0x695A, 0xEB08,
    0x00D6, 0x0009, 0x8B88, 0x6980, 0xE388, 0x0036, 0xBE30, 0xBC20, 0x6909,
    0xB801, 0x9009, 0xBE41, 0xBE41, 0x6928, 0xEB88, 0x0078, 0xBE41, 0xBE40,
    0x7980, 0x0038, 0xBE41, 0xBE41, 0x903A, 0x6938, 0xE308, 0x0056, 0x903A,
    0xBE41, 0xBE40, 0xEF00, 0x903A, 0x6939, 0xE308, 0x005E, 0x903A, 0xEF00,
    0x690B, 0x660C, 0xEF8C, 0x690A, 0x660C, 0x620B, 0x6609, 0xEF00, 0x6910,
    0x660F, 0xEF04, 0xE388, 0x0075, 0x690E, 0x660F, 0x6210, 0x660D, 0xEF00,
    0x690E, 0x660D, 0xEF00, 0xAE70, 0x0001, 0xBC20, 0xAE27, 0x0001, 0x6939,
    0xEB08, 0x005D, 0x6926, 0xB801, 0x9026, 0x0026, 0x8B88, 0x6980, 0xE388,
    0x00CB, 0x9028, 0x0D28, 0x4211, 0xE100, 0x007A, 0x4711, 0xE100, 0x00A0,
    0x7A80, 0x0063, 0xB811, 0x660A, 0x6209, 0xE304, 0x007A, 0x0C0B, 0x4005,
    0x100A, 0xBA01, 0x9012, 0x0C12, 0x4002, 0x7980, 0x00AF, 0x7A80, 0x006B,
    0xBE02, 0x620E, 0x660D, 0xBA10, 0xE344, 0x007A, 0x0C10, 0x4005, 0x100E,
    0xBA01, 0x9012, 0x0C12, 0x4002, 0x1003, 0xBA02, 0x9012, 0x0C12, 0x4000, 
    0x1003, 0xE388, 0x00BA, 0x1004, 0x7980, 0x00BC, 0x1004, 0xBA01, 0x9012,
    0x0C12, 0x4001, 0x0C05, 0x4003, 0x0C06, 0x4004, 0x1011, 0xBFB0, 0x01FF,
    0x9012, 0x0C12, 0x4006, 0xBC20, 0xEF00, 0xAE26, 0x1028, 0x6970, 0xBFD0,
    0x0001, 0x9070, 0xE388, 0x007A, 0xAE28, 0x0000, 0xEF00, 0xAE70, 0x0300, 
    0x0C70, 0xB00C, 0xAE5A, 0x0000, 0xEF00, 0x7A80, 0x038A, 0x697F, 0xB801,
    0x907F, 0x0056, 0x8B88, 0x0CA0, 0xB008, 0xAF71, 0xB000, 0x4E71, 0xE200,
    0x00F3, 0xAE56, 0x1057, 0x0056, 0x0CA0, 0xB008, 0x8056, 0x7980, 0x03A1,
    0x0810, 0xBFA0, 0x1059, 0xE304, 0x03A1, 0x8056, 0x7980, 0x03A1, 0x7A80,
    0x038A, 0xBF01, 0xBE43, 0xBE59, 0x907C, 0x6937, 0xE388, 0x010D, 0xBA01,
    0xE308, 0x010C, 0xAE71, 0x0004, 0x0C71, 0x5000, 0x6936, 0x9037, 0xBF0A,
    0x109E, 0x8B8A, 0xAF80, 0x8014, 0x4C80, 0xBF0A, 0x0560, 0xF500, 0xBF0A,
    0x0520, 0xB900, 0xBB17, 0x90A0, 0x6917, 0xE388, 0x0148, 0x0D17, 0xE100,
    0x0127, 0xBF0C, 0x0578, 0xBF0D, 0x057C, 0x7980, 0x012B, 0xBF0C, 0x0538,
    0xBF0D, 0x053C, 0x6900, 0xE308, 0x0135, 0x8B8C, 0xBE59, 0xBB07, 0x90A0,
    0xBC20, 0x7980, 0x0157, 0x030C, 0x8B8B, 0xB903, 0x8809, 0xBEC6, 0x013E,
    0x69AC, 0x90AB, 0x69AD, 0x90AB, 0x0813, 0x660A, 0xE344, 0x0144, 0x0309,
    0x830C, 0xBC20, 0x7980, 0x0157, 0x6955, 0xE388, 0x0157, 0x7C38, 0xBF0B,
    0x0578, 0xF500, 0xBF0B, 0x0538, 0xB907, 0x8809, 0xBEC6, 0x0156, 0x10AB,
    0x90AA, 0x6974, 0xE388, 0x0163, 0xAE72, 0x0540, 0xF500, 0xAE72, 0x0500,
    0xAE61, 0x103B, 0x7A80, 0x02F6, 0x6978, 0xE388, 0x0182, 0x8B8C, 0xBF0C,
    0x0560, 0xE500, 0x7C40, 0x0814, 0xBA20, 0x8812, 0x733D, 0x7A80, 0x0380,
    0x733E, 0x7A80, 0x0380, 0x8B8C, 0xBF0C, 0x056C, 0xE500, 0x7C40, 0x0814,
    0xBA2C, 0x8812, 0x733F, 0x7A80, 0x0380, 0x7340, 0x7A80, 0x0380, 0x6975,
    0xE388, 0x018E, 0xAE72, 0x0548, 0xF500, 0xAE72, 0x0508, 0xAE61, 0x1041,
    0x7A80, 0x02F6, 0x6979, 0xE388, 0x01AD, 0x8B8C, 0xBF0C, 0x0560, 0xE500,
    0x7C40, 0x0814, 0xBA18, 0x8812, 0x7343, 0x7A80, 0x0380, 0x7344, 0x7A80,
    0x0380, 0x8B8C, 0xBF0C, 0x056C, 0xE500, 0x7C40, 0x0814, 0xBA24, 0x8812,
    0x7345, 0x7A80, 0x0380, 0x7346, 0x7A80, 0x0380, 0x6976, 0xE388, 0x01B9,
    0xAE72, 0x0558, 0xF500, 0xAE72, 0x0518, 0xAE61, 0x1047, 0x7A80, 0x02F6,
    0x697A, 0xE388, 0x01D8, 0x8B8C, 0xBF0C, 0x0560, 0xE500, 0x7C40, 0x0814,
    0xBA08, 0x8812, 0x7349, 0x7A80, 0x0380, 0x734A, 0x7A80, 0x0380, 0x8B8C,
    0xBF0C, 0x056C, 0xE500, 0x7C40, 0x0814, 0xBA14, 0x8812, 0x734B, 0x7A80,
    0x0380, 0x734C, 0x7A80, 0x0380, 0xBC21, 0xAE1C, 0x1090, 0x8B8A, 0xBF0A,
    0x0560, 0xE500, 0x7C40, 0x0812, 0xB804, 0x8813, 0x8B8D, 0xBF0D, 0x056C,
    0xE500, 0x7C40, 0x0815, 0xB804, 0x8811, 0x7A80, 0x034A, 0x8B8A, 0xBF0A,
    0x0560, 0xE500, 0x7C40, 0x731F, 0xB903, 0x8809, 0xBEC6, 0x01F9, 0x548A, 
    0xBE03, 0x98A0, 0x7320, 0xB903, 0x8809, 0xBEC6, 0x0201, 0x548A, 0xBE03,
    0x98A0, 0x1F20, 0x2F1F, 0x9826, 0xBC20, 0x6935, 0xE388, 0x03A1, 0x6933,
    0xB801, 0x9033, 0xBFA0, 0x02EE, 0xE308, 0x03A1, 0x9033, 0xBF00, 0x6951,
    0xE388, 0x021F, 0x7334, 0xBE80, 0x5760, 0xBE03, 0x9F7E, 0xBE59, 0x9034,
    0x697E, 0x0D51, 0x9013, 0xBC20, 0x695C, 0xE388, 0x03A1, 0x735E, 0xBE80,
    0x5760, 0xBE03, 0x9F7E, 0xBE59, 0x905E, 0x697E, 0x0D5C, 0x9013, 0x7980,
    0x03A1, 0x7A80, 0x038A, 0xBF01, 0xBE43, 0x6977, 0xE388, 0x024E, 0xAE61,
    0x104D, 0x0061, 0x8B88, 0x6980, 0xE388, 0x024E, 0x9071, 0x0D71, 0x000B,
    0xAFA0, 0x8010, 0xAFA0, 0x8010, 0x0810, 0x660A, 0xE308, 0x0249, 0x0009,
    0x0810, 0x660C, 0xE388, 0x024E, 0x800B, 0xBC20, 0x697B, 0xE388, 0x03A1,
    0xBF0A, 0x109E, 0x8B8A, 0xAF80, 0x8014, 0x4C80, 0xE100, 0x0266, 0x697C,
    0xBF90, 0x0560, 0x9072, 0x0372, 0x697C, 0xBF90, 0x0564, 0x9073, 0x0473,
    0x7980, 0x0270, 0x697C, 0xBF90, 0x0520, 0x9072, 0x0372, 0x697C, 0xBF90,
    0x0524, 0x9073, 0x0473, 0x697C, 0xB801, 0x907C, 0xBF0A, 0x10FD, 0x8B8A,
    0xAF80, 0x8010, 0x734F, 0x548A, 0xBE03, 0x9880, 0xBC21, 0x7326, 0x548B,
    0xBE03, 0x618B, 0x988C, 0xBE03, 0x6180, 0x9880, 0x7980, 0x03A1, 0x7A80,
    0x038A, 0x0D28, 0x4711, 0xE100, 0x02BE, 0xAF12, 0x4006, 0x6912, 0xBFB0,
    0x0C00, 0xE388, 0x02B6, 0xBFA0, 0x0800, 0xE388, 0x02B2, 0x6912, 0xBFB0,
    0x0C00, 0xBFA0, 0x0400, 0xE388, 0x02A3, 0x6909, 0x900B, 0x7980, 0x02A5,
    0xAF0B, 0x4005, 0x6901, 0x9005, 0x6902, 0x9006, 0x4311, 0xE100, 0x02ED,
    0x6911, 0xBFC0, 0x2000, 0x9011, 0x7980, 0x02ED, 0x6909, 0x900B, 0x7980,
    0x02B8, 0xAF0B, 0x4005, 0xAF05, 0x4003, 0xAF06, 0x4004, 0x7980, 0x02ED,
    0xAF12, 0x4006, 0x6912, 0xBFB0, 0x0C00, 0xE388, 0x02E7, 0xBFA0, 0x0800,
    0xE388, 0x02E3, 0x6912, 0xBFB0, 0x0C00, 0xBFA0, 0x0400, 0xE388, 0x02D4,
    0x690D, 0x9010, 0x7980, 0x02D6, 0xAF10, 0x4005, 0x6901, 0x9005, 0x6902,
    0x9006, 0x4311, 0xE100, 0x02ED, 0x6911, 0xBFC0, 0x2000, 0x9011, 0x7980,
    0x02ED, 0x690D, 0x9010, 0x7980, 0x02E9, 0xAF10, 0x4005, 0xAF05, 0x4003,
    0xAF06, 0x4004, 0xBC20, 0x6970, 0x9071, 0x7A80, 0x0078, 0x6971, 0x9070,
    0x7980, 0x03A1, 0xBC20, 0x0361, 0x8B8B, 0x6980, 0xEF88, 0x0272, 0x0372,
    0x7804, 0x9071, 0x0D71, 0x8B8A, 0x000B, 0xB903, 0x8809, 0xBEC6, 0x0309,
    0x69A8, 0x90AB, 0x69A8, 0x90AA, 0x0810, 0x660A, 0xE344, 0x030F, 0x0009,
    0x0810, 0x660C, 0xE388, 0x0314, 0x800B, 0xBC20, 0x6961, 0xB801, 0x9061,
    0x7980, 0x02F7, 0x7A80, 0x038A, 0x5D35, 0x0001, 0x6934, 0xB801, 0x9034,
    0xBF0A, 0x109E, 0x8B8A, 0xAF80, 0x8014, 0x4880, 0xAE72, 0x0550, 0xF500,
    0xAE72, 0x0510, 0xAE61, 0x1051, 0x7A80, 0x02F6, 0x7980, 0x03A1, 0x7A80,
    0x038A, 0x5D35, 0x0002, 0x695E, 0xB801, 0x905E, 0xBF0A, 0x109E, 0x8B8A,
    0xAF80, 0x8014, 0x4780, 0xAE72, 0x0558, 0xF500, 0xAE72, 0x0518, 0xAE61,
    0x105C, 0x7A80, 0x02F6, 0x7980, 0x03A1, 0x001C, 0x8B88, 0x6980, 0xEF88,
    0x901D, 0x0D1D, 0x100F, 0x6610, 0xE38C, 0x0358, 0x690E, 0x6610, 0x620F,
    0x660D, 0xBA0F, 0xE301, 0x037A, 0x0410, 0x8B8A, 0xB903, 0x8809, 0xBEC6,
    0x036C, 0x6A8C, 0x61AA, 0x98AB, 0x6A8C, 0x61AB, 0x98AD, 0x6A8C, 0x61AD,
    0x98A9, 0x6A8C, 0x61A9, 0x98AA, 0x7C04, 0x8B8B, 0x7C04, 0x8B8D, 0x7C04,
    0x8B89, 0x7C04, 0x0814, 0x660E, 0xE308, 0x0379, 0x040D, 0x8410, 0xBC21,
    0x691C, 0xB801, 0x901C, 0x7980, 0x034A, 0xB903, 0x8809, 0x8B8A, 0xBEC6,
    0x0388, 0x54AC, 0xBE03, 0x618C, 0x98AA, 0xEF00, 0xBC20, 0xBE46, 0x0809,
    0x906B, 0x080A, 0x906C, 0x080B, 0x906D, 0x081A, 0x9062, 0x081B, 0x9063,
    0x081E, 0x9064, 0xBE59, 0x881E, 0x8065, 0x8166, 0x8267, 0x8368, 0x8469,
    0x856A, 0xEF00, 0xBC20, 0x696B, 0x8809, 0x696C, 0x880A, 0x696D, 0x880B,
    0x6962, 0x881A, 0x6963, 0x881B, 0x6964, 0x881E, 0x0065, 0x0166, 0x0267,
    0x0368, 0x0469, 0x056A, 0xBE3A,
};

/*
 * MINI Sample Rate Conversion
 */

uint16_t gaw_minisrc_code_0400[] = {
    0xBF80, 0x101E, 0x906E, 0x006E, 0x8B88, 0x6980, 0xEF88, 0x906F, 0x0D6F,
    0x6900, 0xEB08, 0x0412, 0xBC20, 0x696E, 0xB801, 0x906E, 0x7980, 0x0403,
    0xB90E, 0x8807, 0xBE43, 0xBF01, 0xBE47, 0xBE41, 0x7A80, 0x002A, 0xBE40,
    0x3029, 0xEFCC, 0xBE41, 0x7A80, 0x0028, 0xBE40, 0x3028, 0xEFCC, 0x6907,
    0xE308, 0x042A, 0x6909, 0x902C, 0x7980, 0x042C, 0x690D, 0x902C, 0x1009,
    0x881A, 0x100A, 0xBA01, 0x881B, 0x100D, 0x881C, 0x100E, 0xBA01, 0x881D,
    0xBF80, 0x00ED, 0x881E, 0x050C, 0x0124, 0xB904, 0x9027, 0x6918, 0xE308,
    0x04B3, 0x902D, 0x6913, 0xBFA0, 0x7598, 0xF704, 0xAE2D, 0x00FF, 0x8B8D,
    0x6919, 0xE308, 0x0463, 0x691A, 0xE308, 0x0456, 0xB907, 0x8809, 0xBEC6,
    0x0453, 0x10A9, 0x90AD, 0x7980, 0x047C, 0xB903, 0x8809, 0xBEC6, 0x0460,
    0x1889, 0x6C22, 0x90AD, 0x10A9, 0x6E23, 0x6C22, 0x90AD, 0x7980, 0x047C,
    0x101A, 0xE308, 0x046F, 0xB903, 0x8809, 0xBEC6, 0x046C, 0x10A9, 0x90A0,
    0x90AD, 0x7980, 0x047C, 0xB901, 0x8809, 0xBEC6, 0x047B, 0x1889, 0x6C22,
    0x90A0, 0x90AD, 0x10A9, 0x6E23, 0x6C22, 0x90A0, 0x90AD, 0x692D, 0xE308,
    0x049C, 0x0124, 0xB703, 0xB902, 0x8818, 0x8B89, 0x022C, 0x108A, 0x7C04,
    0x90A0, 0x692B, 0x881F, 0x7E80, 0x055B, 0x692A, 0x8809, 0x8B89, 0x99A0,
    0x108A, 0x90A0, 0x692B, 0x881F, 0x7E80, 0x055B, 0x692A, 0x8809, 0x8B89,
    0x99AF, 0x7B99, 0x0484, 0x0124, 0x060F, 0x101B, 0x2013, 0x901B, 0xBFA0,
    0x7FFF, 0xE344, 0x04AC, 0x901B, 0x8B89, 0x7A80, 0x051A, 0x6927, 0xBA01,
    0x9027, 0x7A80, 0x0523, 0x6927, 0xE308, 0x049E, 0x7980, 0x050F, 0x0624,
    0x1026, 0x2013, 0x9026, 0xBFA0, 0x7FFF, 0xE304, 0x04C0, 0x8B8D, 0x7A80,
    0x051A, 0x7980, 0x04B4, 0x9026, 0x1013, 0x3026, 0x901B, 0x8B8D, 0x7A80,
    0x051A, 0x7A80, 0x0523, 0x1027, 0xBA01, 0x9027, 0xE308, 0x04B4, 0x0124,
    0x060F, 0x8B89, 0x691A, 0xE308, 0x04EA, 0x6919, 0xE388, 0x04E0, 0xB903,
    0x8809, 0xBEC6, 0x04DD, 0x1FA0, 0x2FAE, 0x98A9, 0x7980, 0x050F, 0xB901,
    0x8818, 0xB907, 0x8809, 0xBEC6, 0x04E7, 0x10EE, 0x90A9, 0x7980, 0x050F,
    0x6919, 0xE308, 0x04FE, 0xB903, 0x8809, 0xBE46, 0xBEC6, 0x04FA, 0x17A0,
    0xBE1E, 0x1FAE, 0xBFBF, 0xFF00, 0xBE13, 0xBFDF, 0x8080, 0x99A9, 0xBE47,
    0x7980, 0x050F, 0xB901, 0x8809, 0xBEC6, 0x050E, 0x16A0, 0x26A0, 0xBFB7,
    0xFF00, 0xBE1E, 0x1EA0, 0x2EAE, 0xBFBF, 0xFF00, 0xBE13, 0xBFDF, 0x8080,
    0x99A9, 0x850C, 0x860F, 0x6907, 0xE388, 0x0516, 0x0D07, 0x8510, 0xBE59,
    0x881E, 0xBE4A, 0xEF00, 0x101E, 0x901C, 0x101F, 0x901D, 0x10A0, 0x901E,
    0x10A0, 0x901F, 0xEF00, 0x101E, 0x301C, 0x9020, 0x731B, 0x5420, 0xBE03,
    0x9825, 0x1025, 0x201C, 0x9025, 0x7325, 0x5414, 0xBE03, 0x8B8E, 0x9880,
    0x692F, 0xE388, 0x0539, 0xBE59, 0xBB07, 0x6180, 0x9880, 0x8BA0, 0x101F,
    0x301D, 0x9021, 0x731B, 0x5421, 0xBE03, 0x982E, 0x102E, 0x201D, 0x902E,
    0x732E, 0x5415, 0xBE03, 0x9880, 0x692F, 0xE388, 0x054F, 0xBE59, 0xBB07,
    0x6180, 0x9880, 0x8BA0, 0x6918, 0xEF08, 0x7325, 0x5416, 0xBE03, 0x98A0,
    0x732E, 0x5417, 0xBE03, 0x98A0, 0xEF00, 0x8BA0, 0xBEC6, 0x056B, 0xBE59,
    0xBB04, 0xAA90, 0xBE04, 0xBE1E, 0x99E0, 0x8BE0, 0x69A0, 0x90D0, 0x69A0, 
    0x90D0, 0x081F, 0xB805, 0x881F, 0x8B90, 0x69A0, 0x90D0, 0x69A0, 0x9090,
    0x8BD0, 0x8BD8, 0xBE1F, 0xEF00, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};

uint16_t minisrc_lpf[10] = {
	0X0743, 0X1104, 0X0A4C, 0XF88D, 0X242C,
	0X1023, 0X1AA9, 0X0B60, 0XEFDD, 0X186F
};

#endif	/* !_DEV_SOUND_PCI_ALLEGRO_CODE_H */
