iterations = 1000;
fclose(instrfind);
s = serial('COM4');
set(s, 'DataBits', 8);
set(s, 'StopBits', 1);
set(s, 'BaudRate', 230400);
set(s, 'Parity', 'none');
fopen(s);
a='b';
while a~='a'
    a=fread(s,1,'uchar');
end
fprintf(s,'%c','a');
fscanf(s,'%u');

theta = zeros(1,iterations);
lapse = zeros(1,iterations);

for i = 1:iterations
    tic;
    fprintf(s,strcat('1,',num2str(mod(i,2)),',',num2str(mod(i+1,2))));
    theta(i) = -(fread(s,1,'float')+.09);
    flushinput(s);
    lapse(i) = toc;
end

fprintf(s,'1,0,0');
flushinput(s);
fclose(s);

figure(1);hist(lapse);
figure(2);plot(1:iterations,lapse,'rx');