clc
clear

% Motor Parameters
r = 0.4064/2;     % [m] Wheel radius (diameter/2)
m = 1;          % [kg] Vehicle mass
mrot = 20;        % [kg] Rotor mass
rho = 1.2;        % [kg/m^3] Air density

ppair= 4; % Pole pair
Rs = 1.3e-3;       % [Ohm] Stator phase resistance

Ld = 0.1e-3;     % [H] Direct-axis inductance (phase to phase)
Lq = Ld;        % [H] Quadrature-axis inductance (SPMSM assumption)
lambda = 0.0375;  % [Wb] Permanent magnet flux linkage

% Don't have this number Ke = 0.0135281; % Back-EMF constant [V*Sec/rad]
Kt = 0.15; %[Nm/A]
k = 1;        % [-] Gear ratio (wheel speed to motor speed)
g = 9.8;         % [m/s^2] Gravitational acceleration
J = mrot*r^2/k^2 + 0.0045;  % Drive inertia [kg*m^2]
%J = 0.0045;     % [kg*m^2] Rotor inertia
lambda = 0.0375; % Flux linkage
f = 0.000303448; %viscous friction coefficient

%% inverter parameters

V_bat = 24 * 3.6; % [V] Battery voltage (24 cells * 3.6V nominal per cell)
Current_max = 30; %max current draw [A]
Voltage_max = V_bat; %max allowable voltag [V]

Torque_max = Current_max*3*lambda*ppair/2; %max torque current can generate [Nm]
speed_max = 1000; %Max rated speed for the motor [Rad/s]
EPWM_F = 200000; %EPWM switching frequency (Hz)

C_d = 0.7041;     % [-] Aerodynamic drag coefficient
A_f = 1.24;       % [m^2] Frontal area
C_rr = 0.02;      % [-] Rolling resistance coefficient

% pid controller tuning
% to tune controller make linearized model in simulink using the
% Input/Output tool
% Kp = ?;
% Ki = 5000;
% Kd = ?;

%Possible gains???


Kpq=(Lq*2*pi*EPWM_F)/10;
Kpd=(Ld*2*pi*EPWM_F)/10;
Kiq=Kpd*(Rs/Lq);
Kid=Kpd*(Rs/Ld);
%Kpq = 1;
%Kpd = Kpq;
%Kiq = 0;
%Kid = Kiq;
Ksq=10;
Ksd=0.1;			   
disp('Motor parameters initialized!')
