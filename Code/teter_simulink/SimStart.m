fclose(instrfind);
clearvars -except s;close all;clc;
%% SET PARAMETER VALUES
theta = -45;  %degrees, step jump from zero to this angle, the back to zero after 1 sec
theta2 = 45; %Jump from previous angle to this angle
Tstep = 3;  %Second jump at this time
Tsim = 6;   %Total time
step = .01;  %Step Size

init = 0;

weight = .4*9.81; %N - this is the weight of the whole rotating bar
I = 6187584.80e-9; %kg*m^2   this is the moment of inertia
l = .45; %m   this is the length of between the rotors
[Kp, Ki, Kd] = deal(.5,2,.1); %gains for Proportional, integral, and derivitive correction
TauSat = .75;   %Maximum torque considered
Tmax = .520*9.81;  %N  - maximum thrust

sim('werks'); % run the simulation