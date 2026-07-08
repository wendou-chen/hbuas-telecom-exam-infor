---
name: latex-code-generation
description: 生成标准 LaTeX 代码结构，支持常见环境和中文排版
---

# LaTeX Code Generation Skill

## 功能说明
自动生成符合规范的 LaTeX 代码，适配期末复习文档的常见需求。

## 核心功能

### 1. 文档框架生成
生成完整的 LaTeX 文档结构：
```latex
\documentclass[12pt,a4paper]{ctexart}
\usepackage{amsmath,amssymb}
\usepackage{geometry}
\geometry{left=2.5cm,right=2.5cm,top=2.5cm,bottom=2.5cm}
\title{标题}
\author{作者}
\date{\today}
\begin{document}
\maketitle
\tableofcontents
% 内容
\end{document}
```

### 2. 题目环境生成
- **选择题**：使用 enumerate 环境
- **填空题**：使用自定义命令
- **计算题**：结合 equation 环境
- **简答题**：使用 itemize 或段落

### 3. 数学公式
- 行内公式：`$...$`
- 行间公式：`\[...\]` 或 `equation` 环境
- 多行公式：`align`, `gather` 环境
- 矩阵：`matrix`, `pmatrix`, `bmatrix`

### 4. 专业内容
- **电路图**：使用 circuitikz
- **信号图**：使用 tikz 或 pgfplots
- **代码块**：使用 listings 或 minted

## 使用示例

### 生成选择题
输入：题干 + 4个选项 + 答案
输出：
```latex
\begin{enumerate}
\item 题干内容
\begin{enumerate}[label=(\Alph*)]
    \item 选项A
    \item 选项B
    \item 选项C
    \item 选项D
\end{enumerate}
\textbf{答案：}A
\end{enumerate}
```

### 生成公式
输入：数学表达式描述
输出：
```latex
\begin{equation}
    f(x) = \int_{0}^{\infty} e^{-x^2} dx
\end{equation}
```

## 适配现有模板
基于项目中已有的 LaTeX 文件风格：
- 使用 ctexart 文档类
- 保持一致的宏包引用
- 遵循现有的格式约定
- 复用自定义命令

## 质量保证
- 确保代码可编译
- 检查括号匹配
- 验证环境闭合
- 处理特殊字符转义
