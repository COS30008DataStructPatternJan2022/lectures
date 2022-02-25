/* 
  Used in computer graphics (most drawing programs support this)
  Bézier curve: https://en.wikipedia.org/wiki/B%C3%A9zier_curve
    - see also: https://web.mit.edu/hyperbook/Patrikalakis-Maekawa-Cho/node12.html
  Recursive algo (De Casteljau's algorithm): https://en.wikipedia.org/wiki/De_Casteljau%27s_algorithm
    - see also: https://web.mit.edu/hyperbook/Patrikalakis-Maekawa-Cho/node13.html

  In Python:
  def de_casteljau(t, coefs):
    beta = [c for c in coefs] # values in this list are overridden
    n = len(beta)
    for j in range(1, n):
      for k in range(n - j):
        beta[k] = beta[k] * (1 - t) + beta[k + 1] * t
    return beta[0]
 */