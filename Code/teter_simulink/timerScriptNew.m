clear;
iterations = 1000;
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
    fprintf(s,'1,0,0');
    theta(i) = -(fread(s,1,'float')+.09);
    flushinput(s);
    lapse(i) = toc;
end


flushinput(s);
fclose(s);

subplot(2,1,1);
plot(1:iterations,lapse,'r.');
hold on;
axis([0 1000 0 max(lapse)]);
text(750,(max(lapse)-min(lapse))/2,strcat('mean: ',num2str(mean(lapse))));
subplot(2,1,2);
hist(lapse,500);
max = max(lapse)
min = min(lapse)