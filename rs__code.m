clc;
m=input('ENTER NO OF BITS PER SYMBOL(m):\n')            %no of bits/symbol
n=2^m-1                                                 %calculate block length
k=input('ENTER NO OF MSG BITS(k):\n')                   %msg bit length
t=(n-k)/2                                               %find error correction capability
nw=input('ENTER NO OF WORD TO BE PROCESSED:\n')         %no of words to process
msgw=gf(randint(nw,k,2^m),m)                            %random k symbol message
c=rsenc(msgw,n,k)                                        %encode using RS code
noise=(1+randint(nw,n,2^m-1)).*randerr(nw,n,t)         %t errors/row
cnoisy= c + noise                                       %add noise
[dc,nerrs,corrcode]=rsdec(cnoisy,n,k);                  %decode using RS code
%%check whether decoding works correctly?
chks=isequal(dc,msgw) & isequal(corrcode,c)             %find out how many errors bchdecoded corretly
nerrs
