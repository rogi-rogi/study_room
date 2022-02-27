'''
O(sqrt(P)) <= O(N^¼)
'''
from math import gcd
from random import randint

def g(x, c, n) :
    return (x * x + c) % n
    
def PollardRho(n) :
    if MillerRabin(n) : return [n]
    if n == 4 : return [2, 2]
    while True :
        c = randint(1, 9)
        x2 = x1 = randint(1, 9)
        d = 1
        while d == 1 :
            x1 = g(x1, c, n)
            x2 = g(g(x2, c, n), c, n)
            d = gcd(abs(x1 - x2), n)
        if d != n :
            return PollardRho(n // d) + PollardRho(d)
