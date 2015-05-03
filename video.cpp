/* 
 * File:   Video.cpp
 * Author: alumno
 * 
 * Created on 3 de mayo de 2015, 14:43
 */

#include "video.h"
#include "utils.h"

Video::Video() {
    terminal_row = 0;
    terminal_column = 0;
    terminal_color = color(COLOR_LIGHT_GREY, COLOR_BLACK);
    terminal_buffer = (unsigned short int*) 0xB8000;
    for (long unsigned int y = 0; y < VGA_HEIGHT; y++ ) {
        for (long unsigned int x = 0; x < VGA_WIDTH; x++ ) {
            const long unsigned int index = y * VGA_WIDTH + x;
            terminal_buffer[index] = vgaentry(' ', terminal_color);
        }
    }
}

Video::Video(const Video& orig) {
}

void Video::clean() {
    terminal_row = 0;
    terminal_column = 0;
    terminal_color = color(COLOR_LIGHT_GREY, COLOR_BLACK);
    terminal_buffer = (unsigned short int*) 0xB8000;
    for (long unsigned int y = 0; y < VGA_HEIGHT; y++ ) {
        for (long unsigned int x = 0; x < VGA_WIDTH; x++ ) {
            const long unsigned int index = y * VGA_WIDTH + x;
            terminal_buffer[index] = vgaentry(' ', terminal_color);
        }
    }
}

unsigned char Video::color(vga_color fg, vga_color bg) {
    return fg | bg << 4;
}

unsigned short int Video::vgaentry(char c, unsigned char color) {
    unsigned short int c16 = c;
    unsigned short int color16 = color;
    return c16 | color16 << 8;
}

void Video::entryAt(char c, unsigned char color, long unsigned int x, long unsigned int y) {
    const long unsigned int index = y * VGA_WIDTH + x;
    terminal_buffer[index] = vgaentry(c, color);
}

void Video::putChar(char c) {
    entryAt(c, terminal_color, terminal_column, terminal_row);
    if ( ++terminal_column == VGA_WIDTH ) {
        terminal_column = 0;
        if ( ++terminal_row == VGA_HEIGHT ) {
            terminal_row = 0;
        }
    }   
}

void Video::print(const char* data) {
    long unsigned int datalen = Utils::strlen(data);
    for (long unsigned int i = 0; i < datalen; i++ ) {
        putChar(data[i]);
    }
}
