# STM32F103VC 到 STM32F103C8 迁移分析报告

## 📋 当前工程配置状态分析

### ✅ 已正确配置为 STM32F103C8 的项目

经过详细分析，**当前工程已经配置为 STM32F103C8**，具体如下：

#### 1. Keil 项目文件配置 (.uvprojx)
- **设备型号**: `STM32F103C8` ✓
- **预处理器定义**: `STM32F10X_MD,USE_STDPERIPH_DRIVER` ✓
- **启动文件**: `startup_stm32f10x_md.s` ✓
- **内存配置**:
  - Flash (IROM): `0x08000000, 0x00010000` (64KB) ✓
  - RAM (IRAM): `0x20000000, 0x00005000` (20KB) ✓

#### 2. 链接脚本配置 (.sct)
```
LR_IROM1 0x08000000 0x00010000  {    ; 64KB Flash
  ER_IROM1 0x08000000 0x00010000  {
   *.o (RESET, +First)
   ...
  }
  RW_IRAM1 0x20000000 0x00005000  {  ; 20KB RAM
   .ANY (+RW +ZI)
  }
}
```
✓ 配置正确

#### 3. 启动文件
- 使用: `startup_stm32f10x_md.s` (Medium Density) ✓
- 未使用: `startup_stm32f10x_hd.s` (High Density，对应 VC)

---

## 🔍 STM32F103VC vs STM32F103C8 对比

### 芯片规格对比

| 特性 | STM32F103VC (HD) | STM32F103C8 (MD) |
|------|------------------|------------------|
| **Flash 容量** | 256 KB | 64 KB |
| **RAM 容量** | 48 KB | 20 KB |
| **引脚数** | 100 引脚 (LQFP100) | 48 引脚 (LQFP48) |
| **GPIO 数量** | 80 个 | 37 个 |
| **定时器** | TIM1-8 | TIM1-4 |
| **USART** | USART1-5 | USART1-3 |
| **SPI** | SPI1-3 | SPI1-2 |
| **I2C** | I2C1-2 | I2C1-2 |
| **ADC** | ADC1-2 (16通道) | ADC1 (10通道) |
| **DMA** | DMA1 (7通道) + DMA2 (5通道) | DMA1 (7通道) |
| **CAN** | CAN1-2 | CAN1 |
| **USB** | USB OTG FS | USB Device |
| **FSMC** | ✓ | ✗ |
| **密度类型** | High Density (HD) | Medium Density (MD) |
| **预处理器宏** | `STM32F10X_HD` | `STM32F10X_MD` |
| **启动文件** | `startup_stm32f10x_hd.s` | `startup_stm32f10x_md.s` |

### 内存映射对比

#### STM32F103VC (HD)
- **Flash**: 0x08000000 - 0x0803FFFF (256 KB)
- **RAM**: 0x20000000 - 0x2000BFFF (48 KB)

#### STM32F103C8 (MD)
- **Flash**: 0x08000000 - 0x0800FFFF (64 KB)
- **RAM**: 0x20000000 - 0x20004FFF (20 KB)

---

## ✅ 配置验证清单

### 1. Keil 项目配置检查

**位置**: `CMT2300A_DemoEasy.uvprojx`

- [x] Device 设置为 `STM32F103C8`
- [x] 预处理器定义包含 `STM32F10X_MD`
- [x] 启动文件使用 `startup_stm32f10x_md.s`
- [x] IROM1 设置为 `0x08000000, 0x00010000` (64KB)
- [x] IRAM1 设置为 `0x20000000, 0x00005000` (20KB)

### 2. 链接脚本检查

**位置**: `CMT2300A_DemoEasy.sct`

- [x] Flash 区域: `0x08000000, 0x00010000` (64KB)
- [x] RAM 区域: `0x20000000, 0x00005000` (20KB)

### 3. 代码配置检查

**需要检查的文件**:
- `stm32f10x.h` - 确保通过预处理器定义 `STM32F10X_MD`
- `system_stm32f10x.c` - 系统时钟配置
- `stm32f10x_conf.h` - 外设库配置

---

## 🔧 如果发现 VC 配置的修复方法

### 方法 1: 修改 Keil 项目文件

1. **打开项目**: `CMT2300A_DemoEasy.uvprojx`
2. **修改设备**:
   - Options for Target → Device → 选择 `STM32F103C8`
