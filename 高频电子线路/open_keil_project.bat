@echo off
REM Keil v5 项目打开脚本
REM 使用方法: 将 .uvprojx 或 .uvproj 文件拖到此脚本上，或传入项目路径作为参数

set "KEIL_PATH=D:\Users\admin\AppData\Local\Keil_v5\UV4\UV4.exe"

if "%~1"=="" (
    echo 使用方法:
    echo   1. 将项目文件拖到此脚本上
    echo   2. 或在命令行中运行: open_keil_project.bat "项目路径.uvprojx"
    pause
    exit /b
)

set "PROJECT_PATH=%~1"

if exist "%PROJECT_PATH%" (
    echo 正在打开项目: %PROJECT_PATH%
    start "" "%KEIL_PATH%" "%PROJECT_PATH%"
    echo 项目已打开！
) else (
    echo 错误: 项目文件不存在: %PROJECT_PATH%
    pause
)
