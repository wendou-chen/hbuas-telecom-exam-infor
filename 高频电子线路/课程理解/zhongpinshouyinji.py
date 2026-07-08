import numpy as np

# 1. 定义参数
f0 = 465e3      # 频率 465 kHz
B = 8e3         # 带宽 8 kHz
C = 200e-12     # 电容 200 pF
Q0 = 100        # 空载 Q 值

# 2. 计算电感 L
omega0 = 2 * np.pi * f0
L = 1 / (omega0**2 * C)

# 3. 计算有载 QL
QL = f0 / B

# 4. 计算并联电阻 Rx
# 特性阻抗 rho
rho = 1 / (omega0 * C)

# 空载并联等效电阻 Rp0
Rp0 = Q0 * rho

# 有载总并联电阻 R_total
R_total = QL * rho

# 计算需并联的外部电阻 Rx (1/R_total = 1/Rp0 + 1/Rx)
Gx = 1/R_total - 1/Rp0
Rx = 1/Gx

# 5. 输出结果
print(f"1. 回路电感 L: {L*1e6:.2f} μH")
print(f"2. 有载品质因数 QL: {QL:.3f}")
print(f"3. 特性阻抗 rho: {rho:.2f} Ω")
print(f"4. 线圈内阻 Rp0: {Rp0/1000:.2f} kΩ")
print(f"5. 总并联电阻 R_total: {R_total/1000:.2f} kΩ")
print(f"6. 需并联的电阻 Rx: {Rx/1000:.2f} kΩ")