3. **修改预处理器定义**:
   - Options for Target → C/C++ → Preprocessor Symbols
   - 确保有: `STM32F10X_MD,USE_STDPERIPH_DRIVER`
   - 移除: `STM32F10X_HD` (如果有)
4. **修改启动文件**:
   - 在项目树中，移除 `startup_stm32f10x_hd.s`
   - 添加 `startup_stm32f10x_md.s`
   - 路径: `Libraries\STM32F10x_StdPeriph_DriverFWLib3.5\Startup\startup_stm32f10x_md.s`
5. **修改内存配置**:
   - Options for Target → Target
   - IROM1: `0x08000000, 0x00010000` (64KB)
   - IRAM1: `0x20000000, 0x00005000` (20KB)

### 方法 2: 手动修改配置文件

如果项目文件已损坏或需要批量修改，可以：

1. **修改 .uvprojx 文件**:
   ```xml
   <Device>STM32F103C8</Device>
   <Define>STM32F10X_MD,USE_STDPERIPH_DRIVER</Define>
   <Cpu>IRAM(0x20000000,0x00005000) IROM(0x08000000,0x00010000)</Cpu>
   ```

2. **修改启动文件引用**:
   ```xml
   <FileName>startup_stm32f10x_md.s</FileName>
   <FilePath>.\startup_stm32f10x_md.s</FilePath>
   ```

---

## ⚠️ 注意事项

### 1. 外设限制
STM32F103C8 相比 VC 缺少以下外设：
- **TIM5-8**: 高级定时器和通用定时器
- **USART4-5**: 串口
- **SPI3**: SPI 接口
- **ADC2**: ADC 通道
- **DMA2**: DMA 控制器
- **CAN2**: CAN 总线
- **FSMC**: 外部存储器接口

**如果代码中使用了这些外设，需要修改或移除相关代码。**

### 2. 内存限制
- **Flash**: 64KB (VC 是 256KB)
- **RAM**: 20KB (VC 是 48KB)

**需要确保代码大小不超过这些限制。**

### 3. GPIO 限制
- C8 只有 37 个 GPIO，VC 有 80 个
- **需要检查引脚定义，确保使用的引脚在 C8 上存在**

---

## 📝 验证步骤

### 步骤 1: 编译检查
1. 打开 Keil 项目
2. 执行 Clean Target
3. 执行 Rebuild All
4. 检查编译输出，确认：
   - 使用 `startup_stm32f10x_md.s`
   - 预处理器定义包含 `STM32F10X_MD`
   - 没有内存溢出错误

### 步骤 2: 内存使用检查
查看编译后的 `.map` 文件，确认：
- 代码大小 < 64KB
- RAM 使用 < 20KB

### 步骤 3: 功能测试
- 基本功能测试
- 外设功能测试
- 确保没有使用 C8 不支持的外设

---

## 📚 相关文件位置

```
CMT2300A_DemoEasy/
├── MDK-ARM/
│   ├── CMT2300A_DemoEasy.uvprojx    # Keil 项目文件
│   └── Obj/
│       └── CMT2300A_DemoEasy.sct     # 链接脚本
└── Libraries/
    └── STM32F10x_StdPeriph_DriverFWLib3.5/
        ├── Startup/
        │   ├── startup_stm32f10x_md.s  # C8 启动文件 ✓
        │   └── startup_stm32f10x_hd.s  # VC 启动文件 ✗
        └── M3/
            └── stm32f10x.h             # 设备头文件
```

---

## 🎯 结论

**当前工程已经正确配置为 STM32F103C8**，所有关键配置都已正确：
- ✅ 设备型号: STM32F103C8
- ✅ 预处理器定义: STM32F10X_MD
- ✅ 启动文件: startup_stm32f10x_md.s
- ✅ 内存配置: 64KB Flash, 20KB RAM

**如果调试时遇到问题，可能是：**
1. 代码中使用了 C8 不支持的外设
2. 内存使用超出限制
3. GPIO 引脚配置不正确
4. 其他硬件相关的问题

**建议下一步：**
1. 检查代码中是否使用了 C8 不支持的外设
2. 验证内存使用情况
3. 检查 GPIO 引脚定义
4. 进行功能测试
