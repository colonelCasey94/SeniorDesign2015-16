steps = 2000;
thetaDot = zeros(steps,6);
theta = zeros(steps,3);
thetaCut = zeros(steps,3);
SerialChat(s,1,90);
SerialChat(s,2,90);
a = .05;
for t = 1:steps
    tic
    thetaDot(t,:) = SerialChat(s,9,1)+[0 0 0 0 .07 -.05]';
    theta(t+1,:) = theta(t,:)+thetaDot(t,4:6)*(a);
    thetaCut(t+1,:)  = [(mod(theta(t+1,1)+pi,2*pi)-pi)*180/pi,(mod(theta(t+1,2)...
        +pi,2*pi)-pi)*180/pi,(mod(theta(t+1,3)+pi,2*pi)-pi)*180/pi];
    if t == 1
        figure(1);
        plot(1,0,'rx')
        hold on;
        axis([1 steps -180 180]);
        grid on;
        grid minor;
    end
    plot(1:t+1,thetaCut(1:t+1,1),'b',1:t+1,thetaCut(1:t+1,2),'c');
    SerialChat(s,1,round(thetaCut(t+1,1))+90);
    SerialChat(s,2,round(thetaCut(t+1,2))+90);
    a = toc;
end