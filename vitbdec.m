clc;
m=input('ENTER THE MESSAGE:\n')
trel=poly2trellis(3,[3,4]);
code=convenc(m,trel);
fprintf(['CODED SEQUENCE IS:\n',num2str(code)]);
tblen=3;
opmode='trunc';
detype='hard';
decode=vitdec(code,trel,tblen,opmode,detype);
fprintf(['\nDECODED SEQUENCE IS:\n',num2str(decode)]);
if (m==decode)
   fprintf('\nSEQUENCE DECODED CORRECTLY\n');
else
    fprintf('\nDECODING FAILED\n');
end
