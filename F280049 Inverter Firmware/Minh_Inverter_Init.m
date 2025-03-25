 clc
clear

%% Motor Parameters
r = 0.36;
m = 1835;
rho = 1.2;

ppair= 1; % Pole pair
Rs = 0.18; % Stator resistance [Ohm]
Ls = 0.000835; % Stator inductance [H]
Ld = 0.000395; % Direct axis inductance [H]
Lq = 0.000435; % Quadrature axis inductance [H]
Ke = 0.0135281; % Back-EMF constant [V*Sec/rad]
k = 12.5;
g = 9.8; 
J = m*r^2/k^2;% Drive inertia [kg*m^2]
lambda = 0.1194; % Flux linkage
f = 0.000303448; %viscous friction coefficient

%% inverter parameters
bat_Voltage = 100; %max power supply voltage
Current_max = 30; %max current draw [A]
Voltage_max = Current_max*Rs; %max supply voltag [V]
if (Voltage_max > bat_Voltage)
    Voltage_max = bat_Voltage; %Max voltage cannot exceed power supply
end
Torque_max = Current_max*3*lambda*ppair/2; %max torque current can generate [Nm]
EPWM_F = 200000; %EPWM switching frequency (Hz)

C_d = 0.219;
A_f = 2.22;
C_rr = 0.01;

% pid controller tuning
% to tune controller make linearized model in simulink using the
% Input/Output tool
Kp = ?;
Ki = 5000;
Kd = ?;

disp('Motor parameters initialized!')
