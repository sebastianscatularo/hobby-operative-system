/* 
 * File:   Utils.h
 * Author: alumno
 *
 * Created on 3 de mayo de 2015, 14:54
 */

#ifndef UTILS_H
#define	UTILS_H

class Utils {
public:

    static long unsigned int strlen(const char* str) {
        long unsigned int ret = 0;
        while (str[ret] != 0) {
            ret++;
        }
        return ret;
    }
};

#endif	/* UTILS_H */

