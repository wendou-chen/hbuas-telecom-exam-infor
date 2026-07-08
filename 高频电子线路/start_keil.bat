@echo off
REM Keil v5 快速启动脚本
REM 双击此文件即可启动 Keil v5

set "KEIL_PATH=D:\Users\admin\AppData\Local\Keil_v5\UV4\UV4.exe"

if exist "%KEIL_PATH%" (
    echo 正在启动 Keil v5...
    start "" "%KEIL_PATH%"
    echo Keil v5 已启动！
) else (
    echo 错误: 未找到 Keil v5 安装路径
    echo 请检查路径: %KEIL_PATH%
    pause
)
