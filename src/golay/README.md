# golay_24_12_8

> 参考： "Coding Theory The Essentials - D.G Hoffman.pdf" P85

## encode

1. $codeword = msg * \begin{bmatrix} I & B \end{bmatrix}$

## decode

1. 计算 $s = codeword * \begin{bmatrix} I \\ B \end{bmatrix}$
2. 如果 $weight(s) <= 3$，则 $e = \begin{bmatrix} s & 0 \end{bmatrix}$
3. 否则，计算 $s + b_i$，如果 ${weight(s + b_i) <= 2}$，则 $e = \begin{bmatrix} s + b_i & e_i \end{bmatrix}$（$e_i$ ）
4. 计算 $s = codeword * \begin{bmatrix} B \\ I \end{bmatrix}$
5. 如果 $weight(s) <= 3$，则 $e = \begin{bmatrix} 0 & s \end{bmatrix}$
6. 否则，计算 $s + b_i$，如果 ${weight(s + b_i) <= 2}$，则 $e = \begin{bmatrix} e_i & s + b_i \end{bmatrix}$

$e$：错误图样

$b_i$：表示 B 中的第 i 行

$e_i$：表示第 i 位为 1，其余位为 0，长度为 k 的行向量