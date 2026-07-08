import numpy as np
import matplotlib.pyplot as plt

# 1. 设置基本电路参数 (与书本例题 1-1 类似量级)
L = 10e-6    # 10 uH
C = 100e-12  # 100 pF
f0 = 1 / (2 * np.pi * np.sqrt(L * C))
w0 = 2 * np.pi * f0

# 定义频率扫描范围 (谐振点前后 50%)
f = np.linspace(0.5 * f0, 1.5 * f0, 1000)
w = 2 * np.pi * f

# 2. 定义 Q 值
Q_high, Q_low = 50, 10

# --- 并联回路仿真 ---
# Y = G + j(wC - 1/wL), G = w0*C/Q
G_high = (w0 * C) / Q_high
Y_p = G_high + 1j * (w * C - 1 / (w * L))
Z_p_norm = (1/Y_p) * G_high # 归一化阻抗

# --- 串联回路仿真 ---
# Z = R + j(wL - 1/wC), R = w0*L/Q
R_high = (w0 * L) / Q_high
Z_s = R_high + 1j * (w * L - 1 / (w * C))
I_s_norm = (R_high / Z_s)     # 归一化电流 (等同于导纳)

# 3. 绘图部分 (此处仅展示核心逻辑)
# 使用 matplotlib 生成类似书中图 1-9 的响应曲线