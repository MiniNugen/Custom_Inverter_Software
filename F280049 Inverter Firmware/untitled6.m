t=I_ABC.Time;
IA = I_ABC.Data(:,1);

%% Fourier transform of IA(t)
% Inputs expected in workspace:
%   t  - time vector in seconds (Nx1 or 1xN)
%   IA - data vector, same length as t

t  = t(:);
IA = IA(:);
assert(numel(t) == numel(IA), 't and IA must have the same length');

Fs   = 1/median(diff(t));      % sampling frequency (Hz)
N    = length(IA);
w    = hann(N);                % Hann window
IA_w = IA .* w;                % apply window

Nfft = 2^nextpow2(N);          % zero-pad to next power of 2
X    = fft(IA_w, Nfft) / sum(w); % normalize by window sum (amplitude-correct)
f    = (0:Nfft/2-1).' * (Fs / Nfft);

mag  = 2 * abs(X(1:Nfft/2));   % single-sided magnitude

figure('Color','w');
plot(f, mag, 'LineWidth', 1);
xlabel('Frequency (Hz)');
ylabel('|X(f)|');
title('Single-Sided Amplitude Spectrum of IA(t)');
grid on;

% ---- Optional: dB scale (comment/uncomment) -----------------------------
% figure('Color','w');
% plot(f, 20*log10(mag + eps), 'LineWidth', 1);
% xlabel('Frequency (Hz)');
% ylabel('Magnitude (dB)');
% title('Single-Sided Amplitude Spectrum of IA(t) [dB]');
% grid on;

% ---- Optional: show two-sided (fftshift) -------------------------------
% f2   = (-Nfft/2:Nfft/2-1).' * (Fs / Nfft);
% X2   = fftshift(fft(IA_w, Nfft)) / sum(w);
% figure('Color','w');
% plot(f2, abs(X2), 'LineWidth', 1);
% xlabel('Frequency (Hz)');
% ylabel('|X(f)|');
% title('Two-Sided Spectrum (shifted)');
% grid on;
