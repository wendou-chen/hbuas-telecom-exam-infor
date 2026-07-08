import numpy as np
import matplotlib.pyplot as plt
from numpy.fft import fft, fftfreq

# 参数设置
fs = 10000       # 采样率
T = 0.5          # 时间长度
t = np.linspace(0, T, int(fs*T), endpoint=False)
f_sig = 5        # 基带信号频率 5Hz
f_c = 100        # 载波频率 100Hz

# 1. 信号定义
v_in = np.cos(2 * np.pi * f_sig * t)            # 输入信号
carrier_sin = np.cos(2 * np.pi * f_c * t)       # 正弦载波
carrier_sq = np.sign(np.cos(2 * np.pi * f_c * t)) # 开关函数 K(t) (+1/-1)

# 2. 调制过程
v_out_analog = v_in * carrier_sin               # 模拟乘法
v_out_switch = v_in * carrier_sq                # 开关调制 (AD630)

# 3. 频域分析
def get_spectrum(signal):
    yf = fft(signal)
    xf = fftfreq(len(signal), 1/fs)
    return xf[:len(signal)//2], 2.0/len(signal) * np.abs(yf[0:len(signal)//2])

freqs, spec_analog = get_spectrum(v_out_analog)
_, spec_switch = get_spectrum(v_out_switch)

# 4. 绘图
fig, (ax1, ax2) = plt.subplots(2, 1, figsize=(10, 8))

# 时域图
ax1.set_title('时域波形对比 (Time Domain)')
ax1.plot(t[:500], v_out_analog[:500], label='模拟乘法 (Analog)', alpha=0.8)
ax1.plot(t[:500], v_out_switch[:500] + 2.5, label='开关调制 (Switching/AD630)', color='red')
ax1.text(0.02, 3.5, '注意：开关调制不仅改变极性，\n还保持了包络的完整幅度', color='red')
ax1.legend(loc='upper right')
ax1.set_xlabel('Time (s)')
ax1.grid(True)

# 频域图
ax2.set_title('频谱对比 (Frequency Domain)')
ax2.plot(freqs, spec_analog, label='模拟乘法频谱', linewidth=2)
ax2.plot(freqs, spec_switch, label='开关调制频谱', alpha=0.7, color='red')
ax2.set_xlim(0, 600)
ax2.set_xlabel('Frequency (Hz)')
ax2.legend()
ax2.grid(True)

# 标注关键谐波
ax2.annotate('基波搬移 $f_c$', xy=(100, 0.5), xytext=(120, 0.8), arrowprops=dict(facecolor='black', shrink=0.05))
ax2.annotate('3次谐波 $3f_c$', xy=(300, 0.17), xytext=(320, 0.4), arrowprops=dict(facecolor='red', shrink=0.05))
ax2.annotate('5次谐波 $5f_c$', xy=(500, 0.1), xytext=(520, 0.3), arrowprops=dict(facecolor='red', shrink=0.05))
ax2.text(200, 0.6, "AD630 引入了奇次谐波\n(需要 LPF 滤除)", color='red', fontweight='bold')

plt.tight_layout()
plt.show()