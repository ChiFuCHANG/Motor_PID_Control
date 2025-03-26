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
title("The actual output of the motor using PID control.")
legend('Actual', 'Reference')
saveas(gcf, 'Regulation Result', 'jpeg')