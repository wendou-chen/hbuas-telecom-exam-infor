# Keil v5 环境配置脚本
# 用于配置和启动 Keil v5 开发环境

$KeilPath = "D:\Users\admin\AppData\Local\Keil_v5\UV4\UV4.exe"
$KeilBasePath = "D:\Users\admin\AppData\Local\Keil_v5"

# 检查 Keil 是否已安装
if (Test-Path $KeilPath) {
    Write-Host "✓ Keil v5 已找到: $KeilPath" -ForegroundColor Green

    # 设置环境变量（可选，用于命令行工具）
    $env:KEIL_PATH = $KeilBasePath
    $env:KEIL_UV4 = $KeilPath

    Write-Host "✓ 环境变量已设置" -ForegroundColor Green
    Write-Host "  KEIL_PATH = $env:KEIL_PATH" -ForegroundColor Cyan
    Write-Host "  KEIL_UV4 = $env:KEIL_UV4" -ForegroundColor Cyan

    # 显示 Keil 版本信息（如果可能）
    $versionInfo = (Get-Item $KeilPath).VersionInfo
    Write-Host "`nKeil 版本信息:" -ForegroundColor Yellow
    Write-Host "  文件版本: $($versionInfo.FileVersion)" -ForegroundColor Cyan
    Write-Host "  产品版本: $($versionInfo.ProductVersion)" -ForegroundColor Cyan

} else {
    Write-Host "✗ 错误: 未找到 Keil v5 安装路径" -ForegroundColor Red
    Write-Host "  请检查路径: $KeilPath" -ForegroundColor Yellow
    exit 1
}

# 函数：打开 Keil 项目文件
function Open-KeilProject {
    param(
        [Parameter(Mandatory=$true)]
        [string]$ProjectPath
    )

    if (Test-Path $ProjectPath) {
        Write-Host "正在打开项目: $ProjectPath" -ForegroundColor Green
        Start-Process -FilePath $KeilPath -ArgumentList $ProjectPath
    } else {
        Write-Host "错误: 项目文件不存在: $ProjectPath" -ForegroundColor Red
    }
}

# 函数：启动 Keil IDE
function Start-Keil {
    Write-Host "正在启动 Keil v5..." -ForegroundColor Green
    Start-Process -FilePath $KeilPath
}

# 导出函数供使用
Export-ModuleMember -Function Open-KeilProject, Start-Keil

Write-Host "`n配置完成！" -ForegroundColor Green
Write-Host "使用方法:" -ForegroundColor Yellow
Write-Host "  1. 启动 Keil: Start-Keil" -ForegroundColor Cyan
Write-Host "  2. 打开项目: Open-KeilProject -ProjectPath '项目路径.uvprojx'" -ForegroundColor Cyan
