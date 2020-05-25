#include "polishToLatin.h"

int polish_letters_to_latin(const char* text)
{
        char *p = text;
        int i, idxToDel = 1;

        while (*p != '\0') {
                i = *p - '0';

                if (i == -108) {
                        ++p;
                        i = *p - '0';
                        --p;

                        switch(i) {
                                case -171: *p = 'a'; break;
                                case -169: *p = 'c'; break;
                                case -151: *p = 'e'; break;
                                case -172: *p = 'A'; break;
                                case -170: *p = 'C'; break;
                                case -152: *p = 'E'; break;

                                default: return -1;
                        }
                        memmove(&text[idxToDel], &text[idxToDel + 1], strlen(text) - idxToDel);
                }

                else if (i == -107) {
                        ++p;
                        i = *p - '0';
                        --p;

                        switch(i) {
                                case -174: *p = 'l'; break;
                                case -172: *p = 'n'; break;
                                case -149: *p = 's'; break;

                                case -118:
                                case -116: *p = 'z'; break;

                                case -175: *p = 'L'; break;
                                case -173: *p = 'N'; break;
                                case -150: *p = 'S'; break;

                                case -119:
                                case -117: *p = 'Z'; break;

                                default: return -1;
                        }
                        memmove(&text[idxToDel], &text[idxToDel + 1], strlen(text) - idxToDel);
                }

                else if (i == -109) {
                        ++p;
                        i = *p - '0';
                        --p;
                        switch(i) {
                                case -125: *p = 'o'; break;
                                case -157: *p = 'O'; break;
                                
                                default: return -1;
                        }
                        memmove(&text[idxToDel], &text[idxToDel + 1], strlen(text) - idxToDel);
                }

                ++idxToDel;
                ++p; 
        }
        return 0;
}