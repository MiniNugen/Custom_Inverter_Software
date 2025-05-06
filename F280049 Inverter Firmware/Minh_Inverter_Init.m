clc
clear


%% Motor Parameters
mVolt = 95;         % [V] Max Continuous voltage
mCurr = 150;        % [A] Max Continous Current
mrot = 20;          % [kg] Rotor mass
ppair= 4;           % [-] Pole pair
Rpp = 0.013;        % [Ohm] Phase-Phase Winding resistance
Rs=(Rpp^2)/(Rpp*3); % [Ohm] Stator phase resistance assuming Rpp is uniform
Ld = 0.1e-3;        % [H] Direct-axis inductance (phase to phase)
Lq = Ld;            % [H] Quadrature-axis inductance (SPMSM assumption)
lambda = 0.0375;    % [Wb] Permanent magnet flux linkage
rpm_max = 5000;                             % [RPM] Max rate rotor RPM
speed_max=rpm_max*2*pi/60;                  % [Rad/s] Max rated speed for the motor
PhaseA_offset = -17.5;                      % [Deg] Offset angle between phase A and the encoder's 0 degree (theta-PhaseA)
Encoder_Offset = 0;                    % [Rad] Translates PhaseA_offset to account for how we define the 

%% Car parameters
m = 1;              % [kg] Vehicle mass
r = 0.4064/2;       % [m] Wheel radius (diameter/2)
rho = 1.2;          % [kg/m^3] Air density
% Don't have this number Ke = 0.0135281; % Back-EMF constant [V*Sec/rad]
Kt = 0.15;          % [Nm/A] Torque Const
k = 1;              % [-] Gear ratio (wheel speed to motor speed)
g = 9.8;            % [m/s^2] Gravitational acceleration
J = mrot*r^2/k^2 + 0.0045;  % Drive inertia [kg*m^2]
f = 3.03448e-4;     %viscous friction coefficient



%% inverter parameters
V_bat = 24 * 3.6;                   % [V] Battery voltage (24 cells * 3.6V nominal per cell);
InvCurr=30;                         % [A] Max inverter power Draw
Current_max =min(InvCurr,mCurr);    % [A] Max Allowable current draw.
Voltage_max = min(V_bat,mVolt);     % [V] max allowable voltage output

Torque_max = Current_max*3*lambda*ppair/2;  %max torque current can generate [Nm]
EPWM_F = 200000;                            % [Hz] EPWM switching frequency

C_d = 0.7041;     % [-] Aerodynamic drag coefficient
A_f = 1.24;       % [m^2] Frontal area
C_rr = 0.02;      % [-] Rolling resistance coefficient

%% PI and PD Tuning (Test)
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
