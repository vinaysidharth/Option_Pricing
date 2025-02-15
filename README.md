# BAPM vs Black-Scholes Model Comparison

This repository provides a comparative analysis of the **Behavioral Asset Pricing Model (BAPM)** and the **Black-Scholes Model** for option pricing. The goal is to highlight key differences, assumptions, and practical applications of both models.

## Overview

### Black-Scholes Model
- **Purpose**: Prices European-style options using a closed-form solution.
- **Assumptions**:
  - Constant volatility and risk-free rate.
  - No dividends during the option's life.
  - Log-normal distribution of stock prices.
  - Efficient markets (no behavioral biases).
- **Formula**:
  \[
  C = S_0 N(d_1) - X e^{-rT} N(d_2)
  \]
  Where \( d_1 = \frac{\ln(S_0/X) + (r + \sigma^2/2)T}{\sigma \sqrt{T}} \), \( d_2 = d_1 - \sigma \sqrt{T} \).

### Behavioral Asset Pricing Model (BAPM)
- **Purpose**: Extends traditional pricing by incorporating investor psychology and market sentiment.
- **Assumptions**:
  - Investors exhibit behavioral biases (e.g., overconfidence, herd behavior).
  - Market prices reflect both rational and irrational behavior.
  - Volatility is influenced by sentiment shifts.

## Key Differences

| Feature                | Black-Scholes                          | BAPM                                   |
|------------------------|----------------------------------------|----------------------------------------|
| **Market Assumption**  | Efficient markets                     | Markets include irrational behavior   |
| **Volatility**         | Constant                              | Time-varying (behavior-driven)        |
| **Complexity**         | Simple, closed-form solution          | Complex, requires sentiment analysis  |
| **Empirical Validity** | Works well in stable markets          | Better in volatile/bubbly markets     |
| **Use Case**           | Standard options pricing              | Behavioral finance research           |
