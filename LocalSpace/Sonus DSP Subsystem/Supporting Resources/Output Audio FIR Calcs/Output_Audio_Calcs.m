% FIR and sample decimation
% 240 ksps -> 16 ksps, 15:1
% 15 tap FIR with increment of 15 on input data

f_cutoff = 8000;
f_sample = 240000;
time_per_sample = 1/f_sample;
number_of_taps = 60;
M = ( number_of_taps - 1 ) / 2;

h = 1:number_of_taps;

normalized_cutoff_freq = 2*pi*f_cutoff/f_sample;

n = -M:M;
h = sin(normalized_cutoff_freq.*n)./(n.*pi);
%h(M+1) = normalized_cutoff_freq / pi;

H = tf([1], h);
Hd = c2d(H, 0.5, 'zoh');

n = number_of_taps - 1;
Wn = f_cutoff/f_sample;
b = fir1(n,Wn);
fvtool(b, 1)

b_fixed = round(b .* (65535 / 2),0);

b = b.*hamming(60)';
grid on
hold on
fvtool(b, 1)

%c = Wn*sinc(Wn*(-M:M));
%fvtool(c, 1)