# Keil v5 运行环境配置说明

## 安装路径
```
D:\Users\admin\AppData\Local\Keil_v5\UV4\UV4.exe
```

## 配置文件说明

### 1. `keil_config.ps1` - PowerShell 配置脚本
这是一个 PowerShell 脚本，用于：
- 验证 Keil 安装路径
- 设置环境变量
- 提供便捷的函数来启动 Keil 和打开项目

**使用方法：**
```powershell
# 在 PowerShell 中运行
. .\keil_config.ps1

# 启动 Keil IDE
Start-Keil

# 打开项目文件
Open-KeilProject -ProjectPath "项目路径.uvprojx"
```

### 2. `start_keil.bat` - 快速启动脚本
双击此文件即可快速启动 Keil v5 IDE。

### 3. `open_keil_project.bat` - 项目打开脚本
用于快速打开 Keil 项目文件。

**使用方法：**
- 方法1：将 `.uvprojx` 或 `.uvproj` 文件拖到此脚本上
- 方法2：在命令行中运行：
  ```cmd
  open_keil_project.bat "项目路径.uvprojx"
  ```

## 环境变量配置（可选）

如果需要将 Keil 添加到系统环境变量中，可以：

1. **临时设置（当前会话）：**
   ```powershell
   $env:KEIL_PATH = "D:\Users\admin\AppData\Local\Keil_v5"
   $env:KEIL_UV4 = "D:\Users\admin\AppData\Local\Keil_v5\UV4\UV4.exe"
   ```

2. **永久设置（系统环境变量）：**
   - 打开"系统属性" → "高级" → "环境变量"
   - 添加以下变量：
     - `KEIL_PATH` = `D:\Users\admin\AppData\Local\Keil_v5`
     - `KEIL_UV4` = `D:\Users\admin\AppData\Local\Keil_v5\UV4\UV4.exe`

## 项目文件位置

在你的工作目录中，我发现了以下 Keil 项目文件：

1. `课外拓展课程设计任务书和参考资料\驱动模块\fd2c4-main\fd2c4-main\CMT2300A_DemoEasy_v1.1\CMT2300A_DemoEasy\MDK-ARM\CMT2300A_DemoEasy.uvprojx`
2. `课外拓展课程设计任务书和参考资料\YX67329-CMT2300A-433M-LoRa无线收发-20190517\CMT2300A\参考代码\CMT2300_N76E003\CMT2300_SI7021\V1\Soft\GPIO.uvproj`

## 快速打开项目示例

```powershell
# 使用 PowerShell 脚本
. .\keil_config.ps1
Open-KeilProject -ProjectPath "课外拓展课程设计任务书和参考资料\驱动模块\fd2c4-main\fd2c4-main\CMT2300A_DemoEasy_v1.1\CMT2300A_DemoEasy\MDK-ARM\CMT2300A_DemoEasy.uvprojx"
```

或者直接使用批处理文件：
```cmd
open_keil_project.bat "课外拓展课程设计任务书和参考资料\驱动模块\fd2c4-main\fd2c4-main\CMT2300A_DemoEasy_v1.1\CMT2300A_DemoEasy\MDK-ARM\CMT2300A_DemoEasy.uvprojx"
```

## 常见问题

### 1. 如果 Keil 路径发生变化
修改以下文件中的路径：
- `keil_config.ps1` 中的 `$KeilPath` 变量
- `start_keil.bat` 中的 `KEIL_PATH` 变量
- `open_keil_project.bat` 中的 `KEIL_PATH` 变量

### 2. 权限问题
如果遇到权限问题，请以管理员身份运行脚本。

### 3. 中文路径问题
如果项目路径包含中文，确保使用 UTF-8 编码保存脚本文件。

## 下一步

1. 运行 `start_keil.bat` 验证 Keil 是否可以正常启动
2. 尝试打开一个项目文件验证配置是否正确
3. 根据需要调整配置脚本中的路径
