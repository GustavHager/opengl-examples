import os
import ycm_core


flags = ['-std=c++11',
         '-stdlib=libc++',
         '-x','c++']


def FlagsForFile(filename, **kwargs):
    return flags
 
