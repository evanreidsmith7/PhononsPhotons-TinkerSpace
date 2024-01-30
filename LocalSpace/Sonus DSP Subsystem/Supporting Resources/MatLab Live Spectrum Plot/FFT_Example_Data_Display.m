
% MatLab 2021 compatible

ADC_CHANNELS = 6;
FFT_BATCH_SIZE = 512;

% Hard coded COM port selection
% "COMxx" should be the stlink virtual com port device
clear com_port;
com_port = serialport("COM13",4000000, 'timeout', 200.0);
% pc com15

x_freqs = 2 * 120/(FFT_BATCH_SIZE / 2):120/(FFT_BATCH_SIZE / 2):240/2 - 120/(FFT_BATCH_SIZE / 2);
start_bytes = 0;

noise_floor = zeros(1, FFT_BATCH_SIZE / 2) - 100;

noise_floor_samples = 0;
noise_floor_offset_db = 3;

while ( 1 )
    %sync with data
    start_bytes = 0;
    while (start_bytes < 4)
        start_byte = read( com_port, 1, "uint8" );
        if ( start_byte == 0x55 )
            start_bytes = start_bytes + 1;
        else
            start_bytes = 0;
        end
    end
    
    fft_data = read( com_port, ADC_CHANNELS * FFT_BATCH_SIZE / 2, "single" );
    fft_one = fft_data(1:256);
    fft_two = fft_data(257:512);
    fft_thr = fft_data(513:768);
    fft_fou = fft_data(769:1024);
    fft_fiv = fft_data(1025:1280);
    fft_six = fft_data(1281:1536);
    
    if ( noise_floor_samples < 20 )
       for index = 1 : FFT_BATCH_SIZE / 2
           if fft_one(index) > noise_floor(index)
               noise_floor(index) = fft_one(index);
           end
           if fft_two(index) > noise_floor(index)
               noise_floor(index) = fft_two(index);
           end
           if fft_thr(index) > noise_floor(index)
               noise_floor(index) = fft_thr(index);
           end
           if fft_fou(index) > noise_floor(index)
               noise_floor(index) = fft_fou(index);
           end
           if fft_fiv(index) > noise_floor(index)
               noise_floor(index) = fft_fiv(index);
           end
           if fft_six(index) > noise_floor(index)
               noise_floor(index) = fft_six(index);
           end
       end        
       noise_floor_samples = noise_floor_samples + 1;
    end
    
    clf;
    hold on
    grid on
    ylim([-100 20]);
    xlim([0 120]);
    xlabel("Frequency (kHz)", 'FontSize', 16);
    ylabel("Magnitude (dBV)", 'FontSize',  16);
    plot( x_freqs, fft_one(3:256), 'LineWidth', 2);
    plot( x_freqs, fft_two(3:256), 'LineWidth', 2); 
    plot( x_freqs, fft_thr(3:256), 'LineWidth', 2);
    plot( x_freqs, fft_fou(3:256), 'LineWidth', 2); 
    plot( x_freqs, fft_fiv(3:256), 'LineWidth', 2); 
    plot( x_freqs, fft_six(3:256), 'LineWidth', 2); 
    plot( x_freqs, noise_floor(3:256) + 6, "--k", 'LineWidth', 2);
    legend("One", "Two", "Three", "Four", "Five", "Six", "Trigger Threshold", 'FontSize',  16);
    
end

clear com_port