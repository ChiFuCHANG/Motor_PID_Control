clear; clc
close all

dataMatrix = readmatrix('motor_pid.txt');

length = 5001;

time = dataMatrix(1 : length, 1);
pos = dataMatrix(1 : length, 2);
vel = dataMatrix(1 : length, 3);
u = dataMatrix(1 : length, 4);

figure()
plot(time, pos, 'r')
yline(pi, '--k')
xlabel('time(sec)'), ylabel('angle(rad)')
title("The actual angle of the motor.")
legend('Actual', 'Reference')
saveas(gcf, 'Regulation Result', 'jpeg')

figure()
plot(time, vel, 'r')
xlabel('time(sec)'), ylabel('angular velocity(rad/s)')
title("The angular velocity of the motor.")
saveas(gcf, 'velocity', 'jpeg')

figure()
plot(time, u, 'r')
xlabel('time(sec)'), ylabel('output(Volt)')
title("The control input of the motor.")
saveas(gcf, 'control input', 'jpeg')