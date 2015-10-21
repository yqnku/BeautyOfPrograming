#!/usr/bin/python3
# -*- coding: <utf-8> -*-

#************************************************************************
# File Name: DynamicProgrammingMethod.py
# Author: yq
# Mail: xiqian013@live.com 
# Created Time: 2015-10-21 15:59:16
#************************************************************************

Max = 65535
def f(x1,x2,x3,x4,x5):
    books = [x1,x2,x3,x4,x5]
    books.sort(reverse = True)
    if (books[0] == 0):
        return 0
    y1 = Max
    y2 = Max
    y3 = Max
    y4 = Max
    y5 = Max
    if (books[4] >= 1):
        y1 = 30 + f(books[0]-1,books[1]-1,books[2]-1,books[3]-1,books[4]-1)
    if (books[3] >= 1):
        y1 = 25.6 + f(books[0]-1,books[1]-1,books[2]-1,books[3]-1,books[4])
    if (books[2] >= 1):
        y3 = 21.6 + f(books[0]-1,books[1]-1,books[2]-1,books[3],books[4])
    if (books[1] >= 1):
        y4 = 15.2 + f(books[0]-1,books[1]-1,books[2],books[3],books[4])
    if (books[0] >= 1):
        y5 = 8 + f(books[0]-1,books[1],books[2],books[3],books[4])
    return min(y1,y2,y3,y4,y5)
print(f(2,2,2,1,1))
