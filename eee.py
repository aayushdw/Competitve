import math
import os
import random
import re
import sys

def pre():
    Fact = [1] * MAX;
    InvFact = [1] * MAX;

    for i in range(1, MAX):
        Fact[i] = (Fact[i-1] * i) % MOD
        InvFact[i] = (InvFact[i-1] * pow(i, MOD-2, MOD)) % MOD
    return Fact, InvFact

def nCr(n, r):
    return ( Fact[n] * InvFact[r] * InvFact[n-r] ) % MOD

def mergeNodes(s1, n1, s2, n2):
    return ( s1+s2 , ( n1 * n2 * nCr(s1+s2, s1) ) % MOD)

def foo(u):
    s, n = 0, 1
    for Child in child[u]:
        x = foo(Child)
        s, n = mergeNodes(s, n, x[0], x[1])
    return s+1, n


def invitations(n, pairs):
    for edge in pairs:
        par[edge[1]] = edge[0]
        child[edge[0]].append(edge[1])
    for i in range(1, n+1):
        if (par[i] == 0):
            child[0].append(i)
    return foo(0)[1]


MAX = 400005
MOD = 10 ** 9 + 7
sys.setrecursionlimit(MAX)
Fact, InvFact = pre()

tc = int(input().strip())

for tc_itr in range(tc):
    first_multiple_input = input().rstrip().split()

    n = int(first_multiple_input[0])

    m = int(first_multiple_input[1])
    par = [0]*(n+1)
    child = [[]]

    for i in range(1,n+1):
        child.append([])
    pairs = []

    for _ in range(m):
        pairs.append(list(map(int, input().rstrip().split())))

    result = invitations(n, pairs)
    print( result )