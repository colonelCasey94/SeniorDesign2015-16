function [ s ] = setSerial( comPort )
s = serial(comPort);
set(s, 'DataBits', 8);
set(s, 'StopBits', 1);
set(s, 'BaudRate', 230400);
set(s, 'Parity', 'none');
fopen(s);
a='b';
while a~='a'
    a=fread(s,1,'uchar');
end
if a=='a'
    disp('serial read');
end
fprintf(s,'%c','a');
fscanf(s,'%u');
end