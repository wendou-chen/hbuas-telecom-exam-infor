---
name: question-extraction
description: 从原始材料中提取题目，结构化内容并转换为 LaTeX 格式
---

# Question Extraction Skill

## 功能说明
从各种来源（文本、图片、PDF）提取期末复习题目，进行结构化处理，并转换为 LaTeX 格式。

## 核心功能

### 1. 题目识别
- 自动识别题目类型（选择、填空、计算、简答、证明）
- 提取题目编号
- 分离题干和选项
- 识别答案和解析

### 2. 内容结构化
将题目转换为结构化数据：
```
{
  "type": "选择题",
  "number": "1",
  "question": "题干内容",
  "options": ["A选项", "B选项", "C选项", "D选项"],
  "answer": "A",
  "explanation": "解析内容"
}
```

### 3. LaTeX 转换
根据题目类型生成对应的 LaTeX 代码：

**选择题**：
```latex
\item 题干
\begin{enumerate}[label=(\Alph*)]
    \item 选项A
    \item 选项B
\end{enumerate}
```

**填空题**：
```latex
\item 题干 \underline{\hspace{3cm}}
```

**计算题**：
```latex
\item 题干
\textbf{解：}
```

### 4. 公式处理
- 识别数学表达式
- 转换为 LaTeX 数学模式
- 处理特殊符号（积分、求和、极限等）
- 保持公式格式正确

## 使用场景

### 场景1：从文本提取
输入：纯文本题目
输出：结构化 + LaTeX 代码

### 场景2：从现有 LaTeX 提取
输入：已有的 LaTeX 文件
输出：题目列表 + 元数据

### 场景3：批量处理
输入：多个题目文件
输出：统一格式的 LaTeX 文档

## 智能特性

### 1. 格式识别
- 自动识别题目分隔符
- 处理不规范的编号
- 适应不同的排版风格

### 2. 内容清洗
- 去除多余空白
- 统一标点符号
- 修正常见错误

### 3. 上下文理解
- 识别题目之间的关联
- 保持章节结构
- 维护题目顺序

## 输出格式

### 标准输出
```latex
\section{第一章}
\subsection{选择题}
\begin{enumerate}
\item 题目1...
\item 题目2...
\end{enumerate}

\subsection{计算题}
\begin{enumerate}
\item 题目1...
\end{enumerate}
```

## 质量控制
- 验证题目完整性
- 检查选项数量
- 确认答案存在
- 标记异常题目
