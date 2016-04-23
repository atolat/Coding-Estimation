clc;        %%clear screen
n=input('ENTER THE CODEWORD LENGTH(n):\n')          %get block length
k=input('ENTER NO OF MSG BITS(k):\n')               %get no of msg bits
[gp,t]=bchgenpoly(n,k)                              %generate bch generator polynomial
nw=1                                                %no of words to process
msgw=gf(randint(nw,k))                              %random nw msg symbol
c=bchenc(msgw,n,k)                                  %encode data using bch
noise=randerr(nw,n,t)                               %generate t erros/row
cnoisy = c + noise                                  %add noise to the code
[dc,nerrs,corrcode]=bchdec(cnoisy,n,k)              %decode
%%check whether decoding works correctly?
chks=isequal(dc,msgw) & isequal(corrcode,c)         %find out how many errors bchdecoded corretly
nerrs
