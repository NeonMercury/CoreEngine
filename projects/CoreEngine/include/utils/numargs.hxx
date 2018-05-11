#pragma once
#define EXPAND( x ) x

#define NUM_ARGS_(_16, _15, _14, _13, _12, _11, _10, _9, _8, _7, _6, _5, _4, _3, _2, _1, N, ...) N
#define NUM_ARGS(...) EXPAND(NUM_ARGS_(__VA_ARGS__, 16, 15,14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0))

#define FOREACH(MACRO, ...) FOREACH_(NUM_ARGS(__VA_ARGS__), MACRO, __VA_ARGS__)
#define FOREACH_(N, M, ...) FOREACH__(N, M, __VA_ARGS__)
#define FOREACH__(N, M, ...) EXPAND(FOREACH_##N(M, __VA_ARGS__))

#define FOREACH_1(M, A) M(A)
#define FOREACH_2(M, A, ...) M(A)  FOREACH_1(M, __VA_ARGS__)
#define FOREACH_3(M, A, ...) M(A)  FOREACH_2(M, __VA_ARGS__)
#define FOREACH_4(M, A, ...) M(A)  FOREACH_3(M, __VA_ARGS__)
#define FOREACH_5(M, A, ...) M(A)  FOREACH_4(M, __VA_ARGS__)
#define FOREACH_6(M, A, ...) M(A)  FOREACH_5(M, __VA_ARGS__)
#define FOREACH_7(M, A, ...) M(A)  FOREACH_6(M, __VA_ARGS__)
#define FOREACH_8(M, A, ...) M(A)  FOREACH_7(M, __VA_ARGS__)
#define FOREACH_9(M, A, ...) M(A)  FOREACH_8(M, __VA_ARGS__)
#define FOREACH_10(M, A, ...) M(A)  FOREACH_9(M, __VA_ARGS__)
#define FOREACH_11(M, A, ...) M(A)  FOREACH_10(M, __VA_ARGS__)
#define FOREACH_12(M, A, ...) M(A)  FOREACH_11(M, __VA_ARGS__)
#define FOREACH_13(M, A, ...) M(A)  FOREACH_12(M, __VA_ARGS__)
#define FOREACH_14(M, A, ...) M(A)  FOREACH_13(M, __VA_ARGS__)
#define FOREACH_15(M, A, ...) M(A)  FOREACH_14(M, __VA_ARGS__)
#define FOREACH_16(M, A, ...) M(A)  FOREACH_15(M, __VA_ARGS__)
