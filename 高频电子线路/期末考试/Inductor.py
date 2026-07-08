import numpy as np
import matplotlib.pyplot as plt

# 1. 设置参数
f = 1           # 频率 1Hz
omega = 2*np.pi*f
t = np.linspace(0, 2, 1000)

# 2. 定义电流 (正弦波)
i_t = np.sin(omega * t)

# 3. 模拟电感电压 v = L * di/dt
# 这里为了演示数学原理，我们设定 L=1
# 正弦的导数是余弦: di/dt = omega * cos(omega * t)
v_t_theory = omega * np.cos(omega * t)

# 4. 数值求导 (工程验证)
dt = t[1] - t[0]
v_t_numerical = np.gradient(i_t, dt)

# 5. 绘图
plt.figure(figsize=(10, 6))
plt.plot(t, i_t, label='Current i(t) = sin(wt)', linewidth=2)
# 也就是 v(t)
plt.plot(t, v_t_theory, label='Voltage v(t) = w*cos(wt)', linestyle='--', linewidth=2)

plt.title(f'Inductor Physics: v(t) leads i(t) by 90 degrees\n(The physical meaning of "j")', fontsize=12)
plt.xlabel('Time (s)')
plt.ylabel('Amplitude')
plt.grid(True)
plt.legend()
plt.annotate('Voltage Peaks first!', xy=(0, 1), xytext=(0.2, 1.2),
             arrowprops=dict(facecolor='black', shrink=0.05))

plt.show()