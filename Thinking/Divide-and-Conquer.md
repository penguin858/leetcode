---
title: Divide and Conquer
date: 2020-01-02 15:55:18
tags:
---

<!-- toc -->

<!-- more -->

# 1.Master Theorem

It provides an asymptotic analysis for recurrence relations in Divide and Conquer algorithms by big O notation.

> $T(n) = a T(\frac{n}{b}) + f(n)$
> 
> 1. If $f(n) = O(n^{(\log_b{a}) - \epsilon}, \epsilon > 0$, then $T(n) = \Theta(n^{\log_b a})$
> 2. If $f(n) = \Theta(n^{\log_b a} \log^k n)$, then $T(n) = \Theta(n^{\log_b a} \log^{k+1} n)$
> 3. If $f(n) = \Omega(n^{(\log_b a) + \epsilon} )$ , and for big n, $\exists c < 1, af(\frac{n}{b}) \leq cf(n)$, then $T(n) = \Theta(f(n))$



