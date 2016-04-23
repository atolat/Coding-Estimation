clc;                                                %clear screen
syms x;
n=input('ENTER BLOCK LENGTH(n):');                  %get value of n
k=input('ENTER NO OF MSG BITS(k):');                %get value of k
q=n-k;                                              %calculate q
disp('NO OF PARITY BITS(q) :');                     %display q
disp(q);
g=input('ENTER GENERATOR POLYNOMIAL G(p):\n');
fprintf('\nMENU:\n1.ENCODE A MSG \n2.ENCODE ALL COMBINATIONS:\n');
ch=input('\nChoice?');
fprintf('\n');
switch (ch)
    case 1
    m=input('ENTER MSG POLYNOMIAL M(p):\n');
    pol=sym2poly(x^(n-k));
    h=conv(pol,m);
    [a,r]=deconv(h,g);
    q=mod(a,2);
    d=conv(q,g);
    code=mod(d,2);
    fprintf(['CODEWORD IS:\n',num2str(code)]);
    fprintf('\n');
    case 2
    disp('--------------------------------------------------');
    fprintf('\tMSGVECTOR\t\tCODEWORD\t\tHAMMING WEIGHT\n');
    disp('--------------------------------------------------');
    for i=0:1:2^k-1           %encoding begins
        d= bitget(uint8(i), k:-1:1);   %return a bit value
        c= zeros(1,n);        %generate (1*n) bit zeropadded word
        for i=1:k
            c(1,i)=d(1,i);    %copy 1st k bits for division
        end
        [~,r1]=deconv(c,g);   %perform division to find remainder
        r=mod(r1,2);          %determine mod-2
        for i=1:k                                       
            r(1,i)=d(1,i);
        end
        cnt=0;
        for j=1:n             %calculate hamming weight
            if(r(1,j)==1)     %check if bit==1
                cnt=cnt+1;    %if yes increment cnt
            else
                cnt=cnt;      %else restore org value
        end
        end
        fprintf('\t%d',r);    %display codeword
        fprintf('\t\t%d',cnt);%display hamming weight
        fprintf('\n');
    end                       %encoding completed
end
rec=input('ENTER RECEIVED CODEWORD:\n');
[q1,r1]=deconv(rec,g);
synd= mod(r1,2);
e=zeros(1,n);
c=0;
for i=1:n
    e=zeros(1,n);
    e(i)=1;
    [q2,r2]=deconv(e,g);
    synd1=mod(r2,2);
    if synd==synd1
        j=i;
        break
    else
        c=c+1;
    end
end
if c ~=n
    e(1,j)=1;
    dec_c=xor(e,rec);
    fprintf(['\nERROR PATTERN IS:\n',num2str(e)]);
    fprintf(['\nDECODED CODEWORD IS:\n',num2str(dec_c)]);
    fprintf('\n'); 
else
    disp('correctly received');
end