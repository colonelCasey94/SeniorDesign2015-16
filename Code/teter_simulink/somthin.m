clear variables;close all;clc;
mat1 = importdata('IMU_output.txt','\t');
ang = mat1(1:2:end-1,:);
acc = mat1(2:2:end,:);
t = [0:.25:.25*size(ang,1)-.25]';
figure(1)
plot(t,ang)
legend('\alpha_x','\alpha_y','\alpha_z')
figure(2)
plot(t,acc)
legend('a_x','a_y','a_z')
mag = sqrt(sum(acc.^2,2));
figure(3);
plot(t,mag);