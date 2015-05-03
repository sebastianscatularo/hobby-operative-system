/* 
 * File:   Video.h
 * Author: alumno
 *
 * Created on 3 de mayo de 2015, 14:43
 */

#ifndef VIDEO_H
#define	VIDEO_H

enum vga_color {
    COLOR_BLACK = 0,
    COLOR_BLUE = 1,
    COLOR_GREEN = 2,
    COLOR_CYAN = 3,
    COLOR_RED = 4,
    COLOR_MAGENTA = 5,
    COLOR_BROWN = 6,
    COLOR_LIGHT_GREY = 7,
    COLOR_DARK_GREY = 8,
    COLOR_LIGHT_BLUE = 9,
    COLOR_LIGHT_GREEN = 10,
    COLOR_LIGHT_CYAN = 11,
    COLOR_LIGHT_RED = 12,
    COLOR_LIGHT_MAGENTA = 13,
    COLOR_LIGHT_BROWN = 14,
    COLOR_WHITE = 15,
};

class Video {
public:
    Video();
    Video(const Video& orig);
    void clean();
    unsigned char color(enum vga_color fg, enum vga_color bg);
    unsigned short int vgaentry(char c, unsigned char color);
    void entryAt(char c, unsigned char color, long unsigned int x, long unsigned int y);
    void putChar(char c);
    void print(const char* data);
private:
    static const long unsigned int VGA_WIDTH = 80;
    static const long unsigned int VGA_HEIGHT = 25;
 
    long unsigned int terminal_row;
    long unsigned int terminal_column;
    unsigned char terminal_color;
    unsigned short int* terminal_buffer;

};

#endif	/* VIDEO_H */

