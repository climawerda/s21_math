#include "s21_math.h"

// ######################### ventureb #########################

long double s21_fmod(double x, double y) {
  long double result = x;
  if (x == MAX_INF || x == MIN_INF || x != x || y != y || y == 0) {
    result = MAX_NAN;
  } else if (y == MAX_INF || y == MIN_INF || x == 0) {
    result = x;
  } else {
    if (y < 0) {
      y = -y;
    }
    result = s21_fabs(x);
    result = result - s21_trunc(result / y) * y;
    if (x < 0) {
      result = -result;
    }
  }
  return result;
}

long double s21_ceil(double x) {
  long double result;
  if (x == MAX_INF || x == MIN_INF || x != x) {
    result = x;
  } else {
    long double intpart = (long double)((long long)x);
    result = x - intpart;
    if (result > 0.0) {
      result = intpart + 1;
    } else {
      result = intpart;
    }
  }
  return result;
}

long double s21_floor(double x) {
  long double result;
  if (x == MAX_INF || x == MIN_INF || x != x) {
    result = x;
  } else {
    long double intpart = (long double)((long long)x);
    result = x - intpart;
    if (result >= 0.0) {
      result = intpart;
    } else {
      result = intpart - 1;
    }
  }
  return result;
}

long double s21_sqrt(double x) {
  long double result;
  if (x < 0) {
    result = MAX_NAN;
  } else {
    result = s21_pow(x, 0.5);
  }
  return result;
}

long double s21_exp(double x) {
  long double result = 1.0;
  long double sum = 1.0;
  long double i = 1.0;
  if (x == MIN_INF) {
    sum = 0;
  } else if (x == MAX_INF) {
    sum = MAX_INF;
  } else if (x != x) {
    sum = MAX_NAN;
  } else {
    while (s21_fabs(result) > EPS_24) {
      result = result * x / i;
      i += 1.0;
      sum += result;
      if (sum > S21_MAX_DOUBLE) {
        sum = MAX_INF;
        if (x < 0) {
          sum = 1 / sum;
        }
        break;
      }
    }
  }
  return sum;
}

// ######################### grangerc #########################

long double s21_pow(double base, double exp) {
  long double result = 0;
  if (base == MIN_INF && exp == exp) {
    if (exp < 0) {
      result = 0;
    } else if (exp == 0) {
      result = 1;
    } else if (s21_fmod(exp, 2) == 1) {
      result = MIN_INF;
    } else {
      result = MAX_INF;
    }
  } else if (exp == MIN_INF && base < 0) {
    if (s21_fabs(base) == 1) {
      result = 1;
    } else if (base > -1) {
      result = MAX_INF;
    } else {
      result = 0;
    }
  } else if (exp == MAX_INF && base < 0) {
    if (s21_fabs(base) == 1) {
      result = 1;
    } else if (base > -1) {
      result = 0;
    } else {
      result = MAX_INF;
    }
  } else if (exp == 0 || base == 1) {
    result = 1;
  } else if (base == -1) {
    if (exp == MAX_INF || s21_fmod(exp, 2) == 0) {
      result = s21_fabs(base);
    } else if (exp == (long long int)exp) {
      result = base;
    } else
      result = MAX_NAN;
  } else if (base < 0 && !(base == MIN_INF) &&
             (exp != (long long int)exp && exp != MAX_INF)) {
    result = MAX_NAN;
  } else {
    result = s21_exp(s21_fabs(exp) * s21_log(s21_fabs(base)));
    if (exp < 0) {
      result = 1. / result;
    }
    if (base < 0)
      if (s21_fmod(exp, 2) != 0) result = -result;

    if (result == MAX_INF) {
      if ((exp == MAX_INF) || s21_fmod(exp, 2) == 0 ||
          exp != (long long int)exp) {
        result = s21_fabs(result);
      }
    }
  }
  return result;
}

