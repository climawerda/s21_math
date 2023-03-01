#define MAX_INF (1.0f / 0.0f)
#define MIN_INF (-1.0f / 0.0f)
#define MAX_NAN (0.0f / 0.0f)
#define MIN_NAN (-0.0f / 0.0f)

#define S21_E 2.71828182845904523536028747
#define S21_PI 3.14159265358979323846264338327950288
#define S21_MAX_DOUBLE 1.7976931348623158e+308

#define EPS_6 1e-7
#define EPS_24 1e-25

// ventureb
long double s21_ceil(double x);
long double s21_floor(double x);
long double s21_fmod(double x, double y);
long double s21_sqrt(double x);
long double s21_exp(double x);
// grangerc
long double s21_pow(double base, double exp);
long double s21_asin(double x);
long double s21_atan(double x);
long double s21_acos(double x);
long double s21_log(double x);
// migdalia
int s21_abs(int x);
long double s21_fabs(double x);
long double s21_cos(double x);
long double s21_sin(double x);
long double s21_tan(double x);
// other
long double s21_trunc(double x);
