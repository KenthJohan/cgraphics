#pragma once
#include <math.h>

// Set vector scalar
// (v := {x | x = s})
#define SET_VS(N, v, s)                                                 \
{                                                                       \
    int _i;                                                             \
    for (_i = 0; _i < (N); _i++)                                        \
        (v)[_i] = (s);                                                  \
}

// Set vector vector
// (v := u)
#define SET_VV(N, v, u)                                                 \
{                                                                       \
    int _i;                                                             \
    for (_i = 0; _i < (N); _i++)                                        \
        (v)[_i] = (u)[_i];                                              \
}

// Add vector vector scalar
// (v := u + s)
#define ADD_VVS(N, v, u, s)                                             \
{                                                                       \
    int _i;                                                             \
    for (_i = 0; _i < (N); _i++)                                        \
        (v)[_i] = (u)[_i] + (s);                                        \
}

// Add vector vector vector
// (v := u + s)
#define ADD_VVV(N, v, u, w)                                             \
{                                                                       \
    int _i;                                                             \
    for (_i = 0; _i < (N); _i++)                                        \
        (v)[_i] = (u)[_i] + (w)[_i];                                    \
}

// Sub vector vector vector
// (v := u - w)
#define SUB_VVV(N, v, u, w)                                             \
{                                                                       \
    int _i;                                                             \
    for (_i = 0; _i < (N); _i++)                                        \
        (v)[_i] = (u)[_i] - (w)[_i];                                    \
}

// Sub vector vector scalar
// (v := u - s)
#define SUB_VVS(N, v, u, s)                                             \
{                                                                       \
    int _i;                                                             \
    for (_i = 0; _i < (N); _i++)                                        \
        (v)[_i] = (u)[_i] - (s);                                        \
}


// Clear vector
// (v := {x | x = 0})
#define CLR_V(N, v)                                                     \
{                                                                       \
    int _i;                                                             \
    for (_i = 0; _i < (N); _i++)                                        \
        (v)[_i] = 0.0;                                                  \
}


#define UNIT_V(N, v, j)                                                 \
{                                                                       \
    int _i;                                                             \
    for (_i = 0; _i < (N); _i++)                                        \
        (v)[_i] = (_i == (j) ? 1.0 : 0.0);                              \
}


#define MUL_VVS(N, v, u, s)                                             \
{                                                                       \
    int _i;                                                             \
    for (_i = 0; _i < (N); _i++)                                        \
        (v)[_i] = (u)[_i] * (s);                                        \
}


#define DIV_VVS(N, v, u, s)                                             \
{                                                                       \
    int _i;                                                             \
    for (_i = 0; _i < (N); _i++)                                        \
        (v)[_i] = (u)[_i] / (s);                                        \
}


#define DOTP_SVV(N, s, v, u)                                            \
{                                                                       \
    int _i;                                                             \
    (s) = 0.0;                                                          \
    for (_i = 0; _i < N; _i++)                                          \
        (s) += (v)[_i] * (u)[_i];                                       \
}


#define ABS_SV(N, s, v)                                                 \
{                                                                       \
    real _tmp;                                                          \
    int _i;                                                             \
    _tmp = 0.0;                                                         \
    for (_i = 0; _i < (N); _i++)                                        \
        _tmp += (v)[_i] * (v)[_i];                                      \
    (s) = rsqrt(_tmp);                                                  \
}


#define DIST_SVV(N, s, u, v)                                            \
{                                                                       \
    real _tmp;                                                          \
    int _i;                                                             \
    _tmp = 0.0;                                                         \
    for (_i = 0; _i < (N); _i++)                                        \
        _tmp += ((u)[_i]-(v)[_i]) * ((u)[_i]-(v)[_i]);                  \
    (s) = rsqrt(_tmp);                                                  \
}


#define CROSSP_SV2V2(s,v,u)                                             \
{                                                                       \
    (s) = (v)[0]*(u)[1] - (v)[1]*(u)[0];                                \
}


#define CROSSP_SV3V3(v,u,w)                                             \
{                                                                       \
    (v)[0] = (u)[1]*(w)[2] - (u)[2]*(w)[1];                             \
    (v)[1] = (u)[2]*(w)[0] - (u)[0]*(w)[2];                             \
    (v)[2] = (u)[0]*(w)[1] - (u)[1]*(w)[0];                             \
}


#define IDENTITY_M(n1, n2, m)                                           \
{                                                                       \
    for (size_t _i = 0; _i < (n1); _i++)                                \
    for (size_t _j = 0; _j < (n2); _j++)                                \
        (m)[_i*n1 + _j] = (_i == _j ? 1.0 : 0.0);                       \
}


#define TX_M4X4 12
#define TY_M4X4 13
#define TZ_M4X4 14



#define PRINT_M4X4(m)                                                   \
{                                                                       \
	for (size_t _i = 0; _i < 4; _i++)                                     \
	{                                                                     \
		for (size_t _j = 0; _j < 4; _j++)                                   \
			printf ("%2.2f ", m [_j*4 + _i]);                                 \
		printf ("\n");                                                      \
	}                                                                     \
}


#define MUL_M4X4(m, a, b)                                               \
{                                                                       \
	for (size_t _c = 0; _c < 4; _c = _c + 1)                              \
	for (size_t _r = 0; _r < 4; _r = _r + 1)                              \
	{                                                                     \
		(m)[_c*4 + _r] = 0.0f;                                              \
		for(size_t _k = 0; _k < 4; _k = _k + 1)                             \
			(m)[_c*4 + _r] += (a)[_k*4 + _r] * (b)[_c*4 + _k];                \
	}                                                                     \
}

#define ROTX_M4X4(m, a)                                                 \
(m)[5] = cos (a);                                                       \
(m)[6] = sin (a);                                                       \
(m)[9] = -sin (a);                                                      \
(m)[10] = cos (a);                                                      \

#define ROTY_M4X4(m, a)                                                 \
(m)[0] = cos (a);                                                       \
(m)[2] = -sin (a);                                                      \
(m)[8] = sin (a);                                                       \
(m)[10] = cos (a);                                                      \

#define ROTZ_M4X4(m, a)                                                 \
(m)[0] = cos (a);                                                       \
(m)[1] = sin (a);                                                       \
(m)[4] = -sin (a);                                                      \
(m)[5] = cos (a);                                                       \


#define FRUSTUM_M4X4(m, r, t, n, f)                                     \
(m)[0] = (n)/(r);                                                       \
(m)[5] = (n)/(r);                                                       \
(m)[10] = -((f)+(n))/((f)-(n));                                         \
(m)[11] = -1;                                                           \
(m)[14] = (-2*(f)*(n))/((f)-(n));                                       \

#define PERSPECTIVE_M4X4(m, fov, aspect, n, f)                          \
FRUSTUM_M4X4((m),(aspect)*tan((fov) * 0.5 * M_PI / 180), tan((fov) * 0.5 * M_PI / 180) * n, (n), (f))