long double s21_asin(double x) {
  long double term = x, result = MAX_NAN;
  if (-1.0 < x && x < 1.0) {
    result = term;
    x *= x;
    for (int k = 1; s21_fabs((double)term) > EPS_6; k += 2) {
      result += (term *= x * k / (k + 1)) / (k + 2);
    }
  } else if (x == 1.0) {
    result = S21_PI / 2.0;
  } else if (x == -1.0) {
    result = -S21_PI / 2.0;
  }
  return result;
}

long double s21_atan(double x) {
  long double result = 0;
  if (x == MAX_INF) {
    result = S21_PI / 2;
  } else if (x == MIN_INF) {
    result = -S21_PI / 2;
  } else {
    result = s21_asin(x / s21_sqrt(1 + x * x));
  }
  return result;
}

long double s21_acos(double x) {
  long double result = MAX_NAN;
  if (x <= 1 && x >= -1) {
    result = (S21_PI / 2) - s21_asin(x);
  }
  return result;
}

long double s21_log(double x) {
  double result = 0;
  double prev_result = 0;
  int count = 0;
  if (x == MAX_INF) {
    result = x;
  } else if (x == 0) {
    result = MIN_INF;
  } else if (x == 1) {
    result = 0;
  } else if (x < 0 || x == MIN_INF) {
    result = MAX_NAN;
  } else if (x != MAX_INF && x != 0 && x != 1 && !(x < 0 || x == MIN_INF)) {
    while (x >= S21_E) {
      x /= S21_E;
      count++;
    }
    // x -= 1;  //так как ряд Тейлора для ln(1 + x)
    for (int i = 1; i < 1000; i++) {
      // result += minus * s21_pow_int(x, i) / i;
      // minus *= -1;
      prev_result = result;
      result = prev_result +
               2 * (x - s21_exp(prev_result)) / (x + s21_exp(prev_result));
    }
    result += count;
  }
  return result;
}

// ######################### migdalia #########################

int s21_abs(int x) {
  int result = x;
  if (x < 0) {
    result = -x;
  }
  return result;
}

long double s21_fabs(double x) {
  long double result = x;
  if (x == MAX_INF || x == MIN_INF) {
    result = MAX_INF;
  } else if (x < 0) {
    result = -x;
  }
  return result;
}

long double s21_sin(double x) {
  double eps = 1.0 / 1000000000000000.0;  // 1e-15
  int sign = (x < 0) ? -1 : 1;
  x = s21_fmod(s21_fabs(x), 2 * S21_PI);  // Приводим к [0, 2*pi]
  if (x > S21_PI) {
    x -= S21_PI;  // Приводим к [0, pi]
    sign *= -1;
  }
  if (x > S21_PI / 2) {
    x = S21_PI - x;  // Приводим к [0, pi/2]
  }
  double t = x, result = x;
  for (int n = 3; s21_fabs(t) > eps; n += 2) {
    t = -t * x * x / n / (n - 1);
    result = result + t;
  }
  return result * sign;
}

long double s21_cos(double x) {
  double eps = 1.0 / 1000000000000000.0;  // 1e-15
  x = s21_fmod(s21_fabs(x), 2 * S21_PI);
  double t = 1, result = 1;
  for (int n = 1; s21_fabs(t) > eps; n += 1) {
    t = -t * x * x / ((2 * n - 1) * (2 * n));
    result = result + t;
  }
  return result;
}

long double s21_tan(double x) {
  long double result = 0;
  if (x == MAX_INF || x == MIN_INF || x != x) {
    result = MAX_NAN;
  } else {
    result = s21_sin(x) / s21_cos(x);
  }
  return result;
}

// ######################### other #########################

long double s21_trunc(double x) {
  long double result;
  if (x == MAX_INF || x == MIN_INF || x != x || x == 0) {
    result = x;
  } else {
    if (x < 0)
      result = s21_ceil(x);
    else
      result = s21_floor(x);
  }
  return result;
}